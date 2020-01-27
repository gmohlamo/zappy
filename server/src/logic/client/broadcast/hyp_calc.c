#include <zappy.h>

float       get_oob_hypot(t_client *src, t_client *dest, t_game *game)
{
    int     xmax;
    int     ymax;
    double  hypt;

    xmax = game->x;
    ymax = game->y;
    hypt = 0;
    if (src->x == dest->x || src->y == dest->y)
    {
        if (src->y == dest->y)
        {
            if (abs(src->x - dest->x) > (xmax / 2))
                hypt = abs(xmax - abs(src->x - dest->x));
            else
                hypt = abs(src->x - dest->x);
        }
        else
        {
            if (abs(src->y - dest->y) > (ymax / 2))
                hypt = abs(ymax - abs(src->y - dest->y));
            else
                hypt = abs(src->y - dest->y);
        }
    }
    else if (((src->x > xmax / 2) && (dest->x < xmax / 2)) ||\
     ((src->x < xmax / 2) && (dest->x > xmax / 2)))
    {
        if (((src->y > ymax / 2) && (dest->y < ymax / 2)) ||\
            ((src->y < ymax / 2) && (dest->y > ymax / 2)))
        {
            hypt = hypot(abs(src->x + (xmax - dest->x)), abs(src->y + (ymax - dest->y)));
        }
        else if ((src->x < xmax / 2) && (dest->x > xmax / 2))
        {
            hypt = hypot(abs(src->x + (xmax - dest->x)), abs(dest->y - src->y));
        }
        else
        {
            hypt = hypot(abs(dest->x + (xmax - (src->x))), abs(dest->y - src->y));
        }
    }
    else if (((src->y > ymax / 2) && (dest->y < ymax / 2)) ||\
     ((src->y < ymax / 2) && (dest->y > ymax / 2)))
    {
        printf("here y\n");
        if ((src->y < ymax / 2) && (dest->y > ymax / 2))
        {
            hypt = hypot(abs(src->y + (ymax - dest->y)), abs(dest->x - src->x));
        }
        else
        {
            hypt = hypot(abs(dest->y + (ymax - (src->y))), abs(dest->x - src->x));
        }
    }
    else
        hypt = hypot(abs(src->x - dest->x), abs(src->y - dest->y));
    return (hypt);
}