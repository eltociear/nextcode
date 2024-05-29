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
#ifndef LLM_OS_Devices_I2c_Provider_1_H
#define LLM_OS_Devices_I2c_Provider_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.I2c.Provider.0.h"
LLM_EXPORT namespace llm::OS::Devices::I2c::Provider
{
    struct __declspec(empty_bases) II2cControllerProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cControllerProvider>
    {
        II2cControllerProvider(std::nullptr_t = nullptr) noexcept {}
        II2cControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) II2cDeviceProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cDeviceProvider>,
        impl::require<llm::OS::Devices::I2c::Provider::II2cDeviceProvider, llm::OS::Foundation::IClosable>
    {
        II2cDeviceProvider(std::nullptr_t = nullptr) noexcept {}
        II2cDeviceProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) II2cProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cProvider>
    {
        II2cProvider(std::nullptr_t = nullptr) noexcept {}
        II2cProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProviderI2cConnectionSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProviderI2cConnectionSettings>
    {
        IProviderI2cConnectionSettings(std::nullptr_t = nullptr) noexcept {}
        IProviderI2cConnectionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
