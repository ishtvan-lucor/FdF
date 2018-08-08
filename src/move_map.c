/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 20:42:41 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/16 20:42:42 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_y(t_fdf *s, float cof)
{
	size_t	index;

	index = 0;
	while (index < s->len_map)
	{
		s->cur_map[index].y += cof;
		index++;
	}
}

void	move_x(t_fdf *s, float cof)
{
	size_t	index;

	index = 0;
	while (index < s->len_map)
	{
		s->cur_map[index].x += cof;
		index++;
	}
}

void	move_map(t_fdf *store, int side)
{
	float	cof;

	cof = 5.0;
	if (side == 126)
		move_y(store, -cof);
	else if (side == 125)
		move_y(store, cof);
	else if (side == 123)
		move_x(store, -cof);
	else if (side == 124)
		move_x(store, cof);
	draw_img(store);
}
