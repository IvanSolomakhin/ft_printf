/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:46:25 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/03 16:01:59 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s(t_data *data, va_list args, int length)
{
	char *s;
	void *v;

	if (length == 1 || data->form[data->index] == 'S')
	{
		v = (va_arg(args, wchar_t *));
		s = ft_putwstr(v);
	}
	else
		s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	s = process_char(s, data, data->form[data->index]);
	data->count = data->count + ft_strlen(s);
	ft_putstr(s);
}

void	type_c(t_data *data, va_list args, int length)
{
	int empty;

	empty = 0;
	if (length == 1 || data->form[data->index] == 'C')
		data->spec = ft_manage_wint(va_arg(args, wint_t));
	else
		data->spec[0] = va_arg(args, int);
	if (data->spec[0] == 0)
	{
		empty = 1;
		if (data->flags.width > 0)
			data->flags.width--;
		data->count++;
	}
	data->spec = process_char(data->spec, data, data->form[data->index]);
	data->count = data->count + ft_strlen(data->spec);
	ft_putstr(data->spec);
	if (empty == 1)
		write(1, "\0", 1);
}

void	manage_str(t_data *data, va_list args)
{
	int length;

	length = get_length(&data->length);
	if (data->form[data->index] == 's')
		type_s(data, args, length);
	if (data->form[data->index] == 'S')
		type_s(data, args, length);
	if (data->form[data->index] == 'c')
		type_c(data, args, length);
	if (data->form[data->index] == 'C')
		type_c(data, args, length);
}
