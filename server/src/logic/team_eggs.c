#include <zappy.h>

static void		remove_egg(t_game *game, t_egg *egg)
{
	t_egg		*eggs;

	eggs = game->eggs;
	if (eggs == egg)
		game->eggs = egg->next;
	else
	{
		while (eggs->next != egg)
			eggs = eggs->next;
		eggs->next = egg->next;
	}
	free(egg);
}

bool			team_eggs(t_game *game, t_client *client)
{
	t_egg		*egg;

	egg = game->eggs;
	while (egg)
	{
		if (egg->team == client->team)
		{
			client->x = egg->x;
			client->y = egg->y;
			client->life = egg->life;
			remove_egg(game, egg);
			return (true);
		}
		egg = egg->next;
	}
	return (false);
}