/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:39:12 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/22 17:39:14 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	make_smaller_window(t_fdf *s)
{
	int	height;

	if (s->zoom > 100.0)
		s->zoom = 100.0;
	s->img_width = s->zoom * s->len_x;
	s->img_height = s->zoom * s->len_y - (2 * BORDER_H);
	height = s->img_height + (2 * BORDER_H);
	if (!(s->win = mlx_new_window(s->mlx, s->img_width, height, FDF)))
		return (handle_error(7));
	s->img = mlx_new_image(s->mlx, s->img_width, s->img_height);
	s->map = (int*)mlx_get_data_addr(s->img, &s->bpp, &s->sl, &s->e);
	s->x_0 = s->img_width / 2;
	s->y_0 = s->img_height / 2;
	return (0);
}

int	make_default_window(t_fdf *s)
{
	if (!(s->win = mlx_new_window(s->mlx, WIN_WIDTH, WIN_HEIGHT, FDF)))
		return (handle_error(7));
	s->img_width = WIN_WIDTH;
	s->img_height = WIN_HEIGHT - (2 * BORDER_H);
	s->img = mlx_new_image(s->mlx, s->img_width, s->img_height);
	s->map = (int*)mlx_get_data_addr(s->img, &s->bpp, &s->sl, &s->e);
	s->x_0 = s->img_width / 2;
	s->y_0 = s->img_height / 2;
	return (0);
}

int	new_window(t_fdf *store)
{
	if (store->flag != 0)
	{
		mlx_destroy_image(store->mlx, store->img);
		mlx_destroy_window(store->mlx, store->win);
	}
	if (store->flag % 2 == 0)
	{
		if (make_default_window(store))
			return (1);
		if (store->flag > 0)
		{
			default_map(store, 0);
			store->flag += 1;
		}
	}
	else
	{
		if (make_smaller_window(store))
			return (1);
		default_map(store, 0);
		store->flag += 1;
	}
	make_visual_environment(store);
	start(store);
	return (0);
}
