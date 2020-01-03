#include <zappy.h>

void           gfx_commands(t_game *game)
{
    char        *gfx_line;
    const char  *time_unit = "time_unit";

    gfx_line = game->gfx_line;
    if (!ft_memcmp(gfx_line, time_unit, ft_strlen(time_unit)))
        game->timeout = ft_atoi(&gfx_line[ft_strlen(time_unit)]);
    ft_strdel(&(game->gfx_line));
}