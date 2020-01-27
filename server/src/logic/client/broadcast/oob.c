#include <zappy.h>

void		get_square(t_intersect *i, t_client *dest)
{
	t_squares *sq;
    int square_nb;

    square_nb = 1;
    sq = get_squares();
    sq = get_square_sp(sq, dest->orientation);
    while (square_nb < 9)
    {
        if (i->ix == (dest->x + sq->x) && i->iy == (dest->y + sq->y))
        {
        	i->square_nb = square_nb;
        	return ;
        }
        square_nb++;
        sq = sq->next;
    }
}

int 		get_oob_square(t_intersect *i, t_client *dest, t_client *src, t_game *game)
{
	int 	square_nb;
	int 	done;

	get_square(i, dest);
	done = 0;
	square_nb = i->square_nb;
	if (src->x > dest->x && dest->y > src->y)
	{
		if (src->x - dest->x >= ((game->x / 2) + 2) || dest->y - src->y >= ((game->y / 2) + 2))
		{
			i->square_nb = square_nb + 6;
			done = 1;
		}
	}
	else if (src->x > dest->x && dest->y < src->y && done == 0)
	{
		if (src->x - dest->x >= ((game->x / 2) + 2) || src->y - dest->y >= ((game->y / 2) + 2))
		{
			i->square_nb = square_nb;
			done = 1;
		}
	}
	if (done == 0)
	{
		if (i->square_nb <= 4)
			i->square_nb = square_nb + 4;
		else
			i->square_nb = square_nb - 4;
	}
	return (i->square_nb);
}