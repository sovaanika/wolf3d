/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:04:03 by bbear             #+#    #+#             */
/*   Updated: 2019/04/30 17:36:48 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	rotate(int key, t_wolf *w)
{
	double	flag;

	if (key == 123)
		flag = -1.0;
	else
		flag = 1.0;
	w->rotspd = flag * 0.08727;
	w->dir.oldx = w->dir.x;
	w->dir.x = w->dir.x * cos(w->rotspd) - w->dir.y * sin(w->rotspd);
	w->dir.y = w->dir.oldx * sin(w->rotspd) + w->dir.y * cos(w->rotspd);
	w->plane.oldx = w->plane.x;
	w->plane.x = w->plane.x * cos(w->rotspd) - w->plane.y * sin(w->rotspd);
	w->plane.y = w->plane.oldx * sin(w->rotspd) + w->plane.y * cos(w->rotspd);
	draw(w);
}

void	movement(int key, t_wolf *w)
{
	double	flag;

	if (key == 126)
		flag = 1.0;
	else
		flag = -1.0;
	if (w->map[(int)(w->pos.y)][(int)(w->pos.x + w->dir.x * flag)].z == 0)
		w->pos.x += w->dir.x * flag;
	if (w->map[(int)(w->pos.y + w->dir.y * flag)][(int)(w->pos.x)].z == 0)
		w->pos.y += w->dir.y * flag;
	draw(w);
}
