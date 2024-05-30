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
#ifndef LLM_OS_Networking_PushNotifications_0_H
#define LLM_OS_Networking_PushNotifications_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::UI::Notifications
{
    struct BadgeNotification;
    struct TileNotification;
    struct ToastNotification;
}
LLM_EXPORT namespace llm:OS::Networking::PushNotifications
{
    enum class PushNotificationType : int32_t
    {
        Toast = 0,
        Tile = 1,
        Badge = 2,
        Raw = 3,
        TileFlyout = 4,
    };
    struct IPushNotificationChannel;
    struct IPushNotificationChannelManagerForUser;
    struct IPushNotificationChannelManagerForUser2;
    struct IPushNotificationChannelManagerStatics;
    struct IPushNotificationChannelManagerStatics2;
    struct IPushNotificationChannelManagerStatics3;
    struct IPushNotificationChannelManagerStatics4;
    struct IPushNotificationChannelsRevokedEventArgs;
    struct IPushNotificationReceivedEventArgs;
    struct IRawNotification;
    struct IRawNotification2;
    struct IRawNotification3;
    struct PushNotificationChannel;
    struct PushNotificationChannelManager;
    struct PushNotificationChannelManagerForUser;
    struct PushNotificationChannelsRevokedEventArgs;
    struct PushNotificationReceivedEventArgs;
    struct RawNotification;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannel>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser2>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics3>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IRawNotification>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IRawNotification2>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::IRawNotification3>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::PushNotificationChannel>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::PushNotificationChannelManager>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::PushNotificationChannelManagerForUser>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::PushNotificationChannelsRevokedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::PushNotificationReceivedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::RawNotification>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::PushNotifications::PushNotificationType>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::PushNotificationChannel> = L"Windows.Networking.PushNotifications.PushNotificationChannel";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::PushNotificationChannelManager> = L"Windows.Networking.PushNotifications.PushNotificationChannelManager";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::PushNotificationChannelManagerForUser> = L"Windows.Networking.PushNotifications.PushNotificationChannelManagerForUser";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::PushNotificationChannelsRevokedEventArgs> = L"Windows.Networking.PushNotifications.PushNotificationChannelsRevokedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::PushNotificationReceivedEventArgs> = L"Windows.Networking.PushNotifications.PushNotificationReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::RawNotification> = L"Windows.Networking.PushNotifications.RawNotification";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::PushNotificationType> = L"Windows.Networking.PushNotifications.PushNotificationType";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannel> = L"Windows.Networking.PushNotifications.IPushNotificationChannel";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser> = L"Windows.Networking.PushNotifications.IPushNotificationChannelManagerForUser";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser2> = L"Windows.Networking.PushNotifications.IPushNotificationChannelManagerForUser2";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics> = L"Windows.Networking.PushNotifications.IPushNotificationChannelManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics2> = L"Windows.Networking.PushNotifications.IPushNotificationChannelManagerStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics3> = L"Windows.Networking.PushNotifications.IPushNotificationChannelManagerStatics3";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4> = L"Windows.Networking.PushNotifications.IPushNotificationChannelManagerStatics4";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs> = L"Windows.Networking.PushNotifications.IPushNotificationChannelsRevokedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs> = L"Windows.Networking.PushNotifications.IPushNotificationReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IRawNotification> = L"Windows.Networking.PushNotifications.IRawNotification";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IRawNotification2> = L"Windows.Networking.PushNotifications.IRawNotification2";
    template <> inline constexpr auto& name_v<llm:OS::Networking::PushNotifications::IRawNotification3> = L"Windows.Networking.PushNotifications.IRawNotification3";
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannel>{ 0x2B28102E,0xEF0B,0x4F39,{ 0x9B,0x8A,0xA3,0xC1,0x94,0xDE,0x70,0x81 } }; // 2B28102E-EF0B-4F39-9B8A-A3C194DE7081
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser>{ 0xA4C45704,0x1182,0x42C7,{ 0x88,0x90,0xF5,0x63,0xC4,0x89,0x0D,0xC4 } }; // A4C45704-1182-42C7-8890-F563C4890DC4
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser2>{ 0xC38B066A,0x7CC1,0x4DAC,{ 0x87,0xFD,0xBE,0x6E,0x92,0x04,0x14,0xA4 } }; // C38B066A-7CC1-4DAC-87FD-BE6E920414A4
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics>{ 0x8BAF9B65,0x77A1,0x4588,{ 0xBD,0x19,0x86,0x15,0x29,0xA9,0xDC,0xF0 } }; // 8BAF9B65-77A1-4588-BD19-861529A9DCF0
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>{ 0xB444A65D,0xA7E9,0x4B28,{ 0x95,0x0E,0xF3,0x75,0xA9,0x07,0xF9,0xDF } }; // B444A65D-A7E9-4B28-950E-F375A907F9DF
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics3>{ 0x4701FEFE,0x0EDE,0x4A3F,{ 0xAE,0x78,0xBF,0xA4,0x71,0x49,0x69,0x25 } }; // 4701FEFE-0EDE-4A3F-AE78-BFA471496925
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4>{ 0xBC540EFB,0x7820,0x5A5B,{ 0x9C,0x01,0xB4,0x75,0x7F,0x77,0x40,0x25 } }; // BC540EFB-7820-5A5B-9C01-B4757F774025
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs>{ 0x20E1A24C,0x1A34,0x5BEB,{ 0xAA,0xE2,0x40,0xC2,0x32,0xC8,0xC1,0x40 } }; // 20E1A24C-1A34-5BEB-AAE2-40C232C8C140
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs>{ 0xD1065E0C,0x36CD,0x484C,{ 0xB9,0x35,0x0A,0x99,0xB7,0x53,0xCF,0x00 } }; // D1065E0C-36CD-484C-B935-0A99B753CF00
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IRawNotification>{ 0x1A227281,0x3B79,0x42AC,{ 0x99,0x63,0x22,0xAB,0x00,0xD4,0xF0,0xB7 } }; // 1A227281-3B79-42AC-9963-22AB00D4F0B7
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IRawNotification2>{ 0xE6D0CF19,0x0C6F,0x4CDD,{ 0x94,0x24,0xEE,0xC5,0xBE,0x01,0x4D,0x26 } }; // E6D0CF19-0C6F-4CDD-9424-EEC5BE014D26
    template <> inline constexpr guid guid_v<llm:OS::Networking::PushNotifications::IRawNotification3>{ 0x62737DDE,0x8A73,0x424C,{ 0xAB,0x44,0x56,0x35,0xF4,0x0A,0x96,0xE5 } }; // 62737DDE-8A73-424C-AB44-5635F40A96E5
    template <> struct default_interface<llm:OS::Networking::PushNotifications::PushNotificationChannel>{ using type = llm:OS::Networking::PushNotifications::IPushNotificationChannel; };
    template <> struct default_interface<llm:OS::Networking::PushNotifications::PushNotificationChannelManagerForUser>{ using type = llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser; };
    template <> struct default_interface<llm:OS::Networking::PushNotifications::PushNotificationChannelsRevokedEventArgs>{ using type = llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs; };
    template <> struct default_interface<llm:OS::Networking::PushNotifications::PushNotificationReceivedEventArgs>{ using type = llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs; };
    template <> struct default_interface<llm:OS::Networking::PushNotifications::RawNotification>{ using type = llm:OS::Networking::PushNotifications::IRawNotification; };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannel>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExpirationTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall Close() noexcept = 0;
            virtual int32_t __stdcall add_PushNotificationReceived(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PushNotificationReceived(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreatePushNotificationChannelForApplicationAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CreatePushNotificationChannelForApplicationAsyncWithId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePushNotificationChannelForSecondaryTileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateRawPushNotificationChannelWithAlternateKeyForApplicationAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateRawPushNotificationChannelWithAlternateKeyForApplicationAsyncWithId(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreatePushNotificationChannelForApplicationAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CreatePushNotificationChannelForApplicationAsyncWithId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePushNotificationChannelForSecondaryTileAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ChannelsRevoked(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ChannelsRevoked(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_Cancel(bool) noexcept = 0;
            virtual int32_t __stdcall get_Cancel(bool*) noexcept = 0;
            virtual int32_t __stdcall get_NotificationType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ToastNotification(void**) noexcept = 0;
            virtual int32_t __stdcall get_TileNotification(void**) noexcept = 0;
            virtual int32_t __stdcall get_BadgeNotification(void**) noexcept = 0;
            virtual int32_t __stdcall get_RawNotification(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IRawNotification>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IRawNotification2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Headers(void**) noexcept = 0;
            virtual int32_t __stdcall get_ChannelId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::PushNotifications::IRawNotification3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContentBytes(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannel
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Uri() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) ExpirationTime() const;
        LLM_IMPL_AUTO(void) Close() const;
        LLM_IMPL_AUTO(llm::event_token) PushNotificationReceived(llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::PushNotifications::PushNotificationChannel, llm:OS::Networking::PushNotifications::PushNotificationReceivedEventArgs> const& handler) const;
        using PushNotificationReceived_revoker = impl::event_revoker<llm:OS::Networking::PushNotifications::IPushNotificationChannel, &impl::abi_t<llm:OS::Networking::PushNotifications::IPushNotificationChannel>::remove_PushNotificationReceived>;
        [[nodiscard]] PushNotificationReceived_revoker PushNotificationReceived(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::PushNotifications::PushNotificationChannel, llm:OS::Networking::PushNotifications::PushNotificationReceivedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PushNotificationReceived(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannel>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannel<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerForUser
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreatePushNotificationChannelForApplicationAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreatePushNotificationChannelForApplicationAsync(param::hstring const& applicationId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreatePushNotificationChannelForSecondaryTileAsync(param::hstring const& tileId) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerForUser<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerForUser2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreateRawPushNotificationChannelWithAlternateKeyForApplicationAsync(llm:OS::Storage::Streams::IBuffer const& appServerKey, param::hstring const& channelId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreateRawPushNotificationChannelWithAlternateKeyForApplicationAsync(llm:OS::Storage::Streams::IBuffer const& appServerKey, param::hstring const& channelId, param::hstring const& appId) const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser2>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerForUser2<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreatePushNotificationChannelForApplicationAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreatePushNotificationChannelForApplicationAsync(param::hstring const& applicationId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::PushNotifications::PushNotificationChannel>) CreatePushNotificationChannelForSecondaryTileAsync(param::hstring const& tileId) const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Networking::PushNotifications::PushNotificationChannelManagerForUser) GetForUser(llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics3
    {
        LLM_IMPL_AUTO(llm:OS::Networking::PushNotifications::PushNotificationChannelManagerForUser) GetDefault() const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics3>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics4
    {
        LLM_IMPL_AUTO(llm::event_token) ChannelsRevoked(llm:OS::Foundation::EventHandler<llm:OS::Networking::PushNotifications::PushNotificationChannelsRevokedEventArgs> const& handler) const;
        using ChannelsRevoked_revoker = impl::event_revoker<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4, &impl::abi_t<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4>::remove_ChannelsRevoked>;
        [[nodiscard]] ChannelsRevoked_revoker ChannelsRevoked(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Networking::PushNotifications::PushNotificationChannelsRevokedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ChannelsRevoked(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannelManagerStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationChannelsRevokedEventArgs
    {
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationChannelsRevokedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IPushNotificationReceivedEventArgs
    {
        LLM_IMPL_AUTO(void) Cancel(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Cancel() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::PushNotifications::PushNotificationType) NotificationType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Notifications::ToastNotification) ToastNotification() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Notifications::TileNotification) TileNotification() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Notifications::BadgeNotification) BadgeNotification() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::PushNotifications::RawNotification) RawNotification() const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IPushNotificationReceivedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IRawNotification
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Content() const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IRawNotification>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IRawNotification<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IRawNotification2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMapView<hstring, hstring>) Headers() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ChannelId() const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IRawNotification2>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IRawNotification2<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_PushNotifications_IRawNotification3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) ContentBytes() const;
    };
    template <> struct consume<llm:OS::Networking::PushNotifications::IRawNotification3>
    {
        template <typename D> using type = consume_Windows_Networking_PushNotifications_IRawNotification3<D>;
    };
}
#endif
