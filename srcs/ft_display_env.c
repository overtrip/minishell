/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispay_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 17:13:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/17 16:00:05 by jealonso         ###   ########.fr       */
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

void	ft_linker(t_list *list, t_list *new)
{
	t_list	*begin;

	begin = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	list = begin;
}

void	ft_setenv(t_list *env, char *str1, char *str2)
{
	//TODO IMPLEMENTER CETTE FONCTION
}

void	ft_env(t_list *env)
{
	uid_t			uid;
	struct passwd	*pw;

	while (env)
	{
		if (!ft_strstr(env->data, "PATH"))
			ft_setenv(env, "PATH", \
					"/bin:/usr/bin:/usr/local/bin:/sbin:/usr/sbin");
		if (!ft_strstr(env->data, "SHLVL"))
			ft_setenv(env, "SHLVL", "0");
		if (!ft_strstr(env->data, "TERM"))
			ft_setenv(env->data, "TERM", "dumb");
		if (!ft_strstr(env->data, "USER"))
		{
			uid = getuid();
			pw = getpwuid(uid);
			if (pw)
				ft_setenv(env->data, "USER", pw->pw_name);
		}
		env = env->next;
	}
}

void	ft_get_env(t_list *tab_env, char **env)
{
	t_list	*tmp;

	tmp  = NULL;
	while (env++)
		ft_linker(tmp, ft_create_elem(*env));
	ft_env(tmp);
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
