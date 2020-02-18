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

void		increase_arr(t_fdf *fdf)
{
	int		i;
	int		j;

	fdf->max_h = -9999;
	fdf->min_h = 9999;
	j = 0;
	i = 0;
	while (i < fdf->h_map)
	{
		while (j < fdf->w_map)
		{
			fdf->arr_map[i][j] = fdf->arr_orig[i][j] *
				fdf->increase * fdf->incr_h;
			if (fdf->arr_map[i][j] > fdf->max_h)
				fdf->max_h = fdf->arr_map[i][j];
			if (fdf->arr_map[i][j] < fdf->min_h)
				fdf->min_h = fdf->arr_map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	if (fdf->max_h < 0 || fdf->min_h < 0)
		fdf->g_num = 0;
}

void		copy_arr(t_fdf *fdf, int i, int j, char f)
{
	if (!f)
		fdf->orig_max_h = fdf->max_h;
	while (i < fdf->h_map)
	{
		while (j < fdf->w_map)
		{
			if (!f)
				fdf->arr_orig[i][j] = fdf->arr_map[i][j];
			else
				fdf->arr_map[i][j] = fdf->arr_orig[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}
