#include <zappy.h>

//append a new client to the server
void			append_client(t_game *game, t_client *client)
{
	t_client	*ptr;

	ptr = game->clients;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = client;
	}
	else
		game->clients = client;
	init_client(client, game);
}