#ifndef POSITION_H
#define POSITION_H

// Position is a representation of a position on the board with the horizontial
// and vertical coordinates based on looking from the board from the white side.
struct Position 
{
    unsigned char horizontial; // Since our values will never be more than seven it makes sense to set this to the smallest data type.
    unsigned char vertical;
} typedef Position;

bool set_position(Position* position, unsigned char horizontial, unsigned char vertical)
{
    position->horizontial = horizontial;
    position->vertical = vertical;
    return is_horizontial_coordinate_correct(horizontial) && is_vertical_coordinate_correct(vertical);
}

bool set_horizonital_position(Position* position, unsigned char horizontial)
{
    position->horizontial = horizontial;
    return is_horizontial_coordinate_correct(horizontial);
}

bool set_vertical_position(Position* position, unsigned char vertical)
{
    position->vertical = vertical;
    return is_vertical_coordinate_correct(vertical);
}

bool is_horizontial_coordinate_correct(unsigned char horizontial)
{
    return horizontial >= 0 && horizontial <= 7;
}

bool is_vertical_coordinate_correct(unsigned char vertical)
{
    return vertical >= 0 && vertical <= 7;
}

bool is_position_correct(Position* position)
{
    return is_horizontial_coordinate_correct(position->horizontial) && is_vertical_coordinate_correct(position->vertical);
}

bool is_position_equal(Position* position1, Position* position2)
{
    return position1->horizontial == position2->horizontial && position1->vertical == position2->vertical;
}

#endif // POSITION_H