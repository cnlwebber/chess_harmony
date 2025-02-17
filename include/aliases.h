// aliases.h
#ifndef HARMONY_CHESS_ALIASES_H
#define HARMONY_CHESS_ALIASES_H

// ALWAYS INCLUDE <cstdint> IN HEADERS THAT INCLUDE aliases.h IF THE HEADER EXPLICITLY USES uint64_t, uint8_t, or int32_t
#include <cstdint>


namespace harmony_chess {
  using u64 = uint64_t;
  using u16 = uint16_t;
  using u8 = uint8_t;
  using s8 = int8_t;
}


#endif // HARMONY_CHESS_ALIASES_H