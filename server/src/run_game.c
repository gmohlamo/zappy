#include <zappy.h>

void				new_connection(t_game *game)
{
	t_connection	*n_conn;

	ft_putendl("Creating a new connection");
	n_conn = ft_memalloc(sizeof(t_client));
	if (!n_conn)
	{
		ft_putendl_fd(CLIENT_ALLOC_ERR, 2);
		exit(EXIT_FAILURE);
	}
	//accept connections from new clients
	if ((game->conn = accept(game->fd_sock, //need to read this man page
		&(n_conn->addr), &game->socklen)) == -1)
	{
		ft_putendl_fd(ERR_ACCEPT, 2);
		free(n_conn);
	}
	else
	{
		ft_putendl("adding new connection to list");
		n_conn->fd = game->conn;
		append_connection(game, n_conn);
	}
}

void				connect_gfx(t_game *game)
{
	ft_putendl("About to connect the graphics client");
	if (game->gfx_bool == false)
	{
		game->gfx = accept(game->fd_sock,
			&(game->gfx_addr), &game->socklen);
		if (game->gfx == -1)
		{
			ft_putendl_fd("Error: Error connecting to GFX client", 2);
			exit(1); //fuck it... don't even bother letting go cause ish failed
		}
		if (game->gfx > game->max_fd)
			game->max_fd = game->gfx + 1;
		FD_SET(game->gfx, &(game->wset));
		FD_CLR(game->fd_sock, &(game->set));
		ft_putendl("Successfully connected the gfx");
	}
	else
	{
		ft_putendl_fd("Error: Internal server error", 2);
		exit(EXIT_FAILURE);
	}
	FD_CLR(game->fd_sock, &(game->set)); //don't accept any more connections
	//unless the gfx socket has been confirmed.
}//should have the graphical client connected here

void				process_clients(t_game *game)
{
	int				itr;
	
	itr = 0;
	while (itr <= game->max_fd)
	{
		if (FD_ISSET(itr, &(game->rset)))
		{
			printf("Active file descriptor: %d\nMax --> %d\n", itr, game->max_fd);
			if (itr == game->fd_sock)
				new_connection(game);
			else
				process_line(game, itr);
		}
		itr++;
	}
}

void				run_game(t_game *game)
{
	struct timeval	elapse;

	elapse.tv_sec = 0;
	elapse.tv_usec = 0;
	ft_putendl("About to run game");
	while (1)
	{
		game->rset = game->set;
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