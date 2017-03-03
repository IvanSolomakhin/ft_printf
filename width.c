/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:09:59 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 20:27:35 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_width_str(char *ptr, t_flags *flags, int zero)
{
	size_t	i;

	i = 0;
	while (i < flags->width && flags->width > 0)
	{
		if (flags->left_pads > 0 && zero == 1)
			ptr[i] = '0';
		else
			ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

char	*put_width_int(char *ptr, t_flags *flags, char c, int zero)
{
	size_t	i;

	i = 0;
	if (flags->space > 0)
	{
		if (c == 'd' || c == 'i' || c == 'D')
		{
			if (flags->sign != -1 && flags->plus == 0)
			{
				ptr[i++] = ' ';
				flags->space = 0;
			}
		}
	}
	while (i < flags->width && flags->width > 0)
	{
		if (flags->left_pads > 0 && zero == 1 &&
			flags->precision == 0 && flags->dot == 0)
			ptr[i] = '0';
		else
			ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

char	*add_width(char *str, t_flags *flags, char c, int zero)
{
	size_t	len;
	char	*ptr;

	if (flags->width > 0)
	{
		len = ft_strlen(str);
		if (flags->width > len)
		{
			ptr = ft_strnew(flags->width);
			flags->width = flags->width - len;
			if (c == 's' || c == 'c' || c == 'S' || c == 'C')
				ptr = put_width_str(ptr, flags, zero);
			else
				ptr = put_width_int(ptr, flags, c, zero);
			ptr = ft_freejoin(ptr, str, ptr);
			return (ptr);
		}
	}
	return (str);
}

char	*manage_width(char *str, t_data *data, char c, int zero)
{
	if (data->flags.left_justify > 0)
	{
		str = add_hash(str, &data->flags, c);
		str = add_left_justify(str, &data->flags);
	}
	else
	{
		if (data->flags.left_pads > 0 && (data->flags.hash > 0 || c == 'p'))
		{
			if (c == 'x' || c == 'x' || c == 'p')
				data->flags.width -= 2;
			if (c == 'o' || c == 'O')
				data->flags.width--;
			str = add_width(str, &data->flags, c, zero);
			str = add_hash(str, &data->flags, c);
		}
		else
		{
			str = add_hash(str, &data->flags, c);
			str = add_width(str, &data->flags, c, zero);
		}
	}
	return (str);
}

int		width_check(t_data *data)
{
	size_t nbr;

	nbr = 0;
	while (data->form[data->index] >= '0' && data->form[data->index] <= '9')
	{
		nbr = 10 * nbr + data->form[data->index] - '0';
		data->index++;
	}
	if (data->flags.width < nbr)
		data->flags.width = nbr;
	return (1);
}
