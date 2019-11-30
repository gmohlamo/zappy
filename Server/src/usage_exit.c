#include <zappy.h>

//upon error print usage
void		usage_exit(void)
{
	ft_putstr("Usage: /server -p <port> -x <width>");
	ft_putstr(" -y <height> -n <team> [<team>] [<team>]");
	ft_putendl(" ... -c <nb> -t <t>");
	ft_putendl("-p port number");
	ft_putendl("-x world width");
	ft_putendl("-y world height");
	ft_putendl("-n team\\_name\\_1 team\\_name\\_2 ..");
	ft_putendl("-c number of clients authorized at the beginning of the game");
	ft_putstr("-t time unit divider (the greater t is, the faster");
	ft_putendl(" the game will go)");
	exit(EXIT_FAILURE);
}