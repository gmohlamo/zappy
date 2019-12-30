/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:17 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/30 15:59:43 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <sys/time.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <stdio.h>

# define RING_BUFF_SIZE 512
# define RING_SIZE 6
# define LIFE 126
# define ROWS 1024
# define COLUMNS 1024
# define MAX_PLAYERS 12
# define MAX_STONES 2
# define MAX_FOOD 1
# define CMD_BACKLOG 10
# define CLIENT_ALLOC_ERR "Error: Unable to allocate memory for client"
# define ERR_ACCEPT "Error: Unable to accept socket connection"
# define ELEVATE "elevation in progress"
# define GFX "GRAPHICS"

//enums for operations and resources
enum e_operations {advance, right, left, see, inventory, take, put, kick,
	broadcast, incantation, spawn, connect_nbr, death, none};
enum e_resource_type {food, linemate, deraumere, sibur, mendiane, phiras, thystame};
typedef struct				s_object //represent game objects
{
	int						x;
	int						y;
	size_t					count;
	enum e_resource_type	type;
}							t_object;

//last thing we need for each client is for them to belong to a team
typedef struct				s_team
{
	char					*name;
	size_t					current_count;
	size_t					team_size;
}							t_team;

typedef struct				s_objects //hold all objects in the game world.
{
	size_t					count;
	t_object				*objects;
}							t_objects;
typedef struct				s_inv //represent client inventory
{
	int						x;
	int						y;
	t_objects				*items;
	struct s_inv			*next;
}							t_inv;

typedef struct				s_calc
{
	struct timeval			tv;
	struct timezone			tz;
}							t_calc;
typedef struct				s_client //represent each client
{
	int						fd;
	int						x;
	int						y;
	size_t					level;
	size_t					life;
	size_t					cost;
	size_t					orientation;
	size_t					nbr; //client number
	bool					op_complete; //needed to fix backlog management
	t_list					*lines;
	t_inv					*inventory;
	struct timeval			tv; //using this to count down life
	struct timezone			tz;
	struct sockaddr			addr;
	t_team					*team;
	enum e_operations		op;
	struct s_client			*next;
}							t_client;

typedef struct				s_connection
{
	int						fd;
	struct sockaddr			addr;
	char					*line;
	struct s_connection		*next;
}							t_connection; //because I need to keep track of all connections made to
//the server and put them in the game while relavent

typedef struct				s_egg
{
	t_team					*team;
	size_t					life;
	struct timeval			tv;
	struct timezone			tz;
	int						x;
	int						y;
	struct s_egg			*next;
}							t_egg;

typedef struct				s_game //hold the entire game state
{
	int						fd_sock;
	int						conn;
	int						max_fd;
	int						x;
	int						y;
	int						gfx; //the gfx socket
	char					*gfx_line;//cause gfx also needs to send lines
	char					*gfx_line_rem;
	char					*addr;
	struct sockaddr			gfx_addr; //addr info for the gfx
	bool					gfx_bool; //check if the gfx has been connected already... first connection
	int						time_div;
	size_t					allowed_clients;
	size_t					client_count;
	size_t					team_count;
	char					**team_names;
	useconds_t				timeout;
	struct sockaddr_storage	remoteaddr;//server address information
	struct addrinfo 		hints;
	struct addrinfo			*result;
	struct addrinfo			*rp;
	socklen_t				socklen;
	fd_set					set;
	fd_set					rset;
	fd_set					wset;
	t_connection			*connections;
	t_client				*clients;
	t_egg					*eggs;
	t_team					*teams;
	t_objects				*objects;
	void					(*operations[13])(); //array of functions to use when running operations from a client
}							t_game;

t_game      				*init_game(char **av, int ac);
void						add_operations(t_game *game);
t_team						*init_teams(t_game *game);
t_team						*check_team(t_game *game, char *team_name);
t_client					*client(t_game *game, int fd);
t_connection				*find_conn(t_game *game, int fd);
t_client					*find_client(t_game *game, int fd);
void						assign_conn(t_game *game, t_connection *conn);
void						run_game(t_game *game);
void						init_client(t_client *client, t_connection *conn, t_game *game);
char						*parse_args(t_game *game, char **av, int ac);
void						usage_exit(void);
bool						append_line(t_game *game, t_client *client);
void						append_client(t_game *game, t_connection *client,
	t_team *team);
void						send_init_gfx(t_game *game);
void						append_connection(t_game *game, t_connection *conn);
t_client					*process_line(t_game *game, int fd);
void						close_clients(t_game *game);
void						close_connection(t_game *game, int fd);
void						process_or_close(t_game *game, t_connection *conn);
void						remove_conn(t_game *game, t_connection *target);
void						block_contents(t_game *game, int x, int y);
void						send_init_gfx(t_game *game);
void						add_gfx(t_game *game, t_connection *conn);
void						update_gfx(t_game *game, t_client *client);
char						*ft_strjoinint(char *str, int n);
size_t						client_nbr(t_game *game);
enum e_operations			get_op(t_client *client);
void						add_op_cost(t_client *client);
void						move_backlog(t_game *game, t_client *client);
//command processing
void						run_commands(t_game *game);
void						adjust_client_life(t_game *game, t_client *client,
	t_calc *calc, size_t diff);
//client operations
void						advance_op(t_game *game, t_client *client);
void						connect_nbr_op(t_game *game, t_client *client);
void						death_op(t_game *game, t_client *client);
void						inventory_op(t_game *game, t_client *client);
void						incantation_op(t_game *game, t_client *client);
void						fork_op(t_game *game, t_client *client);
void						kick_op(t_game *game, t_client *client);
void						left_op(t_game *game, t_client *client);
void						put_op(t_game *game, t_client *client);
void						right_op(t_game *game, t_client *client);
void						see_op(t_game *game, t_client *client);
void						take_op(t_game *game, t_client *client);
void						broadcast_op(t_game *game, t_client *client);
//client specific gfx
void						client_advance_gfx(t_game *game, t_client *client);
void						client_death_update(t_game *game, t_client *client);
void						update_gfx_client(t_game *game, t_client *client);

#endif