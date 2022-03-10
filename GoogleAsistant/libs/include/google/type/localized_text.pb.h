// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/type/localized_text.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2flocalized_5ftext_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2flocalized_5ftext_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_google_2ftype_2flocalized_5ftext_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2ftype_2flocalized_5ftext_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_google_2ftype_2flocalized_5ftext_2eproto;
namespace google {
namespace type {
class LocalizedText;
struct LocalizedTextDefaultTypeInternal;
extern LocalizedTextDefaultTypeInternal _LocalizedText_default_instance_;
}  // namespace type
}  // namespace google
PROTOBUF_NAMESPACE_OPEN
template<> ::google::type::LocalizedText* Arena::CreateMaybeMessage<::google::type::LocalizedText>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace google {
namespace type {

// ===================================================================

class LocalizedText final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:google.type.LocalizedText) */ {
 public:
  inline LocalizedText() : LocalizedText(nullptr) {}
  ~LocalizedText() override;
  explicit constexpr LocalizedText(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LocalizedText(const LocalizedText& from);
  LocalizedText(LocalizedText&& from) noexcept
    : LocalizedText() {
    *this = ::std::move(from);
  }

  inline LocalizedText& operator=(const LocalizedText& from) {
    CopyFrom(from);
    return *this;
  }
  inline LocalizedText& operator=(LocalizedText&& from) noexcept {
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
  static const LocalizedText& default_instance() {
    return *internal_default_instance();
  }
  static inline const LocalizedText* internal_default_instance() {
    return reinterpret_cast<const LocalizedText*>(
               &_LocalizedText_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(LocalizedText& a, LocalizedText& b) {
    a.Swap(&b);
  }
  inline void Swap(LocalizedText* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LocalizedText* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline LocalizedText* New() const final {
    return new LocalizedText();
  }

  LocalizedText* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<LocalizedText>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LocalizedText& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const LocalizedText& from);
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
  void InternalSwap(LocalizedText* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "google.type.LocalizedText";
  }
  protected:
  explicit LocalizedText(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kTextFieldNumber = 1,
    kLanguageCodeFieldNumber = 2,
  };
  // string text = 1;
  void clear_text();
  const std::string& text() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_text(ArgT0&& arg0, ArgT... args);
  std::string* mutable_text();
  PROTOBUF_MUST_USE_RESULT std::string* release_text();
  void set_allocated_text(std::string* text);
  private:
  const std::string& _internal_text() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_text(const std::string& value);
  std::string* _internal_mutable_text();
  public:

  // string language_code = 2;
  void clear_language_code();
  const std::string& language_code() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_language_code(ArgT0&& arg0, ArgT... args);
  std::string* mutable_language_code();
  PROTOBUF_MUST_USE_RESULT std::string* release_language_code();
  void set_allocated_language_code(std::string* language_code);
  private:
  const std::string& _internal_language_code() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_language_code(const std::string& value);
  std::string* _internal_mutable_language_code();
  public:

  // @@protoc_insertion_point(class_scope:google.type.LocalizedText)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr language_code_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_google_2ftype_2flocalized_5ftext_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// LocalizedText

// string text = 1;
inline void LocalizedText::clear_text() {
  text_.ClearToEmpty();
}
inline const std::string& LocalizedText::text() const {
  // @@protoc_insertion_point(field_get:google.type.LocalizedText.text)
  return _internal_text();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LocalizedText::set_text(ArgT0&& arg0, ArgT... args) {
 
 text_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.type.LocalizedText.text)
}
inline std::string* LocalizedText::mutable_text() {
  std::string* _s = _internal_mutable_text();
  // @@protoc_insertion_point(field_mutable:google.type.LocalizedText.text)
  return _s;
}
inline const std::string& LocalizedText::_internal_text() const {
  return text_.Get();
}
inline void LocalizedText::_internal_set_text(const std::string& value) {
  
  text_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* LocalizedText::_internal_mutable_text() {
  
  return text_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* LocalizedText::release_text() {
  // @@protoc_insertion_point(field_release:google.type.LocalizedText.text)
  return text_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void LocalizedText::set_allocated_text(std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  text_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), text,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.type.LocalizedText.text)
}

// string language_code = 2;
inline void LocalizedText::clear_language_code() {
  language_code_.ClearToEmpty();
}
inline const std::string& LocalizedText::language_code() const {
  // @@protoc_insertion_point(field_get:google.type.LocalizedText.language_code)
  return _internal_language_code();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LocalizedText::set_language_code(ArgT0&& arg0, ArgT... args) {
 
 language_code_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.type.LocalizedText.language_code)
}
inline std::string* LocalizedText::mutable_language_code() {
  std::string* _s = _internal_mutable_language_code();
  // @@protoc_insertion_point(field_mutable:google.type.LocalizedText.language_code)
  return _s;
}
inline const std::string& LocalizedText::_internal_language_code() const {
  return language_code_.Get();
}
inline void LocalizedText::_internal_set_language_code(const std::string& value) {
  
  language_code_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* LocalizedText::_internal_mutable_language_code() {
  
  return language_code_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* LocalizedText::release_language_code() {
  // @@protoc_insertion_point(field_release:google.type.LocalizedText.language_code)
  return language_code_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void LocalizedText::set_allocated_language_code(std::string* language_code) {
  if (language_code != nullptr) {
    
  } else {
    
  }
  language_code_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), language_code,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.type.LocalizedText.language_code)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace type
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2flocalized_5ftext_2eproto
