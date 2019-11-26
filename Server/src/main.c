#include "../includes/zappy.h"

void			cleanboard_exit(t_board *board, size_t allocated)
{
	size_t		itr;

	itr = 0;
	while (itr < allocated)
	{
		free(board->board[itr]);
		itr++;
	}
	free(board->board);
	exit(2);
}

int			init_board(t_board *board)
{
	size_t		itr;

	itr = 0;
	board->board = ft_memalloc(sizeof(t_block*) * ROWS);
	if (board->board)
	{
		while (itr < ROWS)
		{
			board->board[itr] = ft_memalloc(sizeof(t_block) * COLUMNS);
			if (board->board[itr] == NULL)
				cleanboard_exit(board, itr);
			itr++;
		}
	}
}

int			main(int ac, char **av)
{
	t_board		board;

	if (ac == 2)
	{
		if (!init_board(&board))
		{
			ft_putendl_fd("Failed to initialize board", 2);
			exit(1);
		}
	}
	return (0);
}
