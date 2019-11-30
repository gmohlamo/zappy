#include <zappy.h>

int     main(int ac, char **av)
{
	t_game *game;

	srand(time(0)); //used to made pseudo random placement of objects when we initiate the game
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