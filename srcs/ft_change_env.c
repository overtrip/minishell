/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 17:11:38 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/01 18:14:32 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

void		ft_setenv(t_list **env, char *str1, char *str2)
{
	t_list	*new;
	t_list	*save;
	char	*tmp;

	tmp = ft_strjoin(str1, str2);
	if ((*env))
	{
		save = (*env);
		while ((*env)->next)
		{
			if (ft_strstr((*env)->data,
						ft_strndup(str1, ft_strchr(str1, '=') - str1)))
				(*env)->data = ft_strdup(str1);
			(*env) = (*env)->next;
		}
		(*env) = save;
	}
	new = ft_create_elem(tmp);
	new->next = *env;
	*env = new;
}

static char	*ft_get_env(t_list *env, char *str)
{
	int	i;

	i = 0;
	while (env->next)
	{
		if (ft_strstr(env->data, str))
			return (str);
		env = env->next;
	}
	return (NULL);
}

static void	ft_env(t_list **env)
{
	uid_t			uid;
	struct passwd	*pw;
	int				i;

	i = 0;
	if (!ft_get_env(*env, "PATH="))
		ft_setenv(env, "PATH=",
				"/bin:/usr/bin:/usr/local/bin:/sbin:/usr/sbin");
	if (!ft_get_env(*env, "SHLVL="))
		ft_setenv(env, "SHLVL=", "1");
	if (!ft_get_env(*env, "TERM="))
		ft_setenv(env, "TERM=", "dumb");
	if (!ft_get_env(*env, "USER="))
	{
		uid = getuid();
		pw = getpwuid(uid);
		if (pw)
			ft_setenv((*env)->data, "USER=", pw->pw_name);
	}
}

void		ft_init_env(t_list **local_env, char **env)
{
	while (*env)
	{
		if (!(*local_env))
			(*local_env) = ft_create_elem(*env);
		else
			ft_list_push_back(local_env, ft_create_elem(*env));
		++env;
	}
	ft_env(local_env);
}
# include <stdio.h>
t_list		*ft_unset_env(t_list **env, char *str)
{
	t_list	*begin;

	if (!(*env))
		return (NULL);
	begin = ft_unset_env(&((*env)->next), str);
	if ((ft_strstr(ft_begin_str((*env)->data, '='), ft_cut_str(str, ' '))))
	{
		ft_putendl("---------------------------");
		printf("(*env)->data -> [%s]\n ft_begin_str((*env)->data, '=') -> [%s]\n str ->[%s]\n",(*env)->data,ft_begin_str((*env)->data, '='), str);
		ft_putendl("---------------------------");
		ft_putendl("------------0--------------");
		free((*env)->data);
		ft_putendl("------------1--------------");
		free((*env));
		ft_putendl("------------2--------------");
		*env = begin;
		ft_putendl("------------3--------------");
		return ((*env));
	}
	else
	{
		(*env)->next = begin;
		return (begin);
	}
}
