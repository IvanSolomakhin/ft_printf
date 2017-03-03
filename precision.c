/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:12:24 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/03 15:59:55 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_precision_str(char *str, t_flags *flags, t_data *data)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	if (flags->precision == 0 && flags->dot > 0 &&
		str[0] != '%' && data->spec[0] == 0)
	{
		ptr = ft_strnew(0);
		return (ptr);
	}
	if (flags->precision > 0)
	{
		len = ft_strlen(str);
		if (flags->precision >= len)
			return (str);
		i = -1;
		ptr = ft_strnew(flags->precision);
		while (++i < flags->precision)
			ptr[i] = str[i];
		return (ptr);
	}
	return (str);
}

char	*add_precision_int(char *str, t_flags *flags)
{
	char	*ptr;
	size_t	len;
	size_t	precision;
	size_t	i;

	i = 0;
	precision = 0;
	len = ft_strlen(str);
	if (flags->precision >= len)
	{
		precision = flags->precision - len;
		ptr = ft_strnew(len + precision);
		while (precision > 0)
		{
			ptr[i++] = '0';
			precision--;
		}
		while (str[precision])
		{
			ptr[i++] = str[precision];
			precision++;
		}
		return (ptr);
	}
	return (str);
}

int		precision_check(t_data *data, size_t i)
{
	size_t nbr;

	nbr = 0;
	while (data->form[i] >= '0' && data->form[i] <= '9')
	{
		nbr = 10 * nbr + data->form[data->index++] - '0';
		i++;
	}
	data->flags.precision = nbr;
	return (1);
}
