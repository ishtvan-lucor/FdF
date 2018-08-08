/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:51:52 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/15 20:44:15 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_legend(t_fdf *s)
{
	if (s->legend)
	{
		s->legend = 0;
		mlx_clear_window(s->mlx, s->win);
		make_visual_environment(s);
		draw_img(s);
	}
	else
	{
		s->legend = 1;
		draw_legend(s);
	}
}

int		catch_hooks(int key, t_fdf *store)
{
	if (key == 53)
		exit(1);
	else if (key == 49)
	{
		if (!store->flag)
			store->flag += 1;
		default_map(store, 0);
	}
	else if (!store->flag)
		return (0);
	else if (key >= 123 && key <= 126)
		move_map(store, key);
	else if (key == 69 || key == 78)
		zoom(store, key);
	else if ((key >= 0 && key < 4) || key == 13 || key == 15)
		rotation(store, key);
	else if (key == 48)
		new_window(store);
	else if (key == 36)
		default_map(store, 1);
	else if (key == 37)
		handle_legend(store);
	return (0);
}
