/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:15:12 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 18:07:58 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(uintmax_t nb, int base)
{
	uintmax_t i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char	*ft_base(char *str, uintmax_t nb, uintmax_t len, int base)
{
	uintmax_t i;

	i = 0;
	str[len] = '\0';
	while (len > i)
	{
		if (nb % base <= 9)
		{
			str[len - 1] = nb % base + 48;
		}
		if (nb % base > 9)
		{
			str[len - 1] = nb % base + 55;
		}
		nb = nb / base;
		len--;
	}
	return (str);
}

char	*ft_itoa_base(uintmax_t nb, int base)
{
	uintmax_t	len;
	char		*str;

	len = ft_nbrlen(nb, base);
	str = ft_strnew(len);
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	return (ft_base(str, nb, len, base));
}
