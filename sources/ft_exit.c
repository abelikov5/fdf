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

void	ft_exit(int error)
{
	write(1, "ERROR: ", 8);
	if (error == 1)
		write(1, "please upload valid .fdf file\n", 30);
	else if (error == 0)
		write(1, "uploaded file has unsupported symbol\n", 37);
	else if (error == 2)
		write(1, "map has very big num\n", 21);
	else if (error == 3)
		write(1, "arg at line is less\n", 20);
	exit(1);
}
