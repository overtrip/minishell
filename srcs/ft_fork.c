/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:40:13 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/18 18:01:49 by jealonso         ###   ########.fr       */
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

int			ft_find(char *cmd, t_list **local_env)
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
		ft_fork(tmp[0], tmp, local_env);
	while (tab && *tab)
	{
		save = ft_strjoin(*tab, ft_strjoin("/", *tmp));
		if (access(save, F_OK) != -1)
			ft_fork(save, tmp, local_env);
		++tab;
	}
	free(save);
	ft_free_tab(tmp);
	return (0);
}

int			ft_check(char *cmd, t_list **local_env)
{
	char	**tmp;
	char	**tab;
	char	*save;
	int		valide;

	save = NULL;
	valide = 1;
	tmp = ft_strsplit(cmd, ' ');
	tab = ft_strsplit(ft_cut_str(ft_get_env(*local_env, "PATH"), '='), ':');
	while (tab && *tab)
	{
		save = ft_strjoin(*tab, ft_strjoin("/", *tmp));
		if (access(save, F_OK) != -1)
			valide = 0;
		++tab;
	}
	free(save);
	ft_free_tab(tmp);
	return (valide);
}
