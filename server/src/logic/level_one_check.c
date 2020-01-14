#include <zappy.h>

/*
** level_one_check
** confirms whether an incantation is possible for the client
*/

bool			level_one_check(t_game *game, t_client *client)
{
	size_t		itr;

	itr = 0;
	while (itr < game->objects->count)
	{
		if (game->objects->objects[itr].x == client->x &&
			game->objects->objects[itr].y == client->y &&
			game->objects->objects[itr].type == linemate)
				return (true);
		itr++;
	}
	return (false);
}