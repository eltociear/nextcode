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
#ifndef LLM_OS_Devices_Display_Core_0_H
#define LLM_OS_Devices_Display_Core_0_H
LLM_EXPORT namespace llm::OS::Devices::Display
{
    struct DisplayMonitor;
    enum class DisplayMonitorUsageKind : int32_t;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    struct HResult;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IKeyValuePair;
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Foundation::Numerics
{
    struct Rational;
}
LLM_EXPORT namespace llm::OS::Graphics
{
    struct DisplayAdapterId;
    struct RectInt32;
    struct SizeInt32;
}
LLM_EXPORT namespace llm::OS::Graphics::DirectX
{
    enum class DirectXColorSpace : int32_t;
    enum class DirectXPixelFormat : int32_t;
}
LLM_EXPORT namespace llm::OS::Graphics::DirectX::Direct3D11
{
    struct Direct3DMultisampleDescription;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm::OS::Devices::Display::Core
{
    enum class DisplayBitsPerChannel : uint32_t
    {
        None = 0,
        Bpc6 = 0x1,
        Bpc8 = 0x2,
        Bpc10 = 0x4,
        Bpc12 = 0x8,
        Bpc14 = 0x10,
        Bpc16 = 0x20,
    };
    enum class DisplayDeviceCapability : int32_t
    {
        FlipOverride = 0,
    };
    enum class DisplayManagerOptions : uint32_t
    {
        None = 0,
        EnforceSourceOwnership = 0x1,
        VirtualRefreshRateAware = 0x2,
    };
    enum class DisplayManagerResult : int32_t
    {
        Success = 0,
        UnknownFailure = 1,
        TargetAccessDenied = 2,
        TargetStale = 3,
        RemoteSessionNotSupported = 4,
    };
    enum class DisplayModeQueryOptions : uint32_t
    {
        None = 0,
        OnlyPreferredResolution = 0x1,
    };
    enum class DisplayPathScaling : int32_t
    {
        Identity = 0,
        Centered = 1,
        Stretched = 2,
        AspectRatioStretched = 3,
        Custom = 4,
        DriverPreferred = 5,
    };
    enum class DisplayPathStatus : int32_t
    {
        Unknown = 0,
        Succeeded = 1,
        Pending = 2,
        Failed = 3,
        FailedAsync = 4,
        InvalidatedAsync = 5,
    };
    enum class DisplayPresentStatus : int32_t
    {
        Success = 0,
        SourceStatusPreventedPresent = 1,
        ScanoutInvalid = 2,
        SourceInvalid = 3,
        DeviceInvalid = 4,
        UnknownFailure = 5,
    };
    enum class DisplayRotation : int32_t
    {
        None = 0,
        Clockwise90Degrees = 1,
        Clockwise180Degrees = 2,
        Clockwise270Degrees = 3,
    };
    enum class DisplayScanoutOptions : uint32_t
    {
        None = 0,
        AllowTearing = 0x2,
    };
    enum class DisplaySourceStatus : int32_t
    {
        Active = 0,
        PoweredOff = 1,
        Invalid = 2,
        OwnedByAnotherDevice = 3,
        Unowned = 4,
    };
    enum class DisplayStateApplyOptions : uint32_t
    {
        None = 0,
        FailIfStateChanged = 0x1,
        ForceReapply = 0x2,
        ForceModeEnumeration = 0x4,
    };
    enum class DisplayStateFunctionalizeOptions : uint32_t
    {
        None = 0,
        FailIfStateChanged = 0x1,
        ValidateTopologyOnly = 0x2,
    };
    enum class DisplayStateOperationStatus : int32_t
    {
        Success = 0,
        PartialFailure = 1,
        UnknownFailure = 2,
        TargetOwnershipLost = 3,
        SystemStateChanged = 4,
        TooManyPathsForAdapter = 5,
        ModesNotSupported = 6,
        RemoteSessionNotSupported = 7,
    };
    enum class DisplayTargetPersistence : int32_t
    {
        None = 0,
        BootPersisted = 1,
        TemporaryPersisted = 2,
        PathPersisted = 3,
    };
    enum class DisplayTaskSignalKind : int32_t
    {
        OnPresentFlipAway = 0,
        OnPresentFlipTo = 1,
    };
    enum class DisplayWireFormatColorSpace : int32_t
    {
        BT709 = 0,
        BT2020 = 1,
        ProfileDefinedWideColorGamut = 2,
    };
    enum class DisplayWireFormatEotf : int32_t
    {
        Sdr = 0,
        HdrSmpte2084 = 1,
    };
    enum class DisplayWireFormatHdrMetadata : int32_t
    {
        None = 0,
        Hdr10 = 1,
        Hdr10Plus = 2,
        DolbyVisionLowLatency = 3,
    };
    enum class DisplayWireFormatPixelEncoding : int32_t
    {
        Rgb444 = 0,
        Ycc444 = 1,
        Ycc422 = 2,
        Ycc420 = 3,
        Intensity = 4,
    };
    struct IDisplayAdapter;
    struct IDisplayAdapterStatics;
    struct IDisplayDevice;
    struct IDisplayDevice2;
    struct IDisplayFence;
    struct IDisplayManager;
    struct IDisplayManagerChangedEventArgs;
    struct IDisplayManagerDisabledEventArgs;
    struct IDisplayManagerEnabledEventArgs;
    struct IDisplayManagerPathsFailedOrInvalidatedEventArgs;
    struct IDisplayManagerResultWithState;
    struct IDisplayManagerStatics;
    struct IDisplayModeInfo;
    struct IDisplayModeInfo2;
    struct IDisplayPath;
    struct IDisplayPath2;
    struct IDisplayPrimaryDescription;
    struct IDisplayPrimaryDescriptionFactory;
    struct IDisplayPrimaryDescriptionStatics;
    struct IDisplayScanout;
    struct IDisplaySource;
    struct IDisplaySource2;
    struct IDisplayState;
    struct IDisplayStateOperationResult;
    struct IDisplaySurface;
    struct IDisplayTarget;
    struct IDisplayTask;
    struct IDisplayTask2;
    struct IDisplayTaskPool;
    struct IDisplayTaskPool2;
    struct IDisplayTaskResult;
    struct IDisplayView;
    struct IDisplayWireFormat;
    struct IDisplayWireFormatFactory;
    struct IDisplayWireFormatStatics;
    struct DisplayAdapter;
    struct DisplayDevice;
    struct DisplayFence;
    struct DisplayManager;
    struct DisplayManagerChangedEventArgs;
    struct DisplayManagerDisabledEventArgs;
    struct DisplayManagerEnabledEventArgs;
    struct DisplayManagerPathsFailedOrInvalidatedEventArgs;
    struct DisplayManagerResultWithState;
    struct DisplayModeInfo;
    struct DisplayPath;
    struct DisplayPrimaryDescription;
    struct DisplayScanout;
    struct DisplaySource;
    struct DisplayState;
    struct DisplayStateOperationResult;
    struct DisplaySurface;
    struct DisplayTarget;
    struct DisplayTask;
    struct DisplayTaskPool;
    struct DisplayTaskResult;
    struct DisplayView;
    struct DisplayWireFormat;
    struct DisplayPresentationRate;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayAdapter>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayAdapterStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayDevice>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayDevice2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayFence>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayManager>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayManagerResultWithState>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayModeInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayModeInfo2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayPath>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayPath2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayPrimaryDescription>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayScanout>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplaySource>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplaySource2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayState>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayStateOperationResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplaySurface>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayTarget>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayTask>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayTask2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayTaskPool>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayTaskPool2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayTaskResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayView>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayWireFormat>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayWireFormatFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::IDisplayWireFormatStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayAdapter>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayDevice>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayFence>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManager>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManagerResultWithState>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayModeInfo>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayPath>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayPrimaryDescription>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayScanout>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplaySource>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayState>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayStateOperationResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplaySurface>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayTarget>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayTask>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayTaskPool>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayTaskResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayView>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayWireFormat>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayBitsPerChannel>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayDeviceCapability>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManagerOptions>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayManagerResult>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayModeQueryOptions>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayPathScaling>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayPathStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayPresentStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayRotation>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayScanoutOptions>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplaySourceStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayStateApplyOptions>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayStateFunctionalizeOptions>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayStateOperationStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayTargetPersistence>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayTaskSignalKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayWireFormatEotf>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::Core::DisplayPresentationRate>{ using type = struct_category<llm::OS::Foundation::Numerics::Rational, int32_t>; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayAdapter> = L"Windows.Devices.Display.Core.DisplayAdapter";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayDevice> = L"Windows.Devices.Display.Core.DisplayDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayFence> = L"Windows.Devices.Display.Core.DisplayFence";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManager> = L"Windows.Devices.Display.Core.DisplayManager";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs> = L"Windows.Devices.Display.Core.DisplayManagerChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs> = L"Windows.Devices.Display.Core.DisplayManagerDisabledEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs> = L"Windows.Devices.Display.Core.DisplayManagerEnabledEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs> = L"Windows.Devices.Display.Core.DisplayManagerPathsFailedOrInvalidatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManagerResultWithState> = L"Windows.Devices.Display.Core.DisplayManagerResultWithState";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayModeInfo> = L"Windows.Devices.Display.Core.DisplayModeInfo";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayPath> = L"Windows.Devices.Display.Core.DisplayPath";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayPrimaryDescription> = L"Windows.Devices.Display.Core.DisplayPrimaryDescription";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayScanout> = L"Windows.Devices.Display.Core.DisplayScanout";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplaySource> = L"Windows.Devices.Display.Core.DisplaySource";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayState> = L"Windows.Devices.Display.Core.DisplayState";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayStateOperationResult> = L"Windows.Devices.Display.Core.DisplayStateOperationResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplaySurface> = L"Windows.Devices.Display.Core.DisplaySurface";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayTarget> = L"Windows.Devices.Display.Core.DisplayTarget";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayTask> = L"Windows.Devices.Display.Core.DisplayTask";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayTaskPool> = L"Windows.Devices.Display.Core.DisplayTaskPool";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayTaskResult> = L"Windows.Devices.Display.Core.DisplayTaskResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayView> = L"Windows.Devices.Display.Core.DisplayView";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayWireFormat> = L"Windows.Devices.Display.Core.DisplayWireFormat";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayBitsPerChannel> = L"Windows.Devices.Display.Core.DisplayBitsPerChannel";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayDeviceCapability> = L"Windows.Devices.Display.Core.DisplayDeviceCapability";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManagerOptions> = L"Windows.Devices.Display.Core.DisplayManagerOptions";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayManagerResult> = L"Windows.Devices.Display.Core.DisplayManagerResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayModeQueryOptions> = L"Windows.Devices.Display.Core.DisplayModeQueryOptions";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayPathScaling> = L"Windows.Devices.Display.Core.DisplayPathScaling";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayPathStatus> = L"Windows.Devices.Display.Core.DisplayPathStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayPresentStatus> = L"Windows.Devices.Display.Core.DisplayPresentStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayRotation> = L"Windows.Devices.Display.Core.DisplayRotation";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayScanoutOptions> = L"Windows.Devices.Display.Core.DisplayScanoutOptions";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplaySourceStatus> = L"Windows.Devices.Display.Core.DisplaySourceStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayStateApplyOptions> = L"Windows.Devices.Display.Core.DisplayStateApplyOptions";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayStateFunctionalizeOptions> = L"Windows.Devices.Display.Core.DisplayStateFunctionalizeOptions";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayStateOperationStatus> = L"Windows.Devices.Display.Core.DisplayStateOperationStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayTargetPersistence> = L"Windows.Devices.Display.Core.DisplayTargetPersistence";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayTaskSignalKind> = L"Windows.Devices.Display.Core.DisplayTaskSignalKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace> = L"Windows.Devices.Display.Core.DisplayWireFormatColorSpace";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayWireFormatEotf> = L"Windows.Devices.Display.Core.DisplayWireFormatEotf";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata> = L"Windows.Devices.Display.Core.DisplayWireFormatHdrMetadata";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding> = L"Windows.Devices.Display.Core.DisplayWireFormatPixelEncoding";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::DisplayPresentationRate> = L"Windows.Devices.Display.Core.DisplayPresentationRate";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayAdapter> = L"Windows.Devices.Display.Core.IDisplayAdapter";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayAdapterStatics> = L"Windows.Devices.Display.Core.IDisplayAdapterStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayDevice> = L"Windows.Devices.Display.Core.IDisplayDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayDevice2> = L"Windows.Devices.Display.Core.IDisplayDevice2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayFence> = L"Windows.Devices.Display.Core.IDisplayFence";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayManager> = L"Windows.Devices.Display.Core.IDisplayManager";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs> = L"Windows.Devices.Display.Core.IDisplayManagerChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs> = L"Windows.Devices.Display.Core.IDisplayManagerDisabledEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs> = L"Windows.Devices.Display.Core.IDisplayManagerEnabledEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs> = L"Windows.Devices.Display.Core.IDisplayManagerPathsFailedOrInvalidatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayManagerResultWithState> = L"Windows.Devices.Display.Core.IDisplayManagerResultWithState";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayManagerStatics> = L"Windows.Devices.Display.Core.IDisplayManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayModeInfo> = L"Windows.Devices.Display.Core.IDisplayModeInfo";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayModeInfo2> = L"Windows.Devices.Display.Core.IDisplayModeInfo2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayPath> = L"Windows.Devices.Display.Core.IDisplayPath";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayPath2> = L"Windows.Devices.Display.Core.IDisplayPath2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayPrimaryDescription> = L"Windows.Devices.Display.Core.IDisplayPrimaryDescription";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory> = L"Windows.Devices.Display.Core.IDisplayPrimaryDescriptionFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics> = L"Windows.Devices.Display.Core.IDisplayPrimaryDescriptionStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayScanout> = L"Windows.Devices.Display.Core.IDisplayScanout";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplaySource> = L"Windows.Devices.Display.Core.IDisplaySource";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplaySource2> = L"Windows.Devices.Display.Core.IDisplaySource2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayState> = L"Windows.Devices.Display.Core.IDisplayState";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayStateOperationResult> = L"Windows.Devices.Display.Core.IDisplayStateOperationResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplaySurface> = L"Windows.Devices.Display.Core.IDisplaySurface";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayTarget> = L"Windows.Devices.Display.Core.IDisplayTarget";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayTask> = L"Windows.Devices.Display.Core.IDisplayTask";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayTask2> = L"Windows.Devices.Display.Core.IDisplayTask2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayTaskPool> = L"Windows.Devices.Display.Core.IDisplayTaskPool";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayTaskPool2> = L"Windows.Devices.Display.Core.IDisplayTaskPool2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayTaskResult> = L"Windows.Devices.Display.Core.IDisplayTaskResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayView> = L"Windows.Devices.Display.Core.IDisplayView";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayWireFormat> = L"Windows.Devices.Display.Core.IDisplayWireFormat";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayWireFormatFactory> = L"Windows.Devices.Display.Core.IDisplayWireFormatFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::Core::IDisplayWireFormatStatics> = L"Windows.Devices.Display.Core.IDisplayWireFormatStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayAdapter>{ 0xA56F5287,0xF000,0x5F2E,{ 0xB5,0xAC,0x37,0x83,0xA2,0xB6,0x9A,0xF5 } }; // A56F5287-F000-5F2E-B5AC-3783A2B69AF5
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayAdapterStatics>{ 0x1DAC3CDA,0x481F,0x5469,{ 0x84,0x70,0x82,0xC4,0xBA,0x68,0x0A,0x28 } }; // 1DAC3CDA-481F-5469-8470-82C4BA680A28
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayDevice>{ 0xA4C9B62C,0x335F,0x5731,{ 0x8C,0xB4,0xC1,0xCC,0xD4,0x73,0x10,0x70 } }; // A4C9B62C-335F-5731-8CB4-C1CCD4731070
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayDevice2>{ 0x3FEFE50C,0x0940,0x54BD,{ 0xA0,0x2F,0xF9,0xC7,0xA5,0x36,0xAD,0x60 } }; // 3FEFE50C-0940-54BD-A02F-F9C7A536AD60
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayFence>{ 0x04DCF9EF,0x3406,0x5700,{ 0x8F,0xEC,0x77,0xEB,0xA4,0xC5,0xA7,0x4B } }; // 04DCF9EF-3406-5700-8FEC-77EBA4C5A74B
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayManager>{ 0x4ED9245B,0x15EC,0x56E2,{ 0x90,0x72,0x7F,0xE5,0x08,0x4A,0x31,0xA7 } }; // 4ED9245B-15EC-56E2-9072-7FE5084A31A7
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs>{ 0x6ABFA285,0x6CCA,0x5731,{ 0xBC,0xDC,0x42,0xE5,0xD2,0xF5,0xC5,0x0F } }; // 6ABFA285-6CCA-5731-BCDC-42E5D2F5C50F
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs>{ 0x8726DDE4,0x6793,0x5973,{ 0xA1,0x1F,0x5F,0xFB,0xC9,0x3F,0xDB,0x90 } }; // 8726DDE4-6793-5973-A11F-5FFBC93FDB90
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs>{ 0xF0CF3F6F,0x42FA,0x59A2,{ 0xB2,0x97,0x26,0xE1,0x71,0x3D,0xE8,0x48 } }; // F0CF3F6F-42FA-59A2-B297-26E1713DE848
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs>{ 0x03A65659,0x1DEC,0x5C15,{ 0xB2,0xA2,0x8F,0xE9,0x12,0x98,0x69,0xFE } }; // 03A65659-1DEC-5C15-B2A2-8FE9129869FE
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayManagerResultWithState>{ 0x8E656AA6,0x6614,0x54BE,{ 0xBF,0xEF,0x49,0x94,0x54,0x7F,0x7B,0xE1 } }; // 8E656AA6-6614-54BE-BFEF-4994547F7BE1
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayManagerStatics>{ 0x2B6B9446,0xB999,0x5535,{ 0x9D,0x69,0x53,0xF0,0x92,0xC7,0x80,0xA1 } }; // 2B6B9446-B999-5535-9D69-53F092C780A1
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayModeInfo>{ 0x48D513A0,0xF79B,0x5A74,{ 0xA0,0x5E,0xDA,0x82,0x1F,0x47,0x08,0x68 } }; // 48D513A0-F79B-5A74-A05E-DA821F470868
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayModeInfo2>{ 0xC86FA386,0x0DDB,0x5473,{ 0xBF,0xB0,0x4B,0x78,0x07,0xB5,0xF9,0x09 } }; // C86FA386-0DDB-5473-BFB0-4B7807B5F909
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayPath>{ 0xB3DFD64A,0x7460,0x5CDE,{ 0x81,0x1B,0xD5,0xAE,0x9F,0x3D,0x9F,0x84 } }; // B3DFD64A-7460-5CDE-811B-D5AE9F3D9F84
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayPath2>{ 0xF32459C5,0xE994,0x570B,{ 0x9E,0xC8,0xEF,0x42,0xC3,0x5A,0x85,0x47 } }; // F32459C5-E994-570B-9EC8-EF42C35A8547
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayPrimaryDescription>{ 0x872591D2,0xD533,0x50FF,{ 0xA8,0x5E,0x06,0x69,0x61,0x94,0xB7,0x7C } }; // 872591D2-D533-50FF-A85E-06696194B77C
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory>{ 0x1A6AFF7B,0x3637,0x5C46,{ 0xB4,0x79,0x76,0xD5,0x76,0x21,0x6E,0x65 } }; // 1A6AFF7B-3637-5C46-B479-76D576216E65
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics>{ 0xE60E4CFB,0x36C9,0x56DD,{ 0x8F,0xA1,0x6F,0xF8,0xC4,0xE0,0xFF,0x07 } }; // E60E4CFB-36C9-56DD-8FA1-6FF8C4E0FF07
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayScanout>{ 0xE3051828,0x1BA5,0x50E7,{ 0x8A,0x39,0xBB,0x1F,0xD2,0xF4,0xF8,0xB9 } }; // E3051828-1BA5-50E7-8A39-BB1FD2F4F8B9
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplaySource>{ 0xECD15FC1,0xEADC,0x51BC,{ 0x97,0x1D,0x3B,0xC6,0x28,0xDB,0x2D,0xD4 } }; // ECD15FC1-EADC-51BC-971D-3BC628DB2DD4
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplaySource2>{ 0x71E18952,0xB321,0x5AF4,{ 0xBF,0xE8,0x03,0xFB,0xEA,0x31,0xE4,0x0D } }; // 71E18952-B321-5AF4-BFE8-03FBEA31E40D
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayState>{ 0x08129321,0x11B5,0x5CB2,{ 0x99,0xF8,0xE9,0x0B,0x47,0x9A,0x8A,0x1D } }; // 08129321-11B5-5CB2-99F8-E90B479A8A1D
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayStateOperationResult>{ 0xFCADBFDF,0xDC27,0x5638,{ 0xB7,0xF2,0xEB,0xDF,0xA4,0xF7,0xEA,0x93 } }; // FCADBFDF-DC27-5638-B7F2-EBDFA4F7EA93
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplaySurface>{ 0x594F6CC6,0x139A,0x56D6,{ 0xA4,0xB1,0x15,0xFE,0x2C,0xB7,0x6A,0xDB } }; // 594F6CC6-139A-56D6-A4B1-15FE2CB76ADB
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayTarget>{ 0xAEC57C6F,0x47B4,0x546B,{ 0x98,0x7C,0xE7,0x3F,0xA7,0x91,0xFE,0x3A } }; // AEC57C6F-47B4-546B-987C-E73FA791FE3A
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayTask>{ 0x5E087448,0x135B,0x5BB0,{ 0xBF,0x63,0x63,0x7F,0x84,0x22,0x7C,0x7A } }; // 5E087448-135B-5BB0-BF63-637F84227C7A
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayTask2>{ 0x0957EA19,0xBD55,0x55DE,{ 0x92,0x67,0xC9,0x7B,0x61,0xE7,0x1C,0x37 } }; // 0957EA19-BD55-55DE-9267-C97B61E71C37
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayTaskPool>{ 0xC676253D,0x237D,0x5548,{ 0xAA,0xFA,0x3E,0x51,0x7F,0xEF,0xEF,0x1C } }; // C676253D-237D-5548-AAFA-3E517FEFEF1C
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayTaskPool2>{ 0x46B879B6,0x5D17,0x5955,{ 0xA8,0x72,0xEB,0x38,0x00,0x3D,0xB5,0x86 } }; // 46B879B6-5D17-5955-A872-EB38003DB586
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayTaskResult>{ 0x6FBC7D67,0xF9B1,0x55E0,{ 0x9D,0x88,0xD3,0xA5,0x19,0x7A,0x3F,0x59 } }; // 6FBC7D67-F9B1-55E0-9D88-D3A5197A3F59
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayView>{ 0xB0C98CA1,0xB759,0x5B59,{ 0xB1,0xAD,0xF0,0x78,0x6A,0xA9,0xE5,0x3D } }; // B0C98CA1-B759-5B59-B1AD-F0786AA9E53D
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayWireFormat>{ 0x1ACC967D,0x872C,0x5A38,{ 0xBB,0xB9,0x1D,0x48,0x72,0xB7,0x62,0x55 } }; // 1ACC967D-872C-5A38-BBB9-1D4872B76255
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayWireFormatFactory>{ 0xB2EFC8D5,0x09D6,0x55E6,{ 0xAD,0x22,0x90,0x14,0xB3,0xD2,0x52,0x29 } }; // B2EFC8D5-09D6-55E6-AD22-9014B3D25229
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::Core::IDisplayWireFormatStatics>{ 0xC575A22D,0xC3E6,0x5F7A,{ 0xBD,0xFB,0x87,0xC6,0xAB,0x86,0x61,0xD5 } }; // C575A22D-C3E6-5F7A-BDFB-87C6AB8661D5
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayAdapter>{ using type = llm::OS::Devices::Display::Core::IDisplayAdapter; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayDevice>{ using type = llm::OS::Devices::Display::Core::IDisplayDevice; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayFence>{ using type = llm::OS::Devices::Display::Core::IDisplayFence; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayManager>{ using type = llm::OS::Devices::Display::Core::IDisplayManager; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs>{ using type = llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs>{ using type = llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs>{ using type = llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs>{ using type = llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayManagerResultWithState>{ using type = llm::OS::Devices::Display::Core::IDisplayManagerResultWithState; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayModeInfo>{ using type = llm::OS::Devices::Display::Core::IDisplayModeInfo; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayPath>{ using type = llm::OS::Devices::Display::Core::IDisplayPath; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayPrimaryDescription>{ using type = llm::OS::Devices::Display::Core::IDisplayPrimaryDescription; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayScanout>{ using type = llm::OS::Devices::Display::Core::IDisplayScanout; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplaySource>{ using type = llm::OS::Devices::Display::Core::IDisplaySource; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayState>{ using type = llm::OS::Devices::Display::Core::IDisplayState; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayStateOperationResult>{ using type = llm::OS::Devices::Display::Core::IDisplayStateOperationResult; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplaySurface>{ using type = llm::OS::Devices::Display::Core::IDisplaySurface; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayTarget>{ using type = llm::OS::Devices::Display::Core::IDisplayTarget; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayTask>{ using type = llm::OS::Devices::Display::Core::IDisplayTask; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayTaskPool>{ using type = llm::OS::Devices::Display::Core::IDisplayTaskPool; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayTaskResult>{ using type = llm::OS::Devices::Display::Core::IDisplayTaskResult; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayView>{ using type = llm::OS::Devices::Display::Core::IDisplayView; };
    template <> struct default_interface<llm::OS::Devices::Display::Core::DisplayWireFormat>{ using type = llm::OS::Devices::Display::Core::IDisplayWireFormat; };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayAdapter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(struct struct_Windows_Graphics_DisplayAdapterId*) noexcept = 0;
            virtual int32_t __stdcall get_DeviceInterfacePath(void**) noexcept = 0;
            virtual int32_t __stdcall get_SourceCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PciVendorId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PciDeviceId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PciSubSystemId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PciRevision(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayAdapterStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromId(struct struct_Windows_Graphics_DisplayAdapterId, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateScanoutSource(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreatePrimary(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTaskPool(void**) noexcept = 0;
            virtual int32_t __stdcall CreatePeriodicFence(void*, int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall WaitForVBlank(void*) noexcept = 0;
            virtual int32_t __stdcall CreateSimpleScanout(void*, void*, uint32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall IsCapabilitySupported(int32_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayDevice2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateSimpleScanoutWithDirtyRectsAndOptions(void*, void*, uint32_t, uint32_t, void*, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayFence>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetCurrentTargets(void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentAdapters(void**) noexcept = 0;
            virtual int32_t __stdcall TryAcquireTarget(void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall ReleaseTarget(void*) noexcept = 0;
            virtual int32_t __stdcall TryReadCurrentStateForAllTargets(void**) noexcept = 0;
            virtual int32_t __stdcall TryAcquireTargetsAndReadCurrentState(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryAcquireTargetsAndCreateEmptyState(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryAcquireTargetsAndCreateSubstate(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDisplayDevice(void*, void**) noexcept = 0;
            virtual int32_t __stdcall add_Enabled(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Enabled(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Disabled(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Disabled(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PathsFailedOrInvalidated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PathsFailedOrInvalidated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayManagerResultWithState>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ErrorCode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedErrorCode(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_State(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayModeInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SourceResolution(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall get_IsStereo(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SourcePixelFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TargetResolution(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall get_PresentationRate(struct struct_Windows_Devices_Display_Core_DisplayPresentationRate*) noexcept = 0;
            virtual int32_t __stdcall get_IsInterlaced(bool*) noexcept = 0;
            virtual int32_t __stdcall GetWireFormatSupportedBitsPerChannel(int32_t, uint32_t*) noexcept = 0;
            virtual int32_t __stdcall IsWireFormatSupported(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayModeInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PhysicalPresentationRate(struct struct_Windows_Devices_Display_Core_DisplayPresentationRate*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayPath>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_View(void**) noexcept = 0;
            virtual int32_t __stdcall get_Target(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SourceResolution(void**) noexcept = 0;
            virtual int32_t __stdcall put_SourceResolution(void*) noexcept = 0;
            virtual int32_t __stdcall get_SourcePixelFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SourcePixelFormat(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsStereo(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsStereo(bool) noexcept = 0;
            virtual int32_t __stdcall get_TargetResolution(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetResolution(void*) noexcept = 0;
            virtual int32_t __stdcall get_PresentationRate(void**) noexcept = 0;
            virtual int32_t __stdcall put_PresentationRate(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsInterlaced(void**) noexcept = 0;
            virtual int32_t __stdcall put_IsInterlaced(void*) noexcept = 0;
            virtual int32_t __stdcall get_WireFormat(void**) noexcept = 0;
            virtual int32_t __stdcall put_WireFormat(void*) noexcept = 0;
            virtual int32_t __stdcall get_Rotation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Rotation(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Scaling(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Scaling(int32_t) noexcept = 0;
            virtual int32_t __stdcall FindModes(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ApplyPropertiesFromMode(void*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayPath2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PhysicalPresentationRate(void**) noexcept = 0;
            virtual int32_t __stdcall put_PhysicalPresentationRate(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayPrimaryDescription>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Width(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Height(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Format(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ColorSpace(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsStereo(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MultisampleDescription(struct struct_Windows_Graphics_DirectX_Direct3D11_Direct3DMultisampleDescription*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(uint32_t, uint32_t, int32_t, int32_t, bool, struct struct_Windows_Graphics_DirectX_Direct3D11_Direct3DMultisampleDescription, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithProperties(void*, uint32_t, uint32_t, int32_t, int32_t, bool, struct struct_Windows_Graphics_DirectX_Direct3D11_Direct3DMultisampleDescription, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayScanout>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplaySource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AdapterId(struct struct_Windows_Graphics_DisplayAdapterId*) noexcept = 0;
            virtual int32_t __stdcall get_SourceId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall GetMetadata(llm::guid, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplaySource2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_StatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StatusChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayState>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsReadOnly(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsStale(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Targets(void**) noexcept = 0;
            virtual int32_t __stdcall get_Views(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
            virtual int32_t __stdcall ConnectTarget(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ConnectTargetToView(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CanConnectTargetToView(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall GetViewForTarget(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetPathForTarget(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DisconnectTarget(void*) noexcept = 0;
            virtual int32_t __stdcall TryFunctionalize(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall TryApply(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall Clone(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayStateOperationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedErrorCode(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplaySurface>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayTarget>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Adapter(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceInterfacePath(void**) noexcept = 0;
            virtual int32_t __stdcall get_AdapterRelativeId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsConnected(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsVirtualModeEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsVirtualTopologyEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_UsageKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MonitorPersistence(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_StableMonitorId(void**) noexcept = 0;
            virtual int32_t __stdcall TryGetMonitor(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsStale(bool*) noexcept = 0;
            virtual int32_t __stdcall IsSame(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsEqual(void*, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayTask>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetScanout(void*) noexcept = 0;
            virtual int32_t __stdcall SetWait(void*, uint64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayTask2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetSignal(int32_t, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayTaskPool>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateTask(void**) noexcept = 0;
            virtual int32_t __stdcall ExecuteTask(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayTaskPool2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryExecuteTask(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayTaskResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PresentStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PresentId(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SourceStatus(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayView>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Paths(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContentResolution(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentResolution(void*) noexcept = 0;
            virtual int32_t __stdcall SetPrimaryPath(void*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayWireFormat>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PixelEncoding(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_BitsPerChannel(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ColorSpace(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Eotf(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_HdrMetadata(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayWireFormatFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(int32_t, int32_t, int32_t, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::Core::IDisplayWireFormatStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithProperties(void*, int32_t, int32_t, int32_t, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayAdapter
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DisplayAdapterId) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceInterfacePath() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SourceCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PciVendorId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PciDeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PciSubSystemId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PciRevision() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayAdapter>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayAdapter<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayAdapterStatics
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayAdapter) FromId(llm::OS::Graphics::DisplayAdapterId const& id) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayAdapterStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayAdapterStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayDevice
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySource) CreateScanoutSource(llm::OS::Devices::Display::Core::DisplayTarget const& target) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySurface) CreatePrimary(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Devices::Display::Core::DisplayPrimaryDescription const& desc) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTaskPool) CreateTaskPool() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayFence) CreatePeriodicFence(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Foundation::TimeSpan const& offsetFromVBlank) const;
        LLM_IMPL_AUTO(void) WaitForVBlank(llm::OS::Devices::Display::Core::DisplaySource const& source) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayScanout) CreateSimpleScanout(llm::OS::Devices::Display::Core::DisplaySource const& pSource, llm::OS::Devices::Display::Core::DisplaySurface const& pSurface, uint32_t SubResourceIndex, uint32_t SyncInterval) const;
        LLM_IMPL_AUTO(bool) IsCapabilitySupported(llm::OS::Devices::Display::Core::DisplayDeviceCapability const& capability) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayDevice>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayDevice2
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayScanout) CreateSimpleScanoutWithDirtyRectsAndOptions(llm::OS::Devices::Display::Core::DisplaySource const& source, llm::OS::Devices::Display::Core::DisplaySurface const& surface, uint32_t subresourceIndex, uint32_t syncInterval, param::iterable<llm::OS::Graphics::RectInt32> const& dirtyRects, llm::OS::Devices::Display::Core::DisplayScanoutOptions const& options) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayDevice2>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayDevice2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayFence
    {
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayFence>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayFence<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayManager
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>) GetCurrentTargets() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayAdapter>) GetCurrentAdapters() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResult) TryAcquireTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const;
        LLM_IMPL_AUTO(void) ReleaseTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) TryReadCurrentStateForAllTargets() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) TryAcquireTargetsAndReadCurrentState(param::iterable<llm::OS::Devices::Display::Core::DisplayTarget> const& targets) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) TryAcquireTargetsAndCreateEmptyState(param::iterable<llm::OS::Devices::Display::Core::DisplayTarget> const& targets) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) TryAcquireTargetsAndCreateSubstate(llm::OS::Devices::Display::Core::DisplayState const& existingState, param::iterable<llm::OS::Devices::Display::Core::DisplayTarget> const& targets) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayDevice) CreateDisplayDevice(llm::OS::Devices::Display::Core::DisplayAdapter const& adapter) const;
        LLM_IMPL_AUTO(llm::event_token) Enabled(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs> const& handler) const;
        using Enabled_revoker = impl::event_revoker<llm::OS::Devices::Display::Core::IDisplayManager, &impl::abi_t<llm::OS::Devices::Display::Core::IDisplayManager>::remove_Enabled>;
        [[nodiscard]] Enabled_revoker Enabled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Enabled(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Disabled(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs> const& handler) const;
        using Disabled_revoker = impl::event_revoker<llm::OS::Devices::Display::Core::IDisplayManager, &impl::abi_t<llm::OS::Devices::Display::Core::IDisplayManager>::remove_Disabled>;
        [[nodiscard]] Disabled_revoker Disabled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Disabled(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm::OS::Devices::Display::Core::IDisplayManager, &impl::abi_t<llm::OS::Devices::Display::Core::IDisplayManager>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PathsFailedOrInvalidated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs> const& handler) const;
        using PathsFailedOrInvalidated_revoker = impl::event_revoker<llm::OS::Devices::Display::Core::IDisplayManager, &impl::abi_t<llm::OS::Devices::Display::Core::IDisplayManager>::remove_PathsFailedOrInvalidated>;
        [[nodiscard]] PathsFailedOrInvalidated_revoker PathsFailedOrInvalidated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PathsFailedOrInvalidated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayManager>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayManager<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayManagerChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayManagerChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayManagerDisabledEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayManagerDisabledEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayManagerEnabledEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayManagerEnabledEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayManagerPathsFailedOrInvalidatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayManagerPathsFailedOrInvalidatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayManagerResultWithState
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResult) ErrorCode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedErrorCode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayState) State() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayManagerResultWithState>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayManagerResultWithState<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManager) Create(llm::OS::Devices::Display::Core::DisplayManagerOptions const& options) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayManagerStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayModeInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) SourceResolution() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsStereo() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) SourcePixelFormat() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) TargetResolution() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPresentationRate) PresentationRate() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsInterlaced() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayBitsPerChannel) GetWireFormatSupportedBitsPerChannel(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& encoding) const;
        LLM_IMPL_AUTO(bool) IsWireFormatSupported(llm::OS::Devices::Display::Core::DisplayWireFormat const& wireFormat) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayModeInfo>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayModeInfo2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPresentationRate) PhysicalPresentationRate() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayModeInfo2>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayModeInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayPath
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayView) View() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTarget) Target() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPathStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>) SourceResolution() const;
        LLM_IMPL_AUTO(void) SourceResolution(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) SourcePixelFormat() const;
        LLM_IMPL_AUTO(void) SourcePixelFormat(llm::OS::Graphics::DirectX::DirectXPixelFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsStereo() const;
        LLM_IMPL_AUTO(void) IsStereo(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>) TargetResolution() const;
        LLM_IMPL_AUTO(void) TargetResolution(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>) PresentationRate() const;
        LLM_IMPL_AUTO(void) PresentationRate(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<bool>) IsInterlaced() const;
        LLM_IMPL_AUTO(void) IsInterlaced(llm::OS::Foundation::IReference<bool> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormat) WireFormat() const;
        LLM_IMPL_AUTO(void) WireFormat(llm::OS::Devices::Display::Core::DisplayWireFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayRotation) Rotation() const;
        LLM_IMPL_AUTO(void) Rotation(llm::OS::Devices::Display::Core::DisplayRotation const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPathScaling) Scaling() const;
        LLM_IMPL_AUTO(void) Scaling(llm::OS::Devices::Display::Core::DisplayPathScaling const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayModeInfo>) FindModes(llm::OS::Devices::Display::Core::DisplayModeQueryOptions const& flags) const;
        LLM_IMPL_AUTO(void) ApplyPropertiesFromMode(llm::OS::Devices::Display::Core::DisplayModeInfo const& modeResult) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayPath>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayPath<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayPath2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>) PhysicalPresentationRate() const;
        LLM_IMPL_AUTO(void) PhysicalPresentationRate(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate> const& value) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayPath2>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayPath2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Width() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Height() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) Format() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXColorSpace) ColorSpace() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsStereo() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription) MultisampleDescription() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayPrimaryDescription>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayPrimaryDescriptionFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPrimaryDescription) CreateInstance(uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayPrimaryDescriptionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayPrimaryDescriptionStatics
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPrimaryDescription) CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayPrimaryDescriptionStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayScanout
    {
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayScanout>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayScanout<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplaySource
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DisplayAdapterId) AdapterId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SourceId() const;
        LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) GetMetadata(llm::guid const& Key) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplaySource>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplaySource<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplaySource2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySourceStatus) Status() const;
        LLM_IMPL_AUTO(llm::event_token) StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplaySource, llm::OS::Foundation::IInspectable> const& handler) const;
        using StatusChanged_revoker = impl::event_revoker<llm::OS::Devices::Display::Core::IDisplaySource2, &impl::abi_t<llm::OS::Devices::Display::Core::IDisplaySource2>::remove_StatusChanged>;
        [[nodiscard]] StatusChanged_revoker StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplaySource, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) StatusChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplaySource2>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplaySource2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayState
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsReadOnly() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsStale() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>) Targets() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayView>) Views() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPath) ConnectTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPath) ConnectTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Devices::Display::Core::DisplayView const& view) const;
        LLM_IMPL_AUTO(bool) CanConnectTargetToView(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Devices::Display::Core::DisplayView const& view) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayView) GetViewForTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPath) GetPathForTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const;
        LLM_IMPL_AUTO(void) DisconnectTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayStateOperationResult) TryFunctionalize(llm::OS::Devices::Display::Core::DisplayStateFunctionalizeOptions const& options) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayStateOperationResult) TryApply(llm::OS::Devices::Display::Core::DisplayStateApplyOptions const& options) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayState) Clone() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayState>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayState<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayStateOperationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayStateOperationStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedErrorCode() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayStateOperationResult>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayStateOperationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplaySurface
    {
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplaySurface>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplaySurface<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayTarget
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayAdapter) Adapter() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceInterfacePath() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) AdapterRelativeId() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsConnected() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVirtualModeEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVirtualTopologyEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorUsageKind) UsageKind() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTargetPersistence) MonitorPersistence() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) StableMonitorId() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitor) TryGetMonitor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsStale() const;
        LLM_IMPL_AUTO(bool) IsSame(llm::OS::Devices::Display::Core::DisplayTarget const& otherTarget) const;
        LLM_IMPL_AUTO(bool) IsEqual(llm::OS::Devices::Display::Core::DisplayTarget const& otherTarget) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayTarget>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayTarget<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayTask
    {
        LLM_IMPL_AUTO(void) SetScanout(llm::OS::Devices::Display::Core::DisplayScanout const& scanout) const;
        LLM_IMPL_AUTO(void) SetWait(llm::OS::Devices::Display::Core::DisplayFence const& readyFence, uint64_t readyFenceValue) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayTask>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayTask<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayTask2
    {
        LLM_IMPL_AUTO(void) SetSignal(llm::OS::Devices::Display::Core::DisplayTaskSignalKind const& signalKind, llm::OS::Devices::Display::Core::DisplayFence const& fence) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayTask2>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayTask2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayTaskPool
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTask) CreateTask() const;
        LLM_IMPL_AUTO(void) ExecuteTask(llm::OS::Devices::Display::Core::DisplayTask const& task) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayTaskPool>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayTaskPool<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayTaskPool2
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTaskResult) TryExecuteTask(llm::OS::Devices::Display::Core::DisplayTask const& task) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayTaskPool2>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayTaskPool2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayTaskResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPresentStatus) PresentStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PresentId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySourceStatus) SourceStatus() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayTaskResult>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayTaskResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayView
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayPath>) Paths() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>) ContentResolution() const;
        LLM_IMPL_AUTO(void) ContentResolution(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const& value) const;
        LLM_IMPL_AUTO(void) SetPrimaryPath(llm::OS::Devices::Display::Core::DisplayPath const& path) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayView>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayView<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayWireFormat
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding) PixelEncoding() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) BitsPerChannel() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace) ColorSpace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatEotf) Eotf() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata) HdrMetadata() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) Properties() const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayWireFormat>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayWireFormat<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayWireFormatFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormat) CreateInstance(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayWireFormatFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayWireFormatFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_Core_IDisplayWireFormatStatics
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormat) CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata) const;
    };
    template <> struct consume<llm::OS::Devices::Display::Core::IDisplayWireFormatStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Display_Core_IDisplayWireFormatStatics<D>;
    };
    struct struct_Windows_Devices_Display_Core_DisplayPresentationRate
    {
        llm::OS::Foundation::Numerics::Rational VerticalSyncRate;
        int32_t VerticalSyncsPerPresentation;
    };
    template <> struct abi<Windows::Devices::Display::Core::DisplayPresentationRate>
    {
        using type = struct_Windows_Devices_Display_Core_DisplayPresentationRate;
    };
}
#endif
