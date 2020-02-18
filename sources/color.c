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

int					ft_collor(int red, int green, int blue)
{
	unsigned int	col;

	col = 0;
	col |= (red << 16);
	col |= (green << 8);
	col |= (blue << 0);
	return (col);
}

/*
**  step - кол-во шагов общее;
**  step_crnt - кол-во шагов пройденное;
**  q - цена одного шага;
*/

int					get_collor(t_fdf *fdf)
{
	int				step;
	int				step_crnt;
	double			q;

	if (fdf->crds.h1 == fdf->min_h && fdf->crds.h1 == fdf->crds.h0)
		return (grad_start_end(fdf, 1));
	else if (fdf->crds.h1 == fdf->max_h && fdf->crds.h1 == fdf->crds.h0)
		return (grad_start_end(fdf, 0));
	step = ft_abs(fdf->crds.x1 - fdf->crds.x0);
	step_crnt = ft_abs(fdf->crds.x_c - fdf->crds.x0);
	fdf->color.z_dif = ft_abs(fdf->min_h - fdf->max_h);
	q = (double)(PRST / (fdf->color.z_dif / (double)
		ft_abs(fdf->crds.h1 - fdf->crds.h0))) / step;
	fdf->color.cur_prst = fdf->crds.h0 * PRST / fdf->color.z_dif;
	if (fdf->crds.h0 <= fdf->crds.h1)
		fdf->color.cur_prst += ft_abs(step_crnt * q);
	else
		fdf->color.cur_prst -= ft_abs(step_crnt * q);
	return (ft_collor(fdf->color.grad_arr[fdf->g_num][RED]
	+ ((fdf->color.grad_arr[fdf->g_num][E_RED] - fdf->color.grad_arr[fdf->g_num]
	[RED]) * fdf->color.cur_prst) / PRST, fdf->color.grad_arr[fdf->g_num]
	[GREEN] + ((fdf->color.grad_arr[fdf->g_num][E_GREEN] - fdf->color.grad_arr
	[fdf->g_num][GREEN]) * fdf->color.cur_prst) / PRST, fdf->color.grad_arr
	[fdf->g_num][BLUE] + ((fdf->color.grad_arr[fdf->g_num][E_BLUE]
	- fdf->color.grad_arr[fdf->g_num][BLUE]) * fdf->color.cur_prst) / PRST));
}

int					grad_start_end(t_fdf *fdf, char flag)
{
	if (flag)
		return (ft_collor(fdf->color.grad_arr[fdf->g_num][RED],
				fdf->color.grad_arr[fdf->g_num][GREEN],
				fdf->color.grad_arr[fdf->g_num][BLUE]));
	else
		return (ft_collor(fdf->color.grad_arr[fdf->g_num][E_RED],
				fdf->color.grad_arr[fdf->g_num][E_GREEN],
				fdf->color.grad_arr[fdf->g_num][E_BLUE]));
}
