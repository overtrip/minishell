/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:40:13 by jealonso          #+#    #+#             */
/*   Updated: 2016/01/19 16:57:44 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static char	**ft_convert_to_tab(t_list *local_env)
{
	int		i;
	char	**tab;
	char	**begin_tab;
	t_list	*begin;

	i = 0;
	tab = NULL;
	begin = local_env;
	while (local_env && ++i)
		local_env = local_env->next;
	tab = (char **)malloc(sizeof(char *) * ++i);
	begin_tab = tab;
	while (begin)
	{
		*tab = ft_strdup(begin->data);
		begin = begin->next;
		++tab;
	}
	*tab = NULL;
	return (begin_tab);
}

static int	ft_fork(char *path, char **cmd, t_list **local_env)
{
	pid_t	father;
	char	**env;

	env = ft_convert_to_tab(*local_env);
	father = fork();
	if (father > 0)
	{
		wait(NULL);
		return (0);
	}
	else if (father == 0)
	{
		execve(path, cmd, env);
		ft_free_tab(env);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}

int			ft_find(char *cmd, t_list **local_env, int valide)
{
	char	**tmp;
	char	**tab;
	char	*path;
	char	*save;

	save = NULL;
	tmp = ft_strsplit(cmd, ' ');
	path = ft_cut_str(ft_get_env(*local_env, "PATH"), '=');
	if (!(path))
		return (-1);
	tab = ft_strsplit(path, ':');
	if (access(tmp[0], X_OK) != -1)
	{
		ft_fork(tmp[0], tmp, local_env);
		return (1);
	}
	while (tab && *tab)
	{
		save = ft_strjoin(*tab, ft_strjoin("/", *tmp));
		if (access(save, F_OK) != -1)
		{
			ft_fork(save, tmp, local_env);
			valide = 1;
		}
		++tab;
	}
	free(save);
	ft_free_tab(tmp);
	return (valide);
}
