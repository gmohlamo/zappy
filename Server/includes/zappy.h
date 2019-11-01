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
	enum e_rock_type	rock;
	struct s_stone		*next;
	struct s_stone		*prev;
}				t_stone;

typedef struct			s_food
{
	unsigned int		value;
	struct s_food		*next;
	struct s_food		*prev;
}				t_food;

typedef struct			s_block
{
	t_player		*players;
	t_stone			*stones;
	t_food			*food;
}				t_block;

typedef struct			s_player
{
	int			fd;
	int			x;
	int			y;
	t_stone			*stones;
	t_food			*food;
}				t_player;

typedef struct			s_board
{
	t_block			board[HEIGHT[WIDTH]];
	fd_set			rset;
	fd_set			wset;
	fd_set			orig_set;
	socklen_t		addrlen;
	struct sockaddr_storage	remoteaddr;
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct addrinfo		*res0;
}				t_board;

#endif
