// constants_utils.h
#ifndef HARMONY_CHESS_CONSTANTS_UITLS_H
#define HARMONY_CHESS_CONSTANTS_UITLS_H
#include <stdlib.h>
#include "aliases.h"

namespace harmony_chess {
  enum class square_value : u64;
  enum class direction : int;
  enum class square_identifier : u8;

  constexpr uint8_t get_file_from_square_value(square_value square) {
    return __builtin_ctzll(static_cast<uint64_t>(square)) % 8;
}

  constexpr square_identifier square_value_to_identifier(square_value the_square) {
    u8 i = 0;
    u64 current_value = static_cast<u64>(the_square);
    while (current_value != 0) {
      current_value >>= 1;
      ++i;
    }
    --i;
    return static_cast<square_identifier>(i);
  } ;

  constexpr square_value square_identifier_to_value(square_identifier the_square) {
    u64 i = 0x1;
    u8 current_value = static_cast<u8>(the_square) - 1;
    while (current_value != 0) {
      i <<= 1;
    }
    return static_cast<square_value>(i);
  } ;

  constexpr u64 calculate_a_ray_mask(square_value the_square, direction the_direction) {
    // returns a specific ray mask given the_direction and the_square
  
      u64 current_mask = static_cast<u64>(the_square);
      u64 temp_mask = current_mask;
      int direction_value = static_cast<int>(the_direction);
      if (direction_value == 1) {
        u8 number_of_moves_possible_east = 7 - get_file_from_square_value(the_square);
        while (number_of_moves_possible_east > 0) {
          temp_mask <<= abs(direction_value);
          current_mask |= temp_mask;
          --number_of_moves_possible_east;
        }
      } else if (direction_value == -1) {
        u8 number_of_moves_possible_west = get_file_from_square_value(the_square);
        while (number_of_moves_possible_west > 0) {
          temp_mask >>= abs(direction_value);
          current_mask |= temp_mask;
          --number_of_moves_possible_west;
        }
      } else if (direction_value > 0) {

        while (temp_mask > 0) {
          temp_mask <<= abs(direction_value);
          current_mask |= temp_mask;
        }
      } else if (direction_value < 0) {
        while (temp_mask > 0) {
          temp_mask >>= abs(direction_value);
          current_mask |= temp_mask;
        }
      }
      return current_mask;
    } ;
}


#endif // HARMONY_CHESS_CONSTANTS_ITLS_H

        // n = 8
        // a1 = 0x0000 0000 0000 0000
                         
        // A_1_NortRay = 0b0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001
  
        //               current mask                                                                         temp mask
        // before loop = 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 || 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001
  
        //             = 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0000 0001 || 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0000 0000
        //             = 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0000 0001 0000 0001 || 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0000 0000 0000 0000
        //             = 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0000 0001 0000 0001 0000 0001 || 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0000 0000 0000 0000 0000 0000
        //             = 0b0000 0000 0000 0000 0000 0000 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 || 0b0000 0000 0000 0000 0000 0000 0000 0001 0000 0000 0000 0000 0000 0000 0000 0000
        //             = 0b0000 0000 0000 0000 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 || 0b0000 0000 0000 0000 0000 0001 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
        //             = 0b0000 0000 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 || 0b0000 0000 0000 0001 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
        //             = 0b0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 0000 0001 || 0b0000 0001 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
  
        //    end loop = 0b0000 0001 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 || 0b0
        
        // A_7_NortRay = 0b0000 0001 0000 0001 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
  
        // B_1_NoEaRay = 0b0000 0000 1000 0000 0100 0000 0010 0000 0001 0000 0000 1000 0000 0100 0000 0010