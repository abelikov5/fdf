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

void		read_map(t_fdf *fdf)
{
	char	*buf;

	count_w_h_map(fdf, ZERO);
	fdf->fd = open(fdf->file_name, O_RDONLY);
	get_next_line(fdf->fd, &buf);
	create_arr(fdf, buf, 0);
	while (get_next_line(fdf->fd, &buf))
		validate_buf(fdf, buf, 0, 0);
	close(fdf->fd);
	free(buf);
}

int			main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		initial_fdf(&fdf, av[1]);
		read_map(&fdf);
		copy_arr(&fdf, ZERO, ZERO, ZERO);
		if (fdf.max_h > 9999 || fdf.min_h < -9999)
			ft_exit(2);
		draw_figure(&fdf, ZERO, ZERO);
		setup_cntr(&fdf);
		mlx_loop(fdf.mlx);
	}
	else
		ft_exit(1);
	return (0);
}
