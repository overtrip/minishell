/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:40:13 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/18 16:05:06 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static int	ft_fork(char *path, char **cmd)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(NULL);
		return (0);
	}
	if (father == 0)
	{
		execve(path, cmd, NULL);
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
		ft_fork(tmp[0], tmp);
	while (tab && *tab)
	{
		save = ft_strjoin(*tab, ft_strjoin("/", *tmp));
		if (access(save, F_OK) != -1)
			ft_fork(save, tmp);
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
