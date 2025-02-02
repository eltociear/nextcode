#include <llvm/ADT/StringMap.h>
#include <llvm/DebugInfo/DIContext.h>
#include <llvm/IR/DataLayout.h>

#include "code.h"

#include <map>
#include <mutex>
#include <type_traits>

typedef struct {
    const llvm::object::ObjectFile *obj;
    llvm::DIContext *ctx;
    int64_t slide;
} objfileentry_t;

// Central registry for resolving function addresses to `language_method_instance_t`s and
// originating `ObjectFile`s (for the DWARF debug info).
//
// A global singleton instance is notified by the JIT whenever a new object is emitted,
// and later queried by the various function info APIs. We also use the chance to handle
// some platform-specific unwind info registration (which is unrelated to the query
// functionality).
class JITDebugInfoRegistry
{
public:
    template<typename ResourceT>
    struct Locked {

        template<typename CResourceT>
        struct Lock {
            std::unique_lock<std::mutex> lock;
            CResourceT &resource;

            Lock(std::mutex &mutex, CResourceT &resource) LANGUAGE_NOTSAFEPOINT : lock(mutex), resource(resource) {}
            Lock(Lock &&) LANGUAGE_NOTSAFEPOINT = default;
            Lock &operator=(Lock &&) LANGUAGE_NOTSAFEPOINT = default;

            CResourceT &operator*() LANGUAGE_NOTSAFEPOINT {
                return resource;
            }

            const CResourceT &operator*() const LANGUAGE_NOTSAFEPOINT {
                return resource;
            }

            CResourceT *operator->() LANGUAGE_NOTSAFEPOINT {
                return &**this;
            }

            const CResourceT *operator->() const LANGUAGE_NOTSAFEPOINT {
                return &**this;
            }

            operator const CResourceT &() const LANGUAGE_NOTSAFEPOINT {
                return resource;
            }

            ~Lock() LANGUAGE_NOTSAFEPOINT = default;
        };
    private:

        mutable std::mutex mutex;
        ResourceT resource;
    public:
        typedef Lock<ResourceT> LockT;
        typedef Lock<const ResourceT> ConstLockT;

        Locked(ResourceT resource = ResourceT()) LANGUAGE_NOTSAFEPOINT : mutex(), resource(std::move(resource)) {}

        LockT operator*() LANGUAGE_NOTSAFEPOINT {
            return LockT(mutex, resource);
        }

        ConstLockT operator*() const LANGUAGE_NOTSAFEPOINT {
            return ConstLockT(mutex, resource);
        }

        ~Locked() LANGUAGE_NOTSAFEPOINT = default;
    };

    struct image_info_t {
        uint64_t base;
        language_image_fptrs_t fptrs;
        language_method_instance_t **fvars_linfo;
        size_t fvars_n;
    };

    struct libc_frames_t {
#if defined(_OS_DARWIN_) && defined(LLVM_SHLIB)
        typedef void (*frame_register_func)(void *) LANGUAGE_NOTSAFEPOINT;
        std::atomic<frame_register_func> libc_register_frame_{nullptr};
        std::atomic<frame_register_func> libc_deregister_frame_{nullptr};

        void libc_register_frame(const char *Entry) LANGUAGE_NOTSAFEPOINT;

        void libc_deregister_frame(const char *Entry) LANGUAGE_NOTSAFEPOINT;
#endif
    };
private:

    struct ObjectInfo {
        const llvm::object::ObjectFile *object = nullptr;
        size_t SectionSize = 0;
        ptrdiff_t slide = 0;
        llvm::object::SectionRef Section{};
        llvm::DIContext *context = nullptr;
    };

    template<typename KeyT, typename ValT>
    using rev_map = std::map<KeyT, ValT, std::greater<KeyT>>;

    typedef rev_map<size_t, ObjectInfo> objectmap_t;
    typedef rev_map<uint64_t, objfileentry_t> objfilemap_t;

    objectmap_t objectmap{};
    rev_map<size_t, std::pair<size_t, language_method_instance_t *>> linfomap{};

    // Maintain a mapping of unrealized function names -> linfo objects
    // so that when we see it get emitted, we can add a link back to the linfo
    // that it came from (providing name, type signature, file info, etc.)
    Locked<llvm::StringMap<language_code_instance_t*>> codeinst_in_flight{};

    Locked<llvm::DenseMap<uint64_t, image_info_t>> image_info{};

    Locked<objfilemap_t> objfilemap{};

    static std::string mangle(llvm::StringRef Name, const llvm::DataLayout &DL) LANGUAGE_NOTSAFEPOINT;

public:

    JITDebugInfoRegistry() LANGUAGE_NOTSAFEPOINT;
    ~JITDebugInfoRegistry() LANGUAGE_NOTSAFEPOINT = default;

    libc_frames_t libc_frames{};

    void add_code_in_flight(llvm::StringRef name, language_code_instance_t *codeinst, const llvm::DataLayout &DL) LANGUAGE_NOTSAFEPOINT;
    language_method_instance_t *lookupLinfo(size_t pointer) LANGUAGE_NOTSAFEPOINT;
    void registerJITObject(const llvm::object::ObjectFile &Object,
                        std::function<uint64_t(const llvm::StringRef &)> getLoadAddress,
                        std::function<void*(void*)> lookupWriteAddress);
    objectmap_t& getObjectMap() LANGUAGE_NOTSAFEPOINT;
    void add_image_info(image_info_t info) LANGUAGE_NOTSAFEPOINT;
    bool get_image_info(uint64_t base, image_info_t *info) const LANGUAGE_NOTSAFEPOINT;
    Locked<objfilemap_t>::LockT get_objfile_map() LANGUAGE_NOTSAFEPOINT;
};
