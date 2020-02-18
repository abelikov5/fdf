/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:00:16 by rmarni            #+#    #+#             */
/*   Updated: 2020/01/11 16:46:15 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zero_fdf(t_fdf *fdf)
{
	fdf->step = STEP;
	fdf->increase = 1.0;
	fdf->incr_h = 1.0;
	fdf->g_num = 0;
	increase_arr(fdf);
}

int			height_incr(int button, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->window);
	if (button == NUM_PAD_1)
		fdf->g_num = 0;
	if (button == NUM_PAD_2 && fdf->min_h >= 0)
		fdf->g_num = 1;
	if (button == NUM_PAD_3 && fdf->min_h >= 0)
		fdf->g_num = 2;
	if (button == NUM_PAD_0)
		zero_fdf(fdf);
	else if (button == NUM_PAD_PLUS)
	{
		fdf->incr_h += 0.1;
		increase_arr(fdf);
	}
	else if (button == NUM_PAD_MINUS)
	{
		fdf->incr_h -= 0.1;
		if (fdf->incr_h <= 0)
			fdf->incr_h = 0.0;
		increase_arr(fdf);
	}
	draw_figure(fdf, ZERO, ZERO);
	return (0);
}

void		zoom_map(int button, t_fdf *fdf)
{
	if (fdf->increase <= 0)
		fdf->increase = 0;
	mlx_clear_window(fdf->mlx, fdf->window);
	if (button == SCROLL_DWN)
	{
		if (fdf->w_map > 50 && fdf->increase < 3.0)
			fdf->increase += 0.1;
		if (fdf->w_map < 50 && fdf->increase < 15.0)
			fdf->increase += 0.1;
	}
	if (button == SCROLL_UP)
	{
		fdf->increase -= 0.1;
		if (fdf->increase <= 0)
		{
			mlx_clear_window(fdf->mlx, fdf->window);
			mlx_pixel_put(fdf->mlx, fdf->window, fdf->crds.x0, fdf->crds.y0,
					ft_collor(255, 255, 255));
			draw_menu(fdf, ZERO);
			return ;
		}
	}
	fdf->step = STEP * fdf->increase;
	increase_arr(fdf);
	draw_figure(fdf, ZERO, ZERO);
}

int			mouse_press(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
		zoom_map(button, fdf);
	return (0);
}
