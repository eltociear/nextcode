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
#ifndef LLM_OS_Media_Protection_0_H
#define LLM_OS_Media_Protection_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    struct IPropertySet;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Media::Playback
{
    struct MediaPlaybackItem;
}
LLM_EXPORT namespace llm:OS::Media::Protection
{
    enum class GraphicsTrustStatus : int32_t
    {
        TrustNotRequired = 0,
        TrustEstablished = 1,
        EnvironmentNotSupported = 2,
        DriverNotSupported = 3,
        DriverSigningFailure = 4,
        UnknownFailure = 5,
    };
    enum class HdcpProtection : int32_t
    {
        Off = 0,
        On = 1,
        OnWithTypeEnforcement = 2,
    };
    enum class HdcpSetProtectionResult : int32_t
    {
        Success = 0,
        TimedOut = 1,
        NotSupported = 2,
        UnknownFailure = 3,
    };
    enum class ProtectionCapabilityResult : int32_t
    {
        NotSupported = 0,
        Maybe = 1,
        Probably = 2,
    };
    enum class RenewalStatus : int32_t
    {
        NotStarted = 0,
        UpdatesInProgress = 1,
        UserCancelled = 2,
        AppComponentsMayNeedUpdating = 3,
        NoComponentsFound = 4,
    };
    enum class RevocationAndRenewalReasons : uint32_t
    {
        UserModeComponentLoad = 0x1,
        KernelModeComponentLoad = 0x2,
        AppComponent = 0x4,
        GlobalRevocationListLoadFailed = 0x10,
        InvalidGlobalRevocationListSignature = 0x20,
        GlobalRevocationListAbsent = 0x1000,
        ComponentRevoked = 0x2000,
        InvalidComponentCertificateExtendedKeyUse = 0x4000,
        ComponentCertificateRevoked = 0x8000,
        InvalidComponentCertificateRoot = 0x10000,
        ComponentHighSecurityCertificateRevoked = 0x20000,
        ComponentLowSecurityCertificateRevoked = 0x40000,
        BootDriverVerificationFailed = 0x100000,
        ComponentSignedWithTestCertificate = 0x1000000,
        EncryptionFailure = 0x10000000,
    };
    struct IComponentLoadFailedEventArgs;
    struct IComponentRenewalStatics;
    struct IHdcpSession;
    struct IMediaProtectionManager;
    struct IMediaProtectionPMPServer;
    struct IMediaProtectionPMPServerFactory;
    struct IMediaProtectionServiceCompletion;
    struct IMediaProtectionServiceRequest;
    struct IProtectionCapabilities;
    struct IRevocationAndRenewalInformation;
    struct IRevocationAndRenewalItem;
    struct IServiceRequestedEventArgs;
    struct IServiceRequestedEventArgs2;
    struct ComponentLoadFailedEventArgs;
    struct ComponentRenewal;
    struct HdcpSession;
    struct MediaProtectionManager;
    struct MediaProtectionPMPServer;
    struct MediaProtectionServiceCompletion;
    struct ProtectionCapabilities;
    struct RevocationAndRenewalInformation;
    struct RevocationAndRenewalItem;
    struct ServiceRequestedEventArgs;
    struct ComponentLoadFailedEventHandler;
    struct RebootNeededEventHandler;
    struct ServiceRequestedEventHandler;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Protection::IComponentLoadFailedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IComponentRenewalStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IHdcpSession>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IMediaProtectionManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IMediaProtectionPMPServer>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IMediaProtectionPMPServerFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IMediaProtectionServiceCompletion>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IMediaProtectionServiceRequest>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IProtectionCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IRevocationAndRenewalInformation>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IRevocationAndRenewalItem>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IServiceRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::IServiceRequestedEventArgs2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Protection::ComponentLoadFailedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::ComponentRenewal>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::HdcpSession>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::MediaProtectionManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::MediaProtectionPMPServer>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::MediaProtectionServiceCompletion>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::ProtectionCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::RevocationAndRenewalInformation>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::RevocationAndRenewalItem>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::ServiceRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Protection::GraphicsTrustStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Protection::HdcpProtection>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Protection::HdcpSetProtectionResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Protection::ProtectionCapabilityResult>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Protection::RenewalStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Protection::RevocationAndRenewalReasons>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Protection::ComponentLoadFailedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::Media::Protection::RebootNeededEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::Media::Protection::ServiceRequestedEventHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::ComponentLoadFailedEventArgs> = L"Windows.Media.Protection.ComponentLoadFailedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::ComponentRenewal> = L"Windows.Media.Protection.ComponentRenewal";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::HdcpSession> = L"Windows.Media.Protection.HdcpSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::MediaProtectionManager> = L"Windows.Media.Protection.MediaProtectionManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::MediaProtectionPMPServer> = L"Windows.Media.Protection.MediaProtectionPMPServer";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::MediaProtectionServiceCompletion> = L"Windows.Media.Protection.MediaProtectionServiceCompletion";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::ProtectionCapabilities> = L"Windows.Media.Protection.ProtectionCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::RevocationAndRenewalInformation> = L"Windows.Media.Protection.RevocationAndRenewalInformation";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::RevocationAndRenewalItem> = L"Windows.Media.Protection.RevocationAndRenewalItem";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::ServiceRequestedEventArgs> = L"Windows.Media.Protection.ServiceRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::GraphicsTrustStatus> = L"Windows.Media.Protection.GraphicsTrustStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::HdcpProtection> = L"Windows.Media.Protection.HdcpProtection";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::HdcpSetProtectionResult> = L"Windows.Media.Protection.HdcpSetProtectionResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::ProtectionCapabilityResult> = L"Windows.Media.Protection.ProtectionCapabilityResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::RenewalStatus> = L"Windows.Media.Protection.RenewalStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::RevocationAndRenewalReasons> = L"Windows.Media.Protection.RevocationAndRenewalReasons";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IComponentLoadFailedEventArgs> = L"Windows.Media.Protection.IComponentLoadFailedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IComponentRenewalStatics> = L"Windows.Media.Protection.IComponentRenewalStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IHdcpSession> = L"Windows.Media.Protection.IHdcpSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IMediaProtectionManager> = L"Windows.Media.Protection.IMediaProtectionManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IMediaProtectionPMPServer> = L"Windows.Media.Protection.IMediaProtectionPMPServer";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IMediaProtectionPMPServerFactory> = L"Windows.Media.Protection.IMediaProtectionPMPServerFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IMediaProtectionServiceCompletion> = L"Windows.Media.Protection.IMediaProtectionServiceCompletion";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IMediaProtectionServiceRequest> = L"Windows.Media.Protection.IMediaProtectionServiceRequest";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IProtectionCapabilities> = L"Windows.Media.Protection.IProtectionCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IRevocationAndRenewalInformation> = L"Windows.Media.Protection.IRevocationAndRenewalInformation";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IRevocationAndRenewalItem> = L"Windows.Media.Protection.IRevocationAndRenewalItem";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IServiceRequestedEventArgs> = L"Windows.Media.Protection.IServiceRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::IServiceRequestedEventArgs2> = L"Windows.Media.Protection.IServiceRequestedEventArgs2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::ComponentLoadFailedEventHandler> = L"Windows.Media.Protection.ComponentLoadFailedEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::RebootNeededEventHandler> = L"Windows.Media.Protection.RebootNeededEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::Media::Protection::ServiceRequestedEventHandler> = L"Windows.Media.Protection.ServiceRequestedEventHandler";
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IComponentLoadFailedEventArgs>{ 0x95972E93,0x7746,0x417E,{ 0x84,0x95,0xF0,0x31,0xBB,0xC5,0x86,0x2C } }; // 95972E93-7746-417E-8495-F031BBC5862C
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IComponentRenewalStatics>{ 0x6FFBCD67,0xB795,0x48C5,{ 0x8B,0x7B,0xA7,0xC4,0xEF,0xE2,0x02,0xE3 } }; // 6FFBCD67-B795-48C5-8B7B-A7C4EFE202E3
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IHdcpSession>{ 0x718845E9,0x64D7,0x426D,{ 0x80,0x9B,0x1B,0xE4,0x61,0x94,0x1A,0x2A } }; // 718845E9-64D7-426D-809B-1BE461941A2A
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IMediaProtectionManager>{ 0x45694947,0xC741,0x434B,{ 0xA7,0x9E,0x47,0x4C,0x12,0xD9,0x3D,0x2F } }; // 45694947-C741-434B-A79E-474C12D93D2F
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IMediaProtectionPMPServer>{ 0x0C111226,0x7B26,0x4D31,{ 0x95,0xBB,0x9C,0x1B,0x08,0xEF,0x7F,0xC0 } }; // 0C111226-7B26-4D31-95BB-9C1B08EF7FC0
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IMediaProtectionPMPServerFactory>{ 0x602C8E5E,0xF7D2,0x487E,{ 0xAF,0x91,0xDB,0xC4,0x25,0x2B,0x21,0x82 } }; // 602C8E5E-F7D2-487E-AF91-DBC4252B2182
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IMediaProtectionServiceCompletion>{ 0x8B5CCA18,0xCFD5,0x44EE,{ 0xA2,0xED,0xDF,0x76,0x01,0x0C,0x14,0xB5 } }; // 8B5CCA18-CFD5-44EE-A2ED-DF76010C14B5
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IMediaProtectionServiceRequest>{ 0xB1DE0EA6,0x2094,0x478D,{ 0x87,0xA4,0x8B,0x95,0x20,0x0F,0x85,0xC6 } }; // B1DE0EA6-2094-478D-87A4-8B95200F85C6
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IProtectionCapabilities>{ 0xC7AC5D7E,0x7480,0x4D29,{ 0xA4,0x64,0x7B,0xCD,0x91,0x3D,0xD8,0xE4 } }; // C7AC5D7E-7480-4D29-A464-7BCD913DD8E4
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IRevocationAndRenewalInformation>{ 0xF3A1937B,0x2501,0x439E,{ 0xA6,0xE7,0x6F,0xC9,0x5E,0x17,0x5F,0xCF } }; // F3A1937B-2501-439E-A6E7-6FC95E175FCF
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IRevocationAndRenewalItem>{ 0x3099C20C,0x3CF0,0x49EA,{ 0x90,0x2D,0xCA,0xF3,0x2D,0x2D,0xDE,0x2C } }; // 3099C20C-3CF0-49EA-902D-CAF32D2DDE2C
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IServiceRequestedEventArgs>{ 0x34283BAF,0xABB4,0x4FC1,{ 0xBD,0x89,0x93,0xF1,0x06,0x57,0x3A,0x49 } }; // 34283BAF-ABB4-4FC1-BD89-93F106573A49
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::IServiceRequestedEventArgs2>{ 0x553C69D6,0xFAFE,0x4128,{ 0x8D,0xFA,0x13,0x0E,0x39,0x8A,0x13,0xA7 } }; // 553C69D6-FAFE-4128-8DFA-130E398A13A7
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::ComponentLoadFailedEventHandler>{ 0x95DA643C,0x6DB9,0x424B,{ 0x86,0xCA,0x09,0x1A,0xF4,0x32,0x08,0x1C } }; // 95DA643C-6DB9-424B-86CA-091AF432081C
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::RebootNeededEventHandler>{ 0x64E12A45,0x973B,0x4A3A,{ 0xB2,0x60,0x91,0x89,0x8A,0x49,0xA8,0x2C } }; // 64E12A45-973B-4A3A-B260-91898A49A82C
    template <> inline constexpr guid guid_v<llm:OS::Media::Protection::ServiceRequestedEventHandler>{ 0xD2D690BA,0xCAC9,0x48E1,{ 0x95,0xC0,0xD3,0x84,0x95,0xA8,0x40,0x55 } }; // D2D690BA-CAC9-48E1-95C0-D38495A84055
    template <> struct default_interface<llm:OS::Media::Protection::ComponentLoadFailedEventArgs>{ using type = llm:OS::Media::Protection::IComponentLoadFailedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Protection::HdcpSession>{ using type = llm:OS::Media::Protection::IHdcpSession; };
    template <> struct default_interface<llm:OS::Media::Protection::MediaProtectionManager>{ using type = llm:OS::Media::Protection::IMediaProtectionManager; };
    template <> struct default_interface<llm:OS::Media::Protection::MediaProtectionPMPServer>{ using type = llm:OS::Media::Protection::IMediaProtectionPMPServer; };
    template <> struct default_interface<llm:OS::Media::Protection::MediaProtectionServiceCompletion>{ using type = llm:OS::Media::Protection::IMediaProtectionServiceCompletion; };
    template <> struct default_interface<llm:OS::Media::Protection::ProtectionCapabilities>{ using type = llm:OS::Media::Protection::IProtectionCapabilities; };
    template <> struct default_interface<llm:OS::Media::Protection::RevocationAndRenewalInformation>{ using type = llm:OS::Media::Protection::IRevocationAndRenewalInformation; };
    template <> struct default_interface<llm:OS::Media::Protection::RevocationAndRenewalItem>{ using type = llm:OS::Media::Protection::IRevocationAndRenewalItem; };
    template <> struct default_interface<llm:OS::Media::Protection::ServiceRequestedEventArgs>{ using type = llm:OS::Media::Protection::IServiceRequestedEventArgs; };
    template <> struct abi<llm:OS::Media::Protection::IComponentLoadFailedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Information(void**) noexcept = 0;
            virtual int32_t __stdcall get_Completion(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IComponentRenewalStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RenewSystemComponentsAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IHdcpSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsEffectiveProtectionAtLeast(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall GetEffectiveProtection(void**) noexcept = 0;
            virtual int32_t __stdcall SetDesiredMinProtectionAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall add_ProtectionChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ProtectionChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IMediaProtectionManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ServiceRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ServiceRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RebootNeeded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RebootNeeded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ComponentLoadFailed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ComponentLoadFailed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IMediaProtectionPMPServer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IMediaProtectionPMPServerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreatePMPServer(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IMediaProtectionServiceCompletion>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IMediaProtectionServiceRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProtectionSystem(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Type(llm::guid*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IProtectionCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsTypeSupported(void*, void*, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IRevocationAndRenewalInformation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Items(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IRevocationAndRenewalItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reasons(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_HeaderHash(void**) noexcept = 0;
            virtual int32_t __stdcall get_PublicKeyHash(void**) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_RenewalId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IServiceRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Request(void**) noexcept = 0;
            virtual int32_t __stdcall get_Completion(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::IServiceRequestedEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MediaPlaybackItem(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::ComponentLoadFailedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::RebootNeededEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Protection::ServiceRequestedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IComponentLoadFailedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Protection::RevocationAndRenewalInformation) Information() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Protection::MediaProtectionServiceCompletion) Completion() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IComponentLoadFailedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IComponentLoadFailedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IComponentRenewalStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Protection::RenewalStatus, uint32_t>) RenewSystemComponentsAsync(llm:OS::Media::Protection::RevocationAndRenewalInformation const& information) const;
    };
    template <> struct consume<llm:OS::Media::Protection::IComponentRenewalStatics>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IComponentRenewalStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IHdcpSession
    {
        LLM_IMPL_AUTO(bool) IsEffectiveProtectionAtLeast(llm:OS::Media::Protection::HdcpProtection const& protection) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Media::Protection::HdcpProtection>) GetEffectiveProtection() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Protection::HdcpSetProtectionResult>) SetDesiredMinProtectionAsync(llm:OS::Media::Protection::HdcpProtection const& protection) const;
        LLM_IMPL_AUTO(llm::event_token) ProtectionChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Protection::HdcpSession, llm:OS::Foundation::IInspectable> const& handler) const;
        using ProtectionChanged_revoker = impl::event_revoker<llm:OS::Media::Protection::IHdcpSession, &impl::abi_t<llm:OS::Media::Protection::IHdcpSession>::remove_ProtectionChanged>;
        [[nodiscard]] ProtectionChanged_revoker ProtectionChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Protection::HdcpSession, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ProtectionChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Protection::IHdcpSession>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IHdcpSession<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IMediaProtectionManager
    {
        LLM_IMPL_AUTO(llm::event_token) ServiceRequested(llm:OS::Media::Protection::ServiceRequestedEventHandler const& handler) const;
        using ServiceRequested_revoker = impl::event_revoker<llm:OS::Media::Protection::IMediaProtectionManager, &impl::abi_t<llm:OS::Media::Protection::IMediaProtectionManager>::remove_ServiceRequested>;
        [[nodiscard]] ServiceRequested_revoker ServiceRequested(auto_revoke_t, llm:OS::Media::Protection::ServiceRequestedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) ServiceRequested(llm::event_token const& cookie) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RebootNeeded(llm:OS::Media::Protection::RebootNeededEventHandler const& handler) const;
        using RebootNeeded_revoker = impl::event_revoker<llm:OS::Media::Protection::IMediaProtectionManager, &impl::abi_t<llm:OS::Media::Protection::IMediaProtectionManager>::remove_RebootNeeded>;
        [[nodiscard]] RebootNeeded_revoker RebootNeeded(auto_revoke_t, llm:OS::Media::Protection::RebootNeededEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) RebootNeeded(llm::event_token const& cookie) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ComponentLoadFailed(llm:OS::Media::Protection::ComponentLoadFailedEventHandler const& handler) const;
        using ComponentLoadFailed_revoker = impl::event_revoker<llm:OS::Media::Protection::IMediaProtectionManager, &impl::abi_t<llm:OS::Media::Protection::IMediaProtectionManager>::remove_ComponentLoadFailed>;
        [[nodiscard]] ComponentLoadFailed_revoker ComponentLoadFailed(auto_revoke_t, llm:OS::Media::Protection::ComponentLoadFailedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) ComponentLoadFailed(llm::event_token const& cookie) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IPropertySet) Properties() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IMediaProtectionManager>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IMediaProtectionManager<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IMediaProtectionPMPServer
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IPropertySet) Properties() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IMediaProtectionPMPServer>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IMediaProtectionPMPServer<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IMediaProtectionPMPServerFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Protection::MediaProtectionPMPServer) CreatePMPServer(llm:OS::Foundation::Collections::IPropertySet const& pProperties) const;
    };
    template <> struct consume<llm:OS::Media::Protection::IMediaProtectionPMPServerFactory>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IMediaProtectionPMPServerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IMediaProtectionServiceCompletion
    {
        LLM_IMPL_AUTO(void) Complete(bool success) const;
    };
    template <> struct consume<llm:OS::Media::Protection::IMediaProtectionServiceCompletion>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IMediaProtectionServiceCompletion<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IMediaProtectionServiceRequest
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ProtectionSystem() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) Type() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IMediaProtectionServiceRequest>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IMediaProtectionServiceRequest<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IProtectionCapabilities
    {
        LLM_IMPL_AUTO(llm:OS::Media::Protection::ProtectionCapabilityResult) IsTypeSupported(param::hstring const& type, param::hstring const& keySystem) const;
    };
    template <> struct consume<llm:OS::Media::Protection::IProtectionCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IProtectionCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IRevocationAndRenewalInformation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Protection::RevocationAndRenewalItem>) Items() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IRevocationAndRenewalInformation>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IRevocationAndRenewalInformation<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IRevocationAndRenewalItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Protection::RevocationAndRenewalReasons) Reasons() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HeaderHash() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PublicKeyHash() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RenewalId() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IRevocationAndRenewalItem>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IRevocationAndRenewalItem<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IServiceRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Protection::IMediaProtectionServiceRequest) Request() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Protection::MediaProtectionServiceCompletion) Completion() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IServiceRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IServiceRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Protection_IServiceRequestedEventArgs2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Playback::MediaPlaybackItem) MediaPlaybackItem() const;
    };
    template <> struct consume<llm:OS::Media::Protection::IServiceRequestedEventArgs2>
    {
        template <typename D> using type = consume_Windows_Media_Protection_IServiceRequestedEventArgs2<D>;
    };
}
#endif
