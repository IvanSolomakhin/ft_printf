/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:30 by isolomak          #+#    #+#             */
/*   Updated: 2016/11/29 20:46:22 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;
	unsigned char	p_c;

	str = (unsigned char *)s;
	p_c = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (str[i] == p_c)
			return (str + i);
		i++;
		n--;
	}
	return (0);
}
