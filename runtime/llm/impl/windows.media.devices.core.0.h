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
#ifndef LLM_OS_Media_Devices_Core_0_H
#define LLM_OS_Media_Devices_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Point;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm:OS::Media::MediaProperties
{
    struct IMediaEncodingProperties;
    struct MediaRatio;
}
LLM_EXPORT namespace llm:OS::Perception::Spatial
{
    struct SpatialCoordinateSystem;
}
LLM_EXPORT namespace llm:OS::Media::Devices::Core
{
    enum class FrameFlashMode : int32_t
    {
        Disable = 0,
        Enable = 1,
        Global = 2,
    };
    struct ICameraIntrinsics;
    struct ICameraIntrinsics2;
    struct ICameraIntrinsicsFactory;
    struct IDepthCorrelatedCoordinateMapper;
    struct IFrameControlCapabilities;
    struct IFrameControlCapabilities2;
    struct IFrameController;
    struct IFrameController2;
    struct IFrameExposureCapabilities;
    struct IFrameExposureCompensationCapabilities;
    struct IFrameExposureCompensationControl;
    struct IFrameExposureControl;
    struct IFrameFlashCapabilities;
    struct IFrameFlashControl;
    struct IFrameFocusCapabilities;
    struct IFrameFocusControl;
    struct IFrameIsoSpeedCapabilities;
    struct IFrameIsoSpeedControl;
    struct IVariablePhotoSequenceController;
    struct CameraIntrinsics;
    struct DepthCorrelatedCoordinateMapper;
    struct FrameControlCapabilities;
    struct FrameController;
    struct FrameExposureCapabilities;
    struct FrameExposureCompensationCapabilities;
    struct FrameExposureCompensationControl;
    struct FrameExposureControl;
    struct FrameFlashCapabilities;
    struct FrameFlashControl;
    struct FrameFocusCapabilities;
    struct FrameFocusControl;
    struct FrameIsoSpeedCapabilities;
    struct FrameIsoSpeedControl;
    struct VariablePhotoSequenceController;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Devices::Core::ICameraIntrinsics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::ICameraIntrinsics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::ICameraIntrinsicsFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameControlCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameControlCapabilities2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameController>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameController2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameExposureCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameExposureCompensationControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameExposureControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameFlashCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameFlashControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameFocusCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameFocusControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IFrameIsoSpeedControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::IVariablePhotoSequenceController>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::Core::CameraIntrinsics>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::DepthCorrelatedCoordinateMapper>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameControlCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameController>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameExposureCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameExposureCompensationCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameExposureCompensationControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameExposureControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameFlashCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameFlashControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameFocusCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameFocusControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameIsoSpeedCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameIsoSpeedControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::VariablePhotoSequenceController>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::Core::FrameFlashMode>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::CameraIntrinsics> = L"Windows.Media.Devices.Core.CameraIntrinsics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::DepthCorrelatedCoordinateMapper> = L"Windows.Media.Devices.Core.DepthCorrelatedCoordinateMapper";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameControlCapabilities> = L"Windows.Media.Devices.Core.FrameControlCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameController> = L"Windows.Media.Devices.Core.FrameController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameExposureCapabilities> = L"Windows.Media.Devices.Core.FrameExposureCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameExposureCompensationCapabilities> = L"Windows.Media.Devices.Core.FrameExposureCompensationCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameExposureCompensationControl> = L"Windows.Media.Devices.Core.FrameExposureCompensationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameExposureControl> = L"Windows.Media.Devices.Core.FrameExposureControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameFlashCapabilities> = L"Windows.Media.Devices.Core.FrameFlashCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameFlashControl> = L"Windows.Media.Devices.Core.FrameFlashControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameFocusCapabilities> = L"Windows.Media.Devices.Core.FrameFocusCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameFocusControl> = L"Windows.Media.Devices.Core.FrameFocusControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameIsoSpeedCapabilities> = L"Windows.Media.Devices.Core.FrameIsoSpeedCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameIsoSpeedControl> = L"Windows.Media.Devices.Core.FrameIsoSpeedControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::VariablePhotoSequenceController> = L"Windows.Media.Devices.Core.VariablePhotoSequenceController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::FrameFlashMode> = L"Windows.Media.Devices.Core.FrameFlashMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::ICameraIntrinsics> = L"Windows.Media.Devices.Core.ICameraIntrinsics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::ICameraIntrinsics2> = L"Windows.Media.Devices.Core.ICameraIntrinsics2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::ICameraIntrinsicsFactory> = L"Windows.Media.Devices.Core.ICameraIntrinsicsFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper> = L"Windows.Media.Devices.Core.IDepthCorrelatedCoordinateMapper";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameControlCapabilities> = L"Windows.Media.Devices.Core.IFrameControlCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameControlCapabilities2> = L"Windows.Media.Devices.Core.IFrameControlCapabilities2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameController> = L"Windows.Media.Devices.Core.IFrameController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameController2> = L"Windows.Media.Devices.Core.IFrameController2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameExposureCapabilities> = L"Windows.Media.Devices.Core.IFrameExposureCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities> = L"Windows.Media.Devices.Core.IFrameExposureCompensationCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameExposureCompensationControl> = L"Windows.Media.Devices.Core.IFrameExposureCompensationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameExposureControl> = L"Windows.Media.Devices.Core.IFrameExposureControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameFlashCapabilities> = L"Windows.Media.Devices.Core.IFrameFlashCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameFlashControl> = L"Windows.Media.Devices.Core.IFrameFlashControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameFocusCapabilities> = L"Windows.Media.Devices.Core.IFrameFocusCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameFocusControl> = L"Windows.Media.Devices.Core.IFrameFocusControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities> = L"Windows.Media.Devices.Core.IFrameIsoSpeedCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IFrameIsoSpeedControl> = L"Windows.Media.Devices.Core.IFrameIsoSpeedControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::Core::IVariablePhotoSequenceController> = L"Windows.Media.Devices.Core.IVariablePhotoSequenceController";
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::ICameraIntrinsics>{ 0x0AA6ED32,0x6589,0x49DA,{ 0xAF,0xDE,0x59,0x42,0x70,0xCA,0x0A,0xAC } }; // 0AA6ED32-6589-49DA-AFDE-594270CA0AAC
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::ICameraIntrinsics2>{ 0x0CDAA447,0x0798,0x4B4D,{ 0x83,0x9F,0xC5,0xEC,0x41,0x4D,0xB2,0x7A } }; // 0CDAA447-0798-4B4D-839F-C5EC414DB27A
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::ICameraIntrinsicsFactory>{ 0xC0DDC486,0x2132,0x4A34,{ 0xA6,0x59,0x9B,0xFE,0x2A,0x05,0x57,0x12 } }; // C0DDC486-2132-4A34-A659-9BFE2A055712
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>{ 0xF95D89FB,0x8AF0,0x4CB0,{ 0x92,0x6D,0x69,0x68,0x66,0xE5,0x04,0x6A } }; // F95D89FB-8AF0-4CB0-926D-696866E5046A
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameControlCapabilities>{ 0xA8FFAE60,0x4E9E,0x4377,{ 0xA7,0x89,0xE2,0x4C,0x4A,0xE7,0xE5,0x44 } }; // A8FFAE60-4E9E-4377-A789-E24C4AE7E544
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameControlCapabilities2>{ 0xCE9B0464,0x4730,0x440F,{ 0xBD,0x3E,0xEF,0xE8,0xA8,0xF2,0x30,0xA8 } }; // CE9B0464-4730-440F-BD3E-EFE8A8F230A8
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameController>{ 0xC16459D9,0xBAEF,0x4052,{ 0x91,0x77,0x48,0xAF,0xF2,0xAF,0x75,0x22 } }; // C16459D9-BAEF-4052-9177-48AFF2AF7522
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameController2>{ 0x00D3BC75,0xD87C,0x485B,{ 0x8A,0x09,0x5C,0x35,0x85,0x68,0xB4,0x27 } }; // 00D3BC75-D87C-485B-8A09-5C358568B427
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameExposureCapabilities>{ 0xBDBE9CE3,0x3985,0x4E72,{ 0x97,0xC2,0x05,0x90,0xD6,0x13,0x07,0xA1 } }; // BDBE9CE3-3985-4E72-97C2-0590D61307A1
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities>{ 0xB988A823,0x8065,0x41EE,{ 0xB0,0x4F,0x72,0x22,0x65,0x95,0x45,0x00 } }; // B988A823-8065-41EE-B04F-722265954500
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameExposureCompensationControl>{ 0xE95896C9,0xF7F9,0x48CA,{ 0x85,0x91,0xA2,0x65,0x31,0xCB,0x15,0x78 } }; // E95896C9-F7F9-48CA-8591-A26531CB1578
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameExposureControl>{ 0xB1605A61,0xFFAF,0x4752,{ 0xB6,0x21,0xF5,0xB6,0xF1,0x17,0xF4,0x32 } }; // B1605A61-FFAF-4752-B621-F5B6F117F432
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameFlashCapabilities>{ 0xBB9341A2,0x5EBE,0x4F62,{ 0x82,0x23,0x0E,0x2B,0x05,0xBF,0xBB,0xD0 } }; // BB9341A2-5EBE-4F62-8223-0E2B05BFBBD0
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameFlashControl>{ 0x75D5F6C7,0xBD45,0x4FAB,{ 0x93,0x75,0x45,0xAC,0x04,0xB3,0x32,0xC2 } }; // 75D5F6C7-BD45-4FAB-9375-45AC04B332C2
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameFocusCapabilities>{ 0x7B25CD58,0x01C0,0x4065,{ 0x9C,0x40,0xC1,0xA7,0x21,0x42,0x5C,0x1A } }; // 7B25CD58-01C0-4065-9C40-C1A721425C1A
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameFocusControl>{ 0x272DF1D0,0xD912,0x4214,{ 0xA6,0x7B,0xE3,0x8A,0x8D,0x48,0xD8,0xC6 } }; // 272DF1D0-D912-4214-A67B-E38A8D48D8C6
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities>{ 0x16BDFF61,0x6DF6,0x4AC9,{ 0xB9,0x2A,0x9F,0x6E,0xCD,0x1A,0xD2,0xFA } }; // 16BDFF61-6DF6-4AC9-B92A-9F6ECD1AD2FA
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IFrameIsoSpeedControl>{ 0x1A03EFED,0x786A,0x4C75,{ 0xA5,0x57,0x7A,0xB9,0xA8,0x5F,0x58,0x8C } }; // 1A03EFED-786A-4C75-A557-7AB9A85F588C
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::Core::IVariablePhotoSequenceController>{ 0x7FBFF880,0xED8C,0x43FD,{ 0xA7,0xC3,0xB3,0x58,0x09,0xE4,0x22,0x9A } }; // 7FBFF880-ED8C-43FD-A7C3-B35809E4229A
    template <> struct default_interface<llm:OS::Media::Devices::Core::CameraIntrinsics>{ using type = llm:OS::Media::Devices::Core::ICameraIntrinsics; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::DepthCorrelatedCoordinateMapper>{ using type = llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameControlCapabilities>{ using type = llm:OS::Media::Devices::Core::IFrameControlCapabilities; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameController>{ using type = llm:OS::Media::Devices::Core::IFrameController; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameExposureCapabilities>{ using type = llm:OS::Media::Devices::Core::IFrameExposureCapabilities; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameExposureCompensationCapabilities>{ using type = llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameExposureCompensationControl>{ using type = llm:OS::Media::Devices::Core::IFrameExposureCompensationControl; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameExposureControl>{ using type = llm:OS::Media::Devices::Core::IFrameExposureControl; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameFlashCapabilities>{ using type = llm:OS::Media::Devices::Core::IFrameFlashCapabilities; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameFlashControl>{ using type = llm:OS::Media::Devices::Core::IFrameFlashControl; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameFocusCapabilities>{ using type = llm:OS::Media::Devices::Core::IFrameFocusCapabilities; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameFocusControl>{ using type = llm:OS::Media::Devices::Core::IFrameFocusControl; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameIsoSpeedCapabilities>{ using type = llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::FrameIsoSpeedControl>{ using type = llm:OS::Media::Devices::Core::IFrameIsoSpeedControl; };
    template <> struct default_interface<llm:OS::Media::Devices::Core::VariablePhotoSequenceController>{ using type = llm:OS::Media::Devices::Core::IVariablePhotoSequenceController; };
    template <> struct abi<llm:OS::Media::Devices::Core::ICameraIntrinsics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FocalLength(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall get_PrincipalPoint(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall get_RadialDistortion(llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall get_TangentialDistortion(llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall get_ImageWidth(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ImageHeight(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall ProjectOntoFrame(llm:OS::Foundation::Numerics::float3, llm:OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall UnprojectAtUnitDepth(llm:OS::Foundation::Point, llm:OS::Foundation::Numerics::float2*) noexcept = 0;
            virtual int32_t __stdcall ProjectManyOntoFrame(uint32_t, llm:OS::Foundation::Numerics::float3*, uint32_t, llm:OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall UnprojectPixelsAtUnitDepth(uint32_t, llm:OS::Foundation::Point*, uint32_t, llm:OS::Foundation::Numerics::float2*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::ICameraIntrinsics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UndistortedProjectionTransform(llm:OS::Foundation::Numerics::float4x4*) noexcept = 0;
            virtual int32_t __stdcall DistortPoint(llm:OS::Foundation::Point, llm:OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall DistortPoints(uint32_t, llm:OS::Foundation::Point*, uint32_t, llm:OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall UndistortPoint(llm:OS::Foundation::Point, llm:OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall UndistortPoints(uint32_t, llm:OS::Foundation::Point*, uint32_t, llm:OS::Foundation::Point*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::ICameraIntrinsicsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(llm:OS::Foundation::Numerics::float2, llm:OS::Foundation::Numerics::float2, llm:OS::Foundation::Numerics::float3, llm:OS::Foundation::Numerics::float2, uint32_t, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall UnprojectPoint(llm:OS::Foundation::Point, void*, llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall UnprojectPoints(uint32_t, llm:OS::Foundation::Point*, void*, uint32_t, llm:OS::Foundation::Numerics::float3*) noexcept = 0;
            virtual int32_t __stdcall MapPoint(llm:OS::Foundation::Point, void*, void*, llm:OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall MapPoints(uint32_t, llm:OS::Foundation::Point*, void*, void*, uint32_t, llm:OS::Foundation::Point*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameControlCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Exposure(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExposureCompensation(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsoSpeed(void**) noexcept = 0;
            virtual int32_t __stdcall get_Focus(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhotoConfirmationSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameControlCapabilities2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Flash(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExposureControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExposureCompensationControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsoSpeedControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_FocusControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhotoConfirmationEnabled(void**) noexcept = 0;
            virtual int32_t __stdcall put_PhotoConfirmationEnabled(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameController2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FlashControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameExposureCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Min(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Max(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Step(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Min(float*) noexcept = 0;
            virtual int32_t __stdcall get_Max(float*) noexcept = 0;
            virtual int32_t __stdcall get_Step(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameExposureCompensationControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameExposureControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Auto(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Auto(bool) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameFlashCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_RedEyeReductionSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_PowerSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameFlashControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Auto(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Auto(bool) noexcept = 0;
            virtual int32_t __stdcall get_RedEyeReduction(bool*) noexcept = 0;
            virtual int32_t __stdcall put_RedEyeReduction(bool) noexcept = 0;
            virtual int32_t __stdcall get_PowerPercent(float*) noexcept = 0;
            virtual int32_t __stdcall put_PowerPercent(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameFocusCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Min(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Max(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Step(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameFocusControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Min(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Max(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Step(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IFrameIsoSpeedControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Auto(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Auto(bool) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::Core::IVariablePhotoSequenceController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPhotosPerSecond(float*) noexcept = 0;
            virtual int32_t __stdcall get_PhotosPerSecondLimit(float*) noexcept = 0;
            virtual int32_t __stdcall put_PhotosPerSecondLimit(float) noexcept = 0;
            virtual int32_t __stdcall GetHighestConcurrentFrameRate(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentFrameRate(void**) noexcept = 0;
            virtual int32_t __stdcall get_FrameCapabilities(void**) noexcept = 0;
            virtual int32_t __stdcall get_DesiredFrameControllers(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_ICameraIntrinsics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) FocalLength() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) PrincipalPoint() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) RadialDistortion() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) TangentialDistortion() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ImageWidth() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ImageHeight() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Point) ProjectOntoFrame(llm:OS::Foundation::Numerics::float3 const& coordinate) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float2) UnprojectAtUnitDepth(llm:OS::Foundation::Point const& pixelCoordinate) const;
        LLM_IMPL_AUTO(void) ProjectManyOntoFrame(array_view<llm:OS::Foundation::Numerics::float3 const> coordinates, array_view<llm:OS::Foundation::Point> results) const;
        LLM_IMPL_AUTO(void) UnprojectPixelsAtUnitDepth(array_view<llm:OS::Foundation::Point const> pixelCoordinates, array_view<llm:OS::Foundation::Numerics::float2> results) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::ICameraIntrinsics>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_ICameraIntrinsics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float4x4) UndistortedProjectionTransform() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Point) DistortPoint(llm:OS::Foundation::Point const& input) const;
        LLM_IMPL_AUTO(void) DistortPoints(array_view<llm:OS::Foundation::Point const> inputs, array_view<llm:OS::Foundation::Point> results) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Point) UndistortPoint(llm:OS::Foundation::Point const& input) const;
        LLM_IMPL_AUTO(void) UndistortPoints(array_view<llm:OS::Foundation::Point const> inputs, array_view<llm:OS::Foundation::Point> results) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::ICameraIntrinsics2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_ICameraIntrinsics2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_ICameraIntrinsicsFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::CameraIntrinsics) Create(llm:OS::Foundation::Numerics::float2 const& focalLength, llm:OS::Foundation::Numerics::float2 const& principalPoint, llm:OS::Foundation::Numerics::float3 const& radialDistortion, llm:OS::Foundation::Numerics::float2 const& tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::ICameraIntrinsicsFactory>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_ICameraIntrinsicsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IDepthCorrelatedCoordinateMapper
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::float3) UnprojectPoint(llm:OS::Foundation::Point const& sourcePoint, llm:OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem) const;
        LLM_IMPL_AUTO(void) UnprojectPoints(array_view<llm:OS::Foundation::Point const> sourcePoints, llm:OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem, array_view<llm:OS::Foundation::Numerics::float3> results) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Point) MapPoint(llm:OS::Foundation::Point const& sourcePoint, llm:OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem, llm:OS::Media::Devices::Core::CameraIntrinsics const& targetCameraIntrinsics) const;
        LLM_IMPL_AUTO(void) MapPoints(array_view<llm:OS::Foundation::Point const> sourcePoints, llm:OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem, llm:OS::Media::Devices::Core::CameraIntrinsics const& targetCameraIntrinsics, array_view<llm:OS::Foundation::Point> results) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IDepthCorrelatedCoordinateMapper<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameControlCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameExposureCapabilities) Exposure() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameExposureCompensationCapabilities) ExposureCompensation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameIsoSpeedCapabilities) IsoSpeed() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameFocusCapabilities) Focus() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) PhotoConfirmationSupported() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameControlCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameControlCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameControlCapabilities2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameFlashCapabilities) Flash() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameControlCapabilities2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameControlCapabilities2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameController
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameExposureControl) ExposureControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameExposureCompensationControl) ExposureCompensationControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameIsoSpeedControl) IsoSpeedControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameFocusControl) FocusControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<bool>) PhotoConfirmationEnabled() const;
        LLM_IMPL_AUTO(void) PhotoConfirmationEnabled(llm:OS::Foundation::IReference<bool> const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameController>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameController<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameController2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameFlashControl) FlashControl() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameController2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameController2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameExposureCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Step() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameExposureCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameExposureCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameExposureCompensationCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Step() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameExposureCompensationCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameExposureCompensationControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<float>) Value() const;
        LLM_IMPL_AUTO(void) Value(llm:OS::Foundation::IReference<float> const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameExposureCompensationControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameExposureCompensationControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameExposureControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Auto() const;
        LLM_IMPL_AUTO(void) Auto(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::TimeSpan>) Value() const;
        LLM_IMPL_AUTO(void) Value(llm:OS::Foundation::IReference<llm:OS::Foundation::TimeSpan> const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameExposureControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameExposureControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameFlashCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) RedEyeReductionSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) PowerSupported() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameFlashCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameFlashCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameFlashControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameFlashMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Devices::Core::FrameFlashMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Auto() const;
        LLM_IMPL_AUTO(void) Auto(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) RedEyeReduction() const;
        LLM_IMPL_AUTO(void) RedEyeReduction(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) PowerPercent() const;
        LLM_IMPL_AUTO(void) PowerPercent(float value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameFlashControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameFlashControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameFocusCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Step() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameFocusCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameFocusCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameFocusControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<uint32_t>) Value() const;
        LLM_IMPL_AUTO(void) Value(llm:OS::Foundation::IReference<uint32_t> const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameFocusControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameFocusControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameIsoSpeedCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Step() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameIsoSpeedCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IFrameIsoSpeedControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Auto() const;
        LLM_IMPL_AUTO(void) Auto(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<uint32_t>) Value() const;
        LLM_IMPL_AUTO(void) Value(llm:OS::Foundation::IReference<uint32_t> const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IFrameIsoSpeedControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IFrameIsoSpeedControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxPhotosPerSecond() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) PhotosPerSecondLimit() const;
        LLM_IMPL_AUTO(void) PhotosPerSecondLimit(float value) const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaRatio) GetHighestConcurrentFrameRate(llm:OS::Media::MediaProperties::IMediaEncodingProperties const& captureProperties) const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaRatio) GetCurrentFrameRate() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::FrameControlCapabilities) FrameCapabilities() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Devices::Core::FrameController>) DesiredFrameControllers() const;
    };
    template <> struct consume<llm:OS::Media::Devices::Core::IVariablePhotoSequenceController>
    {
        template <typename D> using type = consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>;
    };
}
#endif
