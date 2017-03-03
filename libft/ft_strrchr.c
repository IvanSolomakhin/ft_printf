/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:20:19 by isolomak          #+#    #+#             */
/*   Updated: 2016/11/30 20:20:59 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	ch;

	ch = (char)c;
	len = ft_strlen(s) - 1;
	str = (char *)s;
	if (ch == '\0')
		return (str + len + 1);
	while (len >= 0)
	{
		if (str[len] == ch)
			return (str + len);
		len--;
	}
	return (0);
}
