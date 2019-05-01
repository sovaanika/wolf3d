/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:39:38 by bbear             #+#    #+#             */
/*   Updated: 2019/04/30 17:32:09 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	draw(t_wolf *w)
{
	int		x;
	int		y;

	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	x = -1;
	while (++x < w->wid)
	{
		y = -1;
		while (++y < w->hei)
		{
			w->data[y * w->wid + x] = 0;
		}
	}
	raycast(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
}
