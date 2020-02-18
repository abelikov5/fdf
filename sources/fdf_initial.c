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

void	grad_initial(t_fdf *fdf)
{
	fdf->color.grad_arr[0][0] = 255;
	fdf->color.grad_arr[0][1] = 255;
	fdf->color.grad_arr[0][2] = 255;
	fdf->color.grad_arr[0][3] = 255;
	fdf->color.grad_arr[0][4] = 255;
	fdf->color.grad_arr[0][5] = 255;
	fdf->color.grad_arr[1][0] = 100;
	fdf->color.grad_arr[1][1] = 115;
	fdf->color.grad_arr[1][2] = 255;
	fdf->color.grad_arr[1][3] = 150;
	fdf->color.grad_arr[1][4] = 210;
	fdf->color.grad_arr[1][5] = 115;
	fdf->color.grad_arr[2][0] = 0;
	fdf->color.grad_arr[2][1] = 210;
	fdf->color.grad_arr[2][2] = 250;
	fdf->color.grad_arr[2][3] = 250;
	fdf->color.grad_arr[2][4] = 0;
	fdf->color.grad_arr[2][5] = 194;
}

void	initial_fdf(t_fdf *fdf, char *file_name)
{
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH_WIN, HEIGHT_WIN,
		"fdf by Rmarni");
	fdf->file_name = file_name;
	fdf->x = 500;
	fdf->y = 500;
	fdf->step = STEP;
	fdf->step_h = 0;
	fdf->max_h = -99999;
	fdf->min_h = 99999;
	fdf->increase = 1.0;
	fdf->incr_h = 1.0;
	fdf->g_num = 0;
	fdf->h_map = 0;
	fdf->w_map = 0;
	fdf->tmp = 0;
	fdf->iso = 1;
	grad_initial(fdf);
}
