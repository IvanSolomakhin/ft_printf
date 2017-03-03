/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:16:32 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:34:06 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		match;
	char	*res;

	i = 0;
	res = NULL;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			res = (char *)big + i;
			match = 0;
			while (big[i + match] == little[match])
			{
				if (little[match + 1] == '\0')
					return (res);
				match++;
			}
		}
		i++;
	}
	return (NULL);
}
