/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:31:55 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 21:35:57 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_int(char *str, t_data *data, char c)
{
	int zero;

	zero = 0;
	if (data->flags.precision > data->flags.width ||
		data->flags.precision == 0)
		zero = 1;
	str = add_precision_int(str, &data->flags);
	str = add_sign(str, data, &data->flags);
	if (data->flags.width > 0 || data->flags.left_justify > 0)
		str = manage_width(str, data, c, zero);
	else
	{
		if (data->flags.hash > 0 || c == 'p')
			str = add_hash(str, &data->flags, c);
	}
	str = add_space(str, &data->flags, c);
	return (str);
}

char	*process_char(char *str, t_data *data, char c)
{
	str = add_precision_str(str, &data->flags, data);
	str = manage_width(str, data, c, 1);
	return (str);
}
