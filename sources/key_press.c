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

int			key_press(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS ||
	key == NUM_PAD_0 || key == NUM_PAD_1 || key == NUM_PAD_2 ||
	key == NUM_PAD_3)
		height_incr(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT ||
	key == ARROW_UP || key == ARROW_DOWN || key == SPACE)
		ft_move(key, fdf);
	return (0);
}
