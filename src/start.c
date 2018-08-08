/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:30:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/28 16:30:34 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		exit_x(t_fdf *s)
{
	s = NULL;
	exit(1);
	return (0);
}

void	start(t_fdf *s)
{
	mlx_hook(s->win, 2, 5, catch_hooks, s);
	mlx_hook(s->win, 17, 1L << 17, exit_x, s);
	mlx_loop(s->mlx);
}
