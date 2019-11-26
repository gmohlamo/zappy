#ifndef FT_ZAPPY
#define FT_ZAPPY

# include <libft.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/select.h>
# include <arpa/inet.h>
# include <netdb.h>

# define ROWS 1024
# define COLUMNS 1024
# define MAX_PLAYERS 12
# define MAX_STONES 2
# define MAX_FOOD 1

enum e_rock_type {linemate, deraumere, sibur, mendiane, phiras, thystame};
enum e_obj {rock, food};

typedef struct		s_object //represent game objects
{
	int				x;
	int				y;
	enum e_obj		type;
	struct s_object	*next;
}					t_object;

typedef struct		s_objects //hold all objects in the game world.
{
	size_t			count;
	t_object		*objects;
}					t_objects;
typedef struct		s_inv //represent client inventory
{
	int				x;
	int				y;
	t_object		*item;
	struct s_inv	*next;
}					t_inv;

typedef struct		s_client //represent each client
{
	int				fd;
	int				x;
	int				y;
	int				team;
	size_t			level;
	size_t			life;
	t_inv			*inventory;
	struct s_client	*next;
}					t_client;

typedef struct		s_game //hold the entire game state
{
	int				fd_sock;
	int				conn;
	struct timeval	timeout;
	struct addrinfo hints;
	struct addrinfo	*result;
	struct addrinfo	*rp;
	fd_set			set;
	t_client		*clients;
	t_objects		*objects;
}					t_game;

#endif
