#include <zappy.h>

t_intersect		*other_option(t_client *src, t_client *dest, t_intersect *i)
{
	if (src->x > dest->x && src->y > dest->y)
	{
		i->ix = dest->x;
	    if (src->y > dest->y)
	    	i->iy = dest->y + 1;
	    else
	    	i->iy = dest->y - 1;
	}
	else
	{
	    if (src->x > dest->x)
	    	i->ix = dest->x + 1;
	    else
	    	i->ix = dest->x - 1;
	    i->iy = dest->y;
	}
    return (i);
}

t_intersect		*get_ver_intersection(t_client *src, t_client *dest)
{
	t_equation *e;
	t_intersect *i;

	e = (t_equation *)malloc(sizeof(t_equation));
	i = (t_intersect *)malloc(sizeof(t_intersect));
	determine_ver_line(src, dest, e);
	printf("x1: %.2f y1: %.2f x2: %.2f y2: %.2f\n", e->x1, e->y1, e->x2, e->y2);
	e->dx = abs(e->x2 - e->x1);
	e->dy = abs(e->y2 - e->y1);
	e->m1 = 0;
	e->c1 = e->y1 + e->x1;
	e->x1 = src->x;
	e->y1 = src->y;
	e->x2 = dest->x;
	e->y2 = dest->y;
	e->dx = e->x2 - e->x1;
	e->dy = e->y2 - e->y1;
	e->m2 = e->dy / e->dx;
	e->c2 = e->y1 - e->m2 * e->x1;
	printf("equation of line 1: y = %.2fx%c %.2f\n", e->m1, (e->c1 < 0) ? ' ': '+', e->c1);
	printf("equation of line 2: y = %.2fx%c %.2f\n", e->m2, (e->c2 < 0) ? ' ': '+', e->c2);
	if ((e->m1 - e->m2) == 0)
		printf("no intersection between lines\n");
	else
	{
		i->x = (e->c2 - e->c1) / (e->m1 - e->m2);
		i->y = e->m1 * e->x_intersect + e->c1;
		printf("intersection point: = %.2f, %.2f\n", i->x, i->y);
	}
	return (i);
}

t_intersect		*check_if_correct(t_intersect *i, t_client *src,
				t_client *dest)
{
	t_squares *sq;
	t_squares	*s;
    int square_nb;

    square_nb = 1;
    s = get_squares();
    dest->orientation = 4;
    sq = get_square_sp(s, dest->orientation);
    while (square_nb < 9)
    {
        if (i->ix == (dest->x + sq->x) && i->iy == (dest->y + sq->y))
        {
            i->square_nb = square_nb;
            return (i);
        }
        square_nb++;
        sq = sq->next;
    }
    if (((int)i->x == src->x && (int)i->y == src->y) ||\
    ((int)i->x == dest->x && (int)i->y == dest->y))
    	return (other_option(src, dest, i));
    return (get_ver_intersection(src, dest));
}

t_intersect	*get_line_intersection(t_client *src, t_client *dest)
{
	t_equation *e;
	t_intersect *i;

	e = (t_equation *)malloc(sizeof(t_equation));
	i = (t_intersect *)malloc(sizeof(t_intersect));
	determine_hor_line(src, dest, e);
	e->dx = abs(e->x2 - e->x1);
	e->dy = abs(e->y2 - e->y1);
	e->m1 = e->dy / e->dx;
	e->c1 = e->y1 - e->m1 * e->x1;
	e->x1 = src->x;
	e->y1 = src->y;
	e->x2 = dest->x;
	e->y2 = dest->y;
	e->dx = e->x2 - e->x1;
	e->dy = e->y2 - e->y1;
	e->m2 = e->dy / e->dx;
	e->c2 = e->y1 - e->m2 * e->x1;
	printf("equation of line 1: y = %.2fx%c %.2f\n", e->m1, (e->c1 < 0) ? ' ': '+', e->c1);
	printf("equation of line 2: y = %.2fx%c %.2f\n", e->m2, (e->c2 < 0) ? ' ': '+', e->c2);
	if ((e->m1 - e->m2) == 0)
		printf("no intersection between lines\n");
	else
	{
		i->x = (e->c2 - e->c1) / (e->m1 - e->m2);
		i->y = e->m1 * e->x_intersect + e->c1;
		i->iy = ceil(i->y);
		i->ix = ceil(i->x);
		printf("intersection point: = %.8f, %.8f\n intersection point = %.2d, %.2d\n", i->x, i->y, i->ix, i->iy);
	}
	return (check_if_correct(i, src, dest));
}