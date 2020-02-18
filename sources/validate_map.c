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

void	count_w_h_map(t_fdf *fdf, int i)
{
	char *buf;

	fdf->h_map++;
	fdf->fd = open(fdf->file_name, O_RDONLY);
	if (fdf->fd < 1)
		ft_exit(1);
	if (get_next_line(fdf->fd, &buf) < 0)
		ft_exit(1);
	while (buf[i] != 0)
	{
		if (ft_isdigit(buf[i]) && (buf[i + 1] == ' ' || buf[i + 1] == 0))
			fdf->w_map++;
		i++;
	}
	while (get_next_line(fdf->fd, &buf))
		fdf->h_map++;
	free(buf);
	close(fdf->fd);
}
