/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:33:00 by isolomak          #+#    #+#             */
/*   Updated: 2017/02/27 20:34:53 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_length(t_len *len)
{
	if (len->z > 0)
		return (4);
	if (len->j > 0)
		return (3);
	if (len->ll > 0)
		return (2);
	if (len->l > 0)
		return (1);
	if (len->hh > 0)
		return (6);
	if (len->h > 0)
		return (5);
	return (0);
}

uintmax_t	get_arg_unsigned(int length, va_list args)
{
	uintmax_t	value;

	if (length == 1)
		return (va_arg(args, unsigned long int));
	if (length == 2)
		return (va_arg(args, unsigned long long int));
	if (length == 3)
		return (va_arg(args, uintmax_t));
	if (length == 4)
		return (va_arg(args, size_t));
	value = va_arg(args, unsigned int);
	if (length == 6)
		value = (unsigned char)value;
	else if (length == 5)
		value = (unsigned short int)value;
	else if (length == 0)
		value = (unsigned int)value;
	return (value);
}

intmax_t	get_arg_signed(int length, va_list args)
{
	intmax_t	value;

	if (length == 1)
		return (va_arg(args, long int));
	if (length == 2)
		return (va_arg(args, long long int));
	if (length == 3)
		return (va_arg(args, intmax_t));
	if (length == 4)
		return (va_arg(args, size_t));
	value = va_arg(args, int);
	if (length == 6)
		value = (char)value;
	else if (length == 5)
		value = (short)value;
	else if (length == 0)
		value = (int)value;
	return (value);
}
