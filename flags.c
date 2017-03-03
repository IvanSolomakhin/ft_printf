/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:38:15 by isolomak          #+#    #+#             */
/*   Updated: 2017/02/27 20:28:30 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hesh_flag(t_flags *flags, t_data *data)
{
	data->index++;
	flags->hash++;
	return (1);
}

int		left_justify_flag(t_flags *flags, t_data *data)
{
	data->index++;
	flags->left_justify++;
	return (1);
}

int		plus_flag(t_flags *flags, t_data *data)
{
	data->index++;
	flags->plus++;
	return (1);
}

int		space_flag(t_flags *flags, t_data *data)
{
	data->index++;
	flags->space++;
	return (1);
}

int		left_pads(t_flags *flags, t_data *data)
{
	data->index++;
	flags->left_pads++;
	return (1);
}
