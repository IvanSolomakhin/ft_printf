/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:31:17 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/03 16:03:36 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char const *s1, char const *s2, char *str)
{
	char *temp;

	temp = str;
	str = ft_strjoin(s1, s2);
	free(temp);
	return (str);
}
