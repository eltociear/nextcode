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
#ifndef LLM_OS_Devices_Printers_0_H
#define LLM_OS_Devices_Printers_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct HResult;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IKeyValuePair;
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Graphics::Printing
{
    struct PrintTaskOptions;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IBuffer;
    struct IInputStream;
    struct IOutputStream;
    struct IRandomAccessStreamWithContentType;
}
LLM_EXPORT namespace llm::OS::Devices::Printers
{
    enum class IppAttributeErrorReason : int32_t
    {
        RequestEntityTooLarge = 0,
        AttributeNotSupported = 1,
        AttributeValuesNotSupported = 2,
        AttributeNotSettable = 3,
        ConflictingAttributes = 4,
    };
    enum class IppAttributeValueKind : int32_t
    {
        Unsupported = 0,
        Unknown = 1,
        NoValue = 2,
        Integer = 3,
        Boolean = 4,
        Enum = 5,
        OctetString = 6,
        DateTime = 7,
        Resolution = 8,
        RangeOfInteger = 9,
        Collection = 10,
        TextWithLanguage = 11,
        NameWithLanguage = 12,
        TextWithoutLanguage = 13,
        NameWithoutLanguage = 14,
        Keyword = 15,
        Uri = 16,
        UriSchema = 17,
        Charset = 18,
        NaturalLanguage = 19,
        MimeMediaType = 20,
    };
    enum class IppResolutionUnit : int32_t
    {
        DotsPerInch = 0,
        DotsPerCentimeter = 1,
    };
    enum class PageConfigurationSource : int32_t
    {
        PrintJobConfiguration = 0,
        PdlContent = 1,
    };
    struct IIppAttributeError;
    struct IIppAttributeValue;
    struct IIppAttributeValueStatics;
    struct IIppIntegerRange;
    struct IIppIntegerRangeFactory;
    struct IIppPrintDevice;
    struct IIppPrintDevice2;
    struct IIppPrintDeviceStatics;
    struct IIppResolution;
    struct IIppResolutionFactory;
    struct IIppSetAttributesResult;
    struct IIppTextWithLanguage;
    struct IIppTextWithLanguageFactory;
    struct IPageConfigurationSettings;
    struct IPdlPassthroughProvider;
    struct IPdlPassthroughTarget;
    struct IPrint3DDevice;
    struct IPrint3DDeviceStatics;
    struct IPrintSchema;
    struct IppAttributeError;
    struct IppAttributeValue;
    struct IppIntegerRange;
    struct IppPrintDevice;
    struct IppResolution;
    struct IppSetAttributesResult;
    struct IppTextWithLanguage;
    struct PageConfigurationSettings;
    struct PdlPassthroughProvider;
    struct PdlPassthroughTarget;
    struct Print3DDevice;
    struct PrintSchema;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Printers::IIppAttributeError>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppAttributeValue>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppAttributeValueStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppIntegerRange>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppIntegerRangeFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppPrintDevice>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppPrintDevice2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppPrintDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppResolution>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppResolutionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppSetAttributesResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppTextWithLanguage>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IIppTextWithLanguageFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IPageConfigurationSettings>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IPdlPassthroughProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IPdlPassthroughTarget>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IPrint3DDevice>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IPrint3DDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IPrintSchema>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Printers::IppAttributeError>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::IppAttributeValue>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::IppIntegerRange>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::IppPrintDevice>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::IppResolution>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::IppSetAttributesResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::IppTextWithLanguage>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::PageConfigurationSettings>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::PdlPassthroughProvider>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::PdlPassthroughTarget>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::Print3DDevice>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::PrintSchema>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Printers::IppAttributeErrorReason>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Printers::IppAttributeValueKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Printers::IppResolutionUnit>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Printers::PageConfigurationSource>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppAttributeError> = L"Windows.Devices.Printers.IppAttributeError";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppAttributeValue> = L"Windows.Devices.Printers.IppAttributeValue";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppIntegerRange> = L"Windows.Devices.Printers.IppIntegerRange";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppPrintDevice> = L"Windows.Devices.Printers.IppPrintDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppResolution> = L"Windows.Devices.Printers.IppResolution";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppSetAttributesResult> = L"Windows.Devices.Printers.IppSetAttributesResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppTextWithLanguage> = L"Windows.Devices.Printers.IppTextWithLanguage";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::PageConfigurationSettings> = L"Windows.Devices.Printers.PageConfigurationSettings";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::PdlPassthroughProvider> = L"Windows.Devices.Printers.PdlPassthroughProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::PdlPassthroughTarget> = L"Windows.Devices.Printers.PdlPassthroughTarget";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::Print3DDevice> = L"Windows.Devices.Printers.Print3DDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::PrintSchema> = L"Windows.Devices.Printers.PrintSchema";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppAttributeErrorReason> = L"Windows.Devices.Printers.IppAttributeErrorReason";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppAttributeValueKind> = L"Windows.Devices.Printers.IppAttributeValueKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IppResolutionUnit> = L"Windows.Devices.Printers.IppResolutionUnit";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::PageConfigurationSource> = L"Windows.Devices.Printers.PageConfigurationSource";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppAttributeError> = L"Windows.Devices.Printers.IIppAttributeError";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppAttributeValue> = L"Windows.Devices.Printers.IIppAttributeValue";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppAttributeValueStatics> = L"Windows.Devices.Printers.IIppAttributeValueStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppIntegerRange> = L"Windows.Devices.Printers.IIppIntegerRange";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppIntegerRangeFactory> = L"Windows.Devices.Printers.IIppIntegerRangeFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppPrintDevice> = L"Windows.Devices.Printers.IIppPrintDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppPrintDevice2> = L"Windows.Devices.Printers.IIppPrintDevice2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppPrintDeviceStatics> = L"Windows.Devices.Printers.IIppPrintDeviceStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppResolution> = L"Windows.Devices.Printers.IIppResolution";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppResolutionFactory> = L"Windows.Devices.Printers.IIppResolutionFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppSetAttributesResult> = L"Windows.Devices.Printers.IIppSetAttributesResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppTextWithLanguage> = L"Windows.Devices.Printers.IIppTextWithLanguage";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IIppTextWithLanguageFactory> = L"Windows.Devices.Printers.IIppTextWithLanguageFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IPageConfigurationSettings> = L"Windows.Devices.Printers.IPageConfigurationSettings";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IPdlPassthroughProvider> = L"Windows.Devices.Printers.IPdlPassthroughProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IPdlPassthroughTarget> = L"Windows.Devices.Printers.IPdlPassthroughTarget";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IPrint3DDevice> = L"Windows.Devices.Printers.IPrint3DDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IPrint3DDeviceStatics> = L"Windows.Devices.Printers.IPrint3DDeviceStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Printers::IPrintSchema> = L"Windows.Devices.Printers.IPrintSchema";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppAttributeError>{ 0x750FEDA1,0x9EEF,0x5C39,{ 0x93,0xE4,0x46,0x14,0x9B,0xBC,0xEF,0x27 } }; // 750FEDA1-9EEF-5C39-93E4-46149BBCEF27
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppAttributeValue>{ 0x99407FED,0xE2BB,0x59A3,{ 0x98,0x8B,0x28,0xA9,0x74,0x05,0x2A,0x26 } }; // 99407FED-E2BB-59A3-988B-28A974052A26
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppAttributeValueStatics>{ 0x10D43942,0xDD94,0x5998,{ 0xB2,0x35,0xAF,0xAF,0xB6,0xFA,0x79,0x35 } }; // 10D43942-DD94-5998-B235-AFAFB6FA7935
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppIntegerRange>{ 0x92907346,0xC3EA,0x5ED6,{ 0xBD,0xB1,0x37,0x52,0xC6,0x2C,0x6F,0x7F } }; // 92907346-C3EA-5ED6-BDB1-3752C62C6F7F
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppIntegerRangeFactory>{ 0x75D4ECAE,0xF87E,0x54AD,{ 0xB5,0xD0,0x46,0x52,0x04,0xDB,0x75,0x53 } }; // 75D4ECAE-F87E-54AD-B5D0-465204DB7553
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppPrintDevice>{ 0xD748AC56,0x76F3,0x5DC6,{ 0xAF,0xD4,0xC2,0xA8,0x68,0x6B,0x93,0x59 } }; // D748AC56-76F3-5DC6-AFD4-C2A8686B9359
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppPrintDevice2>{ 0xF7C844C9,0x9D21,0x5C63,{ 0xAC,0x20,0x36,0x76,0x91,0x5B,0xE2,0xD7 } }; // F7C844C9-9D21-5C63-AC20-3676915BE2D7
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppPrintDeviceStatics>{ 0x7DC19F08,0x7F20,0x52AB,{ 0x94,0xA7,0x89,0x4B,0x83,0xB2,0xA1,0x7E } }; // 7DC19F08-7F20-52AB-94A7-894B83B2A17E
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppResolution>{ 0xCB493F86,0x6BF3,0x56F5,{ 0x86,0xCE,0x26,0x3D,0x08,0xAE,0xAD,0x63 } }; // CB493F86-6BF3-56F5-86CE-263D08AEAD63
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppResolutionFactory>{ 0xE481C2AE,0x251A,0x5326,{ 0xB1,0x73,0x95,0x54,0x3E,0xD9,0x9A,0x35 } }; // E481C2AE-251A-5326-B173-95543ED99A35
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppSetAttributesResult>{ 0x7D1C7F55,0xAA9D,0x58A3,{ 0x90,0xE9,0x17,0xBD,0xC5,0x28,0x1F,0x07 } }; // 7D1C7F55-AA9D-58A3-90E9-17BDC5281F07
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppTextWithLanguage>{ 0x326447A6,0x5149,0x5936,{ 0x90,0xE8,0x0C,0x73,0x60,0x36,0xBF,0x77 } }; // 326447A6-5149-5936-90E8-0C736036BF77
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IIppTextWithLanguageFactory>{ 0xCA4A1E8D,0x2968,0x5775,{ 0x99,0x7C,0x8A,0x46,0xF1,0xA5,0x74,0xED } }; // CA4A1E8D-2968-5775-997C-8A46F1A574ED
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IPageConfigurationSettings>{ 0xB6FC1E02,0x5331,0x54FF,{ 0x95,0xA0,0x1F,0xCB,0x76,0xBB,0x97,0xA9 } }; // B6FC1E02-5331-54FF-95A0-1FCB76BB97A9
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IPdlPassthroughProvider>{ 0x23C71DD2,0x6117,0x553F,{ 0x93,0x78,0x18,0x0A,0xF5,0x84,0x9A,0x49 } }; // 23C71DD2-6117-553F-9378-180AF5849A49
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IPdlPassthroughTarget>{ 0x9840BE79,0x67F8,0x5385,{ 0xA5,0xB9,0xE8,0xC9,0x6E,0x0F,0xCA,0x76 } }; // 9840BE79-67F8-5385-A5B9-E8C96E0FCA76
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IPrint3DDevice>{ 0x041C3D19,0x9713,0x42A2,{ 0x98,0x13,0x7D,0xC3,0x33,0x74,0x28,0xD3 } }; // 041C3D19-9713-42A2-9813-7DC3337428D3
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IPrint3DDeviceStatics>{ 0xFDE3620A,0x67CD,0x41B7,{ 0xA3,0x44,0x51,0x50,0xA1,0xFD,0x75,0xB5 } }; // FDE3620A-67CD-41B7-A344-5150A1FD75B5
    template <> inline constexpr guid guid_v<llm::OS::Devices::Printers::IPrintSchema>{ 0xC2B98316,0x26B8,0x4BFB,{ 0x81,0x38,0x9F,0x96,0x2C,0x22,0xA3,0x5B } }; // C2B98316-26B8-4BFB-8138-9F962C22A35B
    template <> struct default_interface<llm::OS::Devices::Printers::IppAttributeError>{ using type = llm::OS::Devices::Printers::IIppAttributeError; };
    template <> struct default_interface<llm::OS::Devices::Printers::IppAttributeValue>{ using type = llm::OS::Devices::Printers::IIppAttributeValue; };
    template <> struct default_interface<llm::OS::Devices::Printers::IppIntegerRange>{ using type = llm::OS::Devices::Printers::IIppIntegerRange; };
    template <> struct default_interface<llm::OS::Devices::Printers::IppPrintDevice>{ using type = llm::OS::Devices::Printers::IIppPrintDevice; };
    template <> struct default_interface<llm::OS::Devices::Printers::IppResolution>{ using type = llm::OS::Devices::Printers::IIppResolution; };
    template <> struct default_interface<llm::OS::Devices::Printers::IppSetAttributesResult>{ using type = llm::OS::Devices::Printers::IIppSetAttributesResult; };
    template <> struct default_interface<llm::OS::Devices::Printers::IppTextWithLanguage>{ using type = llm::OS::Devices::Printers::IIppTextWithLanguage; };
    template <> struct default_interface<llm::OS::Devices::Printers::PageConfigurationSettings>{ using type = llm::OS::Devices::Printers::IPageConfigurationSettings; };
    template <> struct default_interface<llm::OS::Devices::Printers::PdlPassthroughProvider>{ using type = llm::OS::Devices::Printers::IPdlPassthroughProvider; };
    template <> struct default_interface<llm::OS::Devices::Printers::PdlPassthroughTarget>{ using type = llm::OS::Devices::Printers::IPdlPassthroughTarget; };
    template <> struct default_interface<llm::OS::Devices::Printers::Print3DDevice>{ using type = llm::OS::Devices::Printers::IPrint3DDevice; };
    template <> struct default_interface<llm::OS::Devices::Printers::PrintSchema>{ using type = llm::OS::Devices::Printers::IPrintSchema; };
    template <> struct abi<llm::OS::Devices::Printers::IIppAttributeError>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall GetUnsupportedValues(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppAttributeValue>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetIntegerArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetBooleanArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetEnumArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetOctetStringArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetDateTimeArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetResolutionArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetRangeOfIntegerArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetCollectionArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetTextWithLanguageArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetNameWithLanguageArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetTextWithoutLanguageArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetNameWithoutLanguageArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetKeywordArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetUriArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetUriSchemaArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetCharsetArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetNaturalLanguageArray(void**) noexcept = 0;
            virtual int32_t __stdcall GetMimeMediaTypeArray(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppAttributeValueStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateUnsupported(void**) noexcept = 0;
            virtual int32_t __stdcall CreateUnknown(void**) noexcept = 0;
            virtual int32_t __stdcall CreateNoValue(void**) noexcept = 0;
            virtual int32_t __stdcall CreateInteger(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateIntegerArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBoolean(bool, void**) noexcept = 0;
            virtual int32_t __stdcall CreateBooleanArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateEnum(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateEnumArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateOctetString(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateOctetStringArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDateTime(int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDateTimeArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateResolution(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateResolutionArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateRangeOfInteger(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateRangeOfIntegerArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCollection(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCollectionArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTextWithLanguage(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTextWithLanguageArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateNameWithLanguage(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateNameWithLanguageArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTextWithoutLanguage(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateTextWithoutLanguageArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateNameWithoutLanguage(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateNameWithoutLanguageArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateKeyword(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateKeywordArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUri(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUriArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUriSchema(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateUriSchemaArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCharset(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCharsetArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateNaturalLanguage(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateNaturalLanguageArray(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateMimeMedia(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateMimeMediaArray(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppIntegerRange>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Start(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_End(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppIntegerRangeFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppPrintDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PrinterName(void**) noexcept = 0;
            virtual int32_t __stdcall get_PrinterUri(void**) noexcept = 0;
            virtual int32_t __stdcall GetPrinterAttributesAsBuffer(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetPrinterAttributes(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetPrinterAttributesFromBuffer(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetPrinterAttributes(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppPrintDevice2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetMaxSupportedPdfSize(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall GetMaxSupportedPdfVersion(void**) noexcept = 0;
            virtual int32_t __stdcall IsPdlPassthroughSupported(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall GetPdlPassthroughProvider(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppPrintDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
            virtual int32_t __stdcall FromId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FromPrinterName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall IsIppPrinter(void*, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppResolution>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Width(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Height(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Unit(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppResolutionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(int32_t, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppSetAttributesResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AttributeErrors(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppTextWithLanguage>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Language(void**) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IIppTextWithLanguageFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IPageConfigurationSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OrientationSource(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_OrientationSource(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SizeSource(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SizeSource(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IPdlPassthroughProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SupportedPdlContentTypes(void**) noexcept = 0;
            virtual int32_t __stdcall StartPrintJobWithTaskOptions(void*, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall StartPrintJobWithPrintTicket(void*, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IPdlPassthroughTarget>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PrintJobId(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetOutputStream(void**) noexcept = 0;
            virtual int32_t __stdcall Submit() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IPrint3DDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PrintSchema(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IPrint3DDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Printers::IPrintSchema>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefaultPrintTicketAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetCapabilitiesAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall MergeAndValidateWithDefaultPrintTicketAsync(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppAttributeError
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeErrorReason) Reason() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Printers::IppAttributeValue>) GetUnsupportedValues() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppAttributeError>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppAttributeError<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppAttributeValue
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValueKind) Kind() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<int32_t>) GetIntegerArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<bool>) GetBooleanArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<int32_t>) GetEnumArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Storage::Streams::IBuffer>) GetOctetStringArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::DateTime>) GetDateTimeArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Printers::IppResolution>) GetResolutionArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Printers::IppIntegerRange>) GetRangeOfIntegerArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Devices::Printers::IppAttributeValue>>) GetCollectionArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Printers::IppTextWithLanguage>) GetTextWithLanguageArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Printers::IppTextWithLanguage>) GetNameWithLanguageArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetTextWithoutLanguageArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetNameWithoutLanguageArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetKeywordArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>) GetUriArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetUriSchemaArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetCharsetArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetNaturalLanguageArray() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetMimeMediaTypeArray() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppAttributeValue>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppAttributeValue<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppAttributeValueStatics
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateUnsupported() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateUnknown() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateNoValue() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateInteger(int32_t value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateIntegerArray(param::iterable<int32_t> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateBoolean(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateBooleanArray(param::iterable<bool> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateEnum(int32_t value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateEnumArray(param::iterable<int32_t> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateOctetString(llm::OS::Storage::Streams::IBuffer const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateOctetStringArray(param::iterable<llm::OS::Storage::Streams::IBuffer> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateDateTime(llm::OS::Foundation::DateTime const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateDateTimeArray(param::iterable<llm::OS::Foundation::DateTime> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateResolution(llm::OS::Devices::Printers::IppResolution const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateResolutionArray(param::iterable<llm::OS::Devices::Printers::IppResolution> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateRangeOfInteger(llm::OS::Devices::Printers::IppIntegerRange const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateRangeOfIntegerArray(param::iterable<llm::OS::Devices::Printers::IppIntegerRange> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateCollection(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Devices::Printers::IppAttributeValue>> const& memberAttributes) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateCollectionArray(param::iterable<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Devices::Printers::IppAttributeValue>>> const& memberAttributesArray) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateTextWithLanguage(llm::OS::Devices::Printers::IppTextWithLanguage const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateTextWithLanguageArray(param::iterable<llm::OS::Devices::Printers::IppTextWithLanguage> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateNameWithLanguage(llm::OS::Devices::Printers::IppTextWithLanguage const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateNameWithLanguageArray(param::iterable<llm::OS::Devices::Printers::IppTextWithLanguage> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateTextWithoutLanguage(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateTextWithoutLanguageArray(param::iterable<hstring> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateNameWithoutLanguage(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateNameWithoutLanguageArray(param::iterable<hstring> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateKeyword(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateKeywordArray(param::iterable<hstring> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateUri(llm::OS::Foundation::Uri const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateUriArray(param::iterable<llm::OS::Foundation::Uri> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateUriSchema(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateUriSchemaArray(param::iterable<hstring> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateCharset(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateCharsetArray(param::iterable<hstring> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateNaturalLanguage(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateNaturalLanguageArray(param::iterable<hstring> const& values) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateMimeMedia(param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppAttributeValue) CreateMimeMediaArray(param::iterable<hstring> const& values) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppAttributeValueStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppAttributeValueStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppIntegerRange
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Start() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) End() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppIntegerRange>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppIntegerRange<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppIntegerRangeFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppIntegerRange) CreateInstance(int32_t start, int32_t end) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppIntegerRangeFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppIntegerRangeFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppPrintDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PrinterName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) PrinterUri() const;
        LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) GetPrinterAttributesAsBuffer(param::iterable<hstring> const& attributeNames) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Devices::Printers::IppAttributeValue>) GetPrinterAttributes(param::iterable<hstring> const& attributeNames) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppSetAttributesResult) SetPrinterAttributesFromBuffer(llm::OS::Storage::Streams::IBuffer const& printerAttributesBuffer) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppSetAttributesResult) SetPrinterAttributes(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Devices::Printers::IppAttributeValue>> const& printerAttributes) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppPrintDevice>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppPrintDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppPrintDevice2
    {
        LLM_IMPL_AUTO(uint64_t) GetMaxSupportedPdfSize() const;
        LLM_IMPL_AUTO(hstring) GetMaxSupportedPdfVersion() const;
        LLM_IMPL_AUTO(bool) IsPdlPassthroughSupported(param::hstring const& pdlContentType) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::PdlPassthroughProvider) GetPdlPassthroughProvider() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppPrintDevice2>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppPrintDevice2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppPrintDeviceStatics
    {
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppPrintDevice) FromId(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppPrintDevice) FromPrinterName(param::hstring const& printerName) const;
        LLM_IMPL_AUTO(bool) IsIppPrinter(param::hstring const& printerName) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppPrintDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppPrintDeviceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppResolution
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Width() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Height() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppResolutionUnit) Unit() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppResolution>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppResolution<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppResolutionFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppResolution) CreateInstance(int32_t width, int32_t height, llm::OS::Devices::Printers::IppResolutionUnit const& unit) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppResolutionFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppResolutionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppSetAttributesResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Devices::Printers::IppAttributeError>) AttributeErrors() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppSetAttributesResult>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppSetAttributesResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppTextWithLanguage
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Language() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Value() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppTextWithLanguage>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppTextWithLanguage<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IIppTextWithLanguageFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::IppTextWithLanguage) CreateInstance(param::hstring const& language, param::hstring const& text) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IIppTextWithLanguageFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IIppTextWithLanguageFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IPageConfigurationSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Printers::PageConfigurationSource) OrientationSource() const;
        LLM_IMPL_AUTO(void) OrientationSource(llm::OS::Devices::Printers::PageConfigurationSource const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Printers::PageConfigurationSource) SizeSource() const;
        LLM_IMPL_AUTO(void) SizeSource(llm::OS::Devices::Printers::PageConfigurationSource const& value) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IPageConfigurationSettings>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IPageConfigurationSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IPdlPassthroughProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) SupportedPdlContentTypes() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::PdlPassthroughTarget) StartPrintJobWithTaskOptions(param::hstring const& jobName, param::hstring const& pdlContentType, llm::OS::Graphics::Printing::PrintTaskOptions const& taskOptions, llm::OS::Devices::Printers::PageConfigurationSettings const& pageConfigurationSettings) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Printers::PdlPassthroughTarget) StartPrintJobWithPrintTicket(param::hstring const& jobName, param::hstring const& pdlContentType, llm::OS::Storage::Streams::IInputStream const& printTicket, llm::OS::Devices::Printers::PageConfigurationSettings const& pageConfigurationSettings) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IPdlPassthroughProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IPdlPassthroughProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IPdlPassthroughTarget
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) PrintJobId() const;
        LLM_IMPL_AUTO(llm::OS::Storage::Streams::IOutputStream) GetOutputStream() const;
        LLM_IMPL_AUTO(void) Submit() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IPdlPassthroughTarget>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IPdlPassthroughTarget<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IPrint3DDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Printers::PrintSchema) PrintSchema() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IPrint3DDevice>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IPrint3DDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IPrint3DDeviceStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Printers::Print3DDevice>) FromIdAsync(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IPrint3DDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IPrint3DDeviceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Printers_IPrintSchema
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType>) GetDefaultPrintTicketAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType>) GetCapabilitiesAsync(llm::OS::Storage::Streams::IRandomAccessStreamWithContentType const& constrainTicket) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType>) MergeAndValidateWithDefaultPrintTicketAsync(llm::OS::Storage::Streams::IRandomAccessStreamWithContentType const& deltaTicket) const;
    };
    template <> struct consume<llm::OS::Devices::Printers::IPrintSchema>
    {
        template <typename D> using type = consume_Windows_Devices_Printers_IPrintSchema<D>;
    };
}
#endif
