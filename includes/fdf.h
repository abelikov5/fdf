/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:00:16 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 16:46:15 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_FDF_H
# define FD_FDF_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

# define HEIGHT_WIN	1000
# define WIDTH_MENU	200
# define WIDTH_WIN	1200
# define STEP		10
# define BACKGROUND_MENU	0x181818
# define TXT_CLR			0xfae8e8
# define ISO				0.523599
# define PRST		100
# define PLUS		2
# define ZERO		0

/*
** MOUSE CONTROL BUTTON
*/

# define SCROLL_UP		4
# define SCROLL_DWN		5

/*
**  NUM PAD BUTTON
*/

# define NUM_PAD_0			82
# define NUM_PAD_1			83
# define NUM_PAD_2			84
# define NUM_PAD_3			85
# define NUM_PAD_4			86
# define NUM_PAD_5			87
# define NUM_PAD_6			88
# define NUM_PAD_7			89
# define NUM_PAD_8			91
# define NUM_PAD_9			92
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

/*
**  KEYBOARD BUTTON
*/

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MAIN_PAD_ESC		53
# define SPACE				49

/*
**  GRADIENT MAP
*/

# define RED			0
# define GREEN			1
# define BLUE			2
# define E_RED			3
# define E_GREEN		4
# define E_BLUE			5

typedef struct		s_img
{
	int				bits;
	int				size;
	int				endian;
	void			*img_menu;
	char			*data;
	int				*ptr;
}					t_img;

typedef struct		s_coords
{
	int				h0;
	int				h1;
	int				x_c;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				x_st;
	int				y_st;
	int				x;
	float			y;
	float			error;
	char			flag;
	char			flag2;
	int				length_x;
	int				length_y;
	int				len_x;
	int				len_y;
}					t_coords;

typedef struct		s_color
{
	unsigned char	grad_arr[3][6];
	int				z_dif;
	int				cur_prst;
}					t_color;

typedef struct		s_fdf
{
	void			*mlx;
	void			*window;
	int				step;
	char			iso;
	double			increase;
	double			incr_h;
	int				step_h;
	int				x;
	int				y;
	int				**arr_map;
	int				**arr_orig;
	int				orig_max_h;
	int				h_map;
	int				w_map;
	int				fd;
	char			*file_name;
	int				max_h;
	int				min_h;
	char			g_num;
	int				tmp;
	t_color			color;
	t_coords		crds;
	t_img			img;
}					t_fdf;

void				ft_exit(int error);
int					mouse_press(int button, int x, int y, t_fdf *fdf);
void				zoom_map(int button, t_fdf *fdf);
void				setup_cntr(t_fdf *fdf);
void				draw_figure(t_fdf *fdf, int i, int j);
void				draw_menu(t_fdf *fdf, int i);
void				initial_fdf(t_fdf *fdf, char *file_name);
void				increase_arr(t_fdf *fdf);
void				copy_arr(t_fdf *fdf, int i, int j, char f);
int					key_press(int key, t_fdf *fdf);
int					height_incr(int button, t_fdf *fdf);
int					ft_move (int button, t_fdf *fdf);
void				count_w_h_map(t_fdf *fdf, int i);
void				brznh_alg(t_fdf *fdf);
int					ft_collor(int red, int green, int blue);
int					get_collor(t_fdf *fdf);
void				swap(int *a, int *b);
double				ft_abs(double a);
void				draw_figure(t_fdf *fdf, int i, int j);
int					iso_x(int x, int y, t_fdf *fdf);
int					iso_y(int x, int y, int z, t_fdf *fdf);
int					z_rtrn (int z, t_fdf *fdf);
void				validate_buf(t_fdf *fdf, char *buf, int i, int j);
void				create_arr(t_fdf *fdf, char *buf, int i);
int					grad_start_end(t_fdf *fdf, char flag);
int					ft_printf(const char *format, ...);

#endif
