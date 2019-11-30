#include <zappy.h>

char		*get_port(char *port)
{
	size_t	itr;

	itr = 0;
	while (port[itr])
	{
		if (!ft_isdigit(port[itr]))
			usage_exit();
		else
			itr++;
	}
	return (port);
}

int			get_dim(char *dim)
{
	int		size;

	size = 0;
	size = atoi(dim);
	if (size <= 0)
		usage_exit();
	return (size);
}

void		get_teams(t_game *game, char **av, int ac)
{
	size_t	itr;

	itr = 0;
	while (itr < ac)
	{
		if (ft_strequ(av[itr], "-n") && itr < ac - 1)
		{
			game->teams = &av[itr + 1];
			return ;
		}
		itr++;
	}
	usage_exit();
}

void		parse_game_config(t_game *game, char *addr)
{
	if (game->teams == NULL)
		usage_exit();
	else if (game->x == 0)
		usage_exit();
	else if (game->y == 0)
		usage_exit();
	else if (game->allowed_clients == 0)
		usage_exit();
	else if (addr == NULL)
		usage_exit();
}

char		*parse_args(t_game *game, char **av, int ac)
{
	char	*addr;
	size_t	itr;

	itr = 0;
	addr = NULL;
	while (itr < ac)
	{
		if (ft_strequ(av[itr], "-p") && itr < ac -1)
			addr = get_port(av[itr + 1]);
		else if (ft_strequ(av[itr], "-x") && itr < ac -1)
			game->x = get_dim(av[itr + 1]);
		else if (ft_strequ(av[itr], "-y") && itr < ac -1)
			game->y = get_dim(av[itr + 1]);
		else if (ft_strequ(av[itr], "-c") && itr < ac -1)
			game->allowed_clients = get_dim(av[itr + 1]);
		else if (ft_strequ(av[itr], "-t") && itr < ac -1)
			game->timeout = 1000000 / get_dim(av[itr + 1]);
		itr++;
	}
	get_teams(game, av, ac);
	parse_game_config(game, addr);
}