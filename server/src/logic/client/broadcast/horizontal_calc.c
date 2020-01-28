#include <zappy.h>

int			get_hor_origin(t_client *dest, int x, t_squares *squares)
{
	int		square_nb;

	square_nb = 1;
	squares = get_square_sp(squares, dest->orientation);
	while (squares)
	{
		if ((x == (dest->x + squares->x)) && (dest->y == (dest->y + squares->y)))
			return (square_nb);
		square_nb++;
		squares = squares->next;
	}
	return (0);
}

int			horizontal_calc(t_game *game, t_client *src, t_client *dest)
{
	t_squares *squares;

	squares = get_squares();
	if (src->x > dest->x)
	{
		if ((src->x - dest->x) <= ((game->x - src->x) + dest->x))
			return (get_hor_origin(dest, dest->x + 1, squares));
		else
			return (get_hor_origin(dest, dest->x - 1, squares));
	}
	else if (dest->x > src->x)
	{
		if ((dest->x - src->x) <= ((game->x - dest->x) + src->x))
			return (get_hor_origin(dest, dest->x - 1, squares));
		else
			return (get_hor_origin(dest, dest->x + 1, squares));
	}
	return (0);
}