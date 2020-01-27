#include <zappy.h>

int        is_adjacent(t_client *src, t_client *dest)
{
    t_squares *sq;
    int square_nb;

    square_nb = 1;
    sq = get_squares();
    sq = get_square_sp(sq, dest->orientation);
    while (square_nb < 9)
    {
        if (src->x == (dest->x + sq->x) && src->y == (dest->y + sq->y))
            return (square_nb);
        square_nb++;
        sq = sq->next;
    }
    return (0);
}

int       get_square_nb(t_client *dest, t_intersect *i)
{
    t_squares *sq;
    int square_nb;

    square_nb = 1;
    sq = get_squares();
    sq = get_square_sp(sq, dest->orientation);
    while (square_nb < 9)
    {
        if (i->ix == (dest->x + sq->x) && i->iy == (dest->y + sq->y))
            return(square_nb);
        square_nb++;
        sq = sq->next;
    }
}

int          diagonal_calc(t_game *game, t_client *src, t_client *dest)
{
    float   hypt;
    float   hypt2;
    t_intersect *i;
    int         square_nb;

    if ((square_nb = is_adjacent(src, dest)) != 0)
        return (square_nb);
    hypt2 = hypot(abs(src->x - dest->x), abs(src->y - dest->y));
    hypt = get_oob_hypot(src, dest, game);
    if (hypt < hypt2)
    {
        i = get_line_intersection(src, dest);
        return (get_oob_square(i, dest, src, game));
    }
    else
    {
        i = get_line_intersection(src, dest);
        return (get_square_nb(dest, i));
    }
}