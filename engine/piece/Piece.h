#ifndef PIECE_H
#define PIECE_H

#include "../board/position/Position.h"

struct Piece 
{
    Position position;
    unsigned char type;
    bool is_white;
} typedef Piece;

bool set_piece(Piece* piece, Position position, unsigned char type, bool is_white)
{
    piece->position = position;
    piece->type = type;
    piece->is_white = is_white;
    return is_position_correct(&position) && is_type_correct(type);
}

bool is_piece_equal(Piece* piece1, Piece* piece2)
{
    return is_position_equal(&piece1->position, &piece2->position) && piece1->type == piece2->type && piece1->is_white == piece2->is_white;
}

bool is_piece_correct(Piece* piece)
{
    return is_position_correct(&piece->position) && is_type_correct(piece->type);
}

bool is_type_correct(unsigned char type)
{
    // 0 -- Pawn
    // 1 -- Knight
    // 2 -- Bishop
    // 3 -- Rook
    // 4 -- Queen
    // 5 -- King
    return type >= 0 && type <= 5;
}

#endif // PIECE_H