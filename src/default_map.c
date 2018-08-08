/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:25:11 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/15 21:40:55 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	slide_map(t_fdf *s, int x0, int y0)
{
	size_t	i;

	i = 0;
	while (i < s->len_map)
	{
		s->cur_map[i].x = s->org_map[i].x * s->zoom + x0;
		s->cur_map[i].y = s->org_map[i].y * s->zoom + y0;
		s->cur_map[i].z = s->org_map[i].z * s->zoom / 3;
		s->cur_map[i].cl = s->org_map[i].cl;
		i++;
	}
}

void	make_calc(t_fdf *map, int width, int height)
{
	int	zoom_x;
	int	zoom_y;
	int	x_start;
	int	y_start;

	zoom_x = (int)roundf(width / map->len_x);
	zoom_y = (int)roundf(height / map->len_y);
	map->zoom = (zoom_x > zoom_y ? zoom_y : zoom_x);
	x_start = (int)roundf((width - map->zoom * (map->len_x - 1)) / 2);
	y_start = (int)roundf((height - map->zoom * (map->len_y - 1)) / 2);
	slide_map(map, x_start, y_start);
}

void	rot_default_map(t_fdf *s)
{
	size_t	i;

	i = 0;
	while (i < s->len_map)
	{
		s->cur_map[i].y = s->y_0 + (s->cur_map[i].y - s->y_0) * cos(0.3) +
		-s->cur_map[i].z * sin(0.3);
		s->cur_map[i].z = (s->cur_map[i].y - s->y_0) * sin(0.3) +
		s->cur_map[i].z * cos(0.3);
		s->cur_map[i].x = s->x_0 + (s->cur_map[i].x - s->x_0) * cos(0.3) +
		s->cur_map[i].z * sin(0.3);
		s->cur_map[i].z = (s->x_0 - s->cur_map[i].x) * sin(0.3) +
		s->cur_map[i].z * cos(0.3);
		s->cur_map[i].x = s->x_0 + (s->cur_map[i].x - s->x_0) * cos(-0.3) +
		(s->y_0 - s->cur_map[i].y) * sin(-0.3);
		s->cur_map[i].y = s->y_0 + (s->cur_map[i].x - s->x_0) * sin(-0.3) +
		(s->cur_map[i].y - s->y_0) * cos(-0.3);
		i++;
	}
}

void	default_map(t_fdf *store, int rot)
{
	make_calc(store, store->img_width, store->img_height);
	if (rot)
		rot_default_map(store);
	draw_img(store);
}
