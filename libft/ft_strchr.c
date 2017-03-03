/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:17:07 by isolomak          #+#    #+#             */
/*   Updated: 2016/11/30 20:17:31 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	p_c;

	i = 0;
	p_c = (char)c;
	while (s[i])
	{
		if (s[i] == p_c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == p_c)
		return ((char *)s + i);
	return (0);
}
