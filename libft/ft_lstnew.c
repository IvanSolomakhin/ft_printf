/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:12:58 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/02 20:13:16 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_list(t_list *this, void const *content, size_t content_size)
{
	this->content = ft_memcpy(this->content, content, content_size);
	this->content_size = content_size;
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *this;

	this = (t_list *)malloc(sizeof(t_list));
	if (this == NULL)
		return (NULL);
	if (content)
	{
		this->content = (void *)malloc(sizeof(content_size));
		if (this->content)
			ft_fill_list(this, content, content_size);
		else
		{
			free((void *)this);
			return (NULL);
		}
	}
	else
	{
		this->content = NULL;
		this->content_size = 0;
	}
	this->next = NULL;
	return (this);
}
