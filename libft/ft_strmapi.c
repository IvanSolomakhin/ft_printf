/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:14:07 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:38:17 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		dest[i] = (*f)(i, src[i]);
		i++;
	}
	return (dest);
}
