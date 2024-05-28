/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#pragma once
#ifndef LLM_OS_UI_Xaml_Printing_H
#define LLM_OS_UI_Xaml_Printing_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Xaml.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Graphics.Printing.2.h"
#include "llm/impl/Windows.UI.Xaml.2.h"
#include "llm/impl/Windows.UI.Xaml.Printing.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::PrintTaskOptions) consume_Windows_UI_Xaml_Printing_IAddPagesEventArgs<D>::PrintTaskOptions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IAddPagesEventArgs)->get_PrintTaskOptions(&value));
        return llm::OS::Graphics::Printing::PrintTaskOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Printing_IGetPreviewPageEventArgs<D>::PageNumber() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IGetPreviewPageEventArgs)->get_PageNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::PrintTaskOptions) consume_Windows_UI_Xaml_Printing_IPaginateEventArgs<D>::PrintTaskOptions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPaginateEventArgs)->get_PrintTaskOptions(&value));
        return llm::OS::Graphics::Printing::PrintTaskOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Printing_IPaginateEventArgs<D>::CurrentPreviewPageNumber() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPaginateEventArgs)->get_CurrentPreviewPageNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing::IPrintDocumentSource) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::DocumentSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->get_DocumentSource(&value));
        return llm::OS::Graphics::Printing::IPrintDocumentSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::Paginate(llm::OS::UI::Xaml::Printing::PaginateEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->add_Paginate(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::Paginate_revoker consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::Paginate(auto_revoke_t, llm::OS::UI::Xaml::Printing::PaginateEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, Paginate_revoker>(this, Paginate(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::Paginate(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->remove_Paginate(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::GetPreviewPage(llm::OS::UI::Xaml::Printing::GetPreviewPageEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->add_GetPreviewPage(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::GetPreviewPage_revoker consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::GetPreviewPage(auto_revoke_t, llm::OS::UI::Xaml::Printing::GetPreviewPageEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, GetPreviewPage_revoker>(this, GetPreviewPage(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::GetPreviewPage(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->remove_GetPreviewPage(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::AddPages(llm::OS::UI::Xaml::Printing::AddPagesEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->add_AddPages(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::AddPages_revoker consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::AddPages(auto_revoke_t, llm::OS::UI::Xaml::Printing::AddPagesEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, AddPages_revoker>(this, AddPages(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::AddPages(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->remove_AddPages(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::AddPage(llm::OS::UI::Xaml::UIElement const& pageVisual) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->AddPage(*(void**)(&pageVisual)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::AddPagesComplete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->AddPagesComplete());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::SetPreviewPageCount(int32_t count, llm::OS::UI::Xaml::Printing::PreviewPageCountType const& type) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->SetPreviewPageCount(count, static_cast<int32_t>(type)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::SetPreviewPage(int32_t pageNumber, llm::OS::UI::Xaml::UIElement const& pageVisual) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->SetPreviewPage(pageNumber, *(void**)(&pageVisual)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Printing_IPrintDocument<D>::InvalidatePreview() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocument)->InvalidatePreview());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Printing::PrintDocument) consume_Windows_UI_Xaml_Printing_IPrintDocumentFactory<D>::CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocumentFactory)->CreateInstance(*(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Printing::PrintDocument{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) consume_Windows_UI_Xaml_Printing_IPrintDocumentStatics<D>::DocumentSourceProperty() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Printing::IPrintDocumentStatics)->get_DocumentSourceProperty(&value));
        return llm::OS::UI::Xaml::DependencyProperty{ value, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::UI::Xaml::Printing::AddPagesEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Printing::AddPagesEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Printing::AddPagesEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Printing::AddPagesEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::Xaml::Printing::GetPreviewPageEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Printing::GetPreviewPageEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Printing::GetPreviewPageEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Printing::GetPreviewPageEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::Xaml::Printing::PaginateEventHandler, H> final : implements_delegate<llm::OS::UI::Xaml::Printing::PaginateEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Xaml::Printing::PaginateEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::Xaml::Printing::PaginateEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Printing::IAddPagesEventArgs> : produce_base<D, llm::OS::UI::Xaml::Printing::IAddPagesEventArgs>
    {
        int32_t __stdcall get_PrintTaskOptions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing::PrintTaskOptions>(this->shim().PrintTaskOptions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Printing::IGetPreviewPageEventArgs> : produce_base<D, llm::OS::UI::Xaml::Printing::IGetPreviewPageEventArgs>
    {
        int32_t __stdcall get_PageNumber(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().PageNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Printing::IPaginateEventArgs> : produce_base<D, llm::OS::UI::Xaml::Printing::IPaginateEventArgs>
    {
        int32_t __stdcall get_PrintTaskOptions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing::PrintTaskOptions>(this->shim().PrintTaskOptions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentPreviewPageNumber(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().CurrentPreviewPageNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Printing::IPrintDocument> : produce_base<D, llm::OS::UI::Xaml::Printing::IPrintDocument>
    {
        int32_t __stdcall get_DocumentSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing::IPrintDocumentSource>(this->shim().DocumentSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Paginate(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Paginate(*reinterpret_cast<llm::OS::UI::Xaml::Printing::PaginateEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Paginate(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Paginate(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_GetPreviewPage(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().GetPreviewPage(*reinterpret_cast<llm::OS::UI::Xaml::Printing::GetPreviewPageEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_GetPreviewPage(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetPreviewPage(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AddPages(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AddPages(*reinterpret_cast<llm::OS::UI::Xaml::Printing::AddPagesEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AddPages(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPages(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall AddPage(void* pageVisual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPage(*reinterpret_cast<llm::OS::UI::Xaml::UIElement const*>(&pageVisual));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddPagesComplete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddPagesComplete();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPreviewPageCount(int32_t count, int32_t type) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreviewPageCount(count, *reinterpret_cast<llm::OS::UI::Xaml::Printing::PreviewPageCountType const*>(&type));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPreviewPage(int32_t pageNumber, void* pageVisual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreviewPage(pageNumber, *reinterpret_cast<llm::OS::UI::Xaml::UIElement const*>(&pageVisual));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InvalidatePreview() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvalidatePreview();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Printing::IPrintDocumentFactory> : produce_base<D, llm::OS::UI::Xaml::Printing::IPrintDocumentFactory>
    {
        int32_t __stdcall CreateInstance(void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Printing::PrintDocument>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Printing::IPrintDocumentStatics> : produce_base<D, llm::OS::UI::Xaml::Printing::IPrintDocumentStatics>
    {
        int32_t __stdcall get_DocumentSourceProperty(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::DependencyProperty>(this->shim().DocumentSourceProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Printing
{
    inline AddPagesEventArgs::AddPagesEventArgs() :
        AddPagesEventArgs(impl::call_factory_cast<AddPagesEventArgs(*)(llm::OS::Foundation::IActivationFactory const&), AddPagesEventArgs>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<AddPagesEventArgs>(); }))
    {
    }
    inline GetPreviewPageEventArgs::GetPreviewPageEventArgs() :
        GetPreviewPageEventArgs(impl::call_factory_cast<GetPreviewPageEventArgs(*)(llm::OS::Foundation::IActivationFactory const&), GetPreviewPageEventArgs>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<GetPreviewPageEventArgs>(); }))
    {
    }
    inline PaginateEventArgs::PaginateEventArgs() :
        PaginateEventArgs(impl::call_factory_cast<PaginateEventArgs(*)(llm::OS::Foundation::IActivationFactory const&), PaginateEventArgs>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PaginateEventArgs>(); }))
    {
    }
    inline PrintDocument::PrintDocument()
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<PrintDocument, IPrintDocumentFactory>([&](IPrintDocumentFactory const& f) { return f.CreateInstance(baseInterface, innerInterface); });
    }
    inline auto PrintDocument::DocumentSourceProperty()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::DependencyProperty(*)(IPrintDocumentStatics const&), PrintDocument, IPrintDocumentStatics>([](IPrintDocumentStatics const& f) { return f.DocumentSourceProperty(); });
    }
    template <typename L> AddPagesEventHandler::AddPagesEventHandler(L handler) :
        AddPagesEventHandler(impl::make_delegate<AddPagesEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> AddPagesEventHandler::AddPagesEventHandler(F* handler) :
        AddPagesEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> AddPagesEventHandler::AddPagesEventHandler(O* object, M method) :
        AddPagesEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> AddPagesEventHandler::AddPagesEventHandler(com_ptr<O>&& object, M method) :
        AddPagesEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> AddPagesEventHandler::AddPagesEventHandler(weak_ref<O>&& object, M method) :
        AddPagesEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto AddPagesEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Printing::AddPagesEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<AddPagesEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> GetPreviewPageEventHandler::GetPreviewPageEventHandler(L handler) :
        GetPreviewPageEventHandler(impl::make_delegate<GetPreviewPageEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> GetPreviewPageEventHandler::GetPreviewPageEventHandler(F* handler) :
        GetPreviewPageEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> GetPreviewPageEventHandler::GetPreviewPageEventHandler(O* object, M method) :
        GetPreviewPageEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> GetPreviewPageEventHandler::GetPreviewPageEventHandler(com_ptr<O>&& object, M method) :
        GetPreviewPageEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> GetPreviewPageEventHandler::GetPreviewPageEventHandler(weak_ref<O>&& object, M method) :
        GetPreviewPageEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto GetPreviewPageEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Printing::GetPreviewPageEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<GetPreviewPageEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> PaginateEventHandler::PaginateEventHandler(L handler) :
        PaginateEventHandler(impl::make_delegate<PaginateEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> PaginateEventHandler::PaginateEventHandler(F* handler) :
        PaginateEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> PaginateEventHandler::PaginateEventHandler(O* object, M method) :
        PaginateEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> PaginateEventHandler::PaginateEventHandler(com_ptr<O>&& object, M method) :
        PaginateEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> PaginateEventHandler::PaginateEventHandler(weak_ref<O>&& object, M method) :
        PaginateEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto PaginateEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::Xaml::Printing::PaginateEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<PaginateEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename D, typename... Interfaces>
    struct PrintDocumentT :
        implements<D, llm::OS::Foundation::IInspectable, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Printing::IPrintDocument, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, PrintDocument, llm::OS::UI::Xaml::DependencyObject>
    {
        using composable = PrintDocument;
    protected:
        PrintDocumentT()
        {
            impl::call_factory<PrintDocument, IPrintDocumentFactory>([&](IPrintDocumentFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstance(*this, this->m_inner); });
        }
    };
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Xaml::Printing::IAddPagesEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::IGetPreviewPageEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::IPaginateEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::IPrintDocument> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::IPrintDocumentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::IPrintDocumentStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::AddPagesEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::GetPreviewPageEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::PaginateEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Printing::PrintDocument> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
