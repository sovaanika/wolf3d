/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:18:27 by bbear             #+#    #+#             */
/*   Updated: 2019/05/13 16:23:45 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	test(t_wolf *w)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	i = 0;
	while (++x < w->wid)
	{
		y = -1;
		while (++y < w->hei)
		{
			w->data[x * w->wid + y] = w->txtrs[i];
			i++;
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
}