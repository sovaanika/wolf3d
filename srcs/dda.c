/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:04:13 by bbear             #+#    #+#             */
/*   Updated: 2019/05/01 15:16:15 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	line_dda(int x, int drawstart, int drawend, t_wolf *w)
{
	w->d.iy1 = drawstart;
	w->d.iy2 = drawend;
	w->d.ix1 = x;
	w->d.ix2 = x;
	w->d.delx = abs(w->d.ix1 - w->d.ix2);
	w->d.dely = abs(w->d.iy1 - w->d.iy2);
	w->d.len = fmax(w->d.delx, w->d.dely);
	if (w->d.len == 0)
		w->data[w->d.ix1 + w->d.iy1 * w->wid] = w->map[w->mapy][w->mapx].color;//w->map[(int)w->d.iy1][(int)w->d.ix1].color;
	else
	{
		w->d.dx = (double)(w->d.ix2 - w->d.ix1) / w->d.len;
		w->d.dy = (double)(w->d.iy2 - w->d.iy1) / w->d.len;
		w->d.x = w->d.ix1;
		w->d.y = w->d.iy1;
		w->d.len++;
		while (w->d.len--)
		{
			w->d.x += w->d.dx;
			w->d.y += w->d.dy;
			w->data[(int)w->d.x + (int)w->d.y * w->wid] = w->map[w->mapy][w->mapx].color;//w->map[(int)w->d.iy1][(int)w->d.ix1].color;
		}
	}
}

// void	line_dda(t_wolf *w)
// {
// 	w->d.ix1 = roundf(w->d.x1);
// 	w->d.ix1 = roundf(w->d.y1);
// 	w->d.ix2 = roundf(w->d.x2);
// 	w->d.iy2 = roundf(w->d.y2);

// 	w->d.delx = abs(w->d.ix1 - w->d.ix2);
// 	w->d.dely = abs(w->d.iy1 - w->d.iy2);
// 	w->d.len = max(w->d.delx, w->d.delx);
// 	if (w->d.len == 0)
// 		w->data[w->d.ix1 + w->d.iy1 * w->wid] = 88888;
// 	else
// 	{
// 		w->d.dx = (w->d.x2 - w->d.x1) / w->d.len;
// 		w->d.dy = (w->d.y2 - w->d.y1) / w->d.len;
// 		w->d.x = w->d.x1;
// 		w->d.y = w->d.y1;
// 		w->d.len++;
// 		while (w->d.len--)
// 		{
// 			w->d.x += w->d.dx;
// 			w->d.y += w->d.dy;
// 			w->data[(int)w->d.x + (int)w->d.iy1 * w->wid] = 88888;
// 			//SetPixel(hdc, roundf(x), roundf(y), 0);
// 		}
// 	}
// }
