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
#ifndef LLM_OS_Security_Authentication_Identity_Core_0_H
#define LLM_OS_Security_Authentication_Identity_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Security::Authentication::Identity::Core
{
    enum class MicrosoftAccountMultiFactorAuthenticationType : int32_t
    {
        User = 0,
        Device = 1,
    };
    enum class MicrosoftAccountMultiFactorServiceResponse : int32_t
    {
        Success = 0,
        Error = 1,
        NoNetworkConnection = 2,
        ServiceUnavailable = 3,
        TotpSetupDenied = 4,
        NgcNotSetup = 5,
        SessionAlreadyDenied = 6,
        SessionAlreadyApproved = 7,
        SessionExpired = 8,
        NgcNonceExpired = 9,
        InvalidSessionId = 10,
        InvalidSessionType = 11,
        InvalidOperation = 12,
        InvalidStateTransition = 13,
        DeviceNotFound = 14,
        FlowDisabled = 15,
        SessionNotApproved = 16,
        OperationCanceledByUser = 17,
        NgcDisabledByServer = 18,
        NgcKeyNotFoundOnServer = 19,
        UIRequired = 20,
        DeviceIdChanged = 21,
    };
    enum class MicrosoftAccountMultiFactorSessionApprovalStatus : int32_t
    {
        Pending = 0,
        Approved = 1,
        Denied = 2,
    };
    enum class MicrosoftAccountMultiFactorSessionAuthenticationStatus : int32_t
    {
        Authenticated = 0,
        Unauthenticated = 1,
    };
    struct IMicrosoftAccountMultiFactorAuthenticationManager;
    struct IMicrosoftAccountMultiFactorAuthenticatorStatics;
    struct IMicrosoftAccountMultiFactorGetSessionsResult;
    struct IMicrosoftAccountMultiFactorOneTimeCodedInfo;
    struct IMicrosoftAccountMultiFactorSessionInfo;
    struct IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;
    struct MicrosoftAccountMultiFactorAuthenticationManager;
    struct MicrosoftAccountMultiFactorGetSessionsResult;
    struct MicrosoftAccountMultiFactorOneTimeCodedInfo;
    struct MicrosoftAccountMultiFactorSessionInfo;
    struct MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorAuthenticationManager";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorGetSessionsResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorOneTimeCodedInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorSessionInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorAuthenticationType";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorServiceResponse";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorSessionApprovalStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus> = L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorSessionAuthenticationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> = L"Windows.Security.Authentication.Identity.Core.IMicrosoftAccountMultiFactorAuthenticationManager";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics> = L"Windows.Security.Authentication.Identity.Core.IMicrosoftAccountMultiFactorAuthenticatorStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> = L"Windows.Security.Authentication.Identity.Core.IMicrosoftAccountMultiFactorGetSessionsResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> = L"Windows.Security.Authentication.Identity.Core.IMicrosoftAccountMultiFactorOneTimeCodedInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> = L"Windows.Security.Authentication.Identity.Core.IMicrosoftAccountMultiFactorSessionInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> = L"Windows.Security.Authentication.Identity.Core.IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo";
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>{ 0x0FD340A5,0xF574,0x4320,{ 0xA0,0x8E,0x0A,0x19,0xA8,0x23,0x22,0xAA } }; // 0FD340A5-F574-4320-A08E-0A19A82322AA
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>{ 0xD964C2E6,0xF446,0x4C71,{ 0x8B,0x79,0x6E,0xA4,0x02,0x4A,0xA9,0xB8 } }; // D964C2E6-F446-4C71-8B79-6EA4024AA9B8
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>{ 0x4E23A9A0,0xE9FA,0x497A,{ 0x95,0xDE,0x6D,0x57,0x47,0xBF,0x97,0x4C } }; // 4E23A9A0-E9FA-497A-95DE-6D5747BF974C
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>{ 0x82BA264B,0xD87C,0x4668,{ 0xA9,0x76,0x40,0xCF,0xAE,0x54,0x7D,0x08 } }; // 82BA264B-D87C-4668-A976-40CFAE547D08
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>{ 0x5F7EABB4,0xA278,0x4635,{ 0xB7,0x65,0xB4,0x94,0xEB,0x26,0x0A,0xF4 } }; // 5F7EABB4-A278-4635-B765-B494EB260AF4
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>{ 0xAA7EC5FB,0xDA3F,0x4088,{ 0xA2,0x0D,0x56,0x18,0xAF,0xAD,0xB2,0xE5 } }; // AA7EC5FB-DA3F-4088-A20D-5618AFADB2E5
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager>{ using type = llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>{ using type = llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>{ using type = llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>{ using type = llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>{ using type = llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo; };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetOneTimePassCodeAsync(void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall AddDeviceAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RemoveDeviceAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UpdateWnsChannelAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetSessionsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetSessionsAndUnregisteredAccountsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ApproveSessionUsingAuthSessionInfoAsync(int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ApproveSessionAsync(int32_t, void*, void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall DenySessionUsingAuthSessionInfoAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DenySessionAsync(void*, void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Sessions(void**) noexcept = 0;
            virtual int32_t __stdcall get_ServiceResponse(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Code(void**) noexcept = 0;
            virtual int32_t __stdcall get_TimeInterval(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TimeToLive(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceResponse(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UserAccountId(void**) noexcept = 0;
            virtual int32_t __stdcall get_SessionId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplaySessionId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ApprovalStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_AuthenticationType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RequestTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExpirationTime(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Sessions(void**) noexcept = 0;
            virtual int32_t __stdcall get_UnregisteredAccounts(void**) noexcept = 0;
            virtual int32_t __stdcall get_ServiceResponse(int32_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>) GetOneTimePassCodeAsync(param::hstring const& userAccountId, uint32_t codeLength) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) AddDeviceAsync(param::hstring const& userAccountId, param::hstring const& authenticationToken, param::hstring const& wnsChannelId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) RemoveDeviceAsync(param::hstring const& userAccountId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) UpdateWnsChannelAsync(param::hstring const& userAccountId, param::hstring const& channelUri) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>) GetSessionsAsync(param::async_iterable<hstring> const& userAccountIdList) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>) GetSessionsAndUnregisteredAccountsAsync(param::async_iterable<hstring> const& userAccountIdList) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) ApproveSessionAsync(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus const& sessionAuthentictionStatus, llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo const& authenticationSessionInfo) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) ApproveSessionAsync(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus const& sessionAuthentictionStatus, param::hstring const& userAccountId, param::hstring const& sessionId, llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType const& sessionAuthenticationType) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) DenySessionAsync(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo const& authenticationSessionInfo) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>) DenySessionAsync(param::hstring const& userAccountId, param::hstring const& sessionId, llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType const& sessionAuthenticationType) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticationManager<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticatorStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager) Current() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorAuthenticatorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorGetSessionsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>) Sessions() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse) ServiceResponse() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorGetSessionsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorOneTimeCodedInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Code() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TimeInterval() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TimeToLive() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse) ServiceResponse() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserAccountId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SessionId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplaySessionId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus) ApprovalStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType) AuthenticationType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) RequestTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) ExpirationTime() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorSessionInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>) Sessions() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) UnregisteredAccounts() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse) ServiceResponse() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Core_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>;
    };
}
#endif
