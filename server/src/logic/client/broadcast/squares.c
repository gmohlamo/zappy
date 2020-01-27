#include <zappy.h>

void		assign_squares(t_squares *squares)
{
	squares->x = 1;
	squares->y = 0;
	squares = squares->next;
	squares->x = 1;
	squares->y = -1;
	squares = squares->next;
	squares->x = 0;
	squares->y = -1;
	squares = squares->next;
	squares->x = -1;
	squares->y = -1;
	squares = squares->next;
	squares->x = -1;
	squares->y = 0;
	squares = squares->next;
	squares->x = -1;
	squares->y = 1;
	squares = squares->next;
	squares->x = 0;
	squares->y = 1;
	squares = squares->next;
	squares->x = 1;
	squares->y = 1;
}

t_squares	*get_squares()
{
	t_squares *squares;
	t_squares *head;
	int i;

	i = 0;
	squares = (t_squares*)malloc(sizeof(t_squares));
	head = squares;
	while (i < 7)
	{
		squares->next = (t_squares*)malloc(sizeof(t_squares));
		squares = squares->next;
		i++;
	}
	squares->next = head;
	squares = head;
	assign_squares(squares);
	i = 0;
	return (head);
}

t_squares	*get_square_sp(t_squares *squares, int orientation)
{
	if (orientation == 1)
	{
		while (squares)
		{
			if (squares->x == 1 && squares->y == 0)
				return (squares);
			squares = squares->next;
		}
	}
	else if (orientation == 2)
	{
		while (squares)
		{
			if (squares->x == 0 && squares->y == -1)
				return (squares);
			squares = squares->next;
		}
	}
	else if (orientation == 3)
	{
		while (squares)
		{
			if (squares->x == -1 && squares->y == 0)
				return (squares);
			squares = squares->next;
		}
	}
	else if (orientation == 4)
	{
		while (squares)
		{
			if (squares->x == 0 && squares->y == 1)
				return (squares);
			squares = squares->next;
		}
	}
	return (squares);
}