/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:51:35 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/15 21:15:58 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		init_ui(t_fdf *s)
{
	if (!(s->mlx = mlx_init()))
		return (handle_error(6));
	if (!(s->cur_map = (t_pnt*)malloc(sizeof(t_pnt) * s->len_map)))
		return (handle_error(10));
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	store;

	store.flag = 0;
	store.legend = 1;
	if (argc == 1)
		return (handle_error(8));
	else if (argc != 2)
		return (handle_error(9));
	if (validation(argv[1], &store))
		return (1);
	if (init_ui(&store))
		return (1);
	if (new_window(&store))
		return (1);
	return (0);
}
