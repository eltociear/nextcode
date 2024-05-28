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
#ifndef LLM_OS_Security_Authentication_Identity_Provider_H
#define LLM_OS_Security_Authentication_Identity_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Security.Authentication.Identity.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Security.Authentication.Identity.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication<D>::ServiceAuthenticationHmac() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication)->get_ServiceAuthenticationHmac(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication<D>::SessionNonce() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication)->get_SessionNonce(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication<D>::DeviceNonce() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication)->get_DeviceNonce(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication<D>::DeviceConfigurationData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication)->get_DeviceConfigurationData(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication<D>::FinishAuthenticationAsync(llm::OS::Storage::Streams::IBuffer const& deviceHmac, llm::OS::Storage::Streams::IBuffer const& sessionHmac) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication)->FinishAuthenticationAsync(*(void**)(&deviceHmac), *(void**)(&sessionHmac), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication<D>::AbortAuthenticationAsync(param::hstring const& errorLogMessage) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication)->AbortAuthenticationAsync(*(void**)(&errorLogMessage), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationResult<D>::Status() const
    {
        llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationResult<D>::Authentication() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult)->get_Authentication(&value));
        return llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs<D>::StageInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs)->get_StageInfo(&value));
        return llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>::Stage() const
    {
        llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo)->get_Stage(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>::Scenario() const
    {
        llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo)->get_Scenario(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>::ShowNotificationMessageAsync(param::hstring const& deviceName, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage const& message) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics)->ShowNotificationMessageAsync(*(void**)(&deviceName), static_cast<int32_t>(message), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>::StartAuthenticationAsync(param::hstring const& deviceId, llm::OS::Storage::Streams::IBuffer const& serviceAuthenticationNonce) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics)->StartAuthenticationAsync(*(void**)(&deviceId), *(void**)(&serviceAuthenticationNonce), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>::AuthenticationStageChanged(llm::OS::Foundation::EventHandler<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics)->add_AuthenticationStageChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>::AuthenticationStageChanged_revoker consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>::AuthenticationStageChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AuthenticationStageChanged_revoker>(this, AuthenticationStageChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>::AuthenticationStageChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics)->remove_AuthenticationStageChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>::GetAuthenticationStageInfoAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics)->GetAuthenticationStageInfoAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics<D>::RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics)->RegisterDevicePresenceMonitoringAsync(*(void**)(&deviceId), *(void**)(&deviceInstancePath), static_cast<int32_t>(monitoringMode), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics<D>::RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm::OS::Storage::Streams::IBuffer const& deviceConfigurationData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics)->RegisterDevicePresenceMonitoringWithNewDeviceAsync(*(void**)(&deviceId), *(void**)(&deviceInstancePath), static_cast<int32_t>(monitoringMode), *(void**)(&deviceFriendlyName), *(void**)(&deviceModelNumber), *(void**)(&deviceConfigurationData), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics<D>::UnregisterDevicePresenceMonitoringAsync(param::hstring const& deviceId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics)->UnregisterDevicePresenceMonitoringAsync(*(void**)(&deviceId), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics<D>::IsDevicePresenceMonitoringSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics)->IsDevicePresenceMonitoringSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo<D>::DeviceId() const
    {
        void* deviceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo)->get_DeviceId(&deviceId));
        return hstring{ deviceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo<D>::DeviceFriendlyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo)->get_DeviceFriendlyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo<D>::DeviceModelNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo)->get_DeviceModelNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo<D>::DeviceConfigurationData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo)->get_DeviceConfigurationData(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo2<D>::PresenceMonitoringMode() const
    {
        llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2)->get_PresenceMonitoringMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo2<D>::UpdateDevicePresenceAsync(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresence const& presenceState) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2)->UpdateDevicePresenceAsync(static_cast<int32_t>(presenceState), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo2<D>::IsAuthenticationSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2)->get_IsAuthenticationSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistration<D>::FinishRegisteringDeviceAsync(llm::OS::Storage::Streams::IBuffer const& deviceConfigurationData) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration)->FinishRegisteringDeviceAsync(*(void**)(&deviceConfigurationData), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistration<D>::AbortRegisteringDeviceAsync(param::hstring const& errorLogMessage) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration)->AbortRegisteringDeviceAsync(*(void**)(&errorLogMessage), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationResult<D>::Status() const
    {
        llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationResult<D>::Registration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult)->get_Registration(&value));
        return llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationStatics<D>::RequestStartRegisteringDeviceAsync(param::hstring const& deviceId, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities const& capabilities, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm::OS::Storage::Streams::IBuffer const& deviceKey, llm::OS::Storage::Streams::IBuffer const& mutualAuthenticationKey) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics)->RequestStartRegisteringDeviceAsync(*(void**)(&deviceId), static_cast<uint32_t>(capabilities), *(void**)(&deviceFriendlyName), *(void**)(&deviceModelNumber), *(void**)(&deviceKey), *(void**)(&mutualAuthenticationKey), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>>) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationStatics<D>::FindAllRegisteredDeviceInfoAsync(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope const& queryType) const
    {
        void* deviceInfoList{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics)->FindAllRegisteredDeviceInfoAsync(static_cast<int32_t>(queryType), &deviceInfoList));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>>{ deviceInfoList, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationStatics<D>::UnregisterDeviceAsync(param::hstring const& deviceId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics)->UnregisterDeviceAsync(*(void**)(&deviceId), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationStatics<D>::UpdateDeviceConfigurationDataAsync(param::hstring const& deviceId, llm::OS::Storage::Streams::IBuffer const& deviceConfigurationData) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics)->UpdateDeviceConfigurationDataAsync(*(void**)(&deviceId), *(void**)(&deviceConfigurationData), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>
    {
        int32_t __stdcall get_ServiceAuthenticationHmac(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().ServiceAuthenticationHmac());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SessionNonce(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().SessionNonce());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceNonce(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().DeviceNonce());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceConfigurationData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().DeviceConfigurationData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FinishAuthenticationAsync(void* deviceHmac, void* sessionHmac, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>>(this->shim().FinishAuthenticationAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&deviceHmac), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&sessionHmac)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AbortAuthenticationAsync(void* errorLogMessage, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().AbortAuthenticationAsync(*reinterpret_cast<hstring const*>(&errorLogMessage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Authentication(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication>(this->shim().Authentication());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
    {
        int32_t __stdcall get_StageInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>(this->shim().StageInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
    {
        int32_t __stdcall get_Stage(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage>(this->shim().Stage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scenario(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario>(this->shim().Scenario());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>
    {
        int32_t __stdcall ShowNotificationMessageAsync(void* deviceName, int32_t message, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowNotificationMessageAsync(*reinterpret_cast<hstring const*>(&deviceName), *reinterpret_cast<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAuthenticationAsync(void* deviceId, void* serviceAuthenticationNonce, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>>(this->shim().StartAuthenticationAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&serviceAuthenticationNonce)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AuthenticationStageChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AuthenticationStageChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AuthenticationStageChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationStageChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetAuthenticationStageInfoAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>>(this->shim().GetAuthenticationStageInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>
    {
        int32_t __stdcall RegisterDevicePresenceMonitoringAsync(void* deviceId, void* deviceInstancePath, int32_t monitoringMode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>>(this->shim().RegisterDevicePresenceMonitoringAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<hstring const*>(&deviceInstancePath), *reinterpret_cast<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const*>(&monitoringMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterDevicePresenceMonitoringWithNewDeviceAsync(void* deviceId, void* deviceInstancePath, int32_t monitoringMode, void* deviceFriendlyName, void* deviceModelNumber, void* deviceConfigurationData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>>(this->shim().RegisterDevicePresenceMonitoringAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<hstring const*>(&deviceInstancePath), *reinterpret_cast<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const*>(&monitoringMode), *reinterpret_cast<hstring const*>(&deviceFriendlyName), *reinterpret_cast<hstring const*>(&deviceModelNumber), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&deviceConfigurationData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterDevicePresenceMonitoringAsync(void* deviceId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UnregisterDevicePresenceMonitoringAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsDevicePresenceMonitoringSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDevicePresenceMonitoringSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>
    {
        int32_t __stdcall get_DeviceId(void** deviceId) noexcept final try
        {
            clear_abi(deviceId);
            typename D::abi_guard guard(this->shim());
            *deviceId = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceFriendlyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceFriendlyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceModelNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceModelNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceConfigurationData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().DeviceConfigurationData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2>
    {
        int32_t __stdcall get_PresenceMonitoringMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode>(this->shim().PresenceMonitoringMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateDevicePresenceAsync(int32_t presenceState, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UpdateDevicePresenceAsync(*reinterpret_cast<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresence const*>(&presenceState)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAuthenticationSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAuthenticationSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>
    {
        int32_t __stdcall FinishRegisteringDeviceAsync(void* deviceConfigurationData, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().FinishRegisteringDeviceAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&deviceConfigurationData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AbortRegisteringDeviceAsync(void* errorLogMessage, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().AbortRegisteringDeviceAsync(*reinterpret_cast<hstring const*>(&errorLogMessage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Registration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration>(this->shim().Registration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics> : produce_base<D, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>
    {
        int32_t __stdcall RequestStartRegisteringDeviceAsync(void* deviceId, uint32_t capabilities, void* deviceFriendlyName, void* deviceModelNumber, void* deviceKey, void* mutualAuthenticationKey, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>>(this->shim().RequestStartRegisteringDeviceAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities const*>(&capabilities), *reinterpret_cast<hstring const*>(&deviceFriendlyName), *reinterpret_cast<hstring const*>(&deviceModelNumber), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&deviceKey), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&mutualAuthenticationKey)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllRegisteredDeviceInfoAsync(int32_t queryType, void** deviceInfoList) noexcept final try
        {
            clear_abi(deviceInfoList);
            typename D::abi_guard guard(this->shim());
            *deviceInfoList = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>>>(this->shim().FindAllRegisteredDeviceInfoAsync(*reinterpret_cast<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope const*>(&queryType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterDeviceAsync(void* deviceId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UnregisterDeviceAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateDeviceConfigurationDataAsync(void* deviceId, void* deviceConfigurationData, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UpdateDeviceConfigurationDataAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&deviceConfigurationData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Authentication::Identity::Provider
{
    constexpr auto operator|(SecondaryAuthenticationFactorDeviceCapabilities const left, SecondaryAuthenticationFactorDeviceCapabilities const right) noexcept
    {
        return static_cast<SecondaryAuthenticationFactorDeviceCapabilities>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(SecondaryAuthenticationFactorDeviceCapabilities& left, SecondaryAuthenticationFactorDeviceCapabilities const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(SecondaryAuthenticationFactorDeviceCapabilities const left, SecondaryAuthenticationFactorDeviceCapabilities const right) noexcept
    {
        return static_cast<SecondaryAuthenticationFactorDeviceCapabilities>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(SecondaryAuthenticationFactorDeviceCapabilities& left, SecondaryAuthenticationFactorDeviceCapabilities const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(SecondaryAuthenticationFactorDeviceCapabilities const value) noexcept
    {
        return static_cast<SecondaryAuthenticationFactorDeviceCapabilities>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(SecondaryAuthenticationFactorDeviceCapabilities const left, SecondaryAuthenticationFactorDeviceCapabilities const right) noexcept
    {
        return static_cast<SecondaryAuthenticationFactorDeviceCapabilities>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(SecondaryAuthenticationFactorDeviceCapabilities& left, SecondaryAuthenticationFactorDeviceCapabilities const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto SecondaryAuthenticationFactorAuthentication::ShowNotificationMessageAsync(param::hstring const& deviceName, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage const& message)
    {
        return impl::call_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>([&](ISecondaryAuthenticationFactorAuthenticationStatics const& f) { return f.ShowNotificationMessageAsync(deviceName, message); });
    }
    inline auto SecondaryAuthenticationFactorAuthentication::StartAuthenticationAsync(param::hstring const& deviceId, llm::OS::Storage::Streams::IBuffer const& serviceAuthenticationNonce)
    {
        return impl::call_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>([&](ISecondaryAuthenticationFactorAuthenticationStatics const& f) { return f.StartAuthenticationAsync(deviceId, serviceAuthenticationNonce); });
    }
    inline auto SecondaryAuthenticationFactorAuthentication::AuthenticationStageChanged(llm::OS::Foundation::EventHandler<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler)
    {
        return impl::call_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>([&](ISecondaryAuthenticationFactorAuthenticationStatics const& f) { return f.AuthenticationStageChanged(handler); });
    }
    inline SecondaryAuthenticationFactorAuthentication::AuthenticationStageChanged_revoker SecondaryAuthenticationFactorAuthentication::AuthenticationStageChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler)
    {
        auto f = get_activation_factory<SecondaryAuthenticationFactorAuthentication, llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>();
        return { f, f.AuthenticationStageChanged(handler) };
    }
    inline auto SecondaryAuthenticationFactorAuthentication::AuthenticationStageChanged(llm::event_token const& token)
    {
        impl::call_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>([&](ISecondaryAuthenticationFactorAuthenticationStatics const& f) { return f.AuthenticationStageChanged(token); });
    }
    inline auto SecondaryAuthenticationFactorAuthentication::GetAuthenticationStageInfoAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>(*)(ISecondaryAuthenticationFactorAuthenticationStatics const&), SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>([](ISecondaryAuthenticationFactorAuthenticationStatics const& f) { return f.GetAuthenticationStageInfoAsync(); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode)
    {
        return impl::call_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>([&](ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics const& f) { return f.RegisterDevicePresenceMonitoringAsync(deviceId, deviceInstancePath, monitoringMode); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm::OS::Storage::Streams::IBuffer const& deviceConfigurationData)
    {
        return impl::call_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>([&](ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics const& f) { return f.RegisterDevicePresenceMonitoringAsync(deviceId, deviceInstancePath, monitoringMode, deviceFriendlyName, deviceModelNumber, deviceConfigurationData); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::UnregisterDevicePresenceMonitoringAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>([&](ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics const& f) { return f.UnregisterDevicePresenceMonitoringAsync(deviceId); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::IsDevicePresenceMonitoringSupported()
    {
        return impl::call_factory_cast<bool(*)(ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics const&), SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>([](ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics const& f) { return f.IsDevicePresenceMonitoringSupported(); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::RequestStartRegisteringDeviceAsync(param::hstring const& deviceId, llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities const& capabilities, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm::OS::Storage::Streams::IBuffer const& deviceKey, llm::OS::Storage::Streams::IBuffer const& mutualAuthenticationKey)
    {
        return impl::call_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>([&](ISecondaryAuthenticationFactorRegistrationStatics const& f) { return f.RequestStartRegisteringDeviceAsync(deviceId, capabilities, deviceFriendlyName, deviceModelNumber, deviceKey, mutualAuthenticationKey); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::FindAllRegisteredDeviceInfoAsync(llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope const& queryType)
    {
        return impl::call_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>([&](ISecondaryAuthenticationFactorRegistrationStatics const& f) { return f.FindAllRegisteredDeviceInfoAsync(queryType); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::UnregisterDeviceAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>([&](ISecondaryAuthenticationFactorRegistrationStatics const& f) { return f.UnregisterDeviceAsync(deviceId); });
    }
    inline auto SecondaryAuthenticationFactorRegistration::UpdateDeviceConfigurationDataAsync(param::hstring const& deviceId, llm::OS::Storage::Streams::IBuffer const& deviceConfigurationData)
    {
        return impl::call_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>([&](ISecondaryAuthenticationFactorRegistrationStatics const& f) { return f.UpdateDeviceConfigurationDataAsync(deviceId, deviceConfigurationData); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
