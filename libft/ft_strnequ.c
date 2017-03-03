/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:28:49 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 20:28:51 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] == s2[i] && s2[i] != '\0' && i < (n - 1))
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	if (i == (n - 1))
		return (1);
	return (0);
}
