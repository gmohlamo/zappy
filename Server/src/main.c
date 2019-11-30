#include <zappy.h>

int     main(int ac, char **av)
{
	t_game *game;

	if (ac == 2)
	{
		game = init_game(av[1]);
		run_game(game);
	}
	else
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putendl(" PORT");
	}
	return (0);
}