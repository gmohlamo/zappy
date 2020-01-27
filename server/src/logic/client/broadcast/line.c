#include <zappy.h>

void		determine_ver_line(t_client *src, t_client *dest, t_equation *e)
{
	if (dest->x < src->x)
	{
		e->x1 = dest->x;
		e->y1 = 0;
		e->x2 = dest->x;
		e->y2 = dest->y;
	}
	else
	{
		printf("here 1\n");
		e->x1 = dest->x - 1;
		e->y1 = 0;
		e->x2 = dest->x -1;
		e->y2 = dest->y;
		printf("x1: %.2fy1:%.2fx2:%.2fy2:%.2f\n", e->x1, e->y1, e->x2, e->y2);
	}
}

void		determine_hor_line(t_client *src, t_client *dest, t_equation *e)
{
	if ((dest->x < src->x && dest->y < src->y) ||\
	(dest->x > src->x && dest->y < src->y))
	{
		e->x1 = 0;
		e->y1 = dest->y;
		e->x2 = dest->x;
		e->y2 = dest->y;
	}
	else if ((dest->x > src->x && dest->y > src->y) ||\
	 (dest->x < src->x && dest->y > src->y))
	{
		e->x1 = 0;
		e->y1 = dest->y -1;
		e->x2 = dest->x;
		e->y2 = dest->y - 1;
	}
}