/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:26:30 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/17 17:26:38 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_img(t_fdf *store)
{
	size_t	x;
	size_t	y;
	size_t	row;

	y = 0;
	ft_bzero(store->map, store->img_width * store->img_height * 4);
	while (y < store->len_y)
	{
		x = 0;
		row = y * store->len_x;
		while (x < store->len_x)
		{
			if (x != store->len_x - 1)
				draw_line(store, (x + row), (x + row + 1));
			if (y != store->len_y - 1)
				draw_line(store, (x + row), (x + row + store->len_x));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(store->mlx, store->win, store->img, 0, BORDER_H);
	draw_legend(store);
}
