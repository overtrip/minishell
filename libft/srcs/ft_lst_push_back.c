/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:28:13 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/29 14:52:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **list, t_list *new)
{
	t_list	*begin;

	begin = (*list);
	if (*list)
	{
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = new;
		(*list) = begin;
	}
	else
		(*list) = new;
}
