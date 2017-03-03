/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:20:36 by isolomak          #+#    #+#             */
/*   Updated: 2017/02/27 20:38:59 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_hh(t_len *length, t_data *data)
{
	length->hh++;
	data->index = data->index + 2;
	return (1);
}

int		len_h(t_len *length, t_data *data)
{
	length->h++;
	data->index++;
	return (1);
}

int		len_ll(t_len *length, t_data *data)
{
	length->ll++;
	data->index = data->index + 2;
	return (1);
}

int		len_l(t_len *length, t_data *data)
{
	length->l++;
	data->index++;
	return (1);
}

int		len_jz(char c, t_data *data)
{
	if (c == 'j')
		data->length.j++;
	if (c == 'z')
		data->length.z++;
	data->index++;
	return (1);
}
