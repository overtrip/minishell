/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 17:11:38 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/28 18:31:03 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"
#include <stdio.h>

void	ft_setenv(t_list **env, char *str1, char *str2)
{
	t_list	*new;

	new = ft_create_elem(ft_strjoin(str1, ft_strjoin("=", str2)));
	new->next = *env;
	*env = new;
}

void	ft_unset_env(t_list *begin, char *str)
{
	t_list	*save;
	t_list	*tmp;

	save = begin;
	tmp = begin;
	while (begin->next)
	{
		if (ft_strstr(begin->data, str))
		{
			tmp->next = begin->next;
			free(begin->data);
			free(begin);
			tmp = save;
			return ;
		}
		tmp = begin;
		begin = begin->next;
	}
}

char	*ft_get_env(t_list **env, char *str)
{
	int	i;

	i = 0;
	//ft_putlist(*env);
	while ((*env)->next)
	{
		if (ft_strstr((*env)->data, str))
			return (str);
		(*env) = (*env)->next;
	}
	return (NULL);
}

void	ft_env(t_list **env)
{
	uid_t			uid;
	struct passwd	*pw;
	int				i;

	i = 0;
	while (*env)
	{
		if (!ft_get_env(env, "PATH"))
			ft_setenv(env, "PATH",
					"/bin:/usr/bin:/usr/local/bin:/sbin:/usr/sbin");
		if (!ft_get_env(env, "SHLVL"))
			ft_setenv(env, "SHLVL", "1");
		if (!ft_get_env(env, "TERM"))
			ft_setenv(env, "TERM", "dumb");
		if (!ft_get_env(env, "USER"))
		{
			uid = getuid();
			pw = getpwuid(uid);
			if (pw)
				ft_setenv((*env)->data, "USER", pw->pw_name);
		}
		(*env) = (*env)->next;
	}
}

void	ft_init_env(t_list **local_env, char **env)
{
	while (*env)
	{
		if (!(*local_env))
			(*local_env) = ft_create_elem(*env);
		else
			ft_list_push_back((*local_env), ft_create_elem(*env));
		++env;
	}
	ft_env(local_env);
}

void	ft_search_in_list(t_list *list, t_list **local_env)
{
	if (list)
	{
		ft_putendl(list->data);
		while (list)
		{
			if (ft_strcmp(list->data, "env") == 0)
				ft_putlist(*local_env);
			if (ft_strcmp(list->data, "unset") == 0)
				ft_unset_env(*local_env,list->data);
			if (ft_strcmp(list->data, "exit") == 0)
				exit(0);
			list = list->next;
		}
	}
	else
		ft_putendl("pas de list");
}
