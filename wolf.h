/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:34:52 by bbear             #+#    #+#             */
/*   Updated: 2019/04/13 20:05:14 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include "SDL2.framework/Headers/SDL.h"
# include "SDL2.framework/Headers/SDL_keycode.h"
# include "SDL2.framework/Headers/SDL_opengl.h"
# include "SDL2.framework/Headers/SDL_events.h"

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	//int			color;
}				t_point;

typedef struct	s_dda
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	int			ix1;
	int			ix2;
	int			iy1;
	int			iy2;
	int			delx;
	int			dely;
	int			len;
	double		dx;
	double		dy;
	double		x;
	double		y;
}				t_dda;

typedef struct	s_wolf
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			end;
	int			wid;
	int			hei;
	int			sizex;
	int			sizey;
	int			textusz;
	t_point		**map;
	t_dda		d;
}				t_wolf;

void			init(t_wolf *w);
void			validation(t_wolf *w, int fd);
void			mkmap(char **arrn, t_wolf *w);
void			second_split(char **arrn, t_wolf *w);
void			check_size(char **arrfin, t_wolf *w, int i);
void			cleanarr(char **array);
void			draw(t_wolf *w);
void			putcords(t_wolf *w);

#endif