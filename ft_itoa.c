/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:03:02 by aabelque          #+#    #+#             */
/*   Updated: 2018/04/02 13:37:36 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		ft_size_number(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int		ft_abs(int val)
{
	return (val < 0 ? -val : val);
}


char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_size_number(n);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	while (1)
	{
		str[len - 1] = ft_abs(n % 10) + '0';
		n /= 10;
		if (n == 0)
			break ;
		len--;
	}
	return (str);
}
