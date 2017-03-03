/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:30:06 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 21:26:25 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_d_i(intmax_t i, t_data *data, int length, va_list args)
{
	char *s;

	if (data->form[data->index] == 'i' || data->form[data->index] == 'd')
	{
		i = get_arg_signed(length, args);
		i = get_sign(i, &data->flags);
		s = check_null(i, &data->flags, 10);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		ft_putstr(s);
		free(s);
	}
	if (data->form[data->index] == 'D')
	{
		i = va_arg(args, long int);
		i = get_sign(i, &data->flags);
		s = ft_itoa_base(i, 10);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		ft_putstr(s);
		free(s);
	}
}

void	manage_o(intmax_t i, t_data *data, int length, va_list args)
{
	char *s;

	if (data->form[data->index] == 'o')
	{
		i = get_arg_unsigned(length, args);
		s = check_null_unsigned(i, &data->flags, 8);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		ft_putstr(s);
		free(s);
	}
	if (data->form[data->index] == 'O')
	{
		i = va_arg(args, unsigned long int);
		s = check_null(i, &data->flags, 8);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		ft_putstr(s);
		free(s);
	}
}

void	manage_x(intmax_t i, t_data *data, int length, va_list args)
{
	char *s;

	if (data->form[data->index] == 'x')
	{
		i = get_arg_unsigned(length, args);
		s = check_null_unsigned(i, &data->flags, 16);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		s = ft_strtolower(s);
		ft_putstr(s);
		free(s);
	}
	if (data->form[data->index] == 'X')
	{
		i = get_arg_unsigned(length, args);
		s = check_null_unsigned(i, &data->flags, 16);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		s = ft_strtoupper(s);
		ft_putstr(s);
		free(s);
	}
}

void	manage_u(intmax_t i, t_data *data, int length, va_list args)
{
	char *s;

	if (data->form[data->index] == 'u')
	{
		i = get_arg_unsigned(length, args);
		s = check_null_unsigned(i, &data->flags, 10);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		ft_putstr(s);
		free(s);
	}
	if (data->form[data->index] == 'U')
	{
		i = va_arg(args, unsigned long int);
		s = check_null_unsigned(i, &data->flags, 10);
		s = process_int(s, data, data->form[data->index]);
		data->count = data->count + ft_strlen(s);
		ft_putstr(s);
		free(s);
	}
}
