/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:23:13 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/04 19:26:33 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*this;
	t_list	*b_list;

	b_list = NULL;
	if (lst && (*f))
	{
		this = (*f)(lst);
		b_list = this;
		while (lst->next)
		{
			this->next = (*f)(lst->next);
			this = this->next;
			lst = lst->next;
		}
	}
	return (b_list);
}
