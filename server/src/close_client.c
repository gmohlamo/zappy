#include <zappy.h>

void            close_client(t_game *game, t_client *client)
{
    FD_CLR(client->fd, &(game->set));
    close(client->fd);
    client->fd = -1;
    client->op_complete = true;
    client->op = death;
}