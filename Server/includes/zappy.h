#ifndef FT_ZAPPY
#define FT_ZAPPY

# include <stdbool.h>
# include <libft.h>
# include <time.h>
# include <math.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/select.h>
# include <arpa/inet.h>
# include <netdb.h>

# define LIFE 126
# define ROWS 1024
# define COLUMNS 1024
# define MAX_PLAYERS 12
# define MAX_STONES 2
# define MAX_FOOD 1
# define CLIENT_ALLOC_ERR "Error: Unable to allocate memory for client"
# define ERR_ACCEPT "Error: Unable to accept socket connection"

enum e_rock_type {linemate, deraumere, sibur, mendiane, phiras, thystame};
enum e_obj {rock, food};

typedef struct				s_object //represent game objects
{
	int						x;
	int						y;
	enum e_obj				type;
	struct s_object			*next;
}							t_object;

typedef struct				s_objects //hold all objects in the game world.
{
	size_t					count;
	t_object				*objects;
}							t_objects;
typedef struct				s_inv //represent client inventory
{
	int						x;
	int						y;
	t_object				*item;
	struct s_inv			*next;
}							t_inv;

typedef struct				s_client //represent each client
{
	int						fd;
	int						x;
	int						y;
	int						team;
	size_t					level;
	size_t					life;
	size_t					cost;
	size_t					orientation;
	t_inv					*inventory;
	struct sockaddr			addr;
	struct s_client			*next;
}							t_client;

typedef struct				s_game //hold the entire game state
{
	int						fd_sock;
	int						conn;
	int						max_fd;
	int						x;
	int						y;
	int						gfx; //the gfx socket
	bool					gfx_bool; //check if the gfx has been connected already... first connection
	int						time_div;
	size_t					allowed_clients;
	size_t					client_count;
	char					**teams;
	useconds_t				timeout;
	struct sockaddr_storage	remoteaddr;
	struct addrinfo 		hints;
	struct addrinfo			*result;
	struct addrinfo			*rp;
	fd_set					set;
	fd_set					rset;
	fd_set					wset;
	t_client				*clients;
	t_objects				*objects;
}							t_game;

t_game      *init_game(char *addr);
void		run_game(t_game *game);
void		init_client(t_client *client, t_game *game);
char		*parse_args(t_game *game, char **av, int ac);
void		usage_exit(void);

#endif