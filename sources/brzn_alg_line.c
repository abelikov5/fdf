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

void	brznh_alg_initial(t_fdf *fdf)
{
	fdf->crds.length_x = ft_abs(fdf->crds.x0 - fdf->crds.x1);
	fdf->crds.length_y = ft_abs(fdf->crds.y0 - fdf->crds.y1);
	fdf->crds.len_x = fdf->crds.length_x;
	fdf->crds.len_y = fdf->crds.length_y;
	fdf->crds.length_x++;
	fdf->crds.length_y++;
	fdf->crds.error = 0;
	fdf->crds.x = fdf->crds.x0;
	fdf->crds.y = (double)fdf->crds.y0;
}

void	brznh_alg_add(t_fdf *fdf)
{
	fdf->crds.flag2 = fdf->crds.y0 > fdf->crds.y1 ? 0 : 1;
	fdf->crds.flag = fdf->crds.x0 < fdf->crds.x1 ? 1 : 0;
	while (fdf->crds.len_y--)
	{
		fdf->crds.x_c = fdf->crds.x;
		mlx_pixel_put(fdf->mlx, fdf->window, fdf->crds.x, fdf->crds.y,
				get_collor(fdf));
		fdf->crds.flag2 ? fdf->crds.y++ : fdf->crds.y--;
		fdf->crds.error += 1.0 * fdf->crds.length_x / fdf->crds.length_y;
		if (fdf->crds.error > 1)
		{
			fdf->crds.flag ? fdf->crds.x++ : fdf->crds.x--;
			fdf->crds.error--;
		}
	}
}

void	brznh_alg(t_fdf *fdf)
{
	brznh_alg_initial(fdf);
	if (fdf->crds.length_x > fdf->crds.length_y)
	{
		fdf->crds.flag = fdf->crds.y0 < fdf->crds.y1 ? 1 : 0;
		fdf->crds.flag2 = fdf->crds.x0 > fdf->crds.x1 ? 0 : 1;
		if (fdf->crds.x0 < fdf->crds.x1)
			swap(&fdf->crds.x0, &fdf->crds.x1);
		while (fdf->crds.len_x--)
		{
			fdf->crds.x_c = fdf->crds.x;
			mlx_pixel_put(fdf->mlx, fdf->window, fdf->crds.x, fdf->crds.y,
					get_collor(fdf));
			fdf->crds.flag2 ? fdf->crds.x++ : fdf->crds.x--;
			fdf->crds.error += 1.0 * fdf->crds.length_y / fdf->crds.length_x;
			if (fdf->crds.error > 1)
			{
				fdf->crds.flag ? fdf->crds.y++ : fdf->crds.y--;
				fdf->crds.error--;
			}
		}
	}
	else
		brznh_alg_add(fdf);
}
