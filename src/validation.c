/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 22:12:06 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/05 22:03:05 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Check that lines are equal
*/

int		check_lines(int fd, t_fdf *store)
{
	int		gnl_res;
	char	*line;

	gnl_res = get_next_line(fd, &line);
	if (gnl_res == 0)
		return (free_handle(line, 1));
	else if (gnl_res == -1)
		return (handle_error(2));
	store->len_x = ft_wordssplit(line, ' ');
	store->len_y = 1;
	free(line);
	while ((gnl_res = get_next_line(fd, &line)) == 1)
	{
		if (store->len_x != ft_wordssplit(line, ' '))
			return (free_handle(line, 3));
		store->len_y++;
		free(line);
	}
	free(line);
	if (gnl_res == -1)
		return (handle_error(2));
	return (0);
}

/*
** Check that points are valid
*/

int		check_points(char **data, size_t len)
{
	char	*point;
	size_t	index;

	index = 0;
	while (index < len)
	{
		point = data[index];
		if (*point == '-')
			point++;
		while (ft_isdigit((int)(*point)))
			point++;
		if (!(*point))
		{
			index++;
			continue ;
		}
		if (*point == ',')
			point++;
		else
			return (1);
		if (!(ft_iscolor_rgb(point)))
			return (1);
		index++;
	}
	return (0);
}

/*
** Save all points in the row
*/

void	save_points(char **data, t_fdf *store, size_t y)
{
	size_t	x;
	size_t	row;
	size_t	i;
	char	*ptr_col;

	x = 0;
	row = y * store->len_x;
	while (x < store->len_x)
	{
		i = x + row;
		store->org_map[i].x = (float)x;
		store->org_map[i].y = (float)y;
		store->org_map[i].z = (float)ft_atoi(data[x]);
		if ((ptr_col = ft_strchr(data[x], (int)',')))
			store->org_map[i].cl = ft_atoi_base((ptr_col += 3), 16);
		else if (store->org_map[i].z > 0)
			store->org_map[i].cl = 0x00ff00;
		else if (store->org_map[i].z == 0)
			store->org_map[i].cl = 0x0000ff;
		else
			store->org_map[i].cl = 0xff0000;
		x++;
	}
}

/*
** Make store for save map, call check and save points functions
*/

int		make_map(int fd, t_fdf *store)
{
	size_t	y;
	char	*line;
	char	**data;

	y = 0;
	if (!(store->org_map = (t_pnt*)malloc(sizeof(t_pnt) * store->len_map)))
		return (handle_error(10));
	while (y < store->len_y)
	{
		if (get_next_line(fd, &line) != 1)
			return (free_handle(line, 2));
		data = ft_strsplit(line, ' ');
		free(line);
		if (check_points(data, store->len_x))
		{
			ft_free_after_split(data, store->len_x);
			return (handle_error(5));
		}
		save_points(data, store, y);
		ft_free_after_split(data, store->len_x);
		y++;
	}
	return (0);
}

int		validation(char *file, t_fdf *store)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (check_lines(fd, store))
		return (1);
	close(fd);
	store->len_map = store->len_x * store->len_y;
	if (!store->len_map)
		return (handle_error(5));
	fd = open(file, O_RDONLY);
	if (make_map(fd, store))
		return (1);
	close(fd);
	return (0);
}
