/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:40:22 by rmarni            #+#    #+#             */
/*   Updated: 2019/09/23 09:22:51 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = malloc(sizeof(fresh) * size);
	if (fresh == NULL)
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
