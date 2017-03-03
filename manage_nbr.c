/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:15:11 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/03 16:23:49 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_left_justify(char *str, t_flags *flags)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if (flags->width > len)
	{
		i = 0;
		ptr = ft_strnew(flags->width);
		flags->width = flags->width - len;
		while (str[i])
		{
			ptr[i] = str[i];
			i++;
		}
		while (flags->width)
		{
			ptr[i++] = ' ';
			flags->width--;
		}
		return (ptr);
	}
	return (str);
}

intmax_t	get_sign(intmax_t i, t_flags *flags)
{
	if (i < 0)
	{
		i = -i;
		flags->sign = -1;
	}
	else
		flags->sign = 1;
	return (i);
}

char		*check_null(intmax_t i, t_flags *flags, int base)
{
	if (i == 0 && flags->dot > 0 && flags->precision == 0)
		return (ft_strnew(0));
	else
		return (ft_itoa_base(i, base));
}

char		*check_null_unsigned(uintmax_t i, t_flags *flags, int base)
{
	if (i == 0 && flags->dot > 0 && flags->precision == 0)
		return (ft_strnew(0));
	else
		return (ft_itoa_base(i, base));
}

void		manage_nbr(t_data *data, va_list args)
{
	int			length;
	intmax_t	i;

	i = 0;
	length = get_length(&data->length);
	if (data->form[data->index] == 'i' || data->form[data->index] == 'd')
		manage_d_i(i, data, length, args);
	if (data->form[data->index] == 'D')
		manage_d_i(i, data, length, args);
	if (data->form[data->index] == 'o' || data->form[data->index] == 'O')
		manage_o(i, data, length, args);
	if (data->form[data->index] == 'x' || data->form[data->index] == 'X')
		manage_x(i, data, length, args);
	if (data->form[data->index] == 'u' || data->form[data->index] == 'U')
		manage_u(i, data, length, args);
}
