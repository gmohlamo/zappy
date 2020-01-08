#include <zappy.h>

void                add_resource(t_client *client, enum e_resource_type resource)
{
    if (resource == thystame)
        client->inventory->thystame_count++;
    else if (resource == deraumere)
        client->inventory->deraumere_count++;
    else if (resource == linemate)
        client->inventory->linemate_count++;
    else if (resource == sibur)
        client->inventory->sibur_count++;
    else if (resource == mendiane)
        client->inventory->mendiane_count++;
    else if (resource == phiras)
        client->inventory->phiras_count++;
    else if (resource == food)
        client->inventory->food_count++;
}

void                get_item(t_game *game, t_client *client, enum e_resource_type resource)
{
    t_objects       *objects;
    size_t          count;

    count = 0;
    objects = game->objects;
    while (count < objects->count)
    {
        if (objects->objects[count].type == resource &&
            objects->objects[count].x == client->x &&
            objects->objects[count].y == client->y)
        {
            add_resource(client, resource);
            objects->objects[count].x = rand() % game->x;
            objects->objects[count].y = rand() % game->y;
            send(client->fd, "ok\n", 3, MSG_DONTWAIT);
            return ;
        }
        count++;
    }
    send(client->fd, "ko\n", 3, MSG_DONTWAIT);
}

void                take_item(t_game *game, t_client *client, char *item)
{
    if (ft_strstr(item, "linemate"))
        get_item(game, client, linemate);
    else if (ft_strstr(item, "deraumere"))
        get_item(game, client, deraumere);
    else if (ft_strstr(item, "sibur"))
        get_item(game, client, sibur);
    else if (ft_strstr(item, "mendiane"))
        get_item(game, client, mendiane);
    else if (ft_strstr(item, "phiras"))
        get_item(game, client, phiras);
    else if (ft_strstr(item, "thystame"))
        get_item(game, client, thystame);
    else if (ft_strstr(item, "food"))
        get_item(game, client, food);
    else
        send(client->fd, "ko\n", 3, MSG_DONTWAIT);
}