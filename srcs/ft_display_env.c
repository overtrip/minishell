/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispay_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 17:13:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/01 17:39:33 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

void	ft_display_env(char **env)
{
	if (env && *env && **env)
		while (env++)
			ft_putendl(*env);
}

void	ft_search_in_list(t_list *list, char **env)
{
	if (list)
	{
		while (list)
		{
			if (ft_strcmp(ft_strtrim(list->data), "exit") == 0)
				exit(0);
			if (ft_strcmp(ft_strtrim(list->data), "env") == 0)
				ft_display_env(env);
			list = list->next;
		}
	}
}
