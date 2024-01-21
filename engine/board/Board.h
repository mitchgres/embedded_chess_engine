#ifndef BOARD_H
#define BOARD_H

#include "../piece/Piece.h"
#include "position/Position.h"

const Piece DEAFULT_BOARD[] =
{
    { {0, 0}, 3, true },
    { {1, 0}, 1, true },
    { {2, 0}, 2, true },
    { {3, 0}, 4, true },
    { {4, 0}, 5, true },
    { {5, 0}, 2, true },
    { {6, 0}, 1, true },
    { {7, 0}, 3, true },
    { {0, 1}, 0, true },
    { {1, 1}, 0, true },
    { {2, 1}, 0, true },
    { {3, 1}, 0, true },
    { {4, 1}, 0, true },
    { {5, 1}, 0, true },
    { {6, 1}, 0, true },
    { {7, 1}, 0, true },
    { {0, 6}, 0, false },
    { {1, 6}, 0, false },
    { {2, 6}, 0, false },
    { {3, 6}, 0, false },
    { {4, 6}, 0, false },
    { {5, 6}, 0, false },
    { {6, 6}, 0, false },
    { {7, 6}, 0, false },
    { {0, 7}, 3, false },
    { {1, 7}, 1, false },
    { {2, 7}, 2, false },
    { {3, 7}, 4, false },
    { {4, 7}, 5, false },
    { {5, 7}, 2, false },
    { {6, 7}, 1, false },
    { {7, 7}, 3, false }
};

struct Board
{
    Piece pieces[32];
} typedef Board;

bool can_piece_move_to_square(Piece* piece, Position* position, Board* board)
{
    // TODO: Explanation of the functions needed to generate the possible positions that a piece can move.
    // For ALL PIECES check whether the target position is even in bounds. If not then false.
    // For ALL PIECES check whether the target square they are moving to in empty. If it's not empty then false.
    // For PAWN:
    // - If WHITE:
    //     - See if the target square is one up. If not then false.
    //     - If the current position of the pawn is it's starting position then see if the target square is two up. If not then false.
    // - If BLACK:
    //     - See if the target square is one down. If not then false.
    //     - If the current position of the pawn is it's starting position then see if the target square is two down. If not then false.
    // For KNIGHT:
    // - See if the target square either...
            // - Two Up One Left.
            // - Two Up One Right.
            // - Two Down One Left.
            // - Two Down One Right.
            // - Two Left One Up.
            // - Two Left One Down.
            // - Two Right One Up.
            // - Two Right One Down.
    // For BISHOP:
    // - See if the target square is either...
            // - Up Left Diagonal.
            // - Up Right Diagonal.
            // - Down Left Diagonal.
            // - Down Right Diagonal.
            // Note: The function that does this should be a recursive function that stops in the diagonal that it's moving on whenever it hits a position that has a piece in it.
    // For ROOK:
    // - See if the target square is either...
            // - Up.
            // - Down.
            // - Left.
            // - Right.
            // Note: The function that does this should be a recursive function that stops in the direction that it's moving on whenever it hits a position that has a piece in it.
    // For QUEEN:
    // - See if the target square is either...
            // - Up.
            // - Down.
            // - Left.
            // - Right.
            // - Up Left Diagonal.
            // - Up Right Diagonal.
            // - Down Left Diagonal.
            // - Down Right Diagonal.
            // Note: The function that does this should be a recursive function that stops in the direction that it's moving on whenever it hits a position that has a piece in it. And will just be a
            // combination of the BISHOP and ROOK functions.
    // For KING:
    // - See if the target square is either...
            // - One Up.
            // - One Down.
            // - One Left.
            // - One Right.
            // - One Up One Left.
            // - One Up One Right.
            // - One Down One Left.
            // - One Down One Right.


}

bool can_piece_attack_square(Piece* piece, Position* position, Board* board)
{

}

bool set_board(Board* board, Piece pieces[32])
{
    for (int i = 0; i < 32; i++)
    {
        board->pieces[i] = pieces[i];
    }
    return is_board_correct(board);
}

bool is_board_correct(Board* board)
{
    for (int i = 0; i < 32; i++)
    {
        if (!is_piece_correct(&board->pieces[i]))
        {
            return false;
        }
    }
    return true;
}

bool is_board_equal(Board* board_one, Board* board_two)
{
    for (int i = 0; i < 32; i++)
    {
        if (!is_piece_equal(&board_one->pieces[i], &board_two->pieces[i]))
        {
            return false;
        }
    }
    return true;
}



#endif // BOARD_H