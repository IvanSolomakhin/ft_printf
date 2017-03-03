/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:29:18 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:31:28 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (len > 0)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			len--;
			i++;
		}
	}
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	return (ft_strsub(s, i, (len + 1)));
}
