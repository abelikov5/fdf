/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:26:57 by rmarni            #+#    #+#             */
/*   Updated: 2019/09/15 11:35:31 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_int(int n)
{
	int			i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
		ft_count_int(n);
	}
	return (i);
}

static char		*ft_exp(int n)
{
	char		*arr;

	if (n == 0)
	{
		if (!(arr = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		arr[0] = '0';
		arr[1] = '\0';
	}
	if (n == -2147483648)
	{
		if (!(arr = (char *)malloc(sizeof(char) * 12)))
			return (NULL);
		ft_strcpy(arr, "-2147483648");
	}
	return (arr);
}

static char		*ft_neg_mem(int n)
{
	int			i;
	char		*arr;

	i = ft_count_int(n) + 2;
	if (!(arr = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	n *= (-1);
	arr[0] = '-';
	arr[i - 1] = '\0';
	i -= 2;
	while (n)
	{
		arr[i] = (n % 10 + '0');
		i--;
		n /= 10;
	}
	return (arr);
}

static char		*ft_pos_mem(int n)
{
	int			i;
	char		*arr;

	i = ft_count_int(n) + 1;
	if (!(arr = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	arr[i - 1] = '\0';
	i -= 2;
	while (n)
	{
		arr[i] = (n % 10 + '0');
		i--;
		n /= 10;
	}
	return (arr);
}

char			*ft_itoa(int n)
{
	char		*arr;
	int			i;

	i = 0;
	if (n == 0 || n == -2147483648)
		return (ft_exp(n));
	if (n < 0)
	{
		if (!(arr = ft_neg_mem(n)))
			return (NULL);
	}
	else
	{
		if (!(arr = ft_pos_mem(n)))
			return (NULL);
	}
	return (arr);
}
