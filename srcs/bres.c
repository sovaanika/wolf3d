/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:17:44 by bbear             #+#    #+#             */
/*   Updated: 2019/04/25 17:28:15 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	plotlinelow(double *xc, double *yc, t_wolf *w, int color)
{
	t_bres	data;

	data.delta[0] = xc[1] - xc[0];
	data.delta[1] = yc[1] - yc[0];
	data.yi = 1;
	if (data.delta[1] < 0)
	{
		data.yi = -1;
		data.delta[1] = -1 * (data.delta[1]);
	}
	data.d = 2 * data.delta[1] - data.delta[0];
	data.y = yc[0];
	data.x = xc[0];
	while (data.x <= xc[1] && data.x >= xc[0])
	{
		if (data.d > 0)
		{
			data.y += data.yi;
			data.d = data.d - 2 * data.delta[0];
		}
		data.d = data.d + 2 * data.delta[1];
		if (data.x < w->wid && data.x > 0 && data.y < w->hei && data.y > 0)
			w->data[(int)data.y * w->wid + (int)data.x] = color;
		++data.x;
	}
}

void	plotlinehigh(double *xc, double *yc, t_wolf *w, int color)
{
	t_bres	data;

	data.delta[0] = xc[1] - xc[0];
	data.delta[1] = yc[1] - yc[0];
	data.xi = 1;
	if (data.delta[0] < 0)
	{
		data.xi = -1;
		data.delta[0] = -1 * data.delta[0];
	}
	data.d = 2 * data.delta[0] - data.delta[1];
	data.x = xc[0];
	data.y = yc[0];
	while (data.y <= yc[1] && data.y >= yc[0])
	{
		if (data.d > 0)
		{
			data.x += data.xi;
			data.d = data.d - 2 * data.delta[1];
		}
		data.d = data.d + 2 * data.delta[0];
		if (data.x < w->wid && data.x > 0 && data.y < w->hei && data.y > 0)
			w->data[(int)data.y * w->wid + (int)data.x] = color;
		++data.y;
	}
}

double	*ft_swap(double *param)
{
	double	tmp;

	tmp = param[0];
	param[0] = param[1];
	param[1] = tmp;
	return (param);
}

void	bresenham(t_wolf *w, double *x, double *y)
{
	int		color;

	color = 179879;
	if (fabs(y[1] - y[0]) < fabs(x[1] - x[0]))
		plotlinelow(x, y, w, color);
	else
	{
		if (y[0] > y[1])
			plotlinehigh(ft_swap(x), ft_swap(y), w, color);
		else
			plotlinehigh(x, y, w, color);
	}
}