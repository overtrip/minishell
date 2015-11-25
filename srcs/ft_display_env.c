/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 17:29:12 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/25 17:54:14 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

void	ft_display_env(t_list *local_env)
{
	if (local_env)
		while (local_env)
		{
			ft_putendl(local_env->data);
			local_env = local_env->next;
		}
}

int		ft_count_env(char **env)
{
	int	count;

	count = 0;
	if (env)
		while (env++)
			++count;
	return (count);
}

void	ft_linker(t_list **list, t_list *new)
{
	t_list	*begin;

	begin = (*list);
	if ((*list))
	{
		while ((*list)->next)
			(*list) = (*list)->next;
		(*list)->next = new;
		(*list) = begin;
	}
	else
		(*list) = new;
}
