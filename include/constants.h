// chess_constants.h
#ifndef HARMONY_CHESS_CONSTANTS_H
#define HARMONY_CHESS_CONSTANTS_H
#include <cstdint>
#include <array>
#include "aliases.h"
#include "constants_utils.h"
// Board is little endian rank file mapping such that 
// a1 is the first bit; starting from the right

// 8 4 2 1 8 4 2 1
// 8 4 2 1 8 4 2 1 ...

//  1 0 0 0  0 0 0 1 = 0x0000000000000081
//  0 0 0 0  0 0 0 1 = 0x0000000000000181
//  0 0 0 0  0 0 0 1 = 0x0000000000010181
//  0 0 0 0  0 0 0 1 = 0x0000000001010181
//  0 0 0 0  0 0 0 1 ...
//  0 0 0 0  0 0 0 1
//  0 0 0 0  0 0 0 1
//MSB 0 0 0  0 0 0 1



namespace harmony_chess {

  // squares

  enum class square_value : u64 {
    //    0x0000 0000 0000 0000
    A_1 = 0x0000000000000001, //
    B_1 = 0x0000000000000002,
    C_1 = 0x0000000000000004,
    D_1 = 0x0000000000000008,
    E_1 = 0x0000000000000010,
    F_1 = 0x0000000000000020,
    G_1 = 0x0000000000000040,
    H_1 = 0x0000000000000080,

    A_2 = 0x0000000000000100,
    B_2 = 0x0000000000000200,
    C_2 = 0x0000000000000400,
    D_2 = 0x0000000000000800,
    E_2 = 0x0000000000001000,
    F_2 = 0x0000000000002000,
    G_2 = 0x0000000000004000,
    H_2 = 0x0000000000008000,

    A_3 = 0x0000000000010000,
    B_3 = 0x0000000000020000,
    C_3 = 0x0000000000040000,
    D_3 = 0x0000000000080000,
    E_3 = 0x0000000000100000,
    F_3 = 0x0000000000200000,
    G_3 = 0x0000000000400000,
    H_3 = 0x0000000000800000,

    A_4 = 0x0000000001000000,
    B_4 = 0x0000000002000000,
    C_4 = 0x0000000004000000,
    D_4 = 0x0000000008000000,
    E_4 = 0x0000000010000000,
    F_4 = 0x0000000020000000,
    G_4 = 0x0000000040000000,
    H_4 = 0x0000000080000000,

    A_5 = 0x0000000100000000,
    B_5 = 0x0000000200000000,
    C_5 = 0x0000000400000000,
    D_5 = 0x0000000800000000,
    E_5 = 0x0000001000000000,
    F_5 = 0x0000002000000000,
    G_5 = 0x0000004000000000,
    H_5 = 0x0000008000000000,

    A_6 = 0x0000010000000000,
    B_6 = 0x0000020000000000,
    C_6 = 0x0000040000000000,
    D_6 = 0x0000080000000000,
    E_6 = 0x0000100000000000,
    F_6 = 0x0000200000000000,
    G_6 = 0x0000400000000000,
    H_6 = 0x0000800000000000,

    A_7 = 0x0001000000000000,
    B_7 = 0x0002000000000000,
    C_7 = 0x0004000000000000,
    D_7 = 0x0008000000000000,
    E_7 = 0x0010000000000000,
    F_7 = 0x0020000000000000,
    G_7 = 0x0040000000000000,
    H_7 = 0x0080000000000000,

    A_8 = 0x0100000000000000,
    B_8 = 0x0200000000000000,
    C_8 = 0x0400000000000000,
    D_8 = 0x0800000000000000,
    E_8 = 0x1000000000000000,
    F_8 = 0x2000000000000000,
    G_8 = 0x4000000000000000,
    H_8 = 0x8000000000000000
  };

  enum class square_identifier : u8 {
    A_1, B_1, C_1, D_1, E_1, F_1, G_1, H_1,
    A_2, B_2, C_2, D_2, E_2, F_2, G_2, H_2,
    A_3, B_3, C_3, D_3, E_3, F_3, G_3, H_3,
    A_4, B_4, C_4, D_4, E_4, F_4, G_4, H_4,
    A_5, B_5, C_5, D_5, E_5, F_5, G_5, H_5,
    A_6, B_6, C_6, D_6, E_6, F_6, G_6, H_6,
    A_7, B_7, C_7, D_7, E_7, F_7, G_7, H_7,
    A_8, B_8, C_8, D_8, E_8, F_8, G_8, H_8
  };


  // files

  constexpr u64 A_FILE = 0x0101010101010101;
  constexpr u64 B_FILE = 0x0202020202020202;
  constexpr u64 C_FILE = 0x0404040404040404;
  constexpr u64 D_FILE = 0x0808080808080808;
  constexpr u64 E_FILE = 0x1010101010101010;
  constexpr u64 F_FILE = 0x2020202020202020;
  constexpr u64 G_File = 0x4040404040404040;
  constexpr u64 H_File = 0x8080808080808080;

  // ranks

  constexpr u64 RankOne = 0x00000000000000ff;
  constexpr u64 RankTwo = 0x000000000000ff00;
  constexpr u64 RankThree = 0x0000000000ff0000;
  constexpr u64 RankFour = 0x00000000ff000000;
  constexpr u64 RankFive = 0x000000ff00000000;
  constexpr u64 RankSix = 0x0000ff0000000000;
  constexpr u64 RankSeven = 0x00ff000000000000;
  constexpr u64 RankEight = 0xff00000000000000;

  // color-specific squares

  constexpr u64 LightSquares = 0x55aa55aa55aa55aa;
  constexpr u64 DarkSquares = 0xaa55aa55aa55aa55;

  // diagonals (main-diagonal[a1-h8], anti-diagonal[h1-a8])

  constexpr u64 MainDiagonal = 0x8040201008040201;
  constexpr u64 AntiDiagonal = 0x102040810204080;

  // directions

  enum class direction : int {
    noWe = 7,
    nort = 8,
    noEa = 9,

    soEa = -7,
    sout = -8,
    soWe = -9,

    east = 1,
    west = -1,

  };

  // universal constants

  constexpr u64 UniversalSet = 0xffffffffffffffff;

  // ray constants
  // rays stored in clock wise order starting from north:
  //    [nort, noEa, east, soEa, sout, soWE, west, noWe]

  constexpr std::array<u64, 8> calculate_ray_masks(square_value the_square) {
  // returns an array containing all ray_masks for the_square provided

    std::array<u64, 8> the_masks = std::array<u64, 8>();
    the_masks[0] = calculate_a_ray_mask(the_square, direction::nort);
    the_masks[1] = calculate_a_ray_mask(the_square, direction::noEa);
    the_masks[2] = calculate_a_ray_mask(the_square, direction::east);
    the_masks[3] = calculate_a_ray_mask(the_square, direction::soEa);
    the_masks[4] = calculate_a_ray_mask(the_square, direction::sout);
    the_masks[5] = calculate_a_ray_mask(the_square, direction::soWe);
    the_masks[6] = calculate_a_ray_mask(the_square, direction::west);
    the_masks[7] = calculate_a_ray_mask(the_square, direction::noWe);
    return the_masks;
  } ;

  constexpr std::array<u64, 8> A_1_RayMasks = calculate_ray_masks(square_value::A_1);
  constexpr std::array<u64, 8> B_1_RayMasks = calculate_ray_masks(square_value::B_1);
  constexpr std::array<u64, 8> C_1_RayMasks = calculate_ray_masks(square_value::C_1);
  constexpr std::array<u64, 8> D_1_RayMasks = calculate_ray_masks(square_value::D_1);
  constexpr std::array<u64, 8> E_1_RayMasks = calculate_ray_masks(square_value::E_1);
  constexpr std::array<u64, 8> F_1_RayMasks = calculate_ray_masks(square_value::F_1);
  constexpr std::array<u64, 8> G_1_RayMasks = calculate_ray_masks(square_value::G_1);
  constexpr std::array<u64, 8> H_1_RayMasks = calculate_ray_masks(square_value::H_1);

  constexpr std::array<u64, 8> A_2_RayMasks = calculate_ray_masks(square_value::A_2);
  constexpr std::array<u64, 8> B_2_RayMasks = calculate_ray_masks(square_value::B_2);
  constexpr std::array<u64, 8> C_2_RayMasks = calculate_ray_masks(square_value::C_2);
  constexpr std::array<u64, 8> D_2_RayMasks = calculate_ray_masks(square_value::D_2);
  constexpr std::array<u64, 8> E_2_RayMasks = calculate_ray_masks(square_value::E_2);
  constexpr std::array<u64, 8> F_2_RayMasks = calculate_ray_masks(square_value::F_2);
  constexpr std::array<u64, 8> G_2_RayMasks = calculate_ray_masks(square_value::G_2);
  constexpr std::array<u64, 8> H_2_RayMasks = calculate_ray_masks(square_value::H_2);

  constexpr std::array<u64, 8> A_3_RayMasks = calculate_ray_masks(square_value::A_3);
  constexpr std::array<u64, 8> B_3_RayMasks = calculate_ray_masks(square_value::B_3);
  constexpr std::array<u64, 8> C_3_RayMasks = calculate_ray_masks(square_value::C_3);
  constexpr std::array<u64, 8> D_3_RayMasks = calculate_ray_masks(square_value::D_3);
  constexpr std::array<u64, 8> E_3_RayMasks = calculate_ray_masks(square_value::E_3);
  constexpr std::array<u64, 8> F_3_RayMasks = calculate_ray_masks(square_value::F_3);
  constexpr std::array<u64, 8> G_3_RayMasks = calculate_ray_masks(square_value::G_3);
  constexpr std::array<u64, 8> H_3_RayMasks = calculate_ray_masks(square_value::H_3);

  constexpr std::array<u64, 8> A_4_RayMasks = calculate_ray_masks(square_value::A_4);
  constexpr std::array<u64, 8> B_4_RayMasks = calculate_ray_masks(square_value::B_4);
  constexpr std::array<u64, 8> C_4_RayMasks = calculate_ray_masks(square_value::C_4);
  constexpr std::array<u64, 8> D_4_RayMasks = calculate_ray_masks(square_value::D_4);
  constexpr std::array<u64, 8> E_4_RayMasks = calculate_ray_masks(square_value::E_4);
  constexpr std::array<u64, 8> F_4_RayMasks = calculate_ray_masks(square_value::F_4);
  constexpr std::array<u64, 8> G_4_RayMasks = calculate_ray_masks(square_value::G_4);
  constexpr std::array<u64, 8> H_4_RayMasks = calculate_ray_masks(square_value::H_4);

  constexpr std::array<u64, 8> A_5_RayMasks = calculate_ray_masks(square_value::A_5);
  constexpr std::array<u64, 8> B_5_RayMasks = calculate_ray_masks(square_value::B_5);
  constexpr std::array<u64, 8> C_5_RayMasks = calculate_ray_masks(square_value::C_5);
  constexpr std::array<u64, 8> D_5_RayMasks = calculate_ray_masks(square_value::D_5);
  constexpr std::array<u64, 8> E_5_RayMasks = calculate_ray_masks(square_value::E_5);
  constexpr std::array<u64, 8> F_5_RayMasks = calculate_ray_masks(square_value::F_5);
  constexpr std::array<u64, 8> G_5_RayMasks = calculate_ray_masks(square_value::G_5);
  constexpr std::array<u64, 8> H_5_RayMasks = calculate_ray_masks(square_value::H_5);

  constexpr std::array<u64, 8> A_6_RayMasks = calculate_ray_masks(square_value::A_6);
  constexpr std::array<u64, 8> B_6_RayMasks = calculate_ray_masks(square_value::B_6);
  constexpr std::array<u64, 8> C_6_RayMasks = calculate_ray_masks(square_value::C_6);
  constexpr std::array<u64, 8> D_6_RayMasks = calculate_ray_masks(square_value::D_6);
  constexpr std::array<u64, 8> E_6_RayMasks = calculate_ray_masks(square_value::E_6);
  constexpr std::array<u64, 8> F_6_RayMasks = calculate_ray_masks(square_value::F_6);
  constexpr std::array<u64, 8> G_6_RayMasks = calculate_ray_masks(square_value::G_6);
  constexpr std::array<u64, 8> H_6_RayMasks = calculate_ray_masks(square_value::H_6);

  constexpr std::array<u64, 8> A_7_RayMasks = calculate_ray_masks(square_value::A_7);
  constexpr std::array<u64, 8> B_7_RayMasks = calculate_ray_masks(square_value::B_7);
  constexpr std::array<u64, 8> C_7_RayMasks = calculate_ray_masks(square_value::C_7);
  constexpr std::array<u64, 8> D_7_RayMasks = calculate_ray_masks(square_value::D_7);
  constexpr std::array<u64, 8> E_7_RayMasks = calculate_ray_masks(square_value::E_7);
  constexpr std::array<u64, 8> F_7_RayMasks = calculate_ray_masks(square_value::F_7);
  constexpr std::array<u64, 8> G_7_RayMasks = calculate_ray_masks(square_value::G_7);
  constexpr std::array<u64, 8> H_7_RayMasks = calculate_ray_masks(square_value::H_7);

  constexpr std::array<u64, 8> A_8_RayMasks = calculate_ray_masks(square_value::A_8);
  constexpr std::array<u64, 8> B_8_RayMasks = calculate_ray_masks(square_value::B_8);
  constexpr std::array<u64, 8> C_8_RayMasks = calculate_ray_masks(square_value::C_8);
  constexpr std::array<u64, 8> D_8_RayMasks = calculate_ray_masks(square_value::D_8);
  constexpr std::array<u64, 8> E_8_RayMasks = calculate_ray_masks(square_value::E_8);
  constexpr std::array<u64, 8> F_8_RayMasks = calculate_ray_masks(square_value::F_8);
  constexpr std::array<u64, 8> G_8_RayMasks = calculate_ray_masks(square_value::G_8);
  constexpr std::array<u64, 8> H_8_RayMasks = calculate_ray_masks(square_value::H_8);

}


#endif // HARMONY_CHESS_CONSTANTS_H