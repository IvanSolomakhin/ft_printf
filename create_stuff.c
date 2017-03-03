/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:55:43 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/03 15:37:07 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->sign = 0;
	flags->hash = 0;
	flags->left_justify = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->left_pads = 0;
}

void	create_len(t_len *length)
{
	length->hh = 0;
	length->h = 0;
	length->l = 0;
	length->ll = 0;
	length->j = 0;
	length->z = 0;
}

void	new_spec(t_data *data)
{
	data->spec = ft_strnew(0);
}

void	create_all(t_data *data)
{
	create_flags(&data->flags);
	create_len(&data->length);
	new_spec(data);
}

void	create_data(const char *format, t_data *data)
{
	data->form = format;
	data->count = 0;
	data->index = 0;
	data->percent = 0;
}
