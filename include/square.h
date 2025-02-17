#ifndef SQUARE_H
#define SQUARE_H

#include <cstdint>
#include <stdlib.h>
#include "aliases.h"
#include "constants.h"


namespace harmony_chess {

  // ranks    1, 2, 3, 4, 5, 6, 7, 8 are zero indexed when returned
  // as such: 0, 1, 2, 3, 4, 5, 6, 7
  constexpr u8 getRank(square_identifier the_square) {
    return static_cast<u8>(the_square) / 8;
  } ; 

  // files    a, b, c, d, e, f, g, h are zero indexed when returned
  // as such: 0, 1, 2, 3, 4, 5, 6, 7
  constexpr u8 getFile(square_identifier the_square) {
    return static_cast<u8>(the_square) % 8;
  } ; 

  constexpr int getRankDifference(square_identifier the_square, square_identifier the_other_square) {
    return abs((static_cast<u8>(the_square) / 8) - (static_cast<u8>(the_other_square) / 8));
  } ; 

  constexpr int getFileDifference(square_identifier the_square, square_identifier the_other_square) {
    return abs((static_cast<u8>(the_square) % 8) - (static_cast<u8>(the_other_square) % 8));
  } ;

  constexpr square_identifier sqByRankAndFile(u8 the_rank, u8 the_file) {
    u8 i = 0;
    return static_cast<square_identifier>(i);
  } ;
}

#endif // SQUARE_H