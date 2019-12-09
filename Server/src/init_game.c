#include <zappy.h>

void        checkaddr(t_game *game)
{
    game->rp = game->result;
    while (game->rp)
    {
        game->fd_sock = socket(game->rp->ai_family, game->rp->ai_socktype,
            game->rp->ai_protocol);
        if (game->fd_sock == -1)
            game->rp = game->rp->ai_next;
        if (bind(game->fd_sock, game->rp->ai_addr,
            game->rp->ai_addrlen) == 0)
            break ;
        else
        {
            close(game->fd_sock);
            game->rp = game->rp->ai_next;
        }
    }
    if (game->rp == NULL)
    {
        ft_putendl_fd("Error: failed to bind to socket", 2);
        freeaddrinfo(game->result);
        free(game);
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(game->result);
}

void        finalize_init(t_game *game)
{
    FD_CLEAR(game->wset);
    game->rset = game->set;
}

void        conn_listen(t_game *game)
{
    int     yes;

    yes = 1;
    setsockopt(game->fd_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    if (listen(game->fd_sock, 1024) == -1)
    {
        ft_putendl_fd("Error: failed to listen on port", 2);
        free(game);
        exit(EXIT_FAILURE);
    }
    FD_SET(game->fd_sock, &(game->set));
    game->max_fd = game->fd_sock; //set to listen for connections and the highest fd has been recorded
    finalize_init(game);
}

t_game      *init_game(char **av, int ac)
{
    t_game  *game;
    char    *addr;

    game = ft_malloc(sizeof(t_game));
    if (game)
    {
        addr = parse_args(game, av, ac);
        game->gfx_bool = false;
        ft_memset(&(game->hints), 0, sizeof(struct addrinfo));
        game->hints.ai_family = AF_UNSPEC;
        game->hints.ai_socktype = SOCK_STREAM;
        game->hints.ai_flags = AI_PASSIVE;
        game->conn = getaddrinfo(NULL, addr, &(game->hints), &(game->result));
        if (game->conn)
        {
            ft_putendl_fd("Error: could not get address information", 2);
            free(game);
            exit(1);
        }
        checkaddr(game);
        conn_listen(game);
    }
    return  (game);
}