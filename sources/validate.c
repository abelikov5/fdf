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

void		validate_buf(t_fdf *fdf, char *buf, int i, int j)
{
	while (buf[i] != 0)
	{
		if (!ft_isdigit(buf[i]) && buf[i] != ' ' && buf[i] != '-')
			ft_exit(0);
		i++;
	}
	i = 0;
	while (buf[i] != 0)
	{
		if (ft_isdigit(buf[i]) || buf[i] == '-')
		{
			fdf->arr_map[fdf->tmp][j] = ft_atoi(buf + i);
			if (fdf->arr_map[fdf->tmp][j] > fdf->max_h)
				fdf->max_h = fdf->arr_map[fdf->tmp][j];
			if (fdf->arr_map[fdf->tmp][j] < fdf->min_h)
				fdf->min_h = fdf->arr_map[fdf->tmp][j];
			while ((ft_isdigit(buf[i]) || buf[i] == '-') && buf[i + 1] != 0)
				i++;
			j++;
		}
		i++;
	}
	if (j != fdf->w_map)
		ft_exit(3);
	fdf->tmp++;
}

void		create_arr(t_fdf *fdf, char *buf, int i)
{
	int		**arr;
	int		**arr2;

	while (buf[i] != 0)
	{
		if (!ft_isdigit(buf[i]) && buf[i] != ' ' && buf[i] != '-')
			ft_exit(0);
		i++;
	}
	arr = (int **)malloc(sizeof(int *) * fdf->h_map + 1);
	arr2 = (int **)malloc(sizeof(int *) * fdf->h_map + 1);
	i = 0;
	while (i < fdf->h_map)
	{
		arr[i] = (int *)malloc(sizeof(int) * fdf->w_map + 1);
		arr2[i] = (int *)malloc(sizeof(int) * fdf->w_map + 1);
		i++;
	}
	fdf->arr_map = arr;
	fdf->arr_orig = arr2;
	validate_buf(fdf, buf, 0, 0);
}
