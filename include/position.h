// position.h
#ifndef HARMONY_CHESS_POSITION_H
#define HARMONY_CHESS_POSITION_H
#include <array>
#include "aliases.h"
#include "bitboard.h"

namespace harmony_chess {

  class ChessPosition {
    private:
      std::array<bitboard, 12> m_bitboards_;
      
    public:

  } ;

}

#endif //HARMONY_CHESS_POSITION_H