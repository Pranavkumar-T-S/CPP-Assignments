// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: versions.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_versions_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_versions_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_versions_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_versions_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_versions_2eproto;
namespace versions {
class Change;
struct ChangeDefaultTypeInternal;
extern ChangeDefaultTypeInternal _Change_default_instance_;
class Version;
struct VersionDefaultTypeInternal;
extern VersionDefaultTypeInternal _Version_default_instance_;
class Versions;
struct VersionsDefaultTypeInternal;
extern VersionsDefaultTypeInternal _Versions_default_instance_;
}  // namespace versions
PROTOBUF_NAMESPACE_OPEN
template<> ::versions::Change* Arena::CreateMaybeMessage<::versions::Change>(Arena*);
template<> ::versions::Version* Arena::CreateMaybeMessage<::versions::Version>(Arena*);
template<> ::versions::Versions* Arena::CreateMaybeMessage<::versions::Versions>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace versions {

enum OperationType : int {
  ADD = 0,
  UPDATE = 1,
  DELETE = 2,
  OperationType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  OperationType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool OperationType_IsValid(int value);
constexpr OperationType OperationType_MIN = ADD;
constexpr OperationType OperationType_MAX = DELETE;
constexpr int OperationType_ARRAYSIZE = OperationType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* OperationType_descriptor();
template<typename T>
inline const std::string& OperationType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, OperationType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function OperationType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    OperationType_descriptor(), enum_t_value);
}
inline bool OperationType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, OperationType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<OperationType>(
    OperationType_descriptor(), name, value);
}
// ===================================================================

class Change final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:versions.Change) */ {
 public:
  inline Change() : Change(nullptr) {}
  ~Change() override;
  explicit PROTOBUF_CONSTEXPR Change(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Change(const Change& from);
  Change(Change&& from) noexcept
    : Change() {
    *this = ::std::move(from);
  }

  inline Change& operator=(const Change& from) {
    CopyFrom(from);
    return *this;
  }
  inline Change& operator=(Change&& from) noexcept {
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
  static const Change& default_instance() {
    return *internal_default_instance();
  }
  static inline const Change* internal_default_instance() {
    return reinterpret_cast<const Change*>(
               &_Change_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Change& a, Change& b) {
    a.Swap(&b);
  }
  inline void Swap(Change* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Change* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Change* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Change>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Change& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Change& from) {
    Change::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Change* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "versions.Change";
  }
  protected:
  explicit Change(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLine0FieldNumber = 3,
    kLine1FieldNumber = 4,
    kTimestampFieldNumber = 5,
    kOpearationtypeFieldNumber = 1,
    kLinenumFieldNumber = 2,
  };
  // string line0 = 3;
  void clear_line0();
  const std::string& line0() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_line0(ArgT0&& arg0, ArgT... args);
  std::string* mutable_line0();
  PROTOBUF_NODISCARD std::string* release_line0();
  void set_allocated_line0(std::string* line0);
  private:
  const std::string& _internal_line0() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_line0(const std::string& value);
  std::string* _internal_mutable_line0();
  public:

  // optional string line1 = 4;
  bool has_line1() const;
  private:
  bool _internal_has_line1() const;
  public:
  void clear_line1();
  const std::string& line1() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_line1(ArgT0&& arg0, ArgT... args);
  std::string* mutable_line1();
  PROTOBUF_NODISCARD std::string* release_line1();
  void set_allocated_line1(std::string* line1);
  private:
  const std::string& _internal_line1() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_line1(const std::string& value);
  std::string* _internal_mutable_line1();
  public:

  // string timestamp = 5;
  void clear_timestamp();
  const std::string& timestamp() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_timestamp(ArgT0&& arg0, ArgT... args);
  std::string* mutable_timestamp();
  PROTOBUF_NODISCARD std::string* release_timestamp();
  void set_allocated_timestamp(std::string* timestamp);
  private:
  const std::string& _internal_timestamp() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_timestamp(const std::string& value);
  std::string* _internal_mutable_timestamp();
  public:

  // .versions.OperationType opearationtype = 1;
  void clear_opearationtype();
  ::versions::OperationType opearationtype() const;
  void set_opearationtype(::versions::OperationType value);
  private:
  ::versions::OperationType _internal_opearationtype() const;
  void _internal_set_opearationtype(::versions::OperationType value);
  public:

  // int32 linenum = 2;
  void clear_linenum();
  int32_t linenum() const;
  void set_linenum(int32_t value);
  private:
  int32_t _internal_linenum() const;
  void _internal_set_linenum(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:versions.Change)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr line0_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr line1_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr timestamp_;
    int opearationtype_;
    int32_t linenum_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_versions_2eproto;
};
// -------------------------------------------------------------------

class Version final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:versions.Version) */ {
 public:
  inline Version() : Version(nullptr) {}
  ~Version() override;
  explicit PROTOBUF_CONSTEXPR Version(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Version(const Version& from);
  Version(Version&& from) noexcept
    : Version() {
    *this = ::std::move(from);
  }

  inline Version& operator=(const Version& from) {
    CopyFrom(from);
    return *this;
  }
  inline Version& operator=(Version&& from) noexcept {
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
  static const Version& default_instance() {
    return *internal_default_instance();
  }
  static inline const Version* internal_default_instance() {
    return reinterpret_cast<const Version*>(
               &_Version_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Version& a, Version& b) {
    a.Swap(&b);
  }
  inline void Swap(Version* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Version* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Version* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Version>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Version& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Version& from) {
    Version::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Version* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "versions.Version";
  }
  protected:
  explicit Version(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kChangesFieldNumber = 2,
    kCreatedTimeFieldNumber = 3,
    kVersionNumberFieldNumber = 1,
  };
  // repeated .versions.Change changes = 2;
  int changes_size() const;
  private:
  int _internal_changes_size() const;
  public:
  void clear_changes();
  ::versions::Change* mutable_changes(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >*
      mutable_changes();
  private:
  const ::versions::Change& _internal_changes(int index) const;
  ::versions::Change* _internal_add_changes();
  public:
  const ::versions::Change& changes(int index) const;
  ::versions::Change* add_changes();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >&
      changes() const;

  // string createdTime = 3;
  void clear_createdtime();
  const std::string& createdtime() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_createdtime(ArgT0&& arg0, ArgT... args);
  std::string* mutable_createdtime();
  PROTOBUF_NODISCARD std::string* release_createdtime();
  void set_allocated_createdtime(std::string* createdtime);
  private:
  const std::string& _internal_createdtime() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_createdtime(const std::string& value);
  std::string* _internal_mutable_createdtime();
  public:

  // int32 versionNumber = 1;
  void clear_versionnumber();
  int32_t versionnumber() const;
  void set_versionnumber(int32_t value);
  private:
  int32_t _internal_versionnumber() const;
  void _internal_set_versionnumber(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:versions.Version)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change > changes_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr createdtime_;
    int32_t versionnumber_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_versions_2eproto;
};
// -------------------------------------------------------------------

class Versions final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:versions.Versions) */ {
 public:
  inline Versions() : Versions(nullptr) {}
  ~Versions() override;
  explicit PROTOBUF_CONSTEXPR Versions(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Versions(const Versions& from);
  Versions(Versions&& from) noexcept
    : Versions() {
    *this = ::std::move(from);
  }

  inline Versions& operator=(const Versions& from) {
    CopyFrom(from);
    return *this;
  }
  inline Versions& operator=(Versions&& from) noexcept {
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
  static const Versions& default_instance() {
    return *internal_default_instance();
  }
  static inline const Versions* internal_default_instance() {
    return reinterpret_cast<const Versions*>(
               &_Versions_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Versions& a, Versions& b) {
    a.Swap(&b);
  }
  inline void Swap(Versions* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Versions* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Versions* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Versions>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Versions& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Versions& from) {
    Versions::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Versions* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "versions.Versions";
  }
  protected:
  explicit Versions(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kVersionlistFieldNumber = 1,
    kChangesFieldNumber = 2,
  };
  // repeated .versions.Version versionlist = 1;
  int versionlist_size() const;
  private:
  int _internal_versionlist_size() const;
  public:
  void clear_versionlist();
  ::versions::Version* mutable_versionlist(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Version >*
      mutable_versionlist();
  private:
  const ::versions::Version& _internal_versionlist(int index) const;
  ::versions::Version* _internal_add_versionlist();
  public:
  const ::versions::Version& versionlist(int index) const;
  ::versions::Version* add_versionlist();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Version >&
      versionlist() const;

  // repeated .versions.Change changes = 2;
  int changes_size() const;
  private:
  int _internal_changes_size() const;
  public:
  void clear_changes();
  ::versions::Change* mutable_changes(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >*
      mutable_changes();
  private:
  const ::versions::Change& _internal_changes(int index) const;
  ::versions::Change* _internal_add_changes();
  public:
  const ::versions::Change& changes(int index) const;
  ::versions::Change* add_changes();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >&
      changes() const;

  // @@protoc_insertion_point(class_scope:versions.Versions)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Version > versionlist_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change > changes_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_versions_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Change

// .versions.OperationType opearationtype = 1;
inline void Change::clear_opearationtype() {
  _impl_.opearationtype_ = 0;
}
inline ::versions::OperationType Change::_internal_opearationtype() const {
  return static_cast< ::versions::OperationType >(_impl_.opearationtype_);
}
inline ::versions::OperationType Change::opearationtype() const {
  // @@protoc_insertion_point(field_get:versions.Change.opearationtype)
  return _internal_opearationtype();
}
inline void Change::_internal_set_opearationtype(::versions::OperationType value) {
  
  _impl_.opearationtype_ = value;
}
inline void Change::set_opearationtype(::versions::OperationType value) {
  _internal_set_opearationtype(value);
  // @@protoc_insertion_point(field_set:versions.Change.opearationtype)
}

// int32 linenum = 2;
inline void Change::clear_linenum() {
  _impl_.linenum_ = 0;
}
inline int32_t Change::_internal_linenum() const {
  return _impl_.linenum_;
}
inline int32_t Change::linenum() const {
  // @@protoc_insertion_point(field_get:versions.Change.linenum)
  return _internal_linenum();
}
inline void Change::_internal_set_linenum(int32_t value) {
  
  _impl_.linenum_ = value;
}
inline void Change::set_linenum(int32_t value) {
  _internal_set_linenum(value);
  // @@protoc_insertion_point(field_set:versions.Change.linenum)
}

// string line0 = 3;
inline void Change::clear_line0() {
  _impl_.line0_.ClearToEmpty();
}
inline const std::string& Change::line0() const {
  // @@protoc_insertion_point(field_get:versions.Change.line0)
  return _internal_line0();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Change::set_line0(ArgT0&& arg0, ArgT... args) {
 
 _impl_.line0_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:versions.Change.line0)
}
inline std::string* Change::mutable_line0() {
  std::string* _s = _internal_mutable_line0();
  // @@protoc_insertion_point(field_mutable:versions.Change.line0)
  return _s;
}
inline const std::string& Change::_internal_line0() const {
  return _impl_.line0_.Get();
}
inline void Change::_internal_set_line0(const std::string& value) {
  
  _impl_.line0_.Set(value, GetArenaForAllocation());
}
inline std::string* Change::_internal_mutable_line0() {
  
  return _impl_.line0_.Mutable(GetArenaForAllocation());
}
inline std::string* Change::release_line0() {
  // @@protoc_insertion_point(field_release:versions.Change.line0)
  return _impl_.line0_.Release();
}
inline void Change::set_allocated_line0(std::string* line0) {
  if (line0 != nullptr) {
    
  } else {
    
  }
  _impl_.line0_.SetAllocated(line0, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.line0_.IsDefault()) {
    _impl_.line0_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:versions.Change.line0)
}

// optional string line1 = 4;
inline bool Change::_internal_has_line1() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Change::has_line1() const {
  return _internal_has_line1();
}
inline void Change::clear_line1() {
  _impl_.line1_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Change::line1() const {
  // @@protoc_insertion_point(field_get:versions.Change.line1)
  return _internal_line1();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Change::set_line1(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.line1_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:versions.Change.line1)
}
inline std::string* Change::mutable_line1() {
  std::string* _s = _internal_mutable_line1();
  // @@protoc_insertion_point(field_mutable:versions.Change.line1)
  return _s;
}
inline const std::string& Change::_internal_line1() const {
  return _impl_.line1_.Get();
}
inline void Change::_internal_set_line1(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.line1_.Set(value, GetArenaForAllocation());
}
inline std::string* Change::_internal_mutable_line1() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.line1_.Mutable(GetArenaForAllocation());
}
inline std::string* Change::release_line1() {
  // @@protoc_insertion_point(field_release:versions.Change.line1)
  if (!_internal_has_line1()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.line1_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.line1_.IsDefault()) {
    _impl_.line1_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Change::set_allocated_line1(std::string* line1) {
  if (line1 != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.line1_.SetAllocated(line1, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.line1_.IsDefault()) {
    _impl_.line1_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:versions.Change.line1)
}

// string timestamp = 5;
inline void Change::clear_timestamp() {
  _impl_.timestamp_.ClearToEmpty();
}
inline const std::string& Change::timestamp() const {
  // @@protoc_insertion_point(field_get:versions.Change.timestamp)
  return _internal_timestamp();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Change::set_timestamp(ArgT0&& arg0, ArgT... args) {
 
 _impl_.timestamp_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:versions.Change.timestamp)
}
inline std::string* Change::mutable_timestamp() {
  std::string* _s = _internal_mutable_timestamp();
  // @@protoc_insertion_point(field_mutable:versions.Change.timestamp)
  return _s;
}
inline const std::string& Change::_internal_timestamp() const {
  return _impl_.timestamp_.Get();
}
inline void Change::_internal_set_timestamp(const std::string& value) {
  
  _impl_.timestamp_.Set(value, GetArenaForAllocation());
}
inline std::string* Change::_internal_mutable_timestamp() {
  
  return _impl_.timestamp_.Mutable(GetArenaForAllocation());
}
inline std::string* Change::release_timestamp() {
  // @@protoc_insertion_point(field_release:versions.Change.timestamp)
  return _impl_.timestamp_.Release();
}
inline void Change::set_allocated_timestamp(std::string* timestamp) {
  if (timestamp != nullptr) {
    
  } else {
    
  }
  _impl_.timestamp_.SetAllocated(timestamp, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.timestamp_.IsDefault()) {
    _impl_.timestamp_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:versions.Change.timestamp)
}

// -------------------------------------------------------------------

// Version

// int32 versionNumber = 1;
inline void Version::clear_versionnumber() {
  _impl_.versionnumber_ = 0;
}
inline int32_t Version::_internal_versionnumber() const {
  return _impl_.versionnumber_;
}
inline int32_t Version::versionnumber() const {
  // @@protoc_insertion_point(field_get:versions.Version.versionNumber)
  return _internal_versionnumber();
}
inline void Version::_internal_set_versionnumber(int32_t value) {
  
  _impl_.versionnumber_ = value;
}
inline void Version::set_versionnumber(int32_t value) {
  _internal_set_versionnumber(value);
  // @@protoc_insertion_point(field_set:versions.Version.versionNumber)
}

// repeated .versions.Change changes = 2;
inline int Version::_internal_changes_size() const {
  return _impl_.changes_.size();
}
inline int Version::changes_size() const {
  return _internal_changes_size();
}
inline void Version::clear_changes() {
  _impl_.changes_.Clear();
}
inline ::versions::Change* Version::mutable_changes(int index) {
  // @@protoc_insertion_point(field_mutable:versions.Version.changes)
  return _impl_.changes_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >*
Version::mutable_changes() {
  // @@protoc_insertion_point(field_mutable_list:versions.Version.changes)
  return &_impl_.changes_;
}
inline const ::versions::Change& Version::_internal_changes(int index) const {
  return _impl_.changes_.Get(index);
}
inline const ::versions::Change& Version::changes(int index) const {
  // @@protoc_insertion_point(field_get:versions.Version.changes)
  return _internal_changes(index);
}
inline ::versions::Change* Version::_internal_add_changes() {
  return _impl_.changes_.Add();
}
inline ::versions::Change* Version::add_changes() {
  ::versions::Change* _add = _internal_add_changes();
  // @@protoc_insertion_point(field_add:versions.Version.changes)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >&
Version::changes() const {
  // @@protoc_insertion_point(field_list:versions.Version.changes)
  return _impl_.changes_;
}

// string createdTime = 3;
inline void Version::clear_createdtime() {
  _impl_.createdtime_.ClearToEmpty();
}
inline const std::string& Version::createdtime() const {
  // @@protoc_insertion_point(field_get:versions.Version.createdTime)
  return _internal_createdtime();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Version::set_createdtime(ArgT0&& arg0, ArgT... args) {
 
 _impl_.createdtime_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:versions.Version.createdTime)
}
inline std::string* Version::mutable_createdtime() {
  std::string* _s = _internal_mutable_createdtime();
  // @@protoc_insertion_point(field_mutable:versions.Version.createdTime)
  return _s;
}
inline const std::string& Version::_internal_createdtime() const {
  return _impl_.createdtime_.Get();
}
inline void Version::_internal_set_createdtime(const std::string& value) {
  
  _impl_.createdtime_.Set(value, GetArenaForAllocation());
}
inline std::string* Version::_internal_mutable_createdtime() {
  
  return _impl_.createdtime_.Mutable(GetArenaForAllocation());
}
inline std::string* Version::release_createdtime() {
  // @@protoc_insertion_point(field_release:versions.Version.createdTime)
  return _impl_.createdtime_.Release();
}
inline void Version::set_allocated_createdtime(std::string* createdtime) {
  if (createdtime != nullptr) {
    
  } else {
    
  }
  _impl_.createdtime_.SetAllocated(createdtime, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.createdtime_.IsDefault()) {
    _impl_.createdtime_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:versions.Version.createdTime)
}

// -------------------------------------------------------------------

// Versions

// repeated .versions.Version versionlist = 1;
inline int Versions::_internal_versionlist_size() const {
  return _impl_.versionlist_.size();
}
inline int Versions::versionlist_size() const {
  return _internal_versionlist_size();
}
inline void Versions::clear_versionlist() {
  _impl_.versionlist_.Clear();
}
inline ::versions::Version* Versions::mutable_versionlist(int index) {
  // @@protoc_insertion_point(field_mutable:versions.Versions.versionlist)
  return _impl_.versionlist_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Version >*
Versions::mutable_versionlist() {
  // @@protoc_insertion_point(field_mutable_list:versions.Versions.versionlist)
  return &_impl_.versionlist_;
}
inline const ::versions::Version& Versions::_internal_versionlist(int index) const {
  return _impl_.versionlist_.Get(index);
}
inline const ::versions::Version& Versions::versionlist(int index) const {
  // @@protoc_insertion_point(field_get:versions.Versions.versionlist)
  return _internal_versionlist(index);
}
inline ::versions::Version* Versions::_internal_add_versionlist() {
  return _impl_.versionlist_.Add();
}
inline ::versions::Version* Versions::add_versionlist() {
  ::versions::Version* _add = _internal_add_versionlist();
  // @@protoc_insertion_point(field_add:versions.Versions.versionlist)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Version >&
Versions::versionlist() const {
  // @@protoc_insertion_point(field_list:versions.Versions.versionlist)
  return _impl_.versionlist_;
}

// repeated .versions.Change changes = 2;
inline int Versions::_internal_changes_size() const {
  return _impl_.changes_.size();
}
inline int Versions::changes_size() const {
  return _internal_changes_size();
}
inline void Versions::clear_changes() {
  _impl_.changes_.Clear();
}
inline ::versions::Change* Versions::mutable_changes(int index) {
  // @@protoc_insertion_point(field_mutable:versions.Versions.changes)
  return _impl_.changes_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >*
Versions::mutable_changes() {
  // @@protoc_insertion_point(field_mutable_list:versions.Versions.changes)
  return &_impl_.changes_;
}
inline const ::versions::Change& Versions::_internal_changes(int index) const {
  return _impl_.changes_.Get(index);
}
inline const ::versions::Change& Versions::changes(int index) const {
  // @@protoc_insertion_point(field_get:versions.Versions.changes)
  return _internal_changes(index);
}
inline ::versions::Change* Versions::_internal_add_changes() {
  return _impl_.changes_.Add();
}
inline ::versions::Change* Versions::add_changes() {
  ::versions::Change* _add = _internal_add_changes();
  // @@protoc_insertion_point(field_add:versions.Versions.changes)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::versions::Change >&
Versions::changes() const {
  // @@protoc_insertion_point(field_list:versions.Versions.changes)
  return _impl_.changes_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace versions

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::versions::OperationType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::versions::OperationType>() {
  return ::versions::OperationType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_versions_2eproto