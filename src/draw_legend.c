/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_legend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:01:52 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/29 15:01:54 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	show_legend(t_fdf *s)
{
	int	x;
	int	y;

	x = 20;
	y = BORDER_H;
	mlx_string_put(s->mlx, s->win, x, (y += x), 0x00ff00, MOVE);
	mlx_string_put(s->mlx, s->win, x, (y += x), 0x00ff00, MOVE_KEY);
	mlx_string_put(s->mlx, s->win, x, (y += x * 3), 0x00ff00, ROT);
	mlx_string_put(s->mlx, s->win, x, (y += x), 0x00ff00, ROT_KEY);
	mlx_string_put(s->mlx, s->win, x, (y += x * 3), 0x00ff00, ZOOM);
	mlx_string_put(s->mlx, s->win, x, s->img_height, 0x00ff00, TWO_D);
	mlx_string_put(s->mlx, s->win, x, s->img_height + x, 0x00ff00, THREE_D);
	x = s->img_width - 2.5 * BORDER_H;
	y = BORDER_H + 20;
	mlx_string_put(s->mlx, s->win, x, y, 0x00ff00, CHNG_W);
	mlx_string_put(s->mlx, s->win, x, s->img_height, 0x00ff00, LGND);
}

void	draw_legend(t_fdf *s)
{
	if (s->legend)
		show_legend(s);
}
