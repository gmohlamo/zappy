#include <zappy.h>

void			new_client(t_game *game)
{
	//accept connections from new clients
	if (game->client_count < MAX_PLAYERS)
	{
		if (game->conn = accept(game->fd_sock))
	}
}

void			process_clients(t_game *game)
{
	size_t		itr;
	
	itr = 0;
	while (itr <= game->max_fd)
	{
		if (FD_ISSET(itr, &(game->rset)))
		{
			if (itr == game->fd_sock)
				new_client(game);
		}
		itr++;
	}
}

void			run_game(t_game *game)
{
	while (1)
	{
		if (select(game->max_fd, &(game->rset),
			&(game->wset), NULL, &(game->timeout)) == -1)
		{
			ft_putendl_fd("Error: select error", 2);
			close(game->fd_sock);
			free(game);
			exit(EXIT_FAILURE);
		}
		process_clients(game);
	}
}