/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_visual_environment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:24:49 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/15 15:58:33 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	make_borders(t_fdf *store)
{
	int	x;
	int	y_1;
	int	y_2;

	y_1 = 0;
	y_2 = store->img_height + BORDER_H;
	while (y_1 < BORDER_H)
	{
		x = 0;
		while (x < store->img_width)
		{
			mlx_pixel_put(store->mlx, store->win, x, y_1, 0x6828cd);
			mlx_pixel_put(store->mlx, store->win, x, y_2, 0x6828cd);
			x++;
		}
		y_1++;
		y_2++;
	}
}

void	start_scren(t_fdf *s)
{
	int	x;
	int	y;

	x = s->img_width / 2 - BORDER_H;
	y = s->img_height / 2;
	mlx_string_put(s->mlx, s->win, x, y, 0x0eaaaf, START);
}

void	make_visual_environment(t_fdf *store)
{
	make_borders(store);
	mlx_string_put(store->mlx, store->win, (store->img_width - 30) / 2,
	40, 0xffffff, FDF);
	if (store->flag == 0)
	{
		start_scren(store);
		return ;
	}
	draw_legend(store);
}
