#include <zappy.h>

int		get_ver_origin(t_client *dest, int y, t_squares *squares)
{
	int		square_nb;

	square_nb = 1;
	squares = get_square_sp(squares, dest->orientation);
	while (squares)
	{
		if ((y == (dest->y + squares->y)) && (dest->x == (dest->x + squares->x)))
			return (square_nb);
		square_nb++;
		squares = squares->next;
	}
}

int			vertical_calc(t_game *game, t_client *src, t_client *dest)
{
	t_squares *squares;

	squares = get_squares();
	if (src->y > dest->y)
	{
		if ((src->y - dest->y) <= ((game->y - src->y) + dest->y))
			return (get_ver_origin(dest, dest->y + 1, squares));
		else
			return (get_ver_origin(dest, dest->y - 1, squares));
	}
	else if (dest->y > src->y)
	{
		if ((dest->y - src->y) <= ((game->y - dest->y) + src->y))
			return (get_ver_origin(dest, dest->y - 1, squares));
		else
			return (get_ver_origin(dest, dest->y + 1, squares));
	}
	else
		return (0);
}