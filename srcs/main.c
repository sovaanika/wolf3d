/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:47:17 by bbear             #+#    #+#             */
/*   Updated: 2019/04/30 18:10:56 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int		key_press(int key, void *param)
{
	t_wolf	*w;

	w = (t_wolf *)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 123 || key == 124)
		rotate(key, w);
	else if (key == 126 || key == 125)
		movement(key, w);
	return (0);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

void	init(t_wolf *w)
{
	w->mlx_ptr = mlx_init();
	w->wid = 1200;
	w->textusz = 1;
	w->hei = 1200;
	w->pos.x = 2;
	w->pos.y = 2;
	w->dir.x = 1;
	w->dir.y = 0;
	w->plane.x = 0;
	w->plane.y = 0.6;
	w->win_ptr = mlx_new_window(w->mlx_ptr, w->wid, w->hei, "wolf");
	w->img_ptr = mlx_new_image(w->mlx_ptr, w->wid, w->hei);
	w->data = (int *)mlx_get_data_addr(w->img_ptr, &w->bpp,
	&w->size_l, &w->end);
}

int		main(int argc, char **argv)
{
	t_wolf	*w;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		//here will be true validation
		w = (t_wolf *)malloc(sizeof(*w));
		init(w);
		validation(w, fd);
		draw(w);
		//mlx_key_hook(w->win_ptr, key_press, (void *)w);
		mlx_hook(w->win_ptr, 17, 0, ft_close, (void *)0);
		mlx_do_key_autorepeaton(w->mlx_ptr);
		mlx_hook(w->win_ptr, 2, (1L << 0), key_press, (void *)w);
		mlx_loop(w->mlx_ptr);
	}
}
