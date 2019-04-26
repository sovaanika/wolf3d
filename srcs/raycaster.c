/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:30:25 by bbear             #+#    #+#             */
/*   Updated: 2019/04/26 20:17:08 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	raycast(t_wolf *w)
{
	int		x;

	x = -1;
	w->pos.x = 1;
	w->pos.y = 1;
	w->dir.x = 1;
	w->dir.y = 0;
	w->plane.x = 0;
	w->plane.y = 0.66;
	while (++x < w->wid)
	{
		w->cam.x = 2 * (double)x / w->wid - 1;
		w->dir.rayx = w->dir.x + w->plane.x * w->cam.x;
		w->dir.rayy = w->dir.y + w->plane.y * w->cam.x;
		w->mapx = (int)w->pos.x;
		w->mapy = (int)w->pos.y;
		w->dist.deltax = fabs((double)1 / w->dir.rayx);
		w->dist.deltay = fabs((double)1 / w->dir.rayy);
		w->hit = 0;
		if (w->dir.rayx < 0)
		{
			w->stepx = -1;
			w->dist.x = (w->pos.x - w->mapx) * w->dist.deltax;
		}
		else
		{
			w->stepx = 1;
			w->dist.x = (w->mapx + 1.0 - w->pos.x) * w->dist.deltax;
		}
		if (w->dir.rayy < 0)
		{
			w->stepy = -1;
			w->dist.y = (w->pos.y - w->mapy) * w->dist.deltay;
		}
		else
		{
			w->stepy = 1;
			w->dist.y = (w->mapy + 1.0 - w->pos.y) * w->dist.deltay;
		}
		while (w->hit == 0)
		{
			if (w->dist.x < w->dist.y)
			{
				w->dist.x += w->dist.deltax;
				w->mapx += w->stepx;
				w->side = 0;
			}
			else
			{
				w->dist.y += w->dist.deltay;
				w->mapy += w->stepy;
				w->side = 1;
			}
			if (w->map[w->mapy][w->mapx].z > 0)
				w->hit = 1;
		}
		if (w->side == 0)
			w->dist.perpwall = (w->mapx - w->pos.x + (1 - w->stepx) / 2) / w->dir.rayx;
		else
			w->dist.perpwall = (w->mapy - w->pos.y + (1 - w->stepy) / 2) / w->dir.rayy;
		if (w->dist.perpwall != 0)
			w->linehei = (int)(w->hei / w->dist.perpwall);
		else
			w->linehei = w->hei;
		w->drwstrt = -w->linehei / 2 + w->hei / 2;
		if (w->drwstrt < 0)
			w->drwstrt = 0;
		w->drwend = w->linehei / 2 + w->hei / 2;
		if (w->drwend >= w->hei)
			w->drwend = w->hei - 1;
		line_dda(x, w->drwstrt, w->drwend, w);
		//bresenham(w,xm,y);
	}
}
