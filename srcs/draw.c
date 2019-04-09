/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:39:38 by bbear             #+#    #+#             */
/*   Updated: 2019/04/09 18:51:29 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	draw(t_wolf *w)
{
	int		y;
	int		x;

	y = -1;
	while (++y < w->sizey)
	{
		x = -1;
		while (++x < w->sizex)
		{
			w->data[x + y * w->wid] = (w->map[y][x].z + 2) * 250;
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
}