/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:45:26 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/31 15:23:39 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"
# define FDF "FdF"
# define ZOOM "zoom: + -"
# define MOVE "motion along x, y:"
# define MOVE_KEY "left, right, up, down"
# define ROT "rotation along x, y, z:"
# define ROT_KEY "W, S, A, D, R, F keys"
# define TWO_D "2D representation: space"
# define THREE_D "3D representation: enter"
# define CHNG_W "cnahge window: tab"
# define LGND "show/hide legend: L"
# define START "press SPACE to start"
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1400
# define BORDER_H 100

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				cl;
}					t_pnt;

typedef union		u_color
{
	int				color_rgb;
	unsigned char	rgb[3];
}					t_cl_rgb;

typedef struct		s_draw_point
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				ln_x;
	int				ln_y;
	int				len;
	int				sl;
	t_cl_rgb		cl_1;
	t_cl_rgb		cl_2;
	float			dlt_rgb[3];
	float			step_rgb[3];
	int				rgb_flag;
	int				heigth_brdr;
	int				width_brdr;
}					t_dp;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	float			zoom;
	int				*map;
	int				bpp;
	int				sl;
	int				e;
	int				img_width;
	int				img_height;
	int				x_0;
	int				y_0;
	int				flag;
	int				legend;
	size_t			len_x;
	size_t			len_y;
	size_t			len_map;
	t_pnt			*cur_map;
	t_pnt			*org_map;
}					t_fdf;

void				draw_line(t_fdf *store, size_t p1, size_t p2);
void				default_map(t_fdf *store, int rot);
void				move_map(t_fdf *store, int side);
void				draw_img(t_fdf *store);
void				zoom(t_fdf *s, int key);
void				rotation(t_fdf *store, int key);
void				make_visual_environment(t_fdf *store);
void				start(t_fdf *s);
void				draw_legend(t_fdf *s);
int					handle_error(int error_code);
int					validation(char *file, t_fdf *store);
int					catch_hooks(int key, t_fdf *store);
int					new_window(t_fdf *store);
int					free_handle(char *garbage, int error);

#endif
