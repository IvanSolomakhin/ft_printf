/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_sign_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:16:37 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 20:32:09 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_hash(char *str, t_flags *flags, char form)
{
	if (flags->hash > 0)
	{
		if ((form == 'x' || form == 'X') && ft_atoi(str) != 0)
			str = ft_freejoin("0x", str, str);
		if (form == 'o' || form == 'O')
		{
			if (ft_atoi(str) != 0 && (flags->dot == 0 || flags->precision == 0))
				str = ft_freejoin("0", str, str);
			if (ft_atoi(str) == 0 && flags->dot > 0)
				str = ft_freejoin("0", str, str);
		}
	}
	if (form == 'p')
		str = ft_freejoin("0x", str, str);
	return (str);
}

char	*add_sign(char *str, t_data *data, t_flags *flags)
{
	if (flags->sign == -1)
	{
		if (flags->left_pads > 0)
		{
			if (flags->width > 0)
				flags->width--;
			data->count++;
			ft_putchar('-');
		}
		else
			str = ft_strjoin("-", str);
	}
	if (flags->left_pads > 0 && flags->sign == 1 && flags->plus > 0)
	{
		flags->width--;
		data->count++;
		ft_putchar('+');
	}
	if (flags->sign == 1 && flags->plus > 0 && flags->left_pads == 0)
		str = ft_freejoin("+", str, str);
	return (str);
}

char	*add_space(char *str, t_flags *flags, char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
	{
		if (flags->sign != -1 && flags->plus == 0 && flags->space > 0)
			str = ft_freejoin(" ", str, str);
	}
	return (str);
}
