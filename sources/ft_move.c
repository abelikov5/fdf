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

int			ft_move_norma(int button, t_fdf *fdf)
{
	if (button == ARROW_DOWN)
	{
		fdf->y += PLUS + PLUS;
		fdf->x += PLUS + PLUS;
	}
	else if (button == ARROW_UP)
	{
		fdf->y -= (PLUS + PLUS);
		fdf->x -= (PLUS + PLUS);
	}
	if (button == ARROW_LEFT)
	{
		fdf->y += (PLUS + PLUS);
		fdf->x -= (PLUS + PLUS);
	}
	else if (button == ARROW_RIGHT)
	{
		fdf->y -= (PLUS + PLUS);
		fdf->x += (PLUS + PLUS);
	}
	return (0);
}

int			ft_move(int button, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->window);
	if (button == SPACE)
		fdf->iso = (fdf->iso ? 0 : 1);
	if (!fdf->iso)
	{
		if (button == ARROW_DOWN)
			fdf->y += PLUS + PLUS;
		else if (button == ARROW_UP)
			fdf->y -= (PLUS + PLUS);
		else if (button == ARROW_LEFT)
			fdf->x -= (PLUS + PLUS);
		else if (button == ARROW_RIGHT)
			fdf->x += (PLUS + PLUS);
	}
	else
		ft_move_norma(button, fdf);
	draw_figure(fdf, ZERO, ZERO);
	return (0);
}
