/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 20:02:48 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/15 19:32:30 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_color(t_dp *dt)
{
	dt->dlt_rgb[0] += dt->step_rgb[0];
	dt->dlt_rgb[1] += dt->step_rgb[1];
	dt->dlt_rgb[2] += dt->step_rgb[2];
	dt->cl_1.rgb[0] = roundf(dt->dlt_rgb[0]);
	dt->cl_1.rgb[1] = roundf(dt->dlt_rgb[1]);
	dt->cl_1.rgb[2] = roundf(dt->dlt_rgb[2]);
}

void	case_x(t_dp *dt, int *map, int x, int y)
{
	int	d;
	int	len;

	d = -dt->ln_x;
	len = dt->len;
	while (len--)
	{
		if (x >= 0 && x < dt->width_brdr && y >= 0 && y < dt->heigth_brdr)
			map[x + y * dt->sl] = dt->cl_1.color_rgb;
		if (dt->rgb_flag)
			set_color(dt);
		x += dt->dx;
		d += 2 * dt->ln_y;
		if (d > 0)
		{
			d -= 2 * dt->ln_x;
			y += dt->dy;
		}
	}
}

void	case_y(t_dp *dt, int *map, int x, int y)
{
	int	d;
	int	len;

	d = -dt->ln_y;
	len = dt->len;
	while (len--)
	{
		if (x >= 0 && x < dt->width_brdr && y >= 0 && y < dt->heigth_brdr)
			map[x + y * dt->sl] = dt->cl_1.color_rgb;
		if (dt->rgb_flag)
			set_color(dt);
		y += dt->dy;
		d += 2 * dt->ln_x;
		if (d > 0)
		{
			d -= 2 * dt->ln_y;
			x += dt->dx;
		}
	}
}

void	prepare_to_draw(t_dp *dt, int *map, int x, int y)
{
	if (dt->cl_1.color_rgb != dt->cl_2.color_rgb)
	{
		dt->step_rgb[0] = (float)(dt->cl_2.rgb[0] - dt->cl_1.rgb[0]) / dt->len;
		dt->step_rgb[1] = (float)(dt->cl_2.rgb[1] - dt->cl_1.rgb[1]) / dt->len;
		dt->step_rgb[2] = (float)(dt->cl_2.rgb[2] - dt->cl_1.rgb[2]) / dt->len;
		dt->dlt_rgb[0] = dt->cl_1.rgb[0];
		dt->dlt_rgb[1] = dt->cl_1.rgb[1];
		dt->dlt_rgb[2] = dt->cl_1.rgb[2];
		if (dt->cl_1.color_rgb < dt->cl_2.color_rgb)
			dt->rgb_flag = 1;
		else
			dt->rgb_flag = 2;
	}
	else
		dt->rgb_flag = 0;
	if (dt->ln_x == 0 && dt->ln_y == 0)
	{
		if (x >= 0 && x < dt->width_brdr && y >= 0 && y < dt->heigth_brdr)
			map[x + y * dt->sl] = dt->cl_1.color_rgb;
	}
	else if (dt->ln_y <= dt->ln_x)
		case_x(dt, map, x, y);
	else
		case_y(dt, map, x, y);
}

void	draw_line(t_fdf *store, size_t p1, size_t p2)
{
	t_dp	data;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = (int)roundf(store->cur_map[p1].x);
	y1 = (int)roundf(store->cur_map[p1].y);
	x2 = (int)roundf(store->cur_map[p2].x);
	y2 = (int)roundf(store->cur_map[p2].y);
	data.sl = store->sl / 4;
	data.dx = (x2 - x1 >= 0 ? 1 : -1);
	data.dy = (y2 - y1 >= 0 ? 1 : -1);
	data.ln_x = (data.dx == 1 ? (x2 - x1) : (x1 - x2));
	data.ln_y = (data.dy == 1 ? (y2 - y1) : (y1 - y2));
	data.len = (data.ln_x > data.ln_y ? data.ln_x : data.ln_y) + 1;
	data.cl_1.color_rgb = store->cur_map[p1].cl;
	data.cl_2.color_rgb = store->cur_map[p2].cl;
	data.heigth_brdr = store->img_height;
	data.width_brdr = store->img_width;
	prepare_to_draw(&data, store->map, x1, y1);
}
