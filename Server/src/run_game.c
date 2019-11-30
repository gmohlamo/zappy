#include <zappy.h>

void			new_client(t_game *game)
{
	t_client	*n_client;

	n_client = ft_memalloc(sizeof(t_client));
	if (!n_client)
	{
		ft_putendl_fd(CLIENT_ALLOC_ERR, 2);
		exit(EXIT_FAILURE);
	}
	//accept connections from new clients
	if (game->client_count < MAX_PLAYERS)
	{
		if ((game->conn = accept(game->fd_sock, //need to read this man page
			&(n_client->addr), sizeof(struct sockaddr))) == -1)
		{
			ft_putendl_fd(ERR_ACCEPT, 2);
			free(n_client);
		}
		else
			append_client(game, n_client);
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
			NULL, NULL, &(game->timeout)) == -1)
		{
			ft_putendl_fd("Error: select error", 2);
			close(game->fd_sock);
			free(game);
			exit(EXIT_FAILURE);
		}
		process_clients(game);
	}
}