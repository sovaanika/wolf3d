/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:34:52 by bbear             #+#    #+#             */
/*   Updated: 2019/05/13 18:59:41 by bbear            ###   ########.fr       */
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

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_direction
{
	double		x;
	double		y;
	double		rayx;
	double		rayy;
	double		oldx;
}				t_direction;

typedef struct	s_position
{
	double		x;
	double		y;
}				t_position;

typedef struct	s_plane
{
	double		x;
	double		oldx;
	double		y;
}				t_plane;

typedef struct	s_camera
{
	double		x;
	double		y;
}				t_camera;

typedef struct	s_distance
{
	double		x;
	double		y;
	double		deltax;
	double		deltay;
	double		perpwall;
}				t_distance;

typedef struct	s_bres
{
	double		delta[2];
	double		xi;
	double		yi;
	double		d;
	double		y;
	double		x;
}				t_bres;

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
	int			lens;
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
	t_direction	dir;
	t_position	pos;
	t_plane		plane;
	t_camera	cam;
	t_distance	dist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			mapx;
	int			mapy;
	int			linehei;
	int			drwstrt;
	int			drwend;
	double		rotspd;
	void		*txtrn;
	void		*ttxtrs;
	int			*txtrs;
	void		*txtrw;
	int			*txtre;
	int			num;
}				t_wolf;

void			init(t_wolf *w);
void			validation(t_wolf *w, int fd);
void			mkmap(char **arrn, t_wolf *w);
void			second_split(char **arrn, t_wolf *w);
void			check_size(char **arrfin, t_wolf *w, int i);
void			cleanarr(char **array);
void			draw(t_wolf *w);
void			putcords(t_wolf *w);
void			line_dda(int x, int drawstart, int drawend, t_wolf *w);
void			raycast(t_wolf *w);
void			rotate(int key, t_wolf *w);
void			movement(int key, t_wolf *w);
void			draw(t_wolf *w);
void			textureread(t_wolf *w);
void			test(t_wolf *w);

#endif