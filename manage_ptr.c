/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:59:27 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 21:21:29 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_ptr(t_data *data, va_list args)
{
	void *v;
	char *s;

	v = va_arg(args, void *);
	if (v == 0 && data->flags.dot > 0 && data->flags.precision == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base((long long int)v, 16);
	s = process_int(s, data, data->form[data->index]);
	s = ft_strtolower(s);
	data->count = data->count + ft_strlen(s);
	ft_putstr(s);
	free(s);
}
