// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/cloud/bigquery/storage/v1/avro.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto;
namespace google {
namespace cloud {
namespace bigquery {
namespace storage {
namespace v1 {
class AvroRows;
struct AvroRowsDefaultTypeInternal;
extern AvroRowsDefaultTypeInternal _AvroRows_default_instance_;
class AvroSchema;
struct AvroSchemaDefaultTypeInternal;
extern AvroSchemaDefaultTypeInternal _AvroSchema_default_instance_;
}  // namespace v1
}  // namespace storage
}  // namespace bigquery
}  // namespace cloud
}  // namespace google
PROTOBUF_NAMESPACE_OPEN
template<> ::google::cloud::bigquery::storage::v1::AvroRows* Arena::CreateMaybeMessage<::google::cloud::bigquery::storage::v1::AvroRows>(Arena*);
template<> ::google::cloud::bigquery::storage::v1::AvroSchema* Arena::CreateMaybeMessage<::google::cloud::bigquery::storage::v1::AvroSchema>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace google {
namespace cloud {
namespace bigquery {
namespace storage {
namespace v1 {

// ===================================================================

class AvroSchema final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:google.cloud.bigquery.storage.v1.AvroSchema) */ {
 public:
  inline AvroSchema() : AvroSchema(nullptr) {}
  ~AvroSchema() override;
  explicit constexpr AvroSchema(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  AvroSchema(const AvroSchema& from);
  AvroSchema(AvroSchema&& from) noexcept
    : AvroSchema() {
    *this = ::std::move(from);
  }

  inline AvroSchema& operator=(const AvroSchema& from) {
    CopyFrom(from);
    return *this;
  }
  inline AvroSchema& operator=(AvroSchema&& from) noexcept {
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
  static const AvroSchema& default_instance() {
    return *internal_default_instance();
  }
  static inline const AvroSchema* internal_default_instance() {
    return reinterpret_cast<const AvroSchema*>(
               &_AvroSchema_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(AvroSchema& a, AvroSchema& b) {
    a.Swap(&b);
  }
  inline void Swap(AvroSchema* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(AvroSchema* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline AvroSchema* New() const final {
    return new AvroSchema();
  }

  AvroSchema* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<AvroSchema>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const AvroSchema& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const AvroSchema& from);
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
  void InternalSwap(AvroSchema* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "google.cloud.bigquery.storage.v1.AvroSchema";
  }
  protected:
  explicit AvroSchema(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kSchemaFieldNumber = 1,
  };
  // string schema = 1;
  void clear_schema();
  const std::string& schema() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_schema(ArgT0&& arg0, ArgT... args);
  std::string* mutable_schema();
  PROTOBUF_MUST_USE_RESULT std::string* release_schema();
  void set_allocated_schema(std::string* schema);
  private:
  const std::string& _internal_schema() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_schema(const std::string& value);
  std::string* _internal_mutable_schema();
  public:

  // @@protoc_insertion_point(class_scope:google.cloud.bigquery.storage.v1.AvroSchema)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr schema_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto;
};
// -------------------------------------------------------------------

class AvroRows final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:google.cloud.bigquery.storage.v1.AvroRows) */ {
 public:
  inline AvroRows() : AvroRows(nullptr) {}
  ~AvroRows() override;
  explicit constexpr AvroRows(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  AvroRows(const AvroRows& from);
  AvroRows(AvroRows&& from) noexcept
    : AvroRows() {
    *this = ::std::move(from);
  }

  inline AvroRows& operator=(const AvroRows& from) {
    CopyFrom(from);
    return *this;
  }
  inline AvroRows& operator=(AvroRows&& from) noexcept {
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
  static const AvroRows& default_instance() {
    return *internal_default_instance();
  }
  static inline const AvroRows* internal_default_instance() {
    return reinterpret_cast<const AvroRows*>(
               &_AvroRows_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(AvroRows& a, AvroRows& b) {
    a.Swap(&b);
  }
  inline void Swap(AvroRows* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(AvroRows* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline AvroRows* New() const final {
    return new AvroRows();
  }

  AvroRows* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<AvroRows>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const AvroRows& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const AvroRows& from);
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
  void InternalSwap(AvroRows* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "google.cloud.bigquery.storage.v1.AvroRows";
  }
  protected:
  explicit AvroRows(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kSerializedBinaryRowsFieldNumber = 1,
    kRowCountFieldNumber = 2,
  };
  // bytes serialized_binary_rows = 1;
  void clear_serialized_binary_rows();
  const std::string& serialized_binary_rows() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_serialized_binary_rows(ArgT0&& arg0, ArgT... args);
  std::string* mutable_serialized_binary_rows();
  PROTOBUF_MUST_USE_RESULT std::string* release_serialized_binary_rows();
  void set_allocated_serialized_binary_rows(std::string* serialized_binary_rows);
  private:
  const std::string& _internal_serialized_binary_rows() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_serialized_binary_rows(const std::string& value);
  std::string* _internal_mutable_serialized_binary_rows();
  public:

  // int64 row_count = 2;
  void clear_row_count();
  ::PROTOBUF_NAMESPACE_ID::int64 row_count() const;
  void set_row_count(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_row_count() const;
  void _internal_set_row_count(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:google.cloud.bigquery.storage.v1.AvroRows)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr serialized_binary_rows_;
  ::PROTOBUF_NAMESPACE_ID::int64 row_count_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AvroSchema

// string schema = 1;
inline void AvroSchema::clear_schema() {
  schema_.ClearToEmpty();
}
inline const std::string& AvroSchema::schema() const {
  // @@protoc_insertion_point(field_get:google.cloud.bigquery.storage.v1.AvroSchema.schema)
  return _internal_schema();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void AvroSchema::set_schema(ArgT0&& arg0, ArgT... args) {
 
 schema_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.cloud.bigquery.storage.v1.AvroSchema.schema)
}
inline std::string* AvroSchema::mutable_schema() {
  std::string* _s = _internal_mutable_schema();
  // @@protoc_insertion_point(field_mutable:google.cloud.bigquery.storage.v1.AvroSchema.schema)
  return _s;
}
inline const std::string& AvroSchema::_internal_schema() const {
  return schema_.Get();
}
inline void AvroSchema::_internal_set_schema(const std::string& value) {
  
  schema_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* AvroSchema::_internal_mutable_schema() {
  
  return schema_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* AvroSchema::release_schema() {
  // @@protoc_insertion_point(field_release:google.cloud.bigquery.storage.v1.AvroSchema.schema)
  return schema_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void AvroSchema::set_allocated_schema(std::string* schema) {
  if (schema != nullptr) {
    
  } else {
    
  }
  schema_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), schema,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.cloud.bigquery.storage.v1.AvroSchema.schema)
}

// -------------------------------------------------------------------

// AvroRows

// bytes serialized_binary_rows = 1;
inline void AvroRows::clear_serialized_binary_rows() {
  serialized_binary_rows_.ClearToEmpty();
}
inline const std::string& AvroRows::serialized_binary_rows() const {
  // @@protoc_insertion_point(field_get:google.cloud.bigquery.storage.v1.AvroRows.serialized_binary_rows)
  return _internal_serialized_binary_rows();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void AvroRows::set_serialized_binary_rows(ArgT0&& arg0, ArgT... args) {
 
 serialized_binary_rows_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:google.cloud.bigquery.storage.v1.AvroRows.serialized_binary_rows)
}
inline std::string* AvroRows::mutable_serialized_binary_rows() {
  std::string* _s = _internal_mutable_serialized_binary_rows();
  // @@protoc_insertion_point(field_mutable:google.cloud.bigquery.storage.v1.AvroRows.serialized_binary_rows)
  return _s;
}
inline const std::string& AvroRows::_internal_serialized_binary_rows() const {
  return serialized_binary_rows_.Get();
}
inline void AvroRows::_internal_set_serialized_binary_rows(const std::string& value) {
  
  serialized_binary_rows_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* AvroRows::_internal_mutable_serialized_binary_rows() {
  
  return serialized_binary_rows_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* AvroRows::release_serialized_binary_rows() {
  // @@protoc_insertion_point(field_release:google.cloud.bigquery.storage.v1.AvroRows.serialized_binary_rows)
  return serialized_binary_rows_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void AvroRows::set_allocated_serialized_binary_rows(std::string* serialized_binary_rows) {
  if (serialized_binary_rows != nullptr) {
    
  } else {
    
  }
  serialized_binary_rows_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), serialized_binary_rows,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:google.cloud.bigquery.storage.v1.AvroRows.serialized_binary_rows)
}

// int64 row_count = 2;
inline void AvroRows::clear_row_count() {
  row_count_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 AvroRows::_internal_row_count() const {
  return row_count_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 AvroRows::row_count() const {
  // @@protoc_insertion_point(field_get:google.cloud.bigquery.storage.v1.AvroRows.row_count)
  return _internal_row_count();
}
inline void AvroRows::_internal_set_row_count(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  row_count_ = value;
}
inline void AvroRows::set_row_count(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_row_count(value);
  // @@protoc_insertion_point(field_set:google.cloud.bigquery.storage.v1.AvroRows.row_count)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace storage
}  // namespace bigquery
}  // namespace cloud
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_google_2fcloud_2fbigquery_2fstorage_2fv1_2favro_2eproto
