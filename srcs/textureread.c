/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:16:31 by bbear             #+#    #+#             */
/*   Updated: 2019/05/01 15:23:33 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	textureread(t_wolf *w)
{
	w->txtre = mlx_xpm_file_to_image(w->mlx_ptr, "../textures/east.xpm",
	w->wid, w->hei);
	w->txtrs = mlx_xpm_file_to_image(w->mlx_ptr, "../textures/south.xpm",
	w->wid, w->hei);
	w->txtrn = mlx_xpm_file_to_image(w->mlx_ptr, "../textures/north.xpm",
	w->wid, w->hei);
	w->txtrw = mlx_xpm_file_to_image(w->mlx_ptr, "../textures/west.xpm",
	w->wid, w->hei);
}
