/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:04:23 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 21:04:25 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t i;
	size_t nbr;

	nbr = n;
	i = 1;
	if (n < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	nbr;
	size_t	len;
	char	*str;

	nbr = n;
	len = count_digits(nbr);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	str[len - 1] = nbr + '0';
	return (str);
}
