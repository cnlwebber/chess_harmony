// square_utils.h
#ifndef HARMONY_CHESS_SQUARE_UTILS_H
#define HARMONY_CHESS_SQUARE_UTILS_H

#include <cstdint>
#include <stdlib.h>
#include "aliases.h"
#include "constants.h"


namespace harmony_chess {

  // ranks    1, 2, 3, 4, 5, 6, 7, 8 are zero indexed when returned
  // as such: 0, 1, 2, 3, 4, 5, 6, 7
  u8 get_rank(SquareIdentifier the_square) ; 
    //return static_cast<u8>(the_square) >> 3 ;

  // files    a, b, c, d, e, f, g, h are zero indexed when returned
  // as such: 0, 1, 2, 3, 4, 5, 6, 7
  u8 get_file(SquareIdentifier the_square) ;
    //return static_cast<u8>(the_square) % 8; 

  u8 rank_difference(SquareIdentifier the_square, SquareIdentifier the_other_square) ;
    //return abs((static_cast<u8>(the_square) >> 3) - (static_cast<u8>(the_other_square) >> 3));

  u8 file_difference(SquareIdentifier the_square, SquareIdentifier the_other_square) ;
    //return abs((static_cast<u8>(the_square) % 8) - (static_cast<u8>(the_other_square) % 8));
    
  SquareIdentifier square_by_rank_and_file(u8 the_rank, u8 the_file) ;

  constexpr SquareIdentifier SquareValue_to_identifier(SquareValue the_square) {
    return static_cast<SquareIdentifier>(__builtin_ctzll(static_cast<u64>(the_square)));
  } ;



}

#endif // HARMONY_CHESS_SQUARE_UTILS_H