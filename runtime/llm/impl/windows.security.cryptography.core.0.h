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
#ifndef LLM_OS_Security_Cryptography_Core_0_H
#define LLM_OS_Security_Cryptography_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Security::Cryptography::Certificates
{
    struct Certificate;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::Security::Cryptography::Core
{
    enum class Capi1KdfTargetAlgorithm : int32_t
    {
        NotAes = 0,
        Aes = 1,
    };
    enum class CryptographicPadding : int32_t
    {
        None = 0,
        RsaOaep = 1,
        RsaPkcs1V15 = 2,
        RsaPss = 3,
    };
    enum class CryptographicPrivateKeyBlobType : int32_t
    {
        Pkcs8RawPrivateKeyInfo = 0,
        Pkcs1RsaPrivateKey = 1,
        BCryptPrivateKey = 2,
        Capi1PrivateKey = 3,
        BCryptEccFullPrivateKey = 4,
    };
    enum class CryptographicPublicKeyBlobType : int32_t
    {
        X509SubjectPublicKeyInfo = 0,
        Pkcs1RsaPublicKey = 1,
        BCryptPublicKey = 2,
        Capi1PublicKey = 3,
        BCryptEccFullPublicKey = 4,
    };
    struct IAsymmetricAlgorithmNamesStatics;
    struct IAsymmetricAlgorithmNamesStatics2;
    struct IAsymmetricKeyAlgorithmProvider;
    struct IAsymmetricKeyAlgorithmProvider2;
    struct IAsymmetricKeyAlgorithmProviderStatics;
    struct ICryptographicEngineStatics;
    struct ICryptographicEngineStatics2;
    struct ICryptographicKey;
    struct IEccCurveNamesStatics;
    struct IEncryptedAndAuthenticatedData;
    struct IHashAlgorithmNamesStatics;
    struct IHashAlgorithmProvider;
    struct IHashAlgorithmProviderStatics;
    struct IHashComputation;
    struct IKeyDerivationAlgorithmNamesStatics;
    struct IKeyDerivationAlgorithmNamesStatics2;
    struct IKeyDerivationAlgorithmProvider;
    struct IKeyDerivationAlgorithmProviderStatics;
    struct IKeyDerivationParameters;
    struct IKeyDerivationParameters2;
    struct IKeyDerivationParametersStatics;
    struct IKeyDerivationParametersStatics2;
    struct IMacAlgorithmNamesStatics;
    struct IMacAlgorithmProvider;
    struct IMacAlgorithmProvider2;
    struct IMacAlgorithmProviderStatics;
    struct IPersistedKeyProviderStatics;
    struct ISymmetricAlgorithmNamesStatics;
    struct ISymmetricKeyAlgorithmProvider;
    struct ISymmetricKeyAlgorithmProviderStatics;
    struct AsymmetricAlgorithmNames;
    struct AsymmetricKeyAlgorithmProvider;
    struct CryptographicEngine;
    struct CryptographicHash;
    struct CryptographicKey;
    struct EccCurveNames;
    struct EncryptedAndAuthenticatedData;
    struct HashAlgorithmNames;
    struct HashAlgorithmProvider;
    struct KeyDerivationAlgorithmNames;
    struct KeyDerivationAlgorithmProvider;
    struct KeyDerivationParameters;
    struct MacAlgorithmNames;
    struct MacAlgorithmProvider;
    struct PersistedKeyProvider;
    struct SymmetricAlgorithmNames;
    struct SymmetricKeyAlgorithmProvider;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::ICryptographicKey>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IEccCurveNamesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IEncryptedAndAuthenticatedData>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IHashAlgorithmNamesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IHashAlgorithmProvider>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IHashAlgorithmProviderStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IHashComputation>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IMacAlgorithmNamesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IMacAlgorithmProviderStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::IPersistedKeyProviderStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::AsymmetricAlgorithmNames>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::AsymmetricKeyAlgorithmProvider>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::CryptographicEngine>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::CryptographicHash>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::CryptographicKey>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::EccCurveNames>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::EncryptedAndAuthenticatedData>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::HashAlgorithmNames>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::HashAlgorithmProvider>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::KeyDerivationAlgorithmNames>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::KeyDerivationAlgorithmProvider>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::KeyDerivationParameters>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::MacAlgorithmNames>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::MacAlgorithmProvider>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::PersistedKeyProvider>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::SymmetricAlgorithmNames>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::SymmetricKeyAlgorithmProvider>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::Capi1KdfTargetAlgorithm>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::CryptographicPadding>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::CryptographicPrivateKeyBlobType>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Cryptography::Core::CryptographicPublicKeyBlobType>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::AsymmetricAlgorithmNames> = L"Windows.Security.Cryptography.Core.AsymmetricAlgorithmNames";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::AsymmetricKeyAlgorithmProvider> = L"Windows.Security.Cryptography.Core.AsymmetricKeyAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::CryptographicEngine> = L"Windows.Security.Cryptography.Core.CryptographicEngine";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::CryptographicHash> = L"Windows.Security.Cryptography.Core.CryptographicHash";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::CryptographicKey> = L"Windows.Security.Cryptography.Core.CryptographicKey";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::EccCurveNames> = L"Windows.Security.Cryptography.Core.EccCurveNames";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::EncryptedAndAuthenticatedData> = L"Windows.Security.Cryptography.Core.EncryptedAndAuthenticatedData";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::HashAlgorithmNames> = L"Windows.Security.Cryptography.Core.HashAlgorithmNames";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::HashAlgorithmProvider> = L"Windows.Security.Cryptography.Core.HashAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::KeyDerivationAlgorithmNames> = L"Windows.Security.Cryptography.Core.KeyDerivationAlgorithmNames";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::KeyDerivationAlgorithmProvider> = L"Windows.Security.Cryptography.Core.KeyDerivationAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::KeyDerivationParameters> = L"Windows.Security.Cryptography.Core.KeyDerivationParameters";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::MacAlgorithmNames> = L"Windows.Security.Cryptography.Core.MacAlgorithmNames";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::MacAlgorithmProvider> = L"Windows.Security.Cryptography.Core.MacAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::PersistedKeyProvider> = L"Windows.Security.Cryptography.Core.PersistedKeyProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::SymmetricAlgorithmNames> = L"Windows.Security.Cryptography.Core.SymmetricAlgorithmNames";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::SymmetricKeyAlgorithmProvider> = L"Windows.Security.Cryptography.Core.SymmetricKeyAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::Capi1KdfTargetAlgorithm> = L"Windows.Security.Cryptography.Core.Capi1KdfTargetAlgorithm";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::CryptographicPadding> = L"Windows.Security.Cryptography.Core.CryptographicPadding";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::CryptographicPrivateKeyBlobType> = L"Windows.Security.Cryptography.Core.CryptographicPrivateKeyBlobType";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::CryptographicPublicKeyBlobType> = L"Windows.Security.Cryptography.Core.CryptographicPublicKeyBlobType";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics> = L"Windows.Security.Cryptography.Core.IAsymmetricAlgorithmNamesStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2> = L"Windows.Security.Cryptography.Core.IAsymmetricAlgorithmNamesStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider> = L"Windows.Security.Cryptography.Core.IAsymmetricKeyAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2> = L"Windows.Security.Cryptography.Core.IAsymmetricKeyAlgorithmProvider2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics> = L"Windows.Security.Cryptography.Core.IAsymmetricKeyAlgorithmProviderStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics> = L"Windows.Security.Cryptography.Core.ICryptographicEngineStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics2> = L"Windows.Security.Cryptography.Core.ICryptographicEngineStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::ICryptographicKey> = L"Windows.Security.Cryptography.Core.ICryptographicKey";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IEccCurveNamesStatics> = L"Windows.Security.Cryptography.Core.IEccCurveNamesStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IEncryptedAndAuthenticatedData> = L"Windows.Security.Cryptography.Core.IEncryptedAndAuthenticatedData";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IHashAlgorithmNamesStatics> = L"Windows.Security.Cryptography.Core.IHashAlgorithmNamesStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IHashAlgorithmProvider> = L"Windows.Security.Cryptography.Core.IHashAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IHashAlgorithmProviderStatics> = L"Windows.Security.Cryptography.Core.IHashAlgorithmProviderStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IHashComputation> = L"Windows.Security.Cryptography.Core.IHashComputation";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics> = L"Windows.Security.Cryptography.Core.IKeyDerivationAlgorithmNamesStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2> = L"Windows.Security.Cryptography.Core.IKeyDerivationAlgorithmNamesStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider> = L"Windows.Security.Cryptography.Core.IKeyDerivationAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics> = L"Windows.Security.Cryptography.Core.IKeyDerivationAlgorithmProviderStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters> = L"Windows.Security.Cryptography.Core.IKeyDerivationParameters";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters2> = L"Windows.Security.Cryptography.Core.IKeyDerivationParameters2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics> = L"Windows.Security.Cryptography.Core.IKeyDerivationParametersStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics2> = L"Windows.Security.Cryptography.Core.IKeyDerivationParametersStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmNamesStatics> = L"Windows.Security.Cryptography.Core.IMacAlgorithmNamesStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider> = L"Windows.Security.Cryptography.Core.IMacAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider2> = L"Windows.Security.Cryptography.Core.IMacAlgorithmProvider2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmProviderStatics> = L"Windows.Security.Cryptography.Core.IMacAlgorithmProviderStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::IPersistedKeyProviderStatics> = L"Windows.Security.Cryptography.Core.IPersistedKeyProviderStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics> = L"Windows.Security.Cryptography.Core.ISymmetricAlgorithmNamesStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider> = L"Windows.Security.Cryptography.Core.ISymmetricKeyAlgorithmProvider";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics> = L"Windows.Security.Cryptography.Core.ISymmetricKeyAlgorithmProviderStatics";
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics>{ 0xCAF6FCE4,0x67C0,0x46AA,{ 0x84,0xF9,0x75,0x2E,0x77,0x44,0x9F,0x9B } }; // CAF6FCE4-67C0-46AA-84F9-752E77449F9B
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2>{ 0xF141C0D6,0x4BFF,0x4F23,{ 0xBA,0x66,0x60,0x45,0xB1,0x37,0xD5,0xDF } }; // F141C0D6-4BFF-4F23-BA66-6045B137D5DF
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>{ 0xE8D2FF37,0x6259,0x4E88,{ 0xB7,0xE0,0x94,0x19,0x1F,0xDE,0x69,0x9E } }; // E8D2FF37-6259-4E88-B7E0-94191FDE699E
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>{ 0x4E322A7E,0x7C4D,0x4997,{ 0xAC,0x4F,0x1B,0x84,0x8B,0x36,0x30,0x6E } }; // 4E322A7E-7C4D-4997-AC4F-1B848B36306E
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics>{ 0x425BDE18,0xA7F3,0x47A6,{ 0xA8,0xD2,0xC4,0x8D,0x60,0x33,0xA6,0x5C } }; // 425BDE18-A7F3-47A6-A8D2-C48D6033A65C
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics>{ 0x9FEA0639,0x6FF7,0x4C85,{ 0xA0,0x95,0x95,0xEB,0x31,0x71,0x5E,0xB9 } }; // 9FEA0639-6FF7-4C85-A095-95EB31715EB9
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics2>{ 0x675948FE,0xDF9F,0x4191,{ 0x92,0xC7,0x6C,0xE6,0xF5,0x84,0x20,0xE0 } }; // 675948FE-DF9F-4191-92C7-6CE6F58420E0
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::ICryptographicKey>{ 0xED2A3B70,0x8E7B,0x4009,{ 0x84,0x01,0xFF,0xD1,0xA6,0x2E,0xEB,0x27 } }; // ED2A3B70-8E7B-4009-8401-FFD1A62EEB27
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IEccCurveNamesStatics>{ 0xB3FF930C,0xAEEB,0x409E,{ 0xB7,0xD4,0x9B,0x95,0x29,0x5A,0xAE,0xCF } }; // B3FF930C-AEEB-409E-B7D4-9B95295AAECF
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IEncryptedAndAuthenticatedData>{ 0x6FA42FE7,0x1ECB,0x4B00,{ 0xBE,0xA5,0x60,0xB8,0x3F,0x86,0x2F,0x17 } }; // 6FA42FE7-1ECB-4B00-BEA5-60B83F862F17
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IHashAlgorithmNamesStatics>{ 0x6B5E0516,0xDE96,0x4F0A,{ 0x8D,0x57,0xDC,0xC9,0xDA,0xE3,0x6C,0x76 } }; // 6B5E0516-DE96-4F0A-8D57-DCC9DAE36C76
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IHashAlgorithmProvider>{ 0xBE9B3080,0xB2C3,0x422B,{ 0xBC,0xE1,0xEC,0x90,0xEF,0xB5,0xD7,0xB5 } }; // BE9B3080-B2C3-422B-BCE1-EC90EFB5D7B5
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IHashAlgorithmProviderStatics>{ 0x9FAC9741,0x5CC4,0x4336,{ 0xAE,0x38,0x62,0x12,0xB7,0x5A,0x91,0x5A } }; // 9FAC9741-5CC4-4336-AE38-6212B75A915A
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IHashComputation>{ 0x5904D1B6,0xAD31,0x4603,{ 0xA3,0xA4,0xB1,0xBD,0xA9,0x8E,0x25,0x62 } }; // 5904D1B6-AD31-4603-A3A4-B1BDA98E2562
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics>{ 0x7B6E363E,0x94D2,0x4739,{ 0xA5,0x7B,0x02,0x2E,0x0C,0x3A,0x40,0x2A } }; // 7B6E363E-94D2-4739-A57B-022E0C3A402A
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2>{ 0x57953FAB,0x6044,0x466F,{ 0x97,0xF4,0x33,0x7B,0x78,0x08,0x38,0x4D } }; // 57953FAB-6044-466F-97F4-337B7808384D
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider>{ 0xE1FBA83B,0x4671,0x43B7,{ 0x91,0x58,0x76,0x3A,0xAA,0x98,0xB6,0xBF } }; // E1FBA83B-4671-43B7-9158-763AAA98B6BF
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics>{ 0x0A22097A,0x0A1C,0x443B,{ 0x94,0x18,0xB9,0x49,0x8A,0xEB,0x16,0x03 } }; // 0A22097A-0A1C-443B-9418-B9498AEB1603
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters>{ 0x7BF05967,0x047B,0x4A8C,{ 0x96,0x4A,0x46,0x9F,0xFD,0x55,0x22,0xE2 } }; // 7BF05967-047B-4A8C-964A-469FFD5522E2
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters2>{ 0xCD4166D1,0x417E,0x4F4C,{ 0xB6,0x66,0xC0,0xD8,0x79,0xF3,0xF8,0xE0 } }; // CD4166D1-417E-4F4C-B666-C0D879F3F8E0
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics>{ 0xEA961FBE,0xF37F,0x4146,{ 0x9D,0xFE,0xA4,0x56,0xF1,0x73,0x5F,0x4B } }; // EA961FBE-F37F-4146-9DFE-A456F1735F4B
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics2>{ 0xA5783DD5,0x58E3,0x4EFB,{ 0xB2,0x83,0xA1,0x65,0x31,0x26,0xE1,0xBE } }; // A5783DD5-58E3-4EFB-B283-A1653126E1BE
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmNamesStatics>{ 0x41412678,0xFB1E,0x43A4,{ 0x89,0x5E,0xA9,0x02,0x6E,0x43,0x90,0xA3 } }; // 41412678-FB1E-43A4-895E-A9026E4390A3
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider>{ 0x4A3FC5C3,0x1CBD,0x41CE,{ 0xA0,0x92,0xAA,0x0B,0xC5,0xD2,0xD2,0xF5 } }; // 4A3FC5C3-1CBD-41CE-A092-AA0BC5D2D2F5
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider2>{ 0x6DA32A15,0xD931,0x42ED,{ 0x8E,0x7E,0xC3,0x01,0xCA,0xEE,0x11,0x9C } }; // 6DA32A15-D931-42ED-8E7E-C301CAEE119C
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IMacAlgorithmProviderStatics>{ 0xC9BDC147,0xCC77,0x4DF0,{ 0x9E,0x4E,0xB9,0x21,0xE0,0x80,0x64,0x4C } }; // C9BDC147-CC77-4DF0-9E4E-B921E080644C
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::IPersistedKeyProviderStatics>{ 0x77274814,0xD9D4,0x4CF5,{ 0xB6,0x68,0xE0,0x45,0x7D,0xF3,0x08,0x94 } }; // 77274814-D9D4-4CF5-B668-E0457DF30894
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics>{ 0x6870727B,0xC996,0x4EAE,{ 0x84,0xD7,0x79,0xB2,0xAE,0xB7,0x3B,0x9C } }; // 6870727B-C996-4EAE-84D7-79B2AEB73B9C
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider>{ 0x3D7E4A33,0x3BD0,0x4902,{ 0x8A,0xC8,0x47,0x0D,0x50,0xD2,0x13,0x76 } }; // 3D7E4A33-3BD0-4902-8AC8-470D50D21376
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics>{ 0x8D3B2326,0x1F37,0x491F,{ 0xB6,0x0E,0xF5,0x43,0x1B,0x26,0xB4,0x83 } }; // 8D3B2326-1F37-491F-B60E-F5431B26B483
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::AsymmetricKeyAlgorithmProvider>{ using type = llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::CryptographicHash>{ using type = llm:OS::Security::Cryptography::Core::IHashComputation; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::CryptographicKey>{ using type = llm:OS::Security::Cryptography::Core::ICryptographicKey; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::EncryptedAndAuthenticatedData>{ using type = llm:OS::Security::Cryptography::Core::IEncryptedAndAuthenticatedData; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::HashAlgorithmProvider>{ using type = llm:OS::Security::Cryptography::Core::IHashAlgorithmProvider; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::KeyDerivationAlgorithmProvider>{ using type = llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::KeyDerivationParameters>{ using type = llm:OS::Security::Cryptography::Core::IKeyDerivationParameters; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::MacAlgorithmProvider>{ using type = llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider; };
    template <> struct default_interface<llm:OS::Security::Cryptography::Core::SymmetricKeyAlgorithmProvider>{ using type = llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider; };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RsaPkcs1(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaOaepSha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaOaepSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaOaepSha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaOaepSha512(void**) noexcept = 0;
            virtual int32_t __stdcall get_EcdsaP256Sha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_EcdsaP384Sha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_EcdsaP521Sha512(void**) noexcept = 0;
            virtual int32_t __stdcall get_DsaSha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_DsaSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPkcs1Sha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPkcs1Sha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPkcs1Sha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPkcs1Sha512(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPssSha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPssSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPssSha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_RsaSignPssSha512(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EcdsaSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_EcdsaSha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_EcdsaSha512(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AlgorithmName(void**) noexcept = 0;
            virtual int32_t __stdcall CreateKeyPair(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ImportDefaultPrivateKeyBlob(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ImportKeyPairWithBlobType(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ImportDefaultPublicKeyBlob(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ImportPublicKeyWithBlobType(void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateKeyPairWithCurveName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateKeyPairWithCurveParameters(uint32_t, uint8_t*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenAlgorithm(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Encrypt(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall Decrypt(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall EncryptAndAuthenticate(void*, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall DecryptAndAuthenticate(void*, void*, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall Sign(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall VerifySignature(void*, void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall DeriveKeyMaterial(void*, void*, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SignHashedData(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall VerifySignatureWithHashInput(void*, void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall DecryptAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall SignAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall SignHashedDataAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::ICryptographicKey>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_KeySize(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall ExportDefaultPrivateKeyBlobType(void**) noexcept = 0;
            virtual int32_t __stdcall ExportPrivateKeyWithBlobType(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ExportDefaultPublicKeyBlobType(void**) noexcept = 0;
            virtual int32_t __stdcall ExportPublicKeyWithBlobType(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IEccCurveNamesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BrainpoolP160r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP160t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP192r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP192t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP224r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP224t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP256r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP256t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP320r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP320t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP384r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP384t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP512r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_BrainpoolP512t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_Curve25519(void**) noexcept = 0;
            virtual int32_t __stdcall get_Ec192wapi(void**) noexcept = 0;
            virtual int32_t __stdcall get_NistP192(void**) noexcept = 0;
            virtual int32_t __stdcall get_NistP224(void**) noexcept = 0;
            virtual int32_t __stdcall get_NistP256(void**) noexcept = 0;
            virtual int32_t __stdcall get_NistP384(void**) noexcept = 0;
            virtual int32_t __stdcall get_NistP521(void**) noexcept = 0;
            virtual int32_t __stdcall get_NumsP256t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_NumsP384t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_NumsP512t1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP160k1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP160r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP160r2(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP192k1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP192r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP224k1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP224r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP256k1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP256r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP384r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecP521r1(void**) noexcept = 0;
            virtual int32_t __stdcall get_Wtls7(void**) noexcept = 0;
            virtual int32_t __stdcall get_Wtls9(void**) noexcept = 0;
            virtual int32_t __stdcall get_Wtls12(void**) noexcept = 0;
            virtual int32_t __stdcall get_X962P192v1(void**) noexcept = 0;
            virtual int32_t __stdcall get_X962P192v2(void**) noexcept = 0;
            virtual int32_t __stdcall get_X962P192v3(void**) noexcept = 0;
            virtual int32_t __stdcall get_X962P239v1(void**) noexcept = 0;
            virtual int32_t __stdcall get_X962P239v2(void**) noexcept = 0;
            virtual int32_t __stdcall get_X962P239v3(void**) noexcept = 0;
            virtual int32_t __stdcall get_X962P256v1(void**) noexcept = 0;
            virtual int32_t __stdcall get_AllEccCurveNames(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IEncryptedAndAuthenticatedData>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EncryptedData(void**) noexcept = 0;
            virtual int32_t __stdcall get_AuthenticationTag(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IHashAlgorithmNamesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Md5(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sha512(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IHashAlgorithmProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AlgorithmName(void**) noexcept = 0;
            virtual int32_t __stdcall get_HashLength(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall HashData(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateHash(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IHashAlgorithmProviderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenAlgorithm(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IHashComputation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Append(void*) noexcept = 0;
            virtual int32_t __stdcall GetValueAndReset(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Pbkdf2Md5(void**) noexcept = 0;
            virtual int32_t __stdcall get_Pbkdf2Sha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_Pbkdf2Sha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_Pbkdf2Sha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_Pbkdf2Sha512(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp800108CtrHmacMd5(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp800108CtrHmacSha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp800108CtrHmacSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp800108CtrHmacSha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp800108CtrHmacSha512(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp80056aConcatMd5(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp80056aConcatSha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp80056aConcatSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp80056aConcatSha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sp80056aConcatSha512(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CapiKdfMd5(void**) noexcept = 0;
            virtual int32_t __stdcall get_CapiKdfSha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_CapiKdfSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_CapiKdfSha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_CapiKdfSha512(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AlgorithmName(void**) noexcept = 0;
            virtual int32_t __stdcall CreateKey(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenAlgorithm(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_KdfGenericBinary(void**) noexcept = 0;
            virtual int32_t __stdcall put_KdfGenericBinary(void*) noexcept = 0;
            virtual int32_t __stdcall get_IterationCount(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Capi1KdfTargetAlgorithm(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Capi1KdfTargetAlgorithm(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall BuildForPbkdf2(void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall BuildForSP800108(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall BuildForSP80056a(void*, void*, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall BuildForCapi1Kdf(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IMacAlgorithmNamesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HmacMd5(void**) noexcept = 0;
            virtual int32_t __stdcall get_HmacSha1(void**) noexcept = 0;
            virtual int32_t __stdcall get_HmacSha256(void**) noexcept = 0;
            virtual int32_t __stdcall get_HmacSha384(void**) noexcept = 0;
            virtual int32_t __stdcall get_HmacSha512(void**) noexcept = 0;
            virtual int32_t __stdcall get_AesCmac(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AlgorithmName(void**) noexcept = 0;
            virtual int32_t __stdcall get_MacLength(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall CreateKey(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateHash(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IMacAlgorithmProviderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenAlgorithm(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::IPersistedKeyProviderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenKeyPairFromCertificateAsync(void*, void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall OpenPublicKeyFromCertificate(void*, void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesCbc(void**) noexcept = 0;
            virtual int32_t __stdcall get_DesEcb(void**) noexcept = 0;
            virtual int32_t __stdcall get_TripleDesCbc(void**) noexcept = 0;
            virtual int32_t __stdcall get_TripleDesEcb(void**) noexcept = 0;
            virtual int32_t __stdcall get_Rc2Cbc(void**) noexcept = 0;
            virtual int32_t __stdcall get_Rc2Ecb(void**) noexcept = 0;
            virtual int32_t __stdcall get_AesCbc(void**) noexcept = 0;
            virtual int32_t __stdcall get_AesEcb(void**) noexcept = 0;
            virtual int32_t __stdcall get_AesGcm(void**) noexcept = 0;
            virtual int32_t __stdcall get_AesCcm(void**) noexcept = 0;
            virtual int32_t __stdcall get_AesCbcPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_AesEcbPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_DesCbcPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_DesEcbPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_TripleDesCbcPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_TripleDesEcbPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_Rc2CbcPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_Rc2EcbPkcs7(void**) noexcept = 0;
            virtual int32_t __stdcall get_Rc4(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AlgorithmName(void**) noexcept = 0;
            virtual int32_t __stdcall get_BlockLength(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall CreateSymmetricKey(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenAlgorithm(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IAsymmetricAlgorithmNamesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaPkcs1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaOaepSha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaOaepSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaOaepSha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaOaepSha512() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EcdsaP256Sha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EcdsaP384Sha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EcdsaP521Sha512() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DsaSha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DsaSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPkcs1Sha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPkcs1Sha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPkcs1Sha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPkcs1Sha512() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPssSha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPssSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPssSha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RsaSignPssSha512() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IAsymmetricAlgorithmNamesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IAsymmetricAlgorithmNamesStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EcdsaSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EcdsaSha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EcdsaSha512() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IAsymmetricAlgorithmNamesStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IAsymmetricKeyAlgorithmProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AlgorithmName() const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) CreateKeyPair(uint32_t keySize) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) ImportKeyPair(llm:OS::Storage::Streams::IBuffer const& keyBlob) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) ImportKeyPair(llm:OS::Storage::Streams::IBuffer const& keyBlob, llm:OS::Security::Cryptography::Core::CryptographicPrivateKeyBlobType const& BlobType) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) ImportPublicKey(llm:OS::Storage::Streams::IBuffer const& keyBlob) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) ImportPublicKey(llm:OS::Storage::Streams::IBuffer const& keyBlob, llm:OS::Security::Cryptography::Core::CryptographicPublicKeyBlobType const& BlobType) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IAsymmetricKeyAlgorithmProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IAsymmetricKeyAlgorithmProvider2
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) CreateKeyPairWithCurveName(param::hstring const& curveName) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) CreateKeyPairWithCurveParameters(array_view<uint8_t const> parameters) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IAsymmetricKeyAlgorithmProvider2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IAsymmetricKeyAlgorithmProviderStatics
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::AsymmetricKeyAlgorithmProvider) OpenAlgorithm(param::hstring const& algorithm) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IAsymmetricKeyAlgorithmProviderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_ICryptographicEngineStatics
    {
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) Encrypt(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data, llm:OS::Storage::Streams::IBuffer const& iv) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) Decrypt(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data, llm:OS::Storage::Streams::IBuffer const& iv) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::EncryptedAndAuthenticatedData) EncryptAndAuthenticate(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data, llm:OS::Storage::Streams::IBuffer const& nonce, llm:OS::Storage::Streams::IBuffer const& authenticatedData) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) DecryptAndAuthenticate(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data, llm:OS::Storage::Streams::IBuffer const& nonce, llm:OS::Storage::Streams::IBuffer const& authenticationTag, llm:OS::Storage::Streams::IBuffer const& authenticatedData) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) Sign(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data) const;
        LLM_IMPL_AUTO(bool) VerifySignature(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data, llm:OS::Storage::Streams::IBuffer const& signature) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) DeriveKeyMaterial(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Security::Cryptography::Core::KeyDerivationParameters const& parameters, uint32_t desiredKeySize) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_ICryptographicEngineStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_ICryptographicEngineStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) SignHashedData(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data) const;
        LLM_IMPL_AUTO(bool) VerifySignatureWithHashInput(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data, llm:OS::Storage::Streams::IBuffer const& signature) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::Streams::IBuffer>) DecryptAsync(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data, llm:OS::Storage::Streams::IBuffer const& iv) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::Streams::IBuffer>) SignAsync(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::Streams::IBuffer>) SignHashedDataAsync(llm:OS::Security::Cryptography::Core::CryptographicKey const& key, llm:OS::Storage::Streams::IBuffer const& data) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::ICryptographicEngineStatics2>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_ICryptographicEngineStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_ICryptographicKey
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) KeySize() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) Export() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) Export(llm:OS::Security::Cryptography::Core::CryptographicPrivateKeyBlobType const& BlobType) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) ExportPublicKey() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) ExportPublicKey(llm:OS::Security::Cryptography::Core::CryptographicPublicKeyBlobType const& BlobType) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::ICryptographicKey>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_ICryptographicKey<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IEccCurveNamesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP160r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP160t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP192r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP192t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP224r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP224t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP256r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP256t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP320r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP320t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP384r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP384t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP512r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) BrainpoolP512t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Curve25519() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Ec192wapi() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NistP192() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NistP224() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NistP256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NistP384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NistP521() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NumsP256t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NumsP384t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NumsP512t1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP160k1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP160r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP160r2() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP192k1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP192r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP224k1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP224r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP256k1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP256r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP384r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecP521r1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Wtls7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Wtls9() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Wtls12() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) X962P192v1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) X962P192v2() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) X962P192v3() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) X962P239v1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) X962P239v2() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) X962P239v3() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) X962P256v1() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) AllEccCurveNames() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IEccCurveNamesStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IEccCurveNamesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IEncryptedAndAuthenticatedData
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) EncryptedData() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) AuthenticationTag() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IEncryptedAndAuthenticatedData>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IEncryptedAndAuthenticatedData<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IHashAlgorithmNamesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Md5() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sha512() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IHashAlgorithmNamesStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IHashAlgorithmNamesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IHashAlgorithmProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AlgorithmName() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) HashLength() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) HashData(llm:OS::Storage::Streams::IBuffer const& data) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicHash) CreateHash() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IHashAlgorithmProvider>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IHashAlgorithmProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IHashAlgorithmProviderStatics
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::HashAlgorithmProvider) OpenAlgorithm(param::hstring const& algorithm) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IHashAlgorithmProviderStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IHashAlgorithmProviderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IHashComputation
    {
        LLM_IMPL_AUTO(void) Append(llm:OS::Storage::Streams::IBuffer const& data) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) GetValueAndReset() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IHashComputation>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IHashComputation<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmNamesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Pbkdf2Md5() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Pbkdf2Sha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Pbkdf2Sha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Pbkdf2Sha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Pbkdf2Sha512() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp800108CtrHmacMd5() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp800108CtrHmacSha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp800108CtrHmacSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp800108CtrHmacSha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp800108CtrHmacSha512() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp80056aConcatMd5() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp80056aConcatSha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp80056aConcatSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp80056aConcatSha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Sp80056aConcatSha512() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmNamesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmNamesStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CapiKdfMd5() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CapiKdfSha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CapiKdfSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CapiKdfSha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CapiKdfSha512() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmNamesStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AlgorithmName() const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) CreateKey(llm:OS::Storage::Streams::IBuffer const& keyMaterial) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmProviderStatics
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::KeyDerivationAlgorithmProvider) OpenAlgorithm(param::hstring const& algorithm) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationAlgorithmProviderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationParameters
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) KdfGenericBinary() const;
        LLM_IMPL_AUTO(void) KdfGenericBinary(llm:OS::Storage::Streams::IBuffer const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) IterationCount() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationParameters<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationParameters2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::Capi1KdfTargetAlgorithm) Capi1KdfTargetAlgorithm() const;
        LLM_IMPL_AUTO(void) Capi1KdfTargetAlgorithm(llm:OS::Security::Cryptography::Core::Capi1KdfTargetAlgorithm const& value) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationParameters2>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationParameters2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationParametersStatics
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::KeyDerivationParameters) BuildForPbkdf2(llm:OS::Storage::Streams::IBuffer const& pbkdf2Salt, uint32_t iterationCount) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::KeyDerivationParameters) BuildForSP800108(llm:OS::Storage::Streams::IBuffer const& label, llm:OS::Storage::Streams::IBuffer const& context) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::KeyDerivationParameters) BuildForSP80056a(llm:OS::Storage::Streams::IBuffer const& algorithmId, llm:OS::Storage::Streams::IBuffer const& partyUInfo, llm:OS::Storage::Streams::IBuffer const& partyVInfo, llm:OS::Storage::Streams::IBuffer const& suppPubInfo, llm:OS::Storage::Streams::IBuffer const& suppPrivInfo) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationParametersStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IKeyDerivationParametersStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::KeyDerivationParameters) BuildForCapi1Kdf(llm:OS::Security::Cryptography::Core::Capi1KdfTargetAlgorithm const& capi1KdfTargetAlgorithm) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IKeyDerivationParametersStatics2>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IKeyDerivationParametersStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IMacAlgorithmNamesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HmacMd5() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HmacSha1() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HmacSha256() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HmacSha384() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HmacSha512() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AesCmac() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IMacAlgorithmNamesStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IMacAlgorithmNamesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IMacAlgorithmProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AlgorithmName() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MacLength() const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) CreateKey(llm:OS::Storage::Streams::IBuffer const& keyMaterial) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IMacAlgorithmProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IMacAlgorithmProvider2
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicHash) CreateHash(llm:OS::Storage::Streams::IBuffer const& keyMaterial) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IMacAlgorithmProvider2>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IMacAlgorithmProvider2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IMacAlgorithmProviderStatics
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::MacAlgorithmProvider) OpenAlgorithm(param::hstring const& algorithm) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IMacAlgorithmProviderStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IMacAlgorithmProviderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_IPersistedKeyProviderStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Cryptography::Core::CryptographicKey>) OpenKeyPairFromCertificateAsync(llm:OS::Security::Cryptography::Certificates::Certificate const& certificate, param::hstring const& hashAlgorithmName, llm:OS::Security::Cryptography::Core::CryptographicPadding const& padding) const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) OpenPublicKeyFromCertificate(llm:OS::Security::Cryptography::Certificates::Certificate const& certificate, param::hstring const& hashAlgorithmName, llm:OS::Security::Cryptography::Core::CryptographicPadding const& padding) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::IPersistedKeyProviderStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_IPersistedKeyProviderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_ISymmetricAlgorithmNamesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DesCbc() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DesEcb() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TripleDesCbc() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TripleDesEcb() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Rc2Cbc() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Rc2Ecb() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AesCbc() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AesEcb() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AesGcm() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AesCcm() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AesCbcPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AesEcbPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DesCbcPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DesEcbPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TripleDesCbcPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TripleDesEcbPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Rc2CbcPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Rc2EcbPkcs7() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Rc4() const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_ISymmetricAlgorithmNamesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_ISymmetricKeyAlgorithmProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AlgorithmName() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) BlockLength() const;
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::CryptographicKey) CreateSymmetricKey(llm:OS::Storage::Streams::IBuffer const& keyMaterial) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_ISymmetricKeyAlgorithmProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_Core_ISymmetricKeyAlgorithmProviderStatics
    {
        LLM_IMPL_AUTO(llm:OS::Security::Cryptography::Core::SymmetricKeyAlgorithmProvider) OpenAlgorithm(param::hstring const& algorithm) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_Core_ISymmetricKeyAlgorithmProviderStatics<D>;
    };
}
#endif
