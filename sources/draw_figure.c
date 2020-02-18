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

void	draw_figure_norma_add(t_fdf *fdf, int i, int j)
{
	fdf->crds.x0 = iso_x(fdf->crds.x_st, fdf->crds.y_st, fdf);
	fdf->crds.y0 = iso_y(fdf->crds.x_st, fdf->crds.y_st,
			z_rtrn(fdf->arr_map[j][i], fdf), fdf);
	fdf->crds.h0 = z_rtrn(fdf->arr_map[j][i], fdf);
	fdf->crds.x1 = iso_x(fdf->crds.x_st, fdf->crds.y_st - fdf->step, fdf);
	fdf->crds.y1 = iso_y(fdf->crds.x_st, fdf->crds.y_st - fdf->step,
			z_rtrn(fdf->arr_map[j - 1][i], fdf), fdf);
	fdf->crds.h1 = z_rtrn(fdf->arr_map[j - 1][i], fdf);
	brznh_alg(fdf);
}

void	draw_figure_norma(t_fdf *fdf, int i, int j)
{
	fdf->crds.x0 = iso_x(fdf->crds.x_st, fdf->crds.y_st, fdf);
	fdf->crds.y0 = iso_y(fdf->crds.x_st, fdf->crds.y_st,
			z_rtrn(fdf->arr_map[j][i], fdf), fdf);
	fdf->crds.h0 = z_rtrn(fdf->arr_map[j][i], fdf);
	fdf->crds.x1 = iso_x(fdf->crds.x_st + fdf->step,
			fdf->crds.y_st, fdf);
	fdf->crds.y1 = iso_y(fdf->crds.x_st + fdf->step,
			fdf->crds.y_st, z_rtrn(fdf->arr_map[j][i + 1], fdf), fdf);
	fdf->crds.h1 = z_rtrn(fdf->arr_map[j][i + 1], fdf);
	brznh_alg(fdf);
}

void	draw_figure(t_fdf *fdf, int i, int j)
{
	fdf->crds.x_st = fdf->x;
	fdf->crds.y_st = fdf->y;
	while (j < fdf->h_map)
	{
		while (i < fdf->w_map)
		{
			if (j > 0)
				draw_figure_norma_add(fdf, i, j);
			if (i < fdf->w_map - 1)
				draw_figure_norma(fdf, i, j);
			fdf->crds.x_st += fdf->step;
			i++;
		}
		fdf->crds.x_st = fdf->x;
		fdf->crds.y_st += fdf->step;
		i = 0;
		j++;
	}
	draw_menu(fdf, ZERO);
}
