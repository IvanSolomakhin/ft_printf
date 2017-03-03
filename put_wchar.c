/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:08:17 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/03 16:26:37 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_wint(wint_t wint)
{
	char *str;

	str = NULL;
	if (wint <= 0x7FF)
	{
		str = ft_strnew(1);
		str[0] = (char)(((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = (char)((wint & 0x003F) + 0x80);
	}
	else if (wint <= 0xFFFF)
	{
		str = ft_strnew(2);
		str[0] = (char)(((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = (char)((wint & 0x003F) + 0x80);
	}
	else if (wint <= 0x10FFFF)
	{
		str = ft_strnew(3);
		str[0] = (char)(((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (char)(((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = (char)((wint & 0x003F) + 0x80);
	}
	return (str);
}

char	*ft_manage_wint(wint_t wint)
{
	char *str;

	if (wint <= 0x7F)
	{
		str = ft_strnew(0);
		str[0] = (char)wint;
		return (str);
	}
	else
		return (get_wint(wint));
}

char	*ft_putwstr(wchar_t *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = ft_strnew(0);
	i = 0;
	while (s[i])
	{
		str = ft_freejoin(str, ft_manage_wint(s[i]), str);
		i++;
	}
	return (str);
}
