/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:31 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/28 17:40:52 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void        checkaddr(t_game *game)
{
	game->rp = game->result;
	while (game->rp)
	{
		ft_putendl("Getting socket");
		game->fd_sock = socket(game->rp->ai_family, game->rp->ai_socktype,
			game->rp->ai_protocol);
		printf("%d\n", game->fd_sock);
		if (game->fd_sock == -1)
			game->rp = game->rp->ai_next;
		if (bind(game->fd_sock, game->rp->ai_addr,
			game->rp->ai_addrlen) == 0)
			break ;
		else
		{
			close(game->fd_sock);
			game->rp = game->rp->ai_next;
		}
	}
	if (game->rp == NULL)
	{
		ft_putendl_fd("Error: failed to bind to socket", 2);
		freeaddrinfo(game->result);
		free(game);
		exit(EXIT_FAILURE);
	}
	printf("Connected socket: %d\n", game->fd_sock);
	freeaddrinfo(game->result);
}

void        finalize_init(t_game *game)
{
	FD_ZERO(&game->wset);
	FD_ZERO(&game->rset);
	ft_putendl("Finished initialization");
	game->rset = game->set;

}

void        conn_listen(t_game *game)
{
	int     yes;

	yes = 1;
	setsockopt(game->fd_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	printf("About to listen to --> %d\n", game->fd_sock);
	if (listen(game->fd_sock, 10) == -1)
	{
		ft_putendl_fd("Error: failed to listen on port", 2);
		free(game);
		exit(EXIT_FAILURE);
	}
	FD_SET(game->fd_sock, &(game->set));
	game->max_fd = game->fd_sock + 1; //set to listen for connections and the highest fd has been recorded
	printf("%d --> max_fd\n", game->max_fd);
	finalize_init(game);
}

t_game      *init_game(char **av, int ac)
{
	t_game  *game;
	char    *addr;

	game = ft_memalloc(sizeof(t_game));
	if (game)
	{
		addr = parse_args(game, av, ac);
		ft_putendl("successfully parsed args");
		game->gfx_bool = false;
		ft_memset(&(game->hints), 0, sizeof(struct addrinfo));
		game->socklen = sizeof(struct sockaddr);
		game->hints.ai_family = AF_UNSPEC;
		game->hints.ai_socktype = SOCK_STREAM;
		game->hints.ai_flags = AI_PASSIVE;
		game->conn = getaddrinfo(NULL, addr, &(game->hints), &(game->result));
		printf("getaddrinfo returned --> %s\n", gai_strerror(game->conn));
		if (game->conn != 0)
		{
			ft_putendl_fd("Error: could not get address information", 2);
			free(game);
			exit(1);
		}
		ft_putendl("Got connection information");
		checkaddr(game);
		ft_putendl("About to connect");
		conn_listen(game);
		add_operations(game);
	}
	return  (game);
}