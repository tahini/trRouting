// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: simulationCollection.capnp

#include "simulationCollection.capnp.h"

namespace capnp {
namespace schemas {
static const ::capnp::_::AlignedData<40> b_b16f82ff3b7534df = {
  {   0,   0,   0,   0,   5,   0,   6,   0,
    223,  52, 117,  59, 255, 130, 111, 177,
     27,   0,   0,   0,   1,   0,   0,   0,
     80, 154, 232,  76,  62,  50, 172, 138,
      1,   0,   7,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     21,   0,   0,   0, 130,   1,   0,   0,
     41,   0,   0,   0,   7,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     37,   0,   0,   0,  63,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    115, 105, 109, 117, 108,  97, 116, 105,
    111, 110,  67, 111, 108, 108, 101,  99,
    116, 105, 111, 110,  46,  99,  97, 112,
    110, 112,  58,  83, 105, 109, 117, 108,
     97, 116, 105, 111, 110,  67, 111, 108,
    108, 101,  99, 116, 105, 111, 110,   0,
      0,   0,   0,   0,   1,   0,   1,   0,
      4,   0,   0,   0,   3,   0,   4,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   1,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     13,   0,   0,   0,  98,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   3,   0,   1,   0,
     40,   0,   0,   0,   2,   0,   1,   0,
    115, 105, 109, 117, 108,  97, 116, 105,
    111, 110, 115,   0,   0,   0,   0,   0,
     14,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   3,   0,   1,   0,
     16,   0,   0,   0,   0,   0,   0,   0,
     24, 168,  15, 153,  95, 111, 133, 227,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     14,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0, }
};
::capnp::word const* const bp_b16f82ff3b7534df = b_b16f82ff3b7534df.words;
#if !CAPNP_LITE
static const ::capnp::_::RawSchema* const d_b16f82ff3b7534df[] = {
  &s_e3856f5f990fa818,
};
static const uint16_t m_b16f82ff3b7534df[] = {0};
static const uint16_t i_b16f82ff3b7534df[] = {0};
const ::capnp::_::RawSchema s_b16f82ff3b7534df = {
  0xb16f82ff3b7534df, b_b16f82ff3b7534df.words, 40, d_b16f82ff3b7534df, m_b16f82ff3b7534df,
  1, 1, i_b16f82ff3b7534df, nullptr, nullptr, { &s_b16f82ff3b7534df, nullptr, nullptr, 0, 0, nullptr }
};
#endif  // !CAPNP_LITE
static const ::capnp::_::AlignedData<191> b_e3856f5f990fa818 = {
  {   0,   0,   0,   0,   5,   0,   6,   0,
     24, 168,  15, 153,  95, 111, 133, 227,
     27,   0,   0,   0,   1,   0,   1,   0,
     80, 154, 232,  76,  62,  50, 172, 138,
      7,   0,   7,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     21,   0,   0,   0,  50,   1,   0,   0,
     37,   0,   0,   0,   7,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     33,   0,   0,   0, 111,   2,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    115, 105, 109, 117, 108,  97, 116, 105,
    111, 110,  67, 111, 108, 108, 101,  99,
    116, 105, 111, 110,  46,  99,  97, 112,
    110, 112,  58,  83, 105, 109, 117, 108,
     97, 116, 105, 111, 110,   0,   0,   0,
      0,   0,   0,   0,   1,   0,   1,   0,
     44,   0,   0,   0,   3,   0,   4,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   1,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     37,   1,   0,   0,  42,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     32,   1,   0,   0,   3,   0,   1,   0,
     44,   1,   0,   0,   2,   0,   1,   0,
      1,   0,   0,   0,   1,   0,   0,   0,
      0,   0,   1,   0,   1,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     41,   1,   0,   0,  82,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     40,   1,   0,   0,   3,   0,   1,   0,
     52,   1,   0,   0,   2,   0,   1,   0,
      2,   0,   0,   0,   2,   0,   0,   0,
      0,   0,   1,   0,   2,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     49,   1,   0,   0,  42,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     44,   1,   0,   0,   3,   0,   1,   0,
     56,   1,   0,   0,   2,   0,   1,   0,
      3,   0,   0,   0,   3,   0,   0,   0,
      0,   0,   1,   0,   3,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     53,   1,   0,   0,  90,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     52,   1,   0,   0,   3,   0,   1,   0,
     64,   1,   0,   0,   2,   0,   1,   0,
      4,   0,   0,   0,   4,   0,   0,   0,
      0,   0,   1,   0,   4,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     61,   1,   0,   0,  50,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     56,   1,   0,   0,   3,   0,   1,   0,
     68,   1,   0,   0,   2,   0,   1,   0,
      5,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   1,   0,   5,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     65,   1,   0,   0,  82,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     64,   1,   0,   0,   3,   0,   1,   0,
     76,   1,   0,   0,   2,   0,   1,   0,
      6,   0,   0,   0,   1,   0,   0,   0,
      0,   0,   1,   0,   6,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     73,   1,   0,   0,  82,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     72,   1,   0,   0,   3,   0,   1,   0,
     84,   1,   0,   0,   2,   0,   1,   0,
      7,   0,   0,   0,   2,   0,   0,   0,
      0,   0,   1,   0,   7,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     81,   1,   0,   0,  98,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     80,   1,   0,   0,   3,   0,   1,   0,
     92,   1,   0,   0,   2,   0,   1,   0,
      8,   0,   0,   0,   5,   0,   0,   0,
      0,   0,   1,   0,   8,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     89,   1,   0,   0,  98,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     88,   1,   0,   0,   3,   0,   1,   0,
    100,   1,   0,   0,   2,   0,   1,   0,
      9,   0,   0,   0,   6,   0,   0,   0,
      0,   0,   1,   0,   9,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     97,   1,   0,   0,  42,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     92,   1,   0,   0,   3,   0,   1,   0,
    104,   1,   0,   0,   2,   0,   1,   0,
     10,   0,   0,   0,   3,   0,   0,   0,
      0,   0,   1,   0,  10,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    101,   1,   0,   0,  74,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    100,   1,   0,   0,   3,   0,   1,   0,
    112,   1,   0,   0,   2,   0,   1,   0,
    117, 117, 105, 100,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    115, 104, 111, 114, 116, 110,  97, 109,
    101,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    110,  97, 109, 101,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    105, 110, 116, 101, 114, 110,  97, 108,
     73, 100,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     99, 111, 108, 111, 114,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    105, 115,  69, 110,  97,  98, 108, 101,
    100,   0,   0,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    105, 115,  83, 116,  97, 114, 116, 101,
    100,   0,   0,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    105, 115,  67, 111, 109, 112, 108, 101,
    116, 101, 100,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    100, 101, 115,  99, 114, 105, 112, 116,
    105, 111, 110,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    100,  97, 116,  97,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
     12,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
    105, 115,  70, 114, 111, 122, 101, 110,
      0,   0,   0,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0, }
};
::capnp::word const* const bp_e3856f5f990fa818 = b_e3856f5f990fa818.words;
#if !CAPNP_LITE
static const uint16_t m_e3856f5f990fa818[] = {4, 9, 8, 3, 7, 5, 10, 6, 2, 1, 0};
static const uint16_t i_e3856f5f990fa818[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const ::capnp::_::RawSchema s_e3856f5f990fa818 = {
  0xe3856f5f990fa818, b_e3856f5f990fa818.words, 191, nullptr, m_e3856f5f990fa818,
  0, 11, i_e3856f5f990fa818, nullptr, nullptr, { &s_e3856f5f990fa818, nullptr, nullptr, 0, 0, nullptr }
};
#endif  // !CAPNP_LITE
}  // namespace schemas
}  // namespace capnp

// =======================================================================================

namespace simulationCollection {

// SimulationCollection
constexpr uint16_t SimulationCollection::_capnpPrivate::dataWordSize;
constexpr uint16_t SimulationCollection::_capnpPrivate::pointerCount;
#if !CAPNP_LITE
constexpr ::capnp::Kind SimulationCollection::_capnpPrivate::kind;
constexpr ::capnp::_::RawSchema const* SimulationCollection::_capnpPrivate::schema;
#endif  // !CAPNP_LITE

// Simulation
constexpr uint16_t Simulation::_capnpPrivate::dataWordSize;
constexpr uint16_t Simulation::_capnpPrivate::pointerCount;
#if !CAPNP_LITE
constexpr ::capnp::Kind Simulation::_capnpPrivate::kind;
constexpr ::capnp::_::RawSchema const* Simulation::_capnpPrivate::schema;
#endif  // !CAPNP_LITE


}  // namespace

