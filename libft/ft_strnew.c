/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:56:30 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:32:48 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	while (i <= size + 1)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
