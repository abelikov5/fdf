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

#include "fdf.h"

void	draw_menu_norma(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->window, 1030, 410, TXT_CLR, "Scroll UP");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 430, TXT_CLR, "Scroll DOWN");
	mlx_string_put(fdf->mlx, fdf->window, 1020, 470, TXT_CLR, "Reset to base:");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 490, TXT_CLR, "NumPud ZERO");
	mlx_string_put(fdf->mlx, fdf->window, 1020, 520, TXT_CLR, "Rotate change:");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 540, TXT_CLR, "Space");
}

void	draw_menu(t_fdf *fdf, int i)
{
	fdf->img.img_menu = mlx_new_image(fdf->mlx, WIDTH_MENU, HEIGHT_WIN);
	fdf->img.data = mlx_get_data_addr(fdf->img.img_menu,
			&fdf->img.bits, &fdf->img.size, &fdf->img.endian);
	fdf->img.ptr = (int *)fdf->img.data;
	while (++i < WIDTH_MENU * HEIGHT_WIN)
		fdf->img.ptr[i] = BACKGROUND_MENU;
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img.img_menu, 1000, 0);
	mlx_string_put(fdf->mlx, fdf->window, 1030, 40, TXT_CLR, "HOW TO USE:");
	mlx_string_put(fdf->mlx, fdf->window, 1020, 80, TXT_CLR, "Gradient:");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 110, TXT_CLR, "1. ONLY WHITE");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 130, TXT_CLR, "2. FUTURE");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 150, TXT_CLR, "3. DISCO");
	mlx_string_put(fdf->mlx, fdf->window, 1020, 190, TXT_CLR, "Height change:");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 210, TXT_CLR, "NumPud PLUS");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 230, TXT_CLR, "NumPud MINUS");
	mlx_string_put(fdf->mlx, fdf->window, 1020, 270, TXT_CLR, "Movement:");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 290, TXT_CLR, "Arrow LEFT");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 310, TXT_CLR, "Arrow RIGHT");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 330, TXT_CLR, "Arrow UP");
	mlx_string_put(fdf->mlx, fdf->window, 1030, 350, TXT_CLR, "Arrow DOWN");
	mlx_string_put(fdf->mlx, fdf->window, 1020, 390, TXT_CLR, "Zoom in/out:");
	draw_menu_norma(fdf);
}
