#ifndef FT_ZAPPY
#define FT_ZAPPY

# include <libft.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <netdb.h>

# define HEIGHT 1024
# define WIDTH 1024
# define MAX_PLAYERS 12
# define MAX_STONES 2
# define MAX_FOOD 1 //wanna treat food as a value I can move back and forth but I don't need to worry about it having came from a unique address.

enum e_rock_type = {linemate, deraumere, sibur, mendiane, phiras, thystame};

typedef struct			s_stone
{
	enum e_rock_type	rock; //literally made this so I can have them in an array without worrying about how to tell the stones apart.
}				t_stone;

typedef struct			s_food
{
	unsigned int		value;
}				t_food;

typedef struct			s_block
{
	t_player		players[MAX_PLAYERS];
	t_stone			stones[MAX_STONES];
	t_food			food[MAX_FOOD];
}				t_block;

typedef struct		;

typedef struct		s_board
{
	t_block		board[HEIGHT[WIDTH]];
}			t_board;

#endif
