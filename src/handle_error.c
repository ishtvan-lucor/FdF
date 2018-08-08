/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 22:32:54 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/07 18:41:26 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_error(int error_code)
{
	if (error_code == 1)
		ft_putstr("ERROR: empty file!\n");
	else if (error_code == 2)
		ft_putstr("ERROR: problem with read file!\n");
	else if (error_code == 3)
		ft_putstr("ERROR: not valid map! Different sizes of rows.\n");
	else if (error_code == 5)
		ft_putstr("ERROR: not valid point!\n");
	else if (error_code == 6)
		ft_putstr("ERROR: problem with initialization with mlx libery!\n");
	else if (error_code == 7)
		ft_putstr("ERROR: the window can't be created!\n");
	else if (error_code == 8)
		ft_putstr("ERROR: no maps! Usage: ./fdf name_map\n");
	else if (error_code == 9)
		ft_putstr("ERROR: to many maps! Usage: ./fdf name_map\n");
	else if (error_code == 10)
		ft_putstr("ERROR: problem with memmory!\n");
	return (1);
}
