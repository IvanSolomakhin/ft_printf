/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:01:37 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/03 16:00:50 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_rest(t_data *data, char c)
{
	int zero;

	zero = 0;
	if (c)
	{
		if (data->flags.precision > data->flags.width ||
			data->flags.precision == 0)
			zero = 1;
		data->spec[0] = c;
		data->spec = add_precision_str(data->spec, &data->flags, data);
		if (data->flags.left_justify > 0)
			data->spec = add_left_justify(data->spec, &data->flags);
		else
			data->spec = manage_width(data->spec, data, 'c', zero);
		data->count = data->count + ft_strlen(data->spec);
		ft_putstr(data->spec);
		data->index++;
	}
}

int		manage_data(const char *form, t_data *data, va_list args)
{
	if (flag_check(data, form[data->index], &data->flags))
		return (1);
	if (nbr_check(data))
		return (1);
	if (length_check(data, data->index))
		return (1);
	if (form_check(data->form[data->index], data, args))
	{
		free(data->spec);
		return (0);
	}
	manage_rest(data, data->form[data->index]);
	free(data->spec);
	return (0);
}

void	read_data(t_data *data, va_list args)
{
	while (data->form[data->index] != '\0')
	{
		if (data->form[data->index] == '%')
		{
			if (data->form[data->index + 1])
			{
				create_all(data);
				data->index++;
				while (manage_data(data->form, data, args))
					;
			}
			else
				data->index++;
		}
		else
		{
			ft_putchar(data->form[data->index]);
			data->count++;
			data->index++;
		}
	}
}
