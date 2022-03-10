// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/type/expr.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2fexpr_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2fexpr_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_google_2ftype_2fexpr_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2ftype_2fexpr_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_google_2ftype_2fexpr_2eproto;
namespace google {
namespace type {
class Expr;
struct ExprDefaultTypeInternal;
extern ExprDefaultTypeInternal _Expr_default_instance_;
}  // namespace type
}  // namespace google
PROTOBUF_NAMESPACE_OPEN
template<> ::google::type::Expr* Arena::CreateMaybeMessage<::google::type::Expr>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace google {
namespace type {

// ===================================================================

class Expr final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:google.type.Expr) */ {
 public:
  inline Expr() : Expr(nullptr) {}
  ~Expr() override;
  explicit constexpr Expr(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Expr(const Expr& from);
  Expr(Expr&& from) noexcept
    : Expr() {
    *this = ::std::move(from);
  }

  inline Expr& operator=(const Expr& from) {
    CopyFrom(from);
    return *this;
  }
  inline Expr& operator=(Expr&& from) noexcept {
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
  static const Expr& default_instance() {
    return *internal_default_instance();
  }
  static inline const Expr* internal_default_instance() {
    return reinterpret_cast<const Expr*>(
               &_Expr_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Expr& a, Expr& b) {
    a.Swap(&b);
  }
  inline void Swap(Expr* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Expr* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Expr* New() const final {
    return new Expr();
  }

  Expr* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Expr>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Expr& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Expr& from);
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
  void InternalSwap(Expr* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "google.type.Expr";
  }
  protected:
  explicit Expr(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kExpressionFieldNumber = 1,
    kTitleFieldNumber = 2,
    kDescriptionFieldNumber = 3,
    kLocationFieldNumber = 4,
  };
  // string expression = 1;
  void clear_expression();
  const std::string& expression() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_expression(ArgT0&& arg0, ArgT... args);
  std::string* mutable_expression();
  PROTOBUF_MUST_USE_RESULT std::string* release_expression();
  void set_allocated_expression(std::string* expression);
  private:
  const std::string& _internal_expression() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_expression(const std::string& value);
  std::string* _internal_mutable_expression();
  public:

  // string title = 2;
  void clear_title();
  const std::string& title() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_title(ArgT0&& arg0, ArgT... args);
  std::string* mutable_title();
  PROTOBUF_MUST_USE_RESULT std::string* release_title();
  void set_allocated_title(std::string* title);
  private:
  const std::string& _internal_title() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_title(const std::string& value);
  std::string* _internal_mutable_title();
  public:

  // string description = 3;
  void clear_description();
  const std::string& description() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_description(ArgT0&& arg0, ArgT... args);
  std::string* mutable_description();
  PROTOBUF_MUST_USE_RESULT std::string* release_description();
  void set_allocated_description(std::string* description);
  private:
  const std::string& _internal_description() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_description(const std::string& value);
  std::string* _internal_mutable_description();
  public:

  // string location = 4;
  void clear_location();
  const std::string& location() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_location(ArgT0&& arg0, ArgT... args);
  std::string* mutable_location();
  PROTOBUF_MUST_USE_RESULT std::string* release_location();
  void set_allocated_location(std::string* location);
  private:
  const std::string& _internal_location() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_location(const std::string& value);
  std::string* _internal_mutable_location();
  public:

  // @@protoc_insertion_point(class_scope:google.type.Expr)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr expression_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr title_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr description_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr location_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_google_2ftype_2fexpr_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Expr

// string expression = 1;
inline void Expr::clear_expression() {
  expression_.ClearToEmpty();
}
inline const std::string& Expr::expression() const {
  // @@protoc_insertion_point(field_get:google.type.Expr.expression)
  return _internal_expression();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Expr::set_expression(ArgT0&& arg0, ArgT... args) {
 
 expression_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.type.Expr.expression)
}
inline std::string* Expr::mutable_expression() {
  std::string* _s = _internal_mutable_expression();
  // @@protoc_insertion_point(field_mutable:google.type.Expr.expression)
  return _s;
}
inline const std::string& Expr::_internal_expression() const {
  return expression_.Get();
}
inline void Expr::_internal_set_expression(const std::string& value) {
  
  expression_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Expr::_internal_mutable_expression() {
  
  return expression_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Expr::release_expression() {
  // @@protoc_insertion_point(field_release:google.type.Expr.expression)
  return expression_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Expr::set_allocated_expression(std::string* expression) {
  if (expression != nullptr) {
    
  } else {
    
  }
  expression_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), expression,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.type.Expr.expression)
}

// string title = 2;
inline void Expr::clear_title() {
  title_.ClearToEmpty();
}
inline const std::string& Expr::title() const {
  // @@protoc_insertion_point(field_get:google.type.Expr.title)
  return _internal_title();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Expr::set_title(ArgT0&& arg0, ArgT... args) {
 
 title_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.type.Expr.title)
}
inline std::string* Expr::mutable_title() {
  std::string* _s = _internal_mutable_title();
  // @@protoc_insertion_point(field_mutable:google.type.Expr.title)
  return _s;
}
inline const std::string& Expr::_internal_title() const {
  return title_.Get();
}
inline void Expr::_internal_set_title(const std::string& value) {
  
  title_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Expr::_internal_mutable_title() {
  
  return title_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Expr::release_title() {
  // @@protoc_insertion_point(field_release:google.type.Expr.title)
  return title_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Expr::set_allocated_title(std::string* title) {
  if (title != nullptr) {
    
  } else {
    
  }
  title_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), title,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.type.Expr.title)
}

// string description = 3;
inline void Expr::clear_description() {
  description_.ClearToEmpty();
}
inline const std::string& Expr::description() const {
  // @@protoc_insertion_point(field_get:google.type.Expr.description)
  return _internal_description();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Expr::set_description(ArgT0&& arg0, ArgT... args) {
 
 description_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.type.Expr.description)
}
inline std::string* Expr::mutable_description() {
  std::string* _s = _internal_mutable_description();
  // @@protoc_insertion_point(field_mutable:google.type.Expr.description)
  return _s;
}
inline const std::string& Expr::_internal_description() const {
  return description_.Get();
}
inline void Expr::_internal_set_description(const std::string& value) {
  
  description_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Expr::_internal_mutable_description() {
  
  return description_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Expr::release_description() {
  // @@protoc_insertion_point(field_release:google.type.Expr.description)
  return description_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Expr::set_allocated_description(std::string* description) {
  if (description != nullptr) {
    
  } else {
    
  }
  description_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), description,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.type.Expr.description)
}

// string location = 4;
inline void Expr::clear_location() {
  location_.ClearToEmpty();
}
inline const std::string& Expr::location() const {
  // @@protoc_insertion_point(field_get:google.type.Expr.location)
  return _internal_location();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Expr::set_location(ArgT0&& arg0, ArgT... args) {
 
 location_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.type.Expr.location)
}
inline std::string* Expr::mutable_location() {
  std::string* _s = _internal_mutable_location();
  // @@protoc_insertion_point(field_mutable:google.type.Expr.location)
  return _s;
}
inline const std::string& Expr::_internal_location() const {
  return location_.Get();
}
inline void Expr::_internal_set_location(const std::string& value) {
  
  location_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Expr::_internal_mutable_location() {
  
  return location_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Expr::release_location() {
  // @@protoc_insertion_point(field_release:google.type.Expr.location)
  return location_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Expr::set_allocated_location(std::string* location) {
  if (location != nullptr) {
    
  } else {
    
  }
  location_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), location,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.type.Expr.location)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace type
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2fexpr_2eproto
