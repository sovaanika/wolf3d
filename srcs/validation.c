/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:56:33 by bbear             #+#    #+#             */
/*   Updated: 2019/04/26 20:37:48 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

// int		validation(int fd)
// {

// }
void	validation(t_wolf *w, int fd)
{
	char	buf[10000];
	char	*res;
	int		count;
	char	*tmp;
	char	**arrn;

	res = ft_strnew(0);
	while ((count = read(fd, buf, 9999)) > 0)
	{
		buf[count] = '\0';
		tmp = res;
		res = ft_strjoin(res, buf);
		free(tmp);
	}
	arrn = ft_strsplit(res, '\n');
	mkmap(arrn, w);
	second_split(arrn, w);
	cleanarr(arrn);
	putcords(w);
	//makestmap(w);
}

void	mkmap(char **arrn, t_wolf *w)
{
	t_point	**map;
	int		i;

	i = 0;
	while (arrn[i])
		i++;
	map = (t_point **)malloc((i + 1) * sizeof(**map));
	w->map = map;
	w->sizey = i;
}

void	second_split(char **arrn, t_wolf *w)
{
	char	**arrfin;
	//char	**elem;
	int		y;
	int		x;
	t_point	**map;

	map = w->map;
	y = -1;
	while (arrn[++y])
	{
		x = -1;
		arrfin = ft_strsplit(arrn[y], ' ');
		check_size(arrfin, w, y);
		map[y] = (t_point *)malloc((w->sizex + 1) * sizeof(t_point));
		while (arrfin[++x])
		{
			//elem = ft_strsplit(arrfin[x], ',');
			map[y][x].z = (double)(ft_atoi(arrfin[x]) * w->textusz);
			//printf("%d %d %f\n", y, x, map[y][x].z);
			map[y][x].color = 1258143 * map[y][x].z;
			//free(elem);
		}
	}
	cleanarr(arrfin);
}

void	check_size(char **arrfin, t_wolf *w, int i)
{
	int		j;

	j = 0;
	while (arrfin[j])
		j++;
	if (i != 0)
		if (j != w->sizex)
			return ;//ft_error(2);
	if (i == 0)
		w->sizex = j;
}

void	cleanarr(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	putcords(t_wolf *w)
{
	t_point	**map;
	int		y;
	int		x;

	y = -1;
	map = w->map;
	while (++y < w->sizey)
	{
		x = -1;
		while (++x < w->sizex)
		{
			map[y][x].x = (double)(x) * 64;//w->cell);
			map[y][x].y = (double)(y) * 64;//w->cell);
		}
	}
}
