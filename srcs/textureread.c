/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:16:31 by bbear             #+#    #+#             */
/*   Updated: 2019/05/13 18:53:44 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	textureread(t_wolf *w)
{
	int hei;
	int wid;

	//w->txtre = mlx_xpm_file_to_image(w->mlx_ptr, "./textures/east.xpm",
	//&wid, &hei);
	w->ttxtrs = mlx_xpm_file_to_image(w->mlx_ptr, "./textures/bluestonebrick.xpm",
	&wid, &hei);
	w->txtrs = (int *)mlx_get_data_addr(w->ttxtrs, &w->bpp, &w->size_l, &w->end);
	// w->txtrn = mlx_xpm_file_to_image(w->mlx_ptr, "./textures/north.xpm",
	// &w->wid, &w->hei);
	// w->txtrw = mlx_xpm_file_to_image(w->mlx_ptr, "./textures/west.xpm",
	// &w->wid, &w->hei);
}
