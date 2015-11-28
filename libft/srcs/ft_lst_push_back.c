/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:28:13 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/26 15:49:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_push_back(t_list *list, t_list *new)
{
	t_list	*begin;

	begin = list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		list = new;
	return (list);
}
