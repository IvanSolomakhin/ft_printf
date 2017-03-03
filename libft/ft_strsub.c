/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:35:00 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:35:11 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ptr = ft_strnew(len);
	if (ptr == NULL)
		return (NULL);
	while (len > 0)
	{
		ptr[i] = s[start + i];
		i++;
		len--;
	}
	return (ptr);
}
