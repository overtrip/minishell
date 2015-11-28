/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:51:39 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/28 18:07:21 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_putlist(t_list *list)
{
	t_list	*begin;

	begin = list;
	if (list)
	{
		while (list->next)
		{
			ft_putendl(list->data);
			list = list->next;
		}
		ft_putendl(list->data);
	}
	list = begin;
}
