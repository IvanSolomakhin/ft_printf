/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:55:15 by isolomak          #+#    #+#             */
/*   Updated: 2016/11/29 20:45:10 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*p_dest;
	const char	*p_src;
	size_t		i;

	i = 0;
	p_dest = dest;
	p_src = src;
	while (i < len)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
