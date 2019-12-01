#include <zappy.h>

void				new_client(t_game *game)
{
	t_client		*n_client;

	n_client = ft_memalloc(sizeof(t_client));
	if (!n_client)
	{
		ft_putendl_fd(CLIENT_ALLOC_ERR, 2);
		exit(EXIT_FAILURE);
	}
	//accept connections from new clients
	if ((game->conn = accept(game->fd_sock, //need to read this man page
		&(n_client->addr), sizeof(struct sockaddr))) == -1)
	{
		ft_putendl_fd(ERR_ACCEPT, 2);
		free(n_client);
	}
	else
		append_client(game, n_client);
}

void				connect_gfx(t_game *game)
{
	if (game->gfx_bool == false)
	{
		game->gfx = accept(game->fd_sock,
			&(game->gfx_addr), sizeof(struct sockaddr));
		if (game->gfx == -1)
		{
			ft_putendl_fd("Error: Error connecting to GFX client", 2);
			exit(1); //fuck it... don't even bother letting go cause ish failed
		}
		if (game->gfx > game->max_fd)
			game->max_fd = game->gfx;
		game->gfx_bool = true;
		FD_SET(game->gfx, &(game->wset));
		ft_Putendl("Successfully connected the gfx");
	}
	else
	{
		ft_putendl_fd("Error: Internal server error", 2);
		exit(EXIT_FAILURE);
	}
}//should have the graphical client connected here

void				process_clients(t_game *game)
{
	size_t			itr;
	
	itr = 0;
	while (itr <= game->max_fd)
	{
		if (FD_ISSET(itr, &(game->rset)))
		{
			if (itr == game->fd_sock && game->gfx_bool)
				new_client(game);
			else if (itr == game->fd_sock)
				connect_gfx(game);
		}
		itr++;
	}
}

void				run_game(t_game *game)
{
	struct timeval	elapse;

	elapse.tv_sec = 0;
	elapse.tv_usec = 0;
	while (1)
	{
		if (select(game->max_fd, &(game->rset),
			NULL, NULL, &elapse) == -1)
		{
			ft_putendl_fd("Error: select error", 2);
			close(game->fd_sock);
			free(game);
			exit(EXIT_FAILURE);
		}
		process_clients(game);
	}
}