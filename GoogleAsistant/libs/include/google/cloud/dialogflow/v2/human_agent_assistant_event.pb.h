// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/cloud/dialogflow/v2/human_agent_assistant_event.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fdialogflow_2fv2_2fhuman_5fagent_5fassistant_5fevent_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fdialogflow_2fv2_2fhuman_5fagent_5fassistant_5fevent_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3018000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3018000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "google/cloud/dialogflow/v2/participant.pb.h"
#include "google/api/annotations.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_google_2fcloud_2fdialogflow_2fv2_2fhuman_5fagent_5fassistant_5fevent_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fcloud_2fdialogflow_2fv2_2fhuman_5fagent_5fassistant_5fevent_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_google_2fcloud_2fdialogflow_2fv2_2fhuman_5fagent_5fassistant_5fevent_2eproto;
namespace google {
namespace cloud {
namespace dialogflow {
namespace v2 {
class HumanAgentAssistantEvent;
struct HumanAgentAssistantEventDefaultTypeInternal;
extern HumanAgentAssistantEventDefaultTypeInternal _HumanAgentAssistantEvent_default_instance_;
}  // namespace v2
}  // namespace dialogflow
}  // namespace cloud
}  // namespace google
PROTOBUF_NAMESPACE_OPEN
template<> ::google::cloud::dialogflow::v2::HumanAgentAssistantEvent* Arena::CreateMaybeMessage<::google::cloud::dialogflow::v2::HumanAgentAssistantEvent>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace google {
namespace cloud {
namespace dialogflow {
namespace v2 {

// ===================================================================

class HumanAgentAssistantEvent final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:google.cloud.dialogflow.v2.HumanAgentAssistantEvent) */ {
 public:
  inline HumanAgentAssistantEvent() : HumanAgentAssistantEvent(nullptr) {}
  ~HumanAgentAssistantEvent() override;
  explicit constexpr HumanAgentAssistantEvent(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  HumanAgentAssistantEvent(const HumanAgentAssistantEvent& from);
  HumanAgentAssistantEvent(HumanAgentAssistantEvent&& from) noexcept
    : HumanAgentAssistantEvent() {
    *this = ::std::move(from);
  }

  inline HumanAgentAssistantEvent& operator=(const HumanAgentAssistantEvent& from) {
    CopyFrom(from);
    return *this;
  }
  inline HumanAgentAssistantEvent& operator=(HumanAgentAssistantEvent&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HumanAgentAssistantEvent& default_instance() {
    return *internal_default_instance();
  }
  static inline const HumanAgentAssistantEvent* internal_default_instance() {
    return reinterpret_cast<const HumanAgentAssistantEvent*>(
               &_HumanAgentAssistantEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(HumanAgentAssistantEvent& a, HumanAgentAssistantEvent& b) {
    a.Swap(&b);
  }
  inline void Swap(HumanAgentAssistantEvent* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HumanAgentAssistantEvent* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline HumanAgentAssistantEvent* New() const final {
    return new HumanAgentAssistantEvent();
  }

  HumanAgentAssistantEvent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<HumanAgentAssistantEvent>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const HumanAgentAssistantEvent& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const HumanAgentAssistantEvent& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HumanAgentAssistantEvent* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "google.cloud.dialogflow.v2.HumanAgentAssistantEvent";
  }
  protected:
  explicit HumanAgentAssistantEvent(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSuggestionResultsFieldNumber = 5,
    kConversationFieldNumber = 1,
    kParticipantFieldNumber = 3,
  };
  // repeated .google.cloud.dialogflow.v2.SuggestionResult suggestion_results = 5;
  int suggestion_results_size() const;
  private:
  int _internal_suggestion_results_size() const;
  public:
  void clear_suggestion_results();
  ::google::cloud::dialogflow::v2::SuggestionResult* mutable_suggestion_results(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::SuggestionResult >*
      mutable_suggestion_results();
  private:
  const ::google::cloud::dialogflow::v2::SuggestionResult& _internal_suggestion_results(int index) const;
  ::google::cloud::dialogflow::v2::SuggestionResult* _internal_add_suggestion_results();
  public:
  const ::google::cloud::dialogflow::v2::SuggestionResult& suggestion_results(int index) const;
  ::google::cloud::dialogflow::v2::SuggestionResult* add_suggestion_results();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::SuggestionResult >&
      suggestion_results() const;

  // string conversation = 1;
  void clear_conversation();
  const std::string& conversation() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_conversation(ArgT0&& arg0, ArgT... args);
  std::string* mutable_conversation();
  PROTOBUF_MUST_USE_RESULT std::string* release_conversation();
  void set_allocated_conversation(std::string* conversation);
  private:
  const std::string& _internal_conversation() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_conversation(const std::string& value);
  std::string* _internal_mutable_conversation();
  public:

  // string participant = 3;
  void clear_participant();
  const std::string& participant() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_participant(ArgT0&& arg0, ArgT... args);
  std::string* mutable_participant();
  PROTOBUF_MUST_USE_RESULT std::string* release_participant();
  void set_allocated_participant(std::string* participant);
  private:
  const std::string& _internal_participant() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_participant(const std::string& value);
  std::string* _internal_mutable_participant();
  public:

  // @@protoc_insertion_point(class_scope:google.cloud.dialogflow.v2.HumanAgentAssistantEvent)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::SuggestionResult > suggestion_results_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr conversation_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr participant_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_google_2fcloud_2fdialogflow_2fv2_2fhuman_5fagent_5fassistant_5fevent_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HumanAgentAssistantEvent

// string conversation = 1;
inline void HumanAgentAssistantEvent::clear_conversation() {
  conversation_.ClearToEmpty();
}
inline const std::string& HumanAgentAssistantEvent::conversation() const {
  // @@protoc_insertion_point(field_get:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.conversation)
  return _internal_conversation();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void HumanAgentAssistantEvent::set_conversation(ArgT0&& arg0, ArgT... args) {
 
 conversation_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.conversation)
}
inline std::string* HumanAgentAssistantEvent::mutable_conversation() {
  std::string* _s = _internal_mutable_conversation();
  // @@protoc_insertion_point(field_mutable:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.conversation)
  return _s;
}
inline const std::string& HumanAgentAssistantEvent::_internal_conversation() const {
  return conversation_.Get();
}
inline void HumanAgentAssistantEvent::_internal_set_conversation(const std::string& value) {
  
  conversation_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* HumanAgentAssistantEvent::_internal_mutable_conversation() {
  
  return conversation_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* HumanAgentAssistantEvent::release_conversation() {
  // @@protoc_insertion_point(field_release:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.conversation)
  return conversation_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void HumanAgentAssistantEvent::set_allocated_conversation(std::string* conversation) {
  if (conversation != nullptr) {
    
  } else {
    
  }
  conversation_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), conversation,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.conversation)
}

// string participant = 3;
inline void HumanAgentAssistantEvent::clear_participant() {
  participant_.ClearToEmpty();
}
inline const std::string& HumanAgentAssistantEvent::participant() const {
  // @@protoc_insertion_point(field_get:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.participant)
  return _internal_participant();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void HumanAgentAssistantEvent::set_participant(ArgT0&& arg0, ArgT... args) {
 
 participant_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.participant)
}
inline std::string* HumanAgentAssistantEvent::mutable_participant() {
  std::string* _s = _internal_mutable_participant();
  // @@protoc_insertion_point(field_mutable:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.participant)
  return _s;
}
inline const std::string& HumanAgentAssistantEvent::_internal_participant() const {
  return participant_.Get();
}
inline void HumanAgentAssistantEvent::_internal_set_participant(const std::string& value) {
  
  participant_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* HumanAgentAssistantEvent::_internal_mutable_participant() {
  
  return participant_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* HumanAgentAssistantEvent::release_participant() {
  // @@protoc_insertion_point(field_release:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.participant)
  return participant_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void HumanAgentAssistantEvent::set_allocated_participant(std::string* participant) {
  if (participant != nullptr) {
    
  } else {
    
  }
  participant_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), participant,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.participant)
}

// repeated .google.cloud.dialogflow.v2.SuggestionResult suggestion_results = 5;
inline int HumanAgentAssistantEvent::_internal_suggestion_results_size() const {
  return suggestion_results_.size();
}
inline int HumanAgentAssistantEvent::suggestion_results_size() const {
  return _internal_suggestion_results_size();
}
inline ::google::cloud::dialogflow::v2::SuggestionResult* HumanAgentAssistantEvent::mutable_suggestion_results(int index) {
  // @@protoc_insertion_point(field_mutable:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.suggestion_results)
  return suggestion_results_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::SuggestionResult >*
HumanAgentAssistantEvent::mutable_suggestion_results() {
  // @@protoc_insertion_point(field_mutable_list:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.suggestion_results)
  return &suggestion_results_;
}
inline const ::google::cloud::dialogflow::v2::SuggestionResult& HumanAgentAssistantEvent::_internal_suggestion_results(int index) const {
  return suggestion_results_.Get(index);
}
inline const ::google::cloud::dialogflow::v2::SuggestionResult& HumanAgentAssistantEvent::suggestion_results(int index) const {
  // @@protoc_insertion_point(field_get:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.suggestion_results)
  return _internal_suggestion_results(index);
}
inline ::google::cloud::dialogflow::v2::SuggestionResult* HumanAgentAssistantEvent::_internal_add_suggestion_results() {
  return suggestion_results_.Add();
}
inline ::google::cloud::dialogflow::v2::SuggestionResult* HumanAgentAssistantEvent::add_suggestion_results() {
  ::google::cloud::dialogflow::v2::SuggestionResult* _add = _internal_add_suggestion_results();
  // @@protoc_insertion_point(field_add:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.suggestion_results)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::google::cloud::dialogflow::v2::SuggestionResult >&
HumanAgentAssistantEvent::suggestion_results() const {
  // @@protoc_insertion_point(field_list:google.cloud.dialogflow.v2.HumanAgentAssistantEvent.suggestion_results)
  return suggestion_results_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace v2
}  // namespace dialogflow
}  // namespace cloud
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fdialogflow_2fv2_2fhuman_5fagent_5fassistant_5fevent_2eproto
