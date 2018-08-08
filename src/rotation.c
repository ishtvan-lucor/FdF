/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 21:10:28 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/17 21:10:33 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_x(t_fdf *s, float alpha)
{
	size_t	i;

	i = 0;
	while (i < s->len_map)
	{
		s->cur_map[i].y = s->y_0 + (s->cur_map[i].y - s->y_0) * cos(alpha) +
		-s->cur_map[i].z * sin(alpha);
		s->cur_map[i].z = (s->cur_map[i].y - s->y_0) * sin(alpha) +
		s->cur_map[i].z * cos(alpha);
		i++;
	}
}

void	rot_y(t_fdf *s, float alpha)
{
	size_t	i;

	i = 0;
	while (i < s->len_map)
	{
		s->cur_map[i].x = s->x_0 + (s->cur_map[i].x - s->x_0) * cos(alpha) +
		s->cur_map[i].z * sin(alpha);
		s->cur_map[i].z = (s->x_0 - s->cur_map[i].x) * sin(alpha) +
		s->cur_map[i].z * cos(alpha);
		i++;
	}
}

void	rot_z(t_fdf *s, float alpha)
{
	size_t	i;

	i = 0;
	while (i < s->len_map)
	{
		s->cur_map[i].x = s->x_0 + (s->cur_map[i].x - s->x_0) * cos(alpha) +
		(s->y_0 - s->cur_map[i].y) * sin(alpha);
		s->cur_map[i].y = s->y_0 + (s->cur_map[i].x - s->x_0) * sin(alpha) +
		(s->cur_map[i].y - s->y_0) * cos(alpha);
		i++;
	}
}

void	rotation(t_fdf *store, int key)
{
	float	cof;

	cof = 0.01;
	if (key == 13)
		rot_x(store, cof);
	else if (key == 1)
		rot_x(store, -cof);
	else if (key == 0)
		rot_y(store, -cof);
	else if (key == 2)
		rot_y(store, cof);
	else if (key == 15)
		rot_z(store, -cof);
	else if (key == 3)
		rot_z(store, cof);
	draw_img(store);
}
