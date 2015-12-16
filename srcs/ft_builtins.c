/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:35:28 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/14 17:58:35 by jealonso         ###   ########.fr       */
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
	if (chdir(old_prompt) < 0)
		ft_putendl("\t/!\\ An error occurred");
}

void		ft_exec_cd(char *cd, t_list **local_env)
{
	char	*prompt;
	char	*tmp;

	tmp = ft_cut_str(cd, ' ');
	if (!tmp || *tmp == '~' || *tmp == '-')
	{
		if (!tmp || *tmp == '~')
		{
			ft_setenv(local_env, "PWD=", getcwd(NULL, 42));
			ft_setenv(local_env, "OLDPWD=", getcwd(NULL, 42));
			chdir("/nfs/zfs-student-3/users/jealonso");
		}
		else
			ft_back(local_env);
	}
	else
	{
		if ((chdir(ft_cut_str(cd, ' ')) < 0))
			ft_putendl("\t/!\\ An error occurred");
	}
	prompt = getcwd(NULL, 42);
	ft_setenv(local_env, "PWD=", prompt);
	free(prompt);
}
