/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:04:13 by bbear             #+#    #+#             */
/*   Updated: 2019/05/13 19:01:19 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	line_dda(int x, int drawstart, int drawend, t_wolf *w)
{
	int		i;

	i = 0;
	w->d.iy1 = drawstart;
	w->d.iy2 = drawend;
	w->d.ix1 = x;
	w->d.ix2 = x;
	w->d.delx = abs(w->d.ix1 - w->d.ix2);
	w->d.dely = abs(w->d.iy1 - w->d.iy2);
	w->d.len = fmax(w->d.delx, w->d.dely);
	if (w->d.len == 0)
		w->data[w->d.ix1 + w->d.iy1 * w->wid] = w->map[w->mapy][w->mapx].color;
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
			if (!w->map[w->mapy][w->mapx].color)
				w->data[(int)w->d.x + (int)w->d.y * w->wid] = w->map[w->mapy][w->mapx].color;
			else
			{
				if (i == 64)
					i = 0;
				w->data[(int)w->d.x + (int)w->d.y * w->wid] = w->txtrs[w->num * 64 + i];// * 256 * 256 + w->txtrs[i + 1] * 256 + w->txtrs[i + 2];
				i++;//= 3;
			}
		}
	}
}
