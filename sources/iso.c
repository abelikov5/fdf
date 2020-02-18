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

int		iso_x(int x, int y, t_fdf *fdf)
{
	if (fdf->iso)
		return ((x - y) * cos(ISO) + 450);
	return (x - 400);
}

int		iso_y(int x, int y, int z, t_fdf *fdf)
{
	if (fdf->iso)
		return (-z + (x + y) * sin(ISO)) - 200;
	return (y - 180);
}

int		z_rtrn(int z, t_fdf *fdf)
{
	if (z > 0)
		return (z + fdf->step_h);
	return (z);
}
