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
#ifndef LLM_OS_Media_SpeechRecognition_0_H
#define LLM_OS_Media_SpeechRecognition_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Globalization
{
    struct Language;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct StorageFile;
}
LLM_EXPORT namespace llm:OS::Media::SpeechRecognition
{
    enum class SpeechContinuousRecognitionMode : int32_t
    {
        Default = 0,
        PauseOnRecognition = 1,
    };
    enum class SpeechRecognitionAudioProblem : int32_t
    {
        None = 0,
        TooNoisy = 1,
        NoSignal = 2,
        TooLoud = 3,
        TooQuiet = 4,
        TooFast = 5,
        TooSlow = 6,
    };
    enum class SpeechRecognitionConfidence : int32_t
    {
        High = 0,
        Medium = 1,
        Low = 2,
        Rejected = 3,
    };
    enum class SpeechRecognitionConstraintProbability : int32_t
    {
        Default = 0,
        Min = 1,
        Max = 2,
    };
    enum class SpeechRecognitionConstraintType : int32_t
    {
        Topic = 0,
        List = 1,
        Grammar = 2,
        VoiceCommandDefinition = 3,
    };
    enum class SpeechRecognitionResultStatus : int32_t
    {
        Success = 0,
        TopicLanguageNotSupported = 1,
        GrammarLanguageMismatch = 2,
        GrammarCompilationFailure = 3,
        AudioQualityFailure = 4,
        UserCanceled = 5,
        Unknown = 6,
        TimeoutExceeded = 7,
        PauseLimitExceeded = 8,
        NetworkFailure = 9,
        MicrophoneUnavailable = 10,
    };
    enum class SpeechRecognitionScenario : int32_t
    {
        WebSearch = 0,
        Dictation = 1,
        FormFilling = 2,
    };
    enum class SpeechRecognizerState : int32_t
    {
        Idle = 0,
        Capturing = 1,
        Processing = 2,
        SoundStarted = 3,
        SoundEnded = 4,
        SpeechDetected = 5,
        Paused = 6,
    };
    struct ISpeechContinuousRecognitionCompletedEventArgs;
    struct ISpeechContinuousRecognitionResultGeneratedEventArgs;
    struct ISpeechContinuousRecognitionSession;
    struct ISpeechRecognitionCompilationResult;
    struct ISpeechRecognitionConstraint;
    struct ISpeechRecognitionGrammarFileConstraint;
    struct ISpeechRecognitionGrammarFileConstraintFactory;
    struct ISpeechRecognitionHypothesis;
    struct ISpeechRecognitionHypothesisGeneratedEventArgs;
    struct ISpeechRecognitionListConstraint;
    struct ISpeechRecognitionListConstraintFactory;
    struct ISpeechRecognitionQualityDegradingEventArgs;
    struct ISpeechRecognitionResult;
    struct ISpeechRecognitionResult2;
    struct ISpeechRecognitionSemanticInterpretation;
    struct ISpeechRecognitionTopicConstraint;
    struct ISpeechRecognitionTopicConstraintFactory;
    struct ISpeechRecognitionVoiceCommandDefinitionConstraint;
    struct ISpeechRecognizer;
    struct ISpeechRecognizer2;
    struct ISpeechRecognizerFactory;
    struct ISpeechRecognizerStateChangedEventArgs;
    struct ISpeechRecognizerStatics;
    struct ISpeechRecognizerStatics2;
    struct ISpeechRecognizerTimeouts;
    struct ISpeechRecognizerUIOptions;
    struct IVoiceCommandManager;
    struct IVoiceCommandSet;
    struct SpeechContinuousRecognitionCompletedEventArgs;
    struct SpeechContinuousRecognitionResultGeneratedEventArgs;
    struct SpeechContinuousRecognitionSession;
    struct SpeechRecognitionCompilationResult;
    struct SpeechRecognitionGrammarFileConstraint;
    struct SpeechRecognitionHypothesis;
    struct SpeechRecognitionHypothesisGeneratedEventArgs;
    struct SpeechRecognitionListConstraint;
    struct SpeechRecognitionQualityDegradingEventArgs;
    struct SpeechRecognitionResult;
    struct SpeechRecognitionSemanticInterpretation;
    struct SpeechRecognitionTopicConstraint;
    struct SpeechRecognitionVoiceCommandDefinitionConstraint;
    struct SpeechRecognizer;
    struct SpeechRecognizerStateChangedEventArgs;
    struct SpeechRecognizerTimeouts;
    struct SpeechRecognizerUIOptions;
    struct VoiceCommandManager;
    struct VoiceCommandSet;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizer>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizer2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizerFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::IVoiceCommandManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::IVoiceCommandSet>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionCompilationResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesis>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionListConstraint>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionTopicConstraint>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionVoiceCommandDefinitionConstraint>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognizer>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognizerTimeouts>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognizerUIOptions>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::VoiceCommandManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::VoiceCommandSet>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionAudioProblem>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionConfidence>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionConstraintProbability>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionConstraintType>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionResultStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognitionScenario>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechRecognition::SpeechRecognizerState>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> = L"Windows.Media.SpeechRecognition.SpeechContinuousRecognitionCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> = L"Windows.Media.SpeechRecognition.SpeechContinuousRecognitionResultGeneratedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession> = L"Windows.Media.SpeechRecognition.SpeechContinuousRecognitionSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionCompilationResult> = L"Windows.Media.SpeechRecognition.SpeechRecognitionCompilationResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint> = L"Windows.Media.SpeechRecognition.SpeechRecognitionGrammarFileConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesis> = L"Windows.Media.SpeechRecognition.SpeechRecognitionHypothesis";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> = L"Windows.Media.SpeechRecognition.SpeechRecognitionHypothesisGeneratedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionListConstraint> = L"Windows.Media.SpeechRecognition.SpeechRecognitionListConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> = L"Windows.Media.SpeechRecognition.SpeechRecognitionQualityDegradingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionResult> = L"Windows.Media.SpeechRecognition.SpeechRecognitionResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation> = L"Windows.Media.SpeechRecognition.SpeechRecognitionSemanticInterpretation";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionTopicConstraint> = L"Windows.Media.SpeechRecognition.SpeechRecognitionTopicConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionVoiceCommandDefinitionConstraint> = L"Windows.Media.SpeechRecognition.SpeechRecognitionVoiceCommandDefinitionConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognizer> = L"Windows.Media.SpeechRecognition.SpeechRecognizer";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> = L"Windows.Media.SpeechRecognition.SpeechRecognizerStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognizerTimeouts> = L"Windows.Media.SpeechRecognition.SpeechRecognizerTimeouts";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognizerUIOptions> = L"Windows.Media.SpeechRecognition.SpeechRecognizerUIOptions";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::VoiceCommandManager> = L"Windows.Media.SpeechRecognition.VoiceCommandManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::VoiceCommandSet> = L"Windows.Media.SpeechRecognition.VoiceCommandSet";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionMode> = L"Windows.Media.SpeechRecognition.SpeechContinuousRecognitionMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionAudioProblem> = L"Windows.Media.SpeechRecognition.SpeechRecognitionAudioProblem";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionConfidence> = L"Windows.Media.SpeechRecognition.SpeechRecognitionConfidence";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionConstraintProbability> = L"Windows.Media.SpeechRecognition.SpeechRecognitionConstraintProbability";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionConstraintType> = L"Windows.Media.SpeechRecognition.SpeechRecognitionConstraintType";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionResultStatus> = L"Windows.Media.SpeechRecognition.SpeechRecognitionResultStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognitionScenario> = L"Windows.Media.SpeechRecognition.SpeechRecognitionScenario";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::SpeechRecognizerState> = L"Windows.Media.SpeechRecognition.SpeechRecognizerState";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs> = L"Windows.Media.SpeechRecognition.ISpeechContinuousRecognitionCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs> = L"Windows.Media.SpeechRecognition.ISpeechContinuousRecognitionResultGeneratedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession> = L"Windows.Media.SpeechRecognition.ISpeechContinuousRecognitionSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionCompilationResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionGrammarFileConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionGrammarFileConstraintFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionHypothesis";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionHypothesisGeneratedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionListConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionListConstraintFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionQualityDegradingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult2> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionResult2";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionSemanticInterpretation";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionTopicConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionTopicConstraintFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint> = L"Windows.Media.SpeechRecognition.ISpeechRecognitionVoiceCommandDefinitionConstraint";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizer> = L"Windows.Media.SpeechRecognition.ISpeechRecognizer";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizer2> = L"Windows.Media.SpeechRecognition.ISpeechRecognizer2";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerFactory> = L"Windows.Media.SpeechRecognition.ISpeechRecognizerFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs> = L"Windows.Media.SpeechRecognition.ISpeechRecognizerStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics> = L"Windows.Media.SpeechRecognition.ISpeechRecognizerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics2> = L"Windows.Media.SpeechRecognition.ISpeechRecognizerStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts> = L"Windows.Media.SpeechRecognition.ISpeechRecognizerTimeouts";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions> = L"Windows.Media.SpeechRecognition.ISpeechRecognizerUIOptions";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::IVoiceCommandManager> = L"Windows.Media.SpeechRecognition.IVoiceCommandManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechRecognition::IVoiceCommandSet> = L"Windows.Media.SpeechRecognition.IVoiceCommandSet";
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs>{ 0xE3D069BB,0xE30C,0x5E18,{ 0x42,0x4B,0x7F,0xBE,0x81,0xF8,0xFB,0xD0 } }; // E3D069BB-E30C-5E18-424B-7FBE81F8FBD0
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs>{ 0x19091E1E,0x6E7E,0x5A46,{ 0x40,0xFB,0x76,0x59,0x4F,0x78,0x65,0x04 } }; // 19091E1E-6E7E-5A46-40FB-76594F786504
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>{ 0x6A213C04,0x6614,0x49F8,{ 0x99,0xA2,0xB5,0xE9,0xB3,0xA0,0x85,0xC8 } }; // 6A213C04-6614-49F8-99A2-B5E9B3A085C8
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult>{ 0x407E6C5D,0x6AC7,0x4DA4,{ 0x9C,0xC1,0x2F,0xCE,0x32,0xCF,0x74,0x89 } }; // 407E6C5D-6AC7-4DA4-9CC1-2FCE32CF7489
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>{ 0x79AC1628,0x4D68,0x43C4,{ 0x89,0x11,0x40,0xDC,0x41,0x01,0xB5,0x5B } }; // 79AC1628-4D68-43C4-8911-40DC4101B55B
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint>{ 0xB5031A8F,0x85CA,0x4FA4,{ 0xB1,0x1A,0x47,0x4F,0xC4,0x1B,0x38,0x35 } }; // B5031A8F-85CA-4FA4-B11A-474FC41B3835
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>{ 0x3DA770EB,0xC479,0x4C27,{ 0x9F,0x19,0x89,0x97,0x4E,0xF3,0x92,0xD1 } }; // 3DA770EB-C479-4C27-9F19-89974EF392D1
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis>{ 0x7A7B25B0,0x99C5,0x4F7D,{ 0xBF,0x84,0x10,0xAA,0x13,0x02,0xB6,0x34 } }; // 7A7B25B0-99C5-4F7D-BF84-10AA1302B634
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs>{ 0x55161A7A,0x8023,0x5866,{ 0x41,0x1D,0x12,0x13,0xBB,0x27,0x14,0x76 } }; // 55161A7A-8023-5866-411D-1213BB271476
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint>{ 0x09C487E9,0xE4AD,0x4526,{ 0x81,0xF2,0x49,0x46,0xFB,0x48,0x1D,0x98 } }; // 09C487E9-E4AD-4526-81F2-4946FB481D98
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>{ 0x40F3CDC7,0x562A,0x426A,{ 0x9F,0x3B,0x3B,0x4E,0x28,0x2B,0xE1,0xD5 } }; // 40F3CDC7-562A-426A-9F3B-3B4E282BE1D5
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs>{ 0x4FE24105,0x8C3A,0x4C7E,{ 0x8D,0x0A,0x5B,0xD4,0xF5,0xB1,0x4A,0xD8 } }; // 4FE24105-8C3A-4C7E-8D0A-5BD4F5B14AD8
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult>{ 0x4E303157,0x034E,0x4652,{ 0x85,0x7E,0xD0,0x45,0x4C,0xC4,0xBE,0xEC } }; // 4E303157-034E-4652-857E-D0454CC4BEEC
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult2>{ 0xAF7ED1BA,0x451B,0x4166,{ 0xA0,0xC1,0x1F,0xFE,0x84,0x03,0x2D,0x03 } }; // AF7ED1BA-451B-4166-A0C1-1FFE84032D03
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation>{ 0xAAE1DA9B,0x7E32,0x4C1F,{ 0x89,0xFE,0x0C,0x65,0xF4,0x86,0xF5,0x2E } }; // AAE1DA9B-7E32-4C1F-89FE-0C65F486F52E
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>{ 0xBF6FDF19,0x825D,0x4E69,{ 0xA6,0x81,0x36,0xE4,0x8C,0xF1,0xC9,0x3E } }; // BF6FDF19-825D-4E69-A681-36E48CF1C93E
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>{ 0x6E6863DF,0xEC05,0x47D7,{ 0xA5,0xDF,0x56,0xA3,0x43,0x1E,0x58,0xD2 } }; // 6E6863DF-EC05-47D7-A5DF-56A3431E58D2
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint>{ 0xF2791C2B,0x1EF4,0x4AE7,{ 0x9D,0x77,0xB6,0xFF,0x10,0xB8,0xA3,0xC2 } }; // F2791C2B-1EF4-4AE7-9D77-B6FF10B8A3C2
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizer>{ 0x0BC3C9CB,0xC26A,0x40F2,{ 0xAE,0xB5,0x80,0x96,0xB2,0xE4,0x80,0x73 } }; // 0BC3C9CB-C26A-40F2-AEB5-8096B2E48073
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizer2>{ 0x63C9BAF1,0x91E3,0x4EA4,{ 0x86,0xA1,0x7C,0x38,0x67,0xD0,0x84,0xA6 } }; // 63C9BAF1-91E3-4EA4-86A1-7C3867D084A6
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerFactory>{ 0x60C488DD,0x7FB8,0x4033,{ 0xAC,0x70,0xD0,0x46,0xF6,0x48,0x18,0xE1 } }; // 60C488DD-7FB8-4033-AC70-D046F64818E1
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs>{ 0x563D4F09,0xBA03,0x4BAD,{ 0xAD,0x81,0xDD,0xC6,0xC4,0xDA,0xB0,0xC3 } }; // 563D4F09-BA03-4BAD-AD81-DDC6C4DAB0C3
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics>{ 0x87A35EAC,0xA7DC,0x4B0B,{ 0xBC,0xC9,0x24,0xF4,0x7C,0x0B,0x7E,0xBF } }; // 87A35EAC-A7DC-4B0B-BCC9-24F47C0B7EBF
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics2>{ 0x1D1B0D95,0x7565,0x4EF9,{ 0xA2,0xF3,0xBA,0x15,0x16,0x2A,0x96,0xCF } }; // 1D1B0D95-7565-4EF9-A2F3-BA15162A96CF
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts>{ 0x2EF76FCA,0x6A3C,0x4DCA,{ 0xA1,0x53,0xDF,0x1B,0xC8,0x8A,0x79,0xAF } }; // 2EF76FCA-6A3C-4DCA-A153-DF1BC88A79AF
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions>{ 0x7888D641,0xB92B,0x44BA,{ 0xA2,0x5F,0xD1,0x86,0x46,0x30,0x64,0x1F } }; // 7888D641-B92B-44BA-A25F-D1864630641F
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::IVoiceCommandManager>{ 0xAA3A8DD5,0xB6E7,0x4EE2,{ 0xBA,0xA9,0xDD,0x6B,0xAC,0xED,0x0A,0x2B } }; // AA3A8DD5-B6E7-4EE2-BAA9-DD6BACED0A2B
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechRecognition::IVoiceCommandSet>{ 0x0BEDDA75,0x46E6,0x4B11,{ 0xA0,0x88,0x5C,0x68,0x63,0x28,0x99,0xB5 } }; // 0BEDDA75-46E6-4B11-A088-5C68632899B5
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs>{ using type = llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs>{ using type = llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession>{ using type = llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionCompilationResult>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesis>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionListConstraint>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionResult>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionTopicConstraint>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognitionVoiceCommandDefinitionConstraint>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognizer>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognizer; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognizerTimeouts>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::SpeechRecognizerUIOptions>{ using type = llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions; };
    template <> struct default_interface<llm:OS::Media::SpeechRecognition::VoiceCommandSet>{ using type = llm:OS::Media::SpeechRecognition::IVoiceCommandSet; };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Result(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AutoStopSilenceTimeout(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_AutoStopSilenceTimeout(int64_t) noexcept = 0;
            virtual int32_t __stdcall StartAsync(void**) noexcept = 0;
            virtual int32_t __stdcall StartWithModeAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall StopAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CancelAsync(void**) noexcept = 0;
            virtual int32_t __stdcall PauseAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Resume() noexcept = 0;
            virtual int32_t __stdcall add_Completed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Completed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ResultGenerated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ResultGenerated(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_Tag(void**) noexcept = 0;
            virtual int32_t __stdcall put_Tag(void*) noexcept = 0;
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Probability(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Probability(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_GrammarFile(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithTag(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Hypothesis(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Commands(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithTag(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Problem(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
            virtual int32_t __stdcall get_Confidence(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SemanticInterpretation(void**) noexcept = 0;
            virtual int32_t __stdcall GetAlternates(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_Constraint(void**) noexcept = 0;
            virtual int32_t __stdcall get_RulePath(void**) noexcept = 0;
            virtual int32_t __stdcall get_RawConfidence(double*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PhraseStartTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_PhraseDuration(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Scenario(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TopicHint(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithTag(int32_t, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CurrentLanguage(void**) noexcept = 0;
            virtual int32_t __stdcall get_Constraints(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timeouts(void**) noexcept = 0;
            virtual int32_t __stdcall get_UIOptions(void**) noexcept = 0;
            virtual int32_t __stdcall CompileConstraintsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RecognizeAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RecognizeWithUIAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_RecognitionQualityDegrading(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RecognitionQualityDegrading(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_StateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StateChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizer2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContinuousRecognitionSession(void**) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall StopRecognitionAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_HypothesisGenerated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_HypothesisGenerated(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SystemSpeechLanguage(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedTopicLanguages(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedGrammarLanguages(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TrySetSystemSpeechLanguageAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InitialSilenceTimeout(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_InitialSilenceTimeout(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_EndSilenceTimeout(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_EndSilenceTimeout(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_BabbleTimeout(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_BabbleTimeout(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExampleText(void**) noexcept = 0;
            virtual int32_t __stdcall put_ExampleText(void*) noexcept = 0;
            virtual int32_t __stdcall get_AudiblePrompt(void**) noexcept = 0;
            virtual int32_t __stdcall put_AudiblePrompt(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsReadBackEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsReadBackEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_ShowConfirmation(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ShowConfirmation(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::IVoiceCommandManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall InstallCommandSetsFromStorageFileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_InstalledCommandSets(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechRecognition::IVoiceCommandSet>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Language(void**) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall SetPhraseListAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechContinuousRecognitionCompletedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionResultStatus) Status() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechContinuousRecognitionCompletedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechContinuousRecognitionResultGeneratedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionResult) Result() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechContinuousRecognitionResultGeneratedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechContinuousRecognitionSession
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) AutoStopSilenceTimeout() const;
        LLM_IMPL_AUTO(void) AutoStopSilenceTimeout(llm:OS::Foundation::TimeSpan const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StartAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StartAsync(llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionMode const& mode) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StopAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) CancelAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) PauseAsync() const;
        LLM_IMPL_AUTO(void) Resume() const;
        LLM_IMPL_AUTO(llm::event_token) Completed(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession, llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> const& value) const;
        using Completed_revoker = impl::event_revoker<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession, &impl::abi_t<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>::remove_Completed>;
        [[nodiscard]] Completed_revoker Completed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession, llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) Completed(llm::event_token const& value) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ResultGenerated(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession, llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> const& value) const;
        using ResultGenerated_revoker = impl::event_revoker<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession, &impl::abi_t<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>::remove_ResultGenerated>;
        [[nodiscard]] ResultGenerated_revoker ResultGenerated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession, llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) ResultGenerated(llm::event_token const& value) const noexcept;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechContinuousRecognitionSession<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionCompilationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionResultStatus) Status() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionCompilationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionConstraint
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        LLM_IMPL_AUTO(void) IsEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Tag() const;
        LLM_IMPL_AUTO(void) Tag(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionConstraintType) Type() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionConstraintProbability) Probability() const;
        LLM_IMPL_AUTO(void) Probability(llm:OS::Media::SpeechRecognition::SpeechRecognitionConstraintProbability const& value) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionConstraint<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionGrammarFileConstraint
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::StorageFile) GrammarFile() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionGrammarFileConstraint<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionGrammarFileConstraintFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint) Create(llm:OS::Storage::StorageFile const& file) const;
        LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint) CreateWithTag(llm:OS::Storage::StorageFile const& file, param::hstring const& tag) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionGrammarFileConstraintFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionHypothesis
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionHypothesis<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionHypothesisGeneratedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesis) Hypothesis() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionHypothesisGeneratedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionListConstraint
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<hstring>) Commands() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionListConstraint<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionListConstraintFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionListConstraint) Create(param::iterable<hstring> const& commands) const;
        LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionListConstraint) CreateWithTag(param::iterable<hstring> const& commands, param::hstring const& tag) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionListConstraintFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionQualityDegradingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionAudioProblem) Problem() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionQualityDegradingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionResultStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionConfidence) Confidence() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation) SemanticInterpretation() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::SpeechRecognition::SpeechRecognitionResult>) GetAlternates(uint32_t maxAlternates) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint) Constraint() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) RulePath() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) RawConfidence() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionResult2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) PhraseStartTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) PhraseDuration() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult2>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionResult2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionSemanticInterpretation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMapView<hstring, llm:OS::Foundation::Collections::IVectorView<hstring>>) Properties() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionSemanticInterpretation<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionTopicConstraint
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionScenario) Scenario() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TopicHint() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionTopicConstraint<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionTopicConstraintFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionTopicConstraint) Create(llm:OS::Media::SpeechRecognition::SpeechRecognitionScenario const& scenario, param::hstring const& topicHint) const;
        LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognitionTopicConstraint) CreateWithTag(llm:OS::Media::SpeechRecognition::SpeechRecognitionScenario const& scenario, param::hstring const& topicHint, param::hstring const& tag) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionTopicConstraintFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognitionVoiceCommandDefinitionConstraint
    {
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognitionVoiceCommandDefinitionConstraint<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizer
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Language) CurrentLanguage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>) Constraints() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognizerTimeouts) Timeouts() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognizerUIOptions) UIOptions() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::SpeechRecognition::SpeechRecognitionCompilationResult>) CompileConstraintsAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::SpeechRecognition::SpeechRecognitionResult>) RecognizeAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::SpeechRecognition::SpeechRecognitionResult>) RecognizeWithUIAsync() const;
        LLM_IMPL_AUTO(llm::event_token) RecognitionQualityDegrading(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechRecognizer, llm:OS::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> const& speechRecognitionQualityDegradingHandler) const;
        using RecognitionQualityDegrading_revoker = impl::event_revoker<llm:OS::Media::SpeechRecognition::ISpeechRecognizer, &impl::abi_t<llm:OS::Media::SpeechRecognition::ISpeechRecognizer>::remove_RecognitionQualityDegrading>;
        [[nodiscard]] RecognitionQualityDegrading_revoker RecognitionQualityDegrading(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechRecognizer, llm:OS::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> const& speechRecognitionQualityDegradingHandler) const;
        LLM_IMPL_AUTO(void) RecognitionQualityDegrading(llm::event_token const& cookie) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) StateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechRecognizer, llm:OS::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> const& stateChangedHandler) const;
        using StateChanged_revoker = impl::event_revoker<llm:OS::Media::SpeechRecognition::ISpeechRecognizer, &impl::abi_t<llm:OS::Media::SpeechRecognition::ISpeechRecognizer>::remove_StateChanged>;
        [[nodiscard]] StateChanged_revoker StateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechRecognizer, llm:OS::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> const& stateChangedHandler) const;
        LLM_IMPL_AUTO(void) StateChanged(llm::event_token const& cookie) const noexcept;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizer>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizer<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizer2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechContinuousRecognitionSession) ContinuousRecognitionSession() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognizerState) State() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) StopRecognitionAsync() const;
        LLM_IMPL_AUTO(llm::event_token) HypothesisGenerated(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechRecognizer, llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> const& value) const;
        using HypothesisGenerated_revoker = impl::event_revoker<llm:OS::Media::SpeechRecognition::ISpeechRecognizer2, &impl::abi_t<llm:OS::Media::SpeechRecognition::ISpeechRecognizer2>::remove_HypothesisGenerated>;
        [[nodiscard]] HypothesisGenerated_revoker HypothesisGenerated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::SpeechRecognition::SpeechRecognizer, llm:OS::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) HypothesisGenerated(llm::event_token const& value) const noexcept;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizer2>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizer2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizerFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognizer) Create(llm:OS::Globalization::Language const& language) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizerFactory>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizerStateChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechRecognition::SpeechRecognizerState) State() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizerStateChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Language) SystemSpeechLanguage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Globalization::Language>) SupportedTopicLanguages() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Globalization::Language>) SupportedGrammarLanguages() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizerStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) TrySetSystemSpeechLanguageAsync(llm:OS::Globalization::Language const& speechLanguage) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizerStatics2>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizerTimeouts
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) InitialSilenceTimeout() const;
        LLM_IMPL_AUTO(void) InitialSilenceTimeout(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) EndSilenceTimeout() const;
        LLM_IMPL_AUTO(void) EndSilenceTimeout(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) BabbleTimeout() const;
        LLM_IMPL_AUTO(void) BabbleTimeout(llm:OS::Foundation::TimeSpan const& value) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizerTimeouts<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_ISpeechRecognizerUIOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ExampleText() const;
        LLM_IMPL_AUTO(void) ExampleText(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AudiblePrompt() const;
        LLM_IMPL_AUTO(void) AudiblePrompt(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsReadBackEnabled() const;
        LLM_IMPL_AUTO(void) IsReadBackEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ShowConfirmation() const;
        LLM_IMPL_AUTO(void) ShowConfirmation(bool value) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_ISpeechRecognizerUIOptions<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_IVoiceCommandManager
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) InstallCommandSetsFromStorageFileAsync(llm:OS::Storage::StorageFile const& file) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMapView<hstring, llm:OS::Media::SpeechRecognition::VoiceCommandSet>) InstalledCommandSets() const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::IVoiceCommandManager>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_IVoiceCommandManager<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechRecognition_IVoiceCommandSet
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Language() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetPhraseListAsync(param::hstring const& phraseListName, param::async_iterable<hstring> const& phraseList) const;
    };
    template <> struct consume<llm:OS::Media::SpeechRecognition::IVoiceCommandSet>
    {
        template <typename D> using type = consume_Windows_Media_SpeechRecognition_IVoiceCommandSet<D>;
    };
}
#endif
