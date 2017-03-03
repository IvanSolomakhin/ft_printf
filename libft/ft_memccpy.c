/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:38:45 by isolomak          #+#    #+#             */
/*   Updated: 2016/11/29 20:40:17 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*p_dest;
	char		p_c;
	const char	*p_src;

	i = 0;
	p_dest = dest;
	p_src = src;
	p_c = c;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		if (p_dest[i] == p_c)
			return (p_dest + i + 1);
		i++;
	}
	return (0);
}
