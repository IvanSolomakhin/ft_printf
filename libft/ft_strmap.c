/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:45:56 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:34:40 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*src;
	char		*dest;
	size_t		i;

	if (s == NULL)
		return (NULL);
	src = (char *)s;
	dest = ft_strnew(ft_strlen(s));
	if (src == NULL || f == NULL || dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = (*f)(src[i]);
		i++;
	}
	return (dest);
}
