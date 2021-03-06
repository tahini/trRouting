// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: networkCollection.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#if CAPNP_VERSION != 8000
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif


namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(bb62056ca51825ce);
CAPNP_DECLARE_SCHEMA(bc5b966d8fc87bc3);

}  // namespace schemas
}  // namespace capnp

namespace networkCollection {

struct NetworkCollection {
  NetworkCollection() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(bb62056ca51825ce, 0, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct Network {
  Network() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(bc5b966d8fc87bc3, 1, 11)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class NetworkCollection::Reader {
public:
  typedef NetworkCollection Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool hasNetworks() const;
  inline  ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Reader getNetworks() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class NetworkCollection::Builder {
public:
  typedef NetworkCollection Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool hasNetworks();
  inline  ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Builder getNetworks();
  inline void setNetworks( ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Reader value);
  inline  ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Builder initNetworks(unsigned int size);
  inline void adoptNetworks(::capnp::Orphan< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>> disownNetworks();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class NetworkCollection::Pipeline {
public:
  typedef NetworkCollection Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class Network::Reader {
public:
  typedef Network Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool hasUuid() const;
  inline  ::capnp::Text::Reader getUuid() const;

  inline bool hasShortname() const;
  inline  ::capnp::Text::Reader getShortname() const;

  inline bool hasName() const;
  inline  ::capnp::Text::Reader getName() const;

  inline bool hasInternalId() const;
  inline  ::capnp::Text::Reader getInternalId() const;

  inline bool hasColor() const;
  inline  ::capnp::Text::Reader getColor() const;

  inline  ::int8_t getIsEnabled() const;

  inline bool hasDescription() const;
  inline  ::capnp::Text::Reader getDescription() const;

  inline bool hasData() const;
  inline  ::capnp::Text::Reader getData() const;

  inline bool hasAgenciesUuids() const;
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader getAgenciesUuids() const;

  inline bool hasServicesUuids() const;
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader getServicesUuids() const;

  inline bool hasScenariosUuids() const;
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader getScenariosUuids() const;

  inline  ::int8_t getIsFrozen() const;

  inline bool hasSimulationUuid() const;
  inline  ::capnp::Text::Reader getSimulationUuid() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class Network::Builder {
public:
  typedef Network Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool hasUuid();
  inline  ::capnp::Text::Builder getUuid();
  inline void setUuid( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initUuid(unsigned int size);
  inline void adoptUuid(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownUuid();

  inline bool hasShortname();
  inline  ::capnp::Text::Builder getShortname();
  inline void setShortname( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initShortname(unsigned int size);
  inline void adoptShortname(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownShortname();

  inline bool hasName();
  inline  ::capnp::Text::Builder getName();
  inline void setName( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initName(unsigned int size);
  inline void adoptName(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownName();

  inline bool hasInternalId();
  inline  ::capnp::Text::Builder getInternalId();
  inline void setInternalId( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initInternalId(unsigned int size);
  inline void adoptInternalId(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownInternalId();

  inline bool hasColor();
  inline  ::capnp::Text::Builder getColor();
  inline void setColor( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initColor(unsigned int size);
  inline void adoptColor(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownColor();

  inline  ::int8_t getIsEnabled();
  inline void setIsEnabled( ::int8_t value);

  inline bool hasDescription();
  inline  ::capnp::Text::Builder getDescription();
  inline void setDescription( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initDescription(unsigned int size);
  inline void adoptDescription(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownDescription();

  inline bool hasData();
  inline  ::capnp::Text::Builder getData();
  inline void setData( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initData(unsigned int size);
  inline void adoptData(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownData();

  inline bool hasAgenciesUuids();
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder getAgenciesUuids();
  inline void setAgenciesUuids( ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader value);
  inline void setAgenciesUuids(::kj::ArrayPtr<const  ::capnp::Text::Reader> value);
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder initAgenciesUuids(unsigned int size);
  inline void adoptAgenciesUuids(::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>> disownAgenciesUuids();

  inline bool hasServicesUuids();
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder getServicesUuids();
  inline void setServicesUuids( ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader value);
  inline void setServicesUuids(::kj::ArrayPtr<const  ::capnp::Text::Reader> value);
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder initServicesUuids(unsigned int size);
  inline void adoptServicesUuids(::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>> disownServicesUuids();

  inline bool hasScenariosUuids();
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder getScenariosUuids();
  inline void setScenariosUuids( ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader value);
  inline void setScenariosUuids(::kj::ArrayPtr<const  ::capnp::Text::Reader> value);
  inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder initScenariosUuids(unsigned int size);
  inline void adoptScenariosUuids(::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>> disownScenariosUuids();

  inline  ::int8_t getIsFrozen();
  inline void setIsFrozen( ::int8_t value);

  inline bool hasSimulationUuid();
  inline  ::capnp::Text::Builder getSimulationUuid();
  inline void setSimulationUuid( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initSimulationUuid(unsigned int size);
  inline void adoptSimulationUuid(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownSimulationUuid();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Network::Pipeline {
public:
  typedef Network Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline bool NetworkCollection::Reader::hasNetworks() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool NetworkCollection::Builder::hasNetworks() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Reader NetworkCollection::Reader::getNetworks() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Builder NetworkCollection::Builder::getNetworks() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void NetworkCollection::Builder::setNetworks( ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>::Builder NetworkCollection::Builder::initNetworks(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void NetworkCollection::Builder::adoptNetworks(
    ::capnp::Orphan< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>> NetworkCollection::Builder::disownNetworks() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::networkCollection::Network,  ::capnp::Kind::STRUCT>>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasUuid() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasUuid() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getUuid() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getUuid() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void Network::Builder::setUuid( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initUuid(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptUuid(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownUuid() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasShortname() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasShortname() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getShortname() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getShortname() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void Network::Builder::setShortname( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initShortname(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptShortname(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownShortname() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasName() const {
  return !_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasName() {
  return !_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getName() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline void Network::Builder::setName( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initName(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptName(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasInternalId() const {
  return !_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasInternalId() {
  return !_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getInternalId() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getInternalId() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline void Network::Builder::setInternalId( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initInternalId(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptInternalId(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownInternalId() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasColor() const {
  return !_reader.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasColor() {
  return !_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getColor() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getColor() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}
inline void Network::Builder::setColor( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initColor(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptColor(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownColor() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}

inline  ::int8_t Network::Reader::getIsEnabled() const {
  return _reader.getDataField< ::int8_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::int8_t Network::Builder::getIsEnabled() {
  return _builder.getDataField< ::int8_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void Network::Builder::setIsEnabled( ::int8_t value) {
  _builder.setDataField< ::int8_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline bool Network::Reader::hasDescription() const {
  return !_reader.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasDescription() {
  return !_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getDescription() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getDescription() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS));
}
inline void Network::Builder::setDescription( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initDescription(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptDescription(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownDescription() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasData() const {
  return !_reader.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasData() {
  return !_builder.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getData() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getData() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS));
}
inline void Network::Builder::setData( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initData(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptData(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownData() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<6>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasAgenciesUuids() const {
  return !_reader.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasAgenciesUuids() {
  return !_builder.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader Network::Reader::getAgenciesUuids() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::get(_reader.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS));
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder Network::Builder::getAgenciesUuids() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::get(_builder.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS));
}
inline void Network::Builder::setAgenciesUuids( ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::set(_builder.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS), value);
}
inline void Network::Builder::setAgenciesUuids(::kj::ArrayPtr<const  ::capnp::Text::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::set(_builder.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder Network::Builder::initAgenciesUuids(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::init(_builder.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptAgenciesUuids(
    ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::adopt(_builder.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>> Network::Builder::disownAgenciesUuids() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::disown(_builder.getPointerField(
      ::capnp::bounded<7>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasServicesUuids() const {
  return !_reader.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasServicesUuids() {
  return !_builder.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader Network::Reader::getServicesUuids() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::get(_reader.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS));
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder Network::Builder::getServicesUuids() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::get(_builder.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS));
}
inline void Network::Builder::setServicesUuids( ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::set(_builder.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS), value);
}
inline void Network::Builder::setServicesUuids(::kj::ArrayPtr<const  ::capnp::Text::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::set(_builder.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder Network::Builder::initServicesUuids(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::init(_builder.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptServicesUuids(
    ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::adopt(_builder.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>> Network::Builder::disownServicesUuids() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::disown(_builder.getPointerField(
      ::capnp::bounded<8>() * ::capnp::POINTERS));
}

inline bool Network::Reader::hasScenariosUuids() const {
  return !_reader.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasScenariosUuids() {
  return !_builder.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader Network::Reader::getScenariosUuids() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::get(_reader.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS));
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder Network::Builder::getScenariosUuids() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::get(_builder.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS));
}
inline void Network::Builder::setScenariosUuids( ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::set(_builder.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS), value);
}
inline void Network::Builder::setScenariosUuids(::kj::ArrayPtr<const  ::capnp::Text::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::set(_builder.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>::Builder Network::Builder::initScenariosUuids(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::init(_builder.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptScenariosUuids(
    ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::adopt(_builder.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>> Network::Builder::disownScenariosUuids() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text,  ::capnp::Kind::BLOB>>::disown(_builder.getPointerField(
      ::capnp::bounded<9>() * ::capnp::POINTERS));
}

inline  ::int8_t Network::Reader::getIsFrozen() const {
  return _reader.getDataField< ::int8_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::int8_t Network::Builder::getIsFrozen() {
  return _builder.getDataField< ::int8_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void Network::Builder::setIsFrozen( ::int8_t value) {
  _builder.setDataField< ::int8_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline bool Network::Reader::hasSimulationUuid() const {
  return !_reader.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS).isNull();
}
inline bool Network::Builder::hasSimulationUuid() {
  return !_builder.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Network::Reader::getSimulationUuid() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Network::Builder::getSimulationUuid() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS));
}
inline void Network::Builder::setSimulationUuid( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Network::Builder::initSimulationUuid(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS), size);
}
inline void Network::Builder::adoptSimulationUuid(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Network::Builder::disownSimulationUuid() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<10>() * ::capnp::POINTERS));
}

}  // namespace

