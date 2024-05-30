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
#ifndef LLM_OS_Media_MediaProperties_2_H
#define LLM_OS_Media_MediaProperties_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Media.MediaProperties.1.h"
LLM_EXPORT namespace llm:OS::Media::MediaProperties
{
    struct __declspec(empty_bases) AudioEncodingProperties : llm:OS::Media::MediaProperties::IAudioEncodingProperties,
        impl::require<AudioEncodingProperties, llm:OS::Media::MediaProperties::IAudioEncodingPropertiesWithFormatUserData, llm:OS::Media::MediaProperties::IAudioEncodingProperties2, llm:OS::Media::MediaProperties::IAudioEncodingProperties3>
    {
        AudioEncodingProperties(std::nullptr_t) noexcept {}
        AudioEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::MediaProperties::IAudioEncodingProperties(ptr, take_ownership_from_abi) {}
        AudioEncodingProperties();
        static auto CreateAac(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
        static auto CreateAacAdts(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
        static auto CreateMp3(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
        static auto CreatePcm(uint32_t sampleRate, uint32_t channelCount, uint32_t bitsPerSample);
        static auto CreateWma(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
        static auto CreateAlac(uint32_t sampleRate, uint32_t channelCount, uint32_t bitsPerSample);
        static auto CreateFlac(uint32_t sampleRate, uint32_t channelCount, uint32_t bitsPerSample);
    };
    struct Av1ProfileIds
    {
        Av1ProfileIds() = delete;
        [[nodiscard]] static auto MainChromaSubsampling420BitDepth8();
        [[nodiscard]] static auto MainChromaSubsampling420BitDepth10();
        [[nodiscard]] static auto MainChromaSubsampling400BitDepth8();
        [[nodiscard]] static auto MainChromaSubsampling400BitDepth10();
        [[nodiscard]] static auto HighChromaSubsampling444BitDepth8();
        [[nodiscard]] static auto HighChromaSubsampling444BitDepth10();
        [[nodiscard]] static auto ProfessionalChromaSubsampling420BitDepth12();
        [[nodiscard]] static auto ProfessionalChromaSubsampling400BitDepth12();
        [[nodiscard]] static auto ProfessionalChromaSubsampling444BitDepth12();
        [[nodiscard]] static auto ProfessionalChromaSubsampling422BitDepth8();
        [[nodiscard]] static auto ProfessionalChromaSubsampling422BitDepth10();
        [[nodiscard]] static auto ProfessionalChromaSubsampling422BitDepth12();
    };
    struct __declspec(empty_bases) ContainerEncodingProperties : llm:OS::Media::MediaProperties::IContainerEncodingProperties,
        impl::require<ContainerEncodingProperties, llm:OS::Media::MediaProperties::IContainerEncodingProperties2>
    {
        ContainerEncodingProperties(std::nullptr_t) noexcept {}
        ContainerEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::MediaProperties::IContainerEncodingProperties(ptr, take_ownership_from_abi) {}
        ContainerEncodingProperties();
    };
    struct H264ProfileIds
    {
        H264ProfileIds() = delete;
        [[nodiscard]] static auto ConstrainedBaseline();
        [[nodiscard]] static auto Baseline();
        [[nodiscard]] static auto Extended();
        [[nodiscard]] static auto Main();
        [[nodiscard]] static auto High();
        [[nodiscard]] static auto High10();
        [[nodiscard]] static auto High422();
        [[nodiscard]] static auto High444();
        [[nodiscard]] static auto StereoHigh();
        [[nodiscard]] static auto MultiviewHigh();
    };
    struct HevcProfileIds
    {
        HevcProfileIds() = delete;
        [[nodiscard]] static auto MainChromaSubsampling420BitDepth8();
        [[nodiscard]] static auto MainChromaSubsampling420BitDepth10();
        [[nodiscard]] static auto MainChromaSubsampling420BitDepth12();
        [[nodiscard]] static auto MainChromaSubsampling422BitDepth10();
        [[nodiscard]] static auto MainChromaSubsampling422BitDepth12();
        [[nodiscard]] static auto MainChromaSubsampling444BitDepth8();
        [[nodiscard]] static auto MainChromaSubsampling444BitDepth10();
        [[nodiscard]] static auto MainChromaSubsampling444BitDepth12();
        [[nodiscard]] static auto MonochromeBitDepth12();
        [[nodiscard]] static auto MonochromeBitDepth16();
        [[nodiscard]] static auto MainIntraChromaSubsampling420BitDepth8();
        [[nodiscard]] static auto MainIntraChromaSubsampling420BitDepth10();
        [[nodiscard]] static auto MainIntraChromaSubsampling420BitDepth12();
        [[nodiscard]] static auto MainIntraChromaSubsampling422BitDepth10();
        [[nodiscard]] static auto MainIntraChromaSubsampling422BitDepth12();
        [[nodiscard]] static auto MainIntraChromaSubsampling444BitDepth8();
        [[nodiscard]] static auto MainIntraChromaSubsampling444BitDepth10();
        [[nodiscard]] static auto MainIntraChromaSubsampling444BitDepth12();
        [[nodiscard]] static auto MainIntraChromaSubsampling444BitDepth16();
        [[nodiscard]] static auto MainStillChromaSubsampling420BitDepth8();
        [[nodiscard]] static auto MainStillChromaSubsampling444BitDepth8();
        [[nodiscard]] static auto MainStillChromaSubsampling444BitDepth16();
    };
    struct __declspec(empty_bases) ImageEncodingProperties : llm:OS::Media::MediaProperties::IImageEncodingProperties,
        impl::require<ImageEncodingProperties, llm:OS::Media::MediaProperties::IImageEncodingProperties2>
    {
        ImageEncodingProperties(std::nullptr_t) noexcept {}
        ImageEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::MediaProperties::IImageEncodingProperties(ptr, take_ownership_from_abi) {}
        ImageEncodingProperties();
        static auto CreateJpeg();
        static auto CreatePng();
        static auto CreateJpegXR();
        static auto CreateUncompressed(llm:OS::Media::MediaProperties::MediaPixelFormat const& format);
        static auto CreateBmp();
        static auto CreateHeif();
    };
    struct __declspec(empty_bases) MediaEncodingProfile : llm:OS::Media::MediaProperties::IMediaEncodingProfile,
        impl::require<MediaEncodingProfile, llm:OS::Media::MediaProperties::IMediaEncodingProfile2, llm:OS::Media::MediaProperties::IMediaEncodingProfile3>
    {
        MediaEncodingProfile(std::nullptr_t) noexcept {}
        MediaEncodingProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::MediaProperties::IMediaEncodingProfile(ptr, take_ownership_from_abi) {}
        MediaEncodingProfile();
        static auto CreateM4a(llm:OS::Media::MediaProperties::AudioEncodingQuality const& quality);
        static auto CreateMp3(llm:OS::Media::MediaProperties::AudioEncodingQuality const& quality);
        static auto CreateWma(llm:OS::Media::MediaProperties::AudioEncodingQuality const& quality);
        static auto CreateMp4(llm:OS::Media::MediaProperties::VideoEncodingQuality const& quality);
        static auto CreateWmv(llm:OS::Media::MediaProperties::VideoEncodingQuality const& quality);
        static auto CreateFromFileAsync(llm:OS::Storage::IStorageFile const& file);
        static auto CreateFromStreamAsync(llm:OS::Storage::Streams::IRandomAccessStream const& stream);
        static auto CreateWav(llm:OS::Media::MediaProperties::AudioEncodingQuality const& quality);
        static auto CreateAvi(llm:OS::Media::MediaProperties::VideoEncodingQuality const& quality);
        static auto CreateAlac(llm:OS::Media::MediaProperties::AudioEncodingQuality const& quality);
        static auto CreateFlac(llm:OS::Media::MediaProperties::AudioEncodingQuality const& quality);
        static auto CreateHevc(llm:OS::Media::MediaProperties::VideoEncodingQuality const& quality);
        static auto CreateVp9(llm:OS::Media::MediaProperties::VideoEncodingQuality const& quality);
        static auto CreateAv1(llm:OS::Media::MediaProperties::VideoEncodingQuality const& quality);
    };
    struct MediaEncodingSubtypes
    {
        MediaEncodingSubtypes() = delete;
        [[nodiscard]] static auto Aac();
        [[nodiscard]] static auto AacAdts();
        [[nodiscard]] static auto Ac3();
        [[nodiscard]] static auto AmrNb();
        [[nodiscard]] static auto AmrWb();
        [[nodiscard]] static auto Argb32();
        [[nodiscard]] static auto Asf();
        [[nodiscard]] static auto Avi();
        [[nodiscard]] static auto Bgra8();
        [[nodiscard]] static auto Bmp();
        [[nodiscard]] static auto Eac3();
        [[nodiscard]] static auto Float();
        [[nodiscard]] static auto Gif();
        [[nodiscard]] static auto H263();
        [[nodiscard]] static auto H264();
        [[nodiscard]] static auto H264Es();
        [[nodiscard]] static auto Hevc();
        [[nodiscard]] static auto HevcEs();
        [[nodiscard]] static auto Iyuv();
        [[nodiscard]] static auto Jpeg();
        [[nodiscard]] static auto JpegXr();
        [[nodiscard]] static auto Mjpg();
        [[nodiscard]] static auto Mpeg();
        [[nodiscard]] static auto Mpeg1();
        [[nodiscard]] static auto Mpeg2();
        [[nodiscard]] static auto Mp3();
        [[nodiscard]] static auto Mpeg4();
        [[nodiscard]] static auto Nv12();
        [[nodiscard]] static auto Pcm();
        [[nodiscard]] static auto Png();
        [[nodiscard]] static auto Rgb24();
        [[nodiscard]] static auto Rgb32();
        [[nodiscard]] static auto Tiff();
        [[nodiscard]] static auto Wave();
        [[nodiscard]] static auto Wma8();
        [[nodiscard]] static auto Wma9();
        [[nodiscard]] static auto Wmv3();
        [[nodiscard]] static auto Wvc1();
        [[nodiscard]] static auto Yuy2();
        [[nodiscard]] static auto Yv12();
        [[nodiscard]] static auto Vp9();
        [[nodiscard]] static auto L8();
        [[nodiscard]] static auto L16();
        [[nodiscard]] static auto D16();
        [[nodiscard]] static auto Alac();
        [[nodiscard]] static auto Flac();
        [[nodiscard]] static auto P010();
        [[nodiscard]] static auto Heif();
        [[nodiscard]] static auto Pgs();
        [[nodiscard]] static auto Srt();
        [[nodiscard]] static auto Ssa();
        [[nodiscard]] static auto VobSub();
        [[nodiscard]] static auto Av1();
    };
    struct __declspec(empty_bases) MediaPropertySet : llm:OS::Foundation::Collections::IMap<llm::guid, llm:OS::Foundation::IInspectable>
    {
        MediaPropertySet(std::nullptr_t) noexcept {}
        MediaPropertySet(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IMap<llm::guid, llm:OS::Foundation::IInspectable>(ptr, take_ownership_from_abi) {}
        MediaPropertySet();
    };
    struct __declspec(empty_bases) MediaRatio : llm:OS::Media::MediaProperties::IMediaRatio
    {
        MediaRatio(std::nullptr_t) noexcept {}
        MediaRatio(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::MediaProperties::IMediaRatio(ptr, take_ownership_from_abi) {}
    };
    struct Mpeg2ProfileIds
    {
        Mpeg2ProfileIds() = delete;
        [[nodiscard]] static auto Simple();
        [[nodiscard]] static auto Main();
        [[nodiscard]] static auto SignalNoiseRatioScalable();
        [[nodiscard]] static auto SpatiallyScalable();
        [[nodiscard]] static auto High();
    };
    struct __declspec(empty_bases) TimedMetadataEncodingProperties : llm:OS::Media::MediaProperties::IMediaEncodingProperties,
        impl::require<TimedMetadataEncodingProperties, llm:OS::Media::MediaProperties::ITimedMetadataEncodingProperties>
    {
        TimedMetadataEncodingProperties(std::nullptr_t) noexcept {}
        TimedMetadataEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::MediaProperties::IMediaEncodingProperties(ptr, take_ownership_from_abi) {}
        TimedMetadataEncodingProperties();
        static auto CreatePgs();
        static auto CreateSrt();
        static auto CreateSsa(array_view<uint8_t const> formatUserData);
        static auto CreateVobSub(array_view<uint8_t const> formatUserData);
    };
    struct __declspec(empty_bases) VideoEncodingProperties : llm:OS::Media::MediaProperties::IVideoEncodingProperties,
        impl::require<VideoEncodingProperties, llm:OS::Media::MediaProperties::IVideoEncodingProperties2, llm:OS::Media::MediaProperties::IVideoEncodingProperties3, llm:OS::Media::MediaProperties::IVideoEncodingProperties4, llm:OS::Media::MediaProperties::IVideoEncodingProperties5>
    {
        VideoEncodingProperties(std::nullptr_t) noexcept {}
        VideoEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::MediaProperties::IVideoEncodingProperties(ptr, take_ownership_from_abi) {}
        VideoEncodingProperties();
        static auto CreateH264();
        static auto CreateMpeg2();
        static auto CreateUncompressed(param::hstring const& subtype, uint32_t width, uint32_t height);
        static auto CreateHevc();
        static auto CreateVp9();
        static auto CreateAv1();
    };
    struct Vp9ProfileIds
    {
        Vp9ProfileIds() = delete;
        [[nodiscard]] static auto Profile0ChromaSubsampling420BitDepth8();
        [[nodiscard]] static auto Profile2ChromaSubsampling420BitDepth10();
        [[nodiscard]] static auto Profile2ChromaSubsampling420BitDepth12();
    };
}
#endif
