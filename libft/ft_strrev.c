/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:27:16 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/04 19:27:18 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*ptr;
	int		len;
	int		i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	ptr = ft_strnew(len);
	i = 0;
	while (len)
	{
		ptr[i] = str[len - 1];
		len--;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
