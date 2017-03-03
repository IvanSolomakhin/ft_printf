/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:18:38 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:37:56 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	match;
	char	*res;

	i = 0;
	res = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			res = (char *)s1 + i;
			match = 0;
			while (s1[i + match] == s2[match] && (i + match) < n)
			{
				if (s2[match + 1] == '\0')
					return (res);
				match++;
			}
		}
		i++;
	}
	return (NULL);
}
