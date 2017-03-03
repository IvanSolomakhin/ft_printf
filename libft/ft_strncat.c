/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:32:01 by isolomak          #+#    #+#             */
/*   Updated: 2016/11/29 21:32:06 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	while (s2[i] && n)
	{
		s1[len + i] = s2[i];
		i++;
		n--;
	}
	s1[len + i] = '\0';
	return (s1);
}
