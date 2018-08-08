/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:32:57 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/07 21:30:54 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	make_zoom(t_fdf *s, float cof)
{
	size_t	i;

	i = 0;
	while (i < s->len_map)
	{
		s->cur_map[i].x = (s->cur_map[i].x - s->x_0) * cof + s->x_0;
		s->cur_map[i].y = (s->cur_map[i].y - s->y_0) * cof + s->y_0;
		s->cur_map[i].z = s->cur_map[i].z * cof;
		i++;
	}
}

void	zoom(t_fdf *s, int key)
{
	float	cof;

	cof = 0.01;
	if (key == 69)
		make_zoom(s, 1 + cof);
	else if (key == 78 && s->zoom * cof > 0.01)
		make_zoom(s, 1 - cof);
	draw_img(s);
}
