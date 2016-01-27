/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:35:28 by jealonso          #+#    #+#             */
/*   Updated: 2016/01/25 17:54:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static void	ft_back(t_list **local_env)
{
	char	*prompt;
	char	*old_prompt;

	old_prompt = NULL;
	prompt = NULL;
	if (!(prompt = ft_cut_str(ft_get_env(*local_env, "PWD"), '=')))
		ft_setenv(local_env, "PWD=", getcwd(NULL, 42));
	prompt = ft_cut_str(ft_get_env(*local_env, "PWD"), '=');
	if (!(old_prompt = ft_cut_str(ft_get_env(*local_env, "OLDPWD"), '=')))
		ft_setenv(local_env, "OLDPWD=", getcwd(NULL, 42));
	old_prompt = ft_cut_str(ft_get_env(*local_env, "OLDPWD"), '=');
	ft_setenv(local_env, "PWD=", old_prompt);
	ft_setenv(local_env, "OLDPWD=", prompt);
	ft_putendl(old_prompt);
	if (chdir(old_prompt) < 0)
		ft_putendl("\t/!\\ An error occurred");
}

void		ft_exec_cd(char *cd, t_list **local_env, char *home)
{
	char	*prompt;
	char	*tmp;

	tmp = ft_cut_str(cd, ' ');
	if (!tmp || *tmp == '-')
	{
		if (!tmp)
		{
			ft_setenv(local_env, "PWD=", getcwd(NULL, 42));
			ft_setenv(local_env, "OLDPWD=", getcwd(NULL, 42));
			if (chdir(home) < 0)
				ft_putendl("\t/!\\ An error occurred");
		}
		else
			ft_back(local_env);
	}
	else
	{
		if (chdir(ft_cut_str(cd, ' ')) < 0)
			ft_putendl("\t/!\\ An error occurred");
	}
	prompt = getcwd(NULL, 42);
	ft_setenv(local_env, "PWD=", prompt);
	free(prompt);
}

void		ft_replace(t_list *list, t_list *local_env)
{
	char	*save;
	char	*env;
	char	*begin;
	char	*tmp;
	char	*first;

	if ((begin = ft_begin_str(list->data, '~')))
	{
		first = list->data;
		save = ft_strdup(ft_strstr(list->data, "~") + 1);
		free(list->data);
		env = ft_absolue(local_env);
		if ((*save) == '/' || !(*save))
			tmp = ft_strjoin(ft_strjoin(begin, env), save);
		else
			tmp = ft_strdup(first);
		list->data = ft_strdup(tmp);
		free(tmp);
		free(save);
	}
}

char		*ft_remove_msp(char *to_cut)
{
	char	*str_new;
	char	*str;
	char	*save;
	int		i;

	i = -1;
	str_new = ft_strtrim(to_cut);
	save = str_new;
	if (!(str = ft_strnew(ft_strlen(str_new))))
		return (NULL);
	while (str_new && *str_new)
	{
		if (*str_new != ' ' && *str_new != '\t')
		{
			if ((*(str_new - 1) == ' ' || *(str_new - 1) == '\t'))
				str[++i] = ' ';
			str[++i] = *str_new;
		}
		++str_new;
	}
	str[++i] = '\0';
	free(save);
	return (str);
}
