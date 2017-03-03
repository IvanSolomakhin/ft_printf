/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:41:20 by isolomak          #+#    #+#             */
/*   Updated: 2016/11/29 20:41:35 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p_dest;
	const unsigned char *p_src;

	p_dest = dest;
	p_src = src;
	i = 0;
	if (p_dest > p_src)
	{
		i = n;
		while (i)
		{
			p_dest[i - 1] = p_src[i - 1];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}
