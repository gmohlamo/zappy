#include <zappy.h>

bool			check_ritual_req(t_game *game, t_client *client)
{
	if (client->level <= 2)
		return (level_one_check(game, client));
}