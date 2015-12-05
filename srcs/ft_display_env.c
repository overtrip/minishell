/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 17:29:12 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/05 18:56:17 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

int			ft_count_env(char **env)
{
	int	count;

	count = 0;
	if (env)
		while (env++)
			++count;
	return (count);
}

char		*ft_cut_str(char *str, char c)
{
	char	*ptr;

	ptr = NULL;
	if (str)
		ptr = ft_strchr(str, c);
	if (ptr)
		return (++ptr);
	else
		return (ptr);
}

char		*ft_begin_str(char *str, char c)
{
	char	*begin;
	int		size;

	begin = str;
	if (!str)
		return (begin);
	str = ft_strchr(str, c);
	size = (str) ? str - begin : ft_strlen(begin);
	return (ft_strndup(begin, size));
}

void		ft_free_list(t_list **list)
{
	t_list	*tmp;

	while ((*list))
	{
		tmp = (*list);
		(*list) = (*list)->next;
		free(tmp->data);
		free(tmp);
	}
}

static void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			ft_fork(char *path, char **cmd)
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
	while (tab && *tab)
	{
		save = ft_strjoin(*tab, ft_strjoin("/", *tmp));
		if (access(path, F_OK) != -1)
	ft_fork(path, tmp);
		++tab;
	}
	free(save);
	ft_free_tab(tab_save);
	ft_free_tab(tmp);
	return (0);
}
