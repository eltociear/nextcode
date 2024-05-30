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
#ifndef LLM_OS_Networking_XboxLive_0_H
#define LLM_OS_Networking_XboxLive_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Networking
{
    struct HostName;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::Networking::XboxLive
{
    enum class XboxLiveEndpointPairCreationBehaviors : uint32_t
    {
        None = 0,
        ReevaluatePath = 0x1,
    };
    enum class XboxLiveEndpointPairCreationStatus : int32_t
    {
        Succeeded = 0,
        NoLocalNetworks = 1,
        NoCompatibleNetworkPaths = 2,
        LocalSystemNotAuthorized = 3,
        Canceled = 4,
        TimedOut = 5,
        RemoteSystemNotAuthorized = 6,
        RefusedDueToConfiguration = 7,
        UnexpectedInternalError = 8,
    };
    enum class XboxLiveEndpointPairState : int32_t
    {
        Invalid = 0,
        CreatingOutbound = 1,
        CreatingInbound = 2,
        Ready = 3,
        DeletingLocally = 4,
        RemoteEndpointTerminating = 5,
        Deleted = 6,
    };
    enum class XboxLiveNetworkAccessKind : int32_t
    {
        Open = 0,
        Moderate = 1,
        Strict = 2,
    };
    enum class XboxLiveQualityOfServiceMeasurementStatus : int32_t
    {
        NotStarted = 0,
        InProgress = 1,
        InProgressWithProvisionalResults = 2,
        Succeeded = 3,
        NoLocalNetworks = 4,
        NoCompatibleNetworkPaths = 5,
        LocalSystemNotAuthorized = 6,
        Canceled = 7,
        TimedOut = 8,
        RemoteSystemNotAuthorized = 9,
        RefusedDueToConfiguration = 10,
        UnexpectedInternalError = 11,
    };
    enum class XboxLiveQualityOfServiceMetric : int32_t
    {
        AverageLatencyInMilliseconds = 0,
        MinLatencyInMilliseconds = 1,
        MaxLatencyInMilliseconds = 2,
        AverageOutboundBitsPerSecond = 3,
        MinOutboundBitsPerSecond = 4,
        MaxOutboundBitsPerSecond = 5,
        AverageInboundBitsPerSecond = 6,
        MinInboundBitsPerSecond = 7,
        MaxInboundBitsPerSecond = 8,
    };
    enum class XboxLiveSocketKind : int32_t
    {
        None = 0,
        Datagram = 1,
        Stream = 2,
    };
    struct IXboxLiveDeviceAddress;
    struct IXboxLiveDeviceAddressStatics;
    struct IXboxLiveEndpointPair;
    struct IXboxLiveEndpointPairCreationResult;
    struct IXboxLiveEndpointPairStateChangedEventArgs;
    struct IXboxLiveEndpointPairStatics;
    struct IXboxLiveEndpointPairTemplate;
    struct IXboxLiveEndpointPairTemplateStatics;
    struct IXboxLiveInboundEndpointPairCreatedEventArgs;
    struct IXboxLiveQualityOfServiceMeasurement;
    struct IXboxLiveQualityOfServiceMeasurementStatics;
    struct IXboxLiveQualityOfServiceMetricResult;
    struct IXboxLiveQualityOfServicePrivatePayloadResult;
    struct XboxLiveDeviceAddress;
    struct XboxLiveEndpointPair;
    struct XboxLiveEndpointPairCreationResult;
    struct XboxLiveEndpointPairStateChangedEventArgs;
    struct XboxLiveEndpointPairTemplate;
    struct XboxLiveInboundEndpointPairCreatedEventArgs;
    struct XboxLiveQualityOfServiceMeasurement;
    struct XboxLiveQualityOfServiceMetricResult;
    struct XboxLiveQualityOfServicePrivatePayloadResult;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveEndpointPair>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveDeviceAddress>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveEndpointPair>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurement>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult>{ using type = class_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors>{ using type = enum_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveEndpointPairState>{ using type = enum_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveNetworkAccessKind>{ using type = enum_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric>{ using type = enum_category; };
    template <> struct category<llm:OS::Networking::XboxLive::XboxLiveSocketKind>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveDeviceAddress> = L"Windows.Networking.XboxLive.XboxLiveDeviceAddress";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveEndpointPair> = L"Windows.Networking.XboxLive.XboxLiveEndpointPair";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult> = L"Windows.Networking.XboxLive.XboxLiveEndpointPairCreationResult";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs> = L"Windows.Networking.XboxLive.XboxLiveEndpointPairStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate> = L"Windows.Networking.XboxLive.XboxLiveEndpointPairTemplate";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs> = L"Windows.Networking.XboxLive.XboxLiveInboundEndpointPairCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurement> = L"Windows.Networking.XboxLive.XboxLiveQualityOfServiceMeasurement";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult> = L"Windows.Networking.XboxLive.XboxLiveQualityOfServiceMetricResult";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult> = L"Windows.Networking.XboxLive.XboxLiveQualityOfServicePrivatePayloadResult";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors> = L"Windows.Networking.XboxLive.XboxLiveEndpointPairCreationBehaviors";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationStatus> = L"Windows.Networking.XboxLive.XboxLiveEndpointPairCreationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveEndpointPairState> = L"Windows.Networking.XboxLive.XboxLiveEndpointPairState";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveNetworkAccessKind> = L"Windows.Networking.XboxLive.XboxLiveNetworkAccessKind";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus> = L"Windows.Networking.XboxLive.XboxLiveQualityOfServiceMeasurementStatus";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric> = L"Windows.Networking.XboxLive.XboxLiveQualityOfServiceMetric";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::XboxLiveSocketKind> = L"Windows.Networking.XboxLive.XboxLiveSocketKind";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress> = L"Windows.Networking.XboxLive.IXboxLiveDeviceAddress";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics> = L"Windows.Networking.XboxLive.IXboxLiveDeviceAddressStatics";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPair> = L"Windows.Networking.XboxLive.IXboxLiveEndpointPair";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult> = L"Windows.Networking.XboxLive.IXboxLiveEndpointPairCreationResult";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs> = L"Windows.Networking.XboxLive.IXboxLiveEndpointPairStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStatics> = L"Windows.Networking.XboxLive.IXboxLiveEndpointPairStatics";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate> = L"Windows.Networking.XboxLive.IXboxLiveEndpointPairTemplate";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics> = L"Windows.Networking.XboxLive.IXboxLiveEndpointPairTemplateStatics";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs> = L"Windows.Networking.XboxLive.IXboxLiveInboundEndpointPairCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement> = L"Windows.Networking.XboxLive.IXboxLiveQualityOfServiceMeasurement";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics> = L"Windows.Networking.XboxLive.IXboxLiveQualityOfServiceMeasurementStatics";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult> = L"Windows.Networking.XboxLive.IXboxLiveQualityOfServiceMetricResult";
    template <> inline constexpr auto& name_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult> = L"Windows.Networking.XboxLive.IXboxLiveQualityOfServicePrivatePayloadResult";
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress>{ 0xF5BBD279,0x3C86,0x4B57,{ 0xA3,0x1A,0xB9,0x46,0x24,0x08,0xFD,0x01 } }; // F5BBD279-3C86-4B57-A31A-B9462408FD01
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics>{ 0x5954A819,0x4A79,0x4931,{ 0x82,0x7C,0x7F,0x50,0x3E,0x96,0x32,0x63 } }; // 5954A819-4A79-4931-827C-7F503E963263
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPair>{ 0x1E9A839B,0x813E,0x44E0,{ 0xB8,0x7F,0xC8,0x7A,0x09,0x34,0x75,0xE4 } }; // 1E9A839B-813E-44E0-B87F-C87A093475E4
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult>{ 0xD9A8BB95,0x2AAB,0x4D1E,{ 0x97,0x94,0x33,0xEC,0xC0,0xDC,0xF0,0xFE } }; // D9A8BB95-2AAB-4D1E-9794-33ECC0DCF0FE
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs>{ 0x592E3B55,0xDE08,0x44E7,{ 0xAC,0x3B,0xB9,0xB9,0xA1,0x69,0x58,0x3A } }; // 592E3B55-DE08-44E7-AC3B-B9B9A169583A
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStatics>{ 0x64316B30,0x217A,0x4243,{ 0x8E,0xE1,0x67,0x29,0x28,0x1D,0x27,0xDB } }; // 64316B30-217A-4243-8EE1-6729281D27DB
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate>{ 0x6B286ECF,0x3457,0x40CE,{ 0xB9,0xA1,0xC0,0xCF,0xE0,0x21,0x3E,0xA7 } }; // 6B286ECF-3457-40CE-B9A1-C0CFE0213EA7
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics>{ 0x1E13137B,0x737B,0x4A23,{ 0xBC,0x64,0x08,0x70,0xF7,0x56,0x55,0xBA } }; // 1E13137B-737B-4A23-BC64-0870F75655BA
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs>{ 0xDC183B62,0x22BA,0x48D2,{ 0x80,0xDE,0xC2,0x39,0x68,0xBD,0x19,0x8B } }; // DC183B62-22BA-48D2-80DE-C23968BD198B
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement>{ 0x4D682BCE,0xA5D6,0x47E6,{ 0xA2,0x36,0xCF,0xDE,0x5F,0xBD,0xF2,0xED } }; // 4D682BCE-A5D6-47E6-A236-CFDE5FBDF2ED
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics>{ 0x6E352DCA,0x23CF,0x440A,{ 0xB0,0x77,0x5E,0x30,0x85,0x7A,0x82,0x34 } }; // 6E352DCA-23CF-440A-B077-5E30857A8234
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult>{ 0xAEEC53D1,0x3561,0x4782,{ 0xB0,0xCF,0xD3,0xAE,0x29,0xD9,0xFA,0x87 } }; // AEEC53D1-3561-4782-B0CF-D3AE29D9FA87
    template <> inline constexpr guid guid_v<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult>{ 0x5A6302AE,0x6F38,0x41C0,{ 0x9F,0xCC,0xEA,0x6C,0xB9,0x78,0xCA,0xFC } }; // 5A6302AE-6F38-41C0-9FCC-EA6CB978CAFC
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveDeviceAddress>{ using type = llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveEndpointPair>{ using type = llm:OS::Networking::XboxLive::IXboxLiveEndpointPair; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>{ using type = llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs>{ using type = llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>{ using type = llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs>{ using type = llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurement>{ using type = llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>{ using type = llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult; };
    template <> struct default_interface<llm:OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult>{ using type = llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult; };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_SnapshotChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SnapshotChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall GetSnapshotAsBase64(void**) noexcept = 0;
            virtual int32_t __stdcall GetSnapshotAsBuffer(void**) noexcept = 0;
            virtual int32_t __stdcall GetSnapshotAsBytes(uint32_t, uint8_t*, uint32_t*) noexcept = 0;
            virtual int32_t __stdcall Compare(void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsValid(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsLocal(bool*) noexcept = 0;
            virtual int32_t __stdcall get_NetworkAccessKind(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateFromSnapshotBase64(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromSnapshotBuffer(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromSnapshotBytes(uint32_t, uint8_t*, void**) noexcept = 0;
            virtual int32_t __stdcall GetLocal(void**) noexcept = 0;
            virtual int32_t __stdcall get_MaxSnapshotBytesSize(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveEndpointPair>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_StateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall DeleteAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetRemoteSocketAddressBytes(uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall GetLocalSocketAddressBytes(uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Template(void**) noexcept = 0;
            virtual int32_t __stdcall get_RemoteDeviceAddress(void**) noexcept = 0;
            virtual int32_t __stdcall get_RemoteHostName(void**) noexcept = 0;
            virtual int32_t __stdcall get_RemotePort(void**) noexcept = 0;
            virtual int32_t __stdcall get_LocalHostName(void**) noexcept = 0;
            virtual int32_t __stdcall get_LocalPort(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceAddress(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsExistingPathEvaluation(bool*) noexcept = 0;
            virtual int32_t __stdcall get_EndpointPair(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OldState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_NewState(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindEndpointPairBySocketAddressBytes(uint32_t, uint8_t*, uint32_t, uint8_t*, void**) noexcept = 0;
            virtual int32_t __stdcall FindEndpointPairByHostNamesAndPorts(void*, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_InboundEndpointPairCreated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_InboundEndpointPairCreated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall CreateEndpointPairDefaultAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateEndpointPairWithBehaviorsAsync(void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateEndpointPairForPortsDefaultAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateEndpointPairForPortsWithBehaviorsAsync(void*, void*, void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_SocketKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_InitiatorBoundPortRangeLower(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_InitiatorBoundPortRangeUpper(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_AcceptorBoundPortRangeLower(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_AcceptorBoundPortRangeUpper(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_EndpointPairs(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetTemplateByName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_Templates(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EndpointPair(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall MeasureAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetMetricResultsForDevice(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetMetricResultsForMetric(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetMetricResult(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetPrivatePayloadResult(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_Metrics(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceAddresses(void**) noexcept = 0;
            virtual int32_t __stdcall get_ShouldRequestPrivatePayloads(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ShouldRequestPrivatePayloads(bool) noexcept = 0;
            virtual int32_t __stdcall get_TimeoutInMilliseconds(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_TimeoutInMilliseconds(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_NumberOfProbesToAttempt(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_NumberOfProbesToAttempt(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_NumberOfResultsPending(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MetricResults(void**) noexcept = 0;
            virtual int32_t __stdcall get_PrivatePayloadResults(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall PublishPrivatePayloadBytes(uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall ClearPrivatePayload() noexcept = 0;
            virtual int32_t __stdcall get_MaxSimultaneousProbeConnections(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MaxSimultaneousProbeConnections(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsSystemOutboundBandwidthConstrained(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsSystemOutboundBandwidthConstrained(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsSystemInboundBandwidthConstrained(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsSystemInboundBandwidthConstrained(bool) noexcept = 0;
            virtual int32_t __stdcall get_PublishedPrivatePayload(void**) noexcept = 0;
            virtual int32_t __stdcall put_PublishedPrivatePayload(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPrivatePayloadSize(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DeviceAddress(void**) noexcept = 0;
            virtual int32_t __stdcall get_Metric(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DeviceAddress(void**) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress
    {
        LLM_IMPL_AUTO(llm::event_token) SnapshotChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::XboxLive::XboxLiveDeviceAddress, llm:OS::Foundation::IInspectable> const& handler) const;
        using SnapshotChanged_revoker = impl::event_revoker<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress, &impl::abi_t<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress>::remove_SnapshotChanged>;
        [[nodiscard]] SnapshotChanged_revoker SnapshotChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::XboxLive::XboxLiveDeviceAddress, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) SnapshotChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(hstring) GetSnapshotAsBase64() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) GetSnapshotAsBuffer() const;
        LLM_IMPL_AUTO(void) GetSnapshotAsBytes(array_view<uint8_t> buffer, uint32_t& bytesWritten) const;
        LLM_IMPL_AUTO(int32_t) Compare(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& otherDeviceAddress) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsValid() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsLocal() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveNetworkAccessKind) NetworkAccessKind() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddressStatics
    {
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) CreateFromSnapshotBase64(param::hstring const& base64) const;
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) CreateFromSnapshotBuffer(llm:OS::Storage::Streams::IBuffer const& buffer) const;
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) CreateFromSnapshotBytes(array_view<uint8_t const> buffer) const;
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) GetLocal() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxSnapshotBytesSize() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddressStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair
    {
        LLM_IMPL_AUTO(llm::event_token) StateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::XboxLive::XboxLiveEndpointPair, llm:OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs> const& handler) const;
        using StateChanged_revoker = impl::event_revoker<llm:OS::Networking::XboxLive::IXboxLiveEndpointPair, &impl::abi_t<llm:OS::Networking::XboxLive::IXboxLiveEndpointPair>::remove_StateChanged>;
        [[nodiscard]] StateChanged_revoker StateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::XboxLive::XboxLiveEndpointPair, llm:OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) StateChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) DeleteAsync() const;
        LLM_IMPL_AUTO(void) GetRemoteSocketAddressBytes(array_view<uint8_t> socketAddress) const;
        LLM_IMPL_AUTO(void) GetLocalSocketAddressBytes(array_view<uint8_t> socketAddress) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPairState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate) Template() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) RemoteDeviceAddress() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::HostName) RemoteHostName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RemotePort() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::HostName) LocalHostName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) LocalPort() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveEndpointPair>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairCreationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) DeviceAddress() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsExistingPathEvaluation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPair) EndpointPair() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairCreationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStateChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPairState) OldState() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPairState) NewState() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStateChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStatics
    {
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPair) FindEndpointPairBySocketAddressBytes(array_view<uint8_t const> localSocketAddress, array_view<uint8_t const> remoteSocketAddress) const;
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPair) FindEndpointPairByHostNamesAndPorts(llm:OS::Networking::HostName const& localHostName, param::hstring const& localPort, llm:OS::Networking::HostName const& remoteHostName, param::hstring const& remotePort) const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStatics>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate
    {
        LLM_IMPL_AUTO(llm::event_token) InboundEndpointPairCreated(llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate, llm:OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs> const& handler) const;
        using InboundEndpointPairCreated_revoker = impl::event_revoker<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate, &impl::abi_t<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate>::remove_InboundEndpointPairCreated>;
        [[nodiscard]] InboundEndpointPairCreated_revoker InboundEndpointPairCreated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate, llm:OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) InboundEndpointPairCreated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) CreateEndpointPairAsync(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) CreateEndpointPairAsync(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors const& behaviors) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) CreateEndpointPairForPortsAsync(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, param::hstring const& initiatorPort, param::hstring const& acceptorPort) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) CreateEndpointPairForPortsAsync(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, param::hstring const& initiatorPort, param::hstring const& acceptorPort, llm:OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors const& behaviors) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveSocketKind) SocketKind() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) InitiatorBoundPortRangeLower() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) InitiatorBoundPortRangeUpper() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) AcceptorBoundPortRangeLower() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) AcceptorBoundPortRangeUpper() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::XboxLive::XboxLiveEndpointPair>) EndpointPairs() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplateStatics
    {
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate) GetTemplateByName(param::hstring const& name) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>) Templates() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplateStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveInboundEndpointPairCreatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveEndpointPair) EndpointPair() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveInboundEndpointPairCreatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) MeasureAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>) GetMetricResultsForDevice(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>) GetMetricResultsForMetric(llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric const& metric) const;
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult) GetMetricResult(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric const& metric) const;
        LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult) GetPrivatePayloadResult(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric>) Metrics() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Networking::XboxLive::XboxLiveDeviceAddress>) DeviceAddresses() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ShouldRequestPrivatePayloads() const;
        LLM_IMPL_AUTO(void) ShouldRequestPrivatePayloads(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TimeoutInMilliseconds() const;
        LLM_IMPL_AUTO(void) TimeoutInMilliseconds(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) NumberOfProbesToAttempt() const;
        LLM_IMPL_AUTO(void) NumberOfProbesToAttempt(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) NumberOfResultsPending() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>) MetricResults() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult>) PrivatePayloadResults() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics
    {
        LLM_IMPL_AUTO(void) PublishPrivatePayloadBytes(array_view<uint8_t const> payload) const;
        LLM_IMPL_AUTO(void) ClearPrivatePayload() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxSimultaneousProbeConnections() const;
        LLM_IMPL_AUTO(void) MaxSimultaneousProbeConnections(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSystemOutboundBandwidthConstrained() const;
        LLM_IMPL_AUTO(void) IsSystemOutboundBandwidthConstrained(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSystemInboundBandwidthConstrained() const;
        LLM_IMPL_AUTO(void) IsSystemInboundBandwidthConstrained(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) PublishedPrivatePayload() const;
        LLM_IMPL_AUTO(void) PublishedPrivatePayload(llm:OS::Storage::Streams::IBuffer const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxPrivatePayloadSize() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMetricResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) DeviceAddress() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric) Metric() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) Value() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMetricResult<D>;
    };
    template <typename D>
    struct consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServicePrivatePayloadResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Networking::XboxLive::XboxLiveDeviceAddress) DeviceAddress() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) Value() const;
    };
    template <> struct consume<llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult>
    {
        template <typename D> using type = consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServicePrivatePayloadResult<D>;
    };
}
#endif
