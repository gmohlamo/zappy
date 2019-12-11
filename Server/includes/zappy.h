/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:17 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/11 10:35:23 by gmohlamo         ###   ########.fr       */
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
# define CLIENT_ALLOC_ERR "Error: Unable to allocate memory for client"
# define ERR_ACCEPT "Error: Unable to accept socket connection"

enum e_resource_type {linemate, deraumere, sibur, mendiane, phiras, thystame};

typedef struct				s_object //represent game objects
{
	int						x;
	int						y;
	enum e_resource_type	type;
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
	t_list					*lines;
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
	char					*gfx_line;//cause gfx also needs to send lines
	char					*gfx_line_rem;
	struct sockaddr			gfx_addr; //addr info for the gfx
	bool					gfx_bool; //check if the gfx has been connected already... first connection
	int						time_div;
	size_t					allowed_clients;
	size_t					client_count;
	char					**teams;
	useconds_t				timeout;
	struct sockaddr_storage	remoteaddr;//server address information
	struct addrinfo 		hints;
	struct addrinfo			*result;
	struct addrinfo			*rp;
	socklen_t				socklen;
	fd_set					set;
	fd_set					rset;
	fd_set					wset;
	t_client				*clients;
	t_objects				*objects;
}							t_game;

t_game      *init_game(char **av, int ac);
void		run_game(t_game *game);
void		init_client(t_client *client, t_game *game);
char		*parse_args(t_game *game, char **av, int ac);
void		usage_exit(void);
void		append_client(t_game *game, t_client *client);
void		process_line(t_game *game, int fd);
void		close_clients(t_game *game);

#endif