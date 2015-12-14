/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:40:13 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/14 17:42:25 by jealonso         ###   ########.fr       */
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
	char	**tab_save;
	char	*path;
	char	*save;

	save = NULL;
	tmp = ft_strsplit(cmd, ' ');
	path = ft_cut_str(ft_get_env(*local_env, "PATH"), '=');
	if (!(path))
		return (-1);
	tab = ft_strsplit(path, ':');
	tab_save = tab;
	if (access(tmp[0], X_OK) != -1)
		ft_fork(tmp[0], tmp);
	while (tab && *tab && tab++)
	{
		save = ft_strjoin(*tab, ft_strjoin("/", *tmp));
		if (access(save, F_OK) != -1)
			ft_fork(save, tmp);
	}
	free(save);
	ft_free_tab(tab_save);
	ft_free_tab(tmp);
	return (0);
}
