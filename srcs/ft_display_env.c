/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispay_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 17:13:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/02 17:30:37 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

void	ft_display_env(char **local_env)
{
	if (local_env)
		while (local_env++)
			ft_putendl(*local_env);
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

void	ft_get_env(char ***tab_env, char **env)
{
	if (!(*tab_env = (char **)malloc(sizeof(char *) * ft_count_env(env) + 1)))
		return ;
	while (env)
	{
		if (!(**tab_env = (char *)malloc(sizeof(char) * ft_strlen(*env) + 1)))
			return ;
		**tab_env = ft_strdup(*env);
		++*tab_env;
		++env;
	}
	**tab_env = "\0";
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
