// chess_constants.h
#ifndef HARMONY_CHESS_CONSTANTS_H
#define HARMONY_CHESS_CONSTANTS_H

#include <array>
#include <stdlib.h>
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

  constexpr u8 NumberOfSquares = 64;
  
  enum class SquareValue : u64 {
    A_1 = 0x0000000000000001,
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
  } ;

  enum class SquareIdentifier : u8 {
    A_1, B_1, C_1, D_1, E_1, F_1, G_1, H_1,
    A_2, B_2, C_2, D_2, E_2, F_2, G_2, H_2,
    A_3, B_3, C_3, D_3, E_3, F_3, G_3, H_3,
    A_4, B_4, C_4, D_4, E_4, F_4, G_4, H_4,
    A_5, B_5, C_5, D_5, E_5, F_5, G_5, H_5,
    A_6, B_6, C_6, D_6, E_6, F_6, G_6, H_6,
    A_7, B_7, C_7, D_7, E_7, F_7, G_7, H_7,
    A_8, B_8, C_8, D_8, E_8, F_8, G_8, H_8
  } ;


  // files

  constexpr u8 NumberOfFilesAndRanks = 8;

  constexpr u64 A_File = 0x0101010101010101;
  constexpr u64 B_File = 0x0202020202020202;
  constexpr u64 C_File = 0x0404040404040404;
  constexpr u64 D_File = 0x0808080808080808;
  constexpr u64 E_File = 0x1010101010101010;
  constexpr u64 F_File = 0x2020202020202020;
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

  enum class Direction : s8 {
    noWe = 7,
    nort = 8,
    noEa = 9,

    soEa = -7,
    sout = -8,
    soWe = -9,

    east = 1,
    west = -1,
  } ;

  constexpr u8 NumberOfDirections = 8;

  constexpr std::array<Direction, 8> AllDirections = {
    Direction::nort,
    Direction::noEa,
    Direction::east,
    Direction::soEa,
    Direction::sout,
    Direction::soWe,
    Direction::west,
    Direction::noWe
  };

  // knight moves

  enum class KnightMoves : s8 {
    noNoEa = 17,
    noEaEa = 10,
    soEaEa = -6,
    soSoEa = -15,
    soSoWe = -17,
    soWeWe = -10,
    noWeWe = 6,
    noNoWe = 15
  } ;

  constexpr std::array<KnightMoves, 8> AllKnightMoves = {
    KnightMoves::noNoEa,
    KnightMoves::noEaEa,
    KnightMoves::soEaEa,
    KnightMoves::soSoEa,
    KnightMoves::soSoWe,
    KnightMoves::soWeWe,
    KnightMoves::noWeWe,
    KnightMoves::noNoWe
  };

  // edges and corners

  constexpr u64 AllEdges = 0xff818181818181ff;
  constexpr u64 AllCorners = 0x8100000000000081;

  // center (d4, e4, d5, e5)
  // extended center (c3, d3, e3, f3, c4, d4, ..., f6)

  constexpr u64 MainCenter = 0x0000001818000000;
  constexpr u64 ExtendedCenter = 0x00003C3C3C3C0000;

  // universal constants

  constexpr u64 UniversalSet = 0xffffffffffffffff;

  // evaluations

  enum class PieceWeights : u16 {
    PawnWeight = 100,
    BishopWeight = 300,
    KnightWeight = 300,
    RookWeight = 500,
    QueenWeight = 900,
    KingWeight = 10000
  } ;

  // ray constants
  // rays stored in clock wise order starting from north:
  //    [nort, noEa, east, soEa, sout, soWE, west, noWe]

  constexpr SquareValue SquareIdentifier_to_value(SquareIdentifier the_square) {
    return static_cast<SquareValue>((1ULL << static_cast<u8>(the_square)));
}

  constexpr std::array<std::array<u64, 8>, 64> calculate_ray_masks() {
  // returns an array containing all ray_masks for the_square provided

    std::array<std::array<u64, 8>, 64> all_masks{};
    for (u8 sq = 0; sq < NumberOfSquares; sq++) {
      for (u8 dir = 0; dir < NumberOfDirections; dir++) {
        all_masks[sq][dir] = calculate_a_ray_mask(SquareIdentifier_to_value(static_cast<SquareIdentifier>(sq)), AllDirections[dir]);
      }
    }

    return all_masks;
  } ;

  constexpr u64 calculate_a_ray_mask(SquareValue the_square, Direction the_direction) {
    u64 mask = 0, bit = static_cast<u64>(the_square);
    s8 shift = static_cast<s8>(the_direction);

    while (bit) {
        u8 file = __builtin_ctzll(bit) % 8;
        u8 rank = __builtin_ctzll(bit) >> 3;

        if ((the_direction == Direction::nort  && rank == 7) ||
            (the_direction == Direction::east  && file == 7) ||
            (the_direction == Direction::sout  && rank == 0) ||
            (the_direction == Direction::west  && file == 0) ||

            (the_direction == Direction::noEa  && (file == 7 || rank == 7)) ||
            (the_direction == Direction::soEa  && (file == 7 || rank == 0)) ||
            (the_direction == Direction::soWe  && (file == 0 || rank == 0)) ||
            (the_direction == Direction::noWe  && (file == 0 || rank == 7))) {
            break;
        }

        bit = (shift > 0) ? (bit << shift) : (bit >> -shift);
        mask |= bit;
    }

    return mask;
}


  constexpr u64 calculate_knight_moves(SquareValue the_square) {
    u64 xd = 0;
    return xd;
  } ;

  constexpr std::array<std::array<u64, 8>, 64> AllRayMasks = calculate_ray_masks();

}


#endif // HARMONY_CHESS_CONSTANTS_H