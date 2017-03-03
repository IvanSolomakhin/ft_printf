/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:59:15 by isolomak          #+#    #+#             */
/*   Updated: 2017/02/27 18:19:24 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_check(t_data *data, char c, t_flags *flags)
{
	if (c == '#')
		return (hesh_flag(flags, data));
	if (c == '-')
		return (left_justify_flag(flags, data));
	if (c == '+')
		return (plus_flag(flags, data));
	if (c == ' ')
		return (space_flag(flags, data));
	if (c == '0')
		return (left_pads(flags, data));
	return (0);
}

int		nbr_check(t_data *data)
{
	if (data->form[data->index] == '.')
	{
		data->index++;
		data->flags.dot++;
		return (precision_check(data, data->index));
	}
	if (data->form[data->index] >= '1' && data->form[data->index] <= '9')
		return (width_check(data));
	return (0);
}

int		length_check(t_data *data, size_t i)
{
	if (data->form[i] == 'h' && data->form[i + 1] == 'h')
		return (len_hh(&data->length, data));
	if (data->form[i] == 'h' && data->length.hh == 0)
		return (len_h(&data->length, data));
	if (data->form[i] == 'l' && data->form[i + 1] == 'l')
		return (len_ll(&data->length, data));
	if (data->form[i] == 'l' && data->length.ll == 0)
		return (len_l(&data->length, data));
	if (data->form[i] == 'j' || data->form[i] == 'z')
		return (len_jz(data->form[i], data));
	return (0);
}

int		form_check(char c, t_data *data, va_list args)
{
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
	{
		manage_str(data, args);
		data->index++;
		return (1);
	}
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' || c == 'x' || c == 'X')
	{
		manage_nbr(data, args);
		data->index++;
		return (1);
	}
	if (c == 'p')
	{
		manage_ptr(data, args);
		data->index++;
		return (1);
	}
	return (0);
}
