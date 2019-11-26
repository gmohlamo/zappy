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

typedef struct		s_object
{
	int				x;
	int				y;
	enum e_obj		type;
}					t_object;
typedef struct		s_inv
{
	int				x;
	int				y;
	t_object		*item;
	struct s_inv	*next;
}					t_inv;

typedef struct		s_client
{
	int				fd;
	int				x;
	int				y;
	size_t			level;
	t_inv			*inventory;
	struct s_client	*next;
}					t_client;

#endif
