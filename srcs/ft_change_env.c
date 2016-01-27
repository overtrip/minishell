/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 17:11:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/01/27 17:46:29 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

char		*ft_get_env(t_list *env, char *str)
{
	if (env)
		while (env)
		{
			if (ft_strnequ(env->data, str, ft_strlen(str)))
				return (env->data);
			env = env->next;
		}
	return (NULL);
}

static void	ft_env(t_list **env)
{
	uid_t			uid;
	struct passwd	*pw;

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
			ft_setenv(env, "USER=", pw->pw_name);
	}
}

void		ft_init_env(t_list **local_env, char **env)
{
	t_list	*tmp;

	tmp = *local_env;
	if (env && *env)
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

t_list		*ft_unset_env(t_list **env, char *str)
{
	t_list	*begin;

	if (!(env && *env && str))
		return (*env);
	begin = ft_unset_env(&((*env)->next), str);
	if (ft_strnequ((*env)->data, str, ft_strlen(str)))
	{
		free((*env)->data);
		free((*env));
		*env = begin;
		return (begin);
	}
	else
	{
		(*env)->next = begin;
		return (*env);
	}
}

void		ft_setenv(t_list **env, char *str1, char *str2)
{
	t_list	*save;
	char	*tmp;
	char	*env_val;

	if (!str1)
		return ;
	tmp = ft_strjoin(str1, str2);
	if (!(env_val = ft_strndup(str1, ft_strchr(str1, '=') - str1)))
		return ;
	if (env && *env && (save = *env))
	{
		while ((*env)->next)
		{
			if (ft_strnequ((*env)->data, env_val, ft_strlen(env_val)))
			{
				(*env)->data = ft_strdup(tmp);
				*env = save;
				return ;
			}
			(*env) = (*env)->next;
		}
		(*env) = save;
	}
	ft_lstadd(env, ft_create_elem(tmp));
	free(tmp);
}
