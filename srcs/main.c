/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:21:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/14 17:05:37 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static void	ft_my_split_list(t_list **list, char *buff, int size)
{
	char	*tmp;

	if (!(tmp = ft_strndup(buff, size)))
		return ;
	ft_list_push_back(list, ft_create_elem(ft_strtrim(tmp)));
}

static void	ft_lex(char *buff, t_list **list)
{
	char	*tmp;
	int		parite;

	parite = 0;
	tmp = buff;
	while (buff && *buff)
	{
		if (*buff == '"' && ++parite == 2)
			parite = 0;
		if (*buff == ';' && !parite)
		{
			ft_my_split_list(list, tmp, (buff - tmp));
			tmp = ++buff;
		}
		++buff;
	}
	if (!*buff)
		ft_my_split_list(list, tmp, (buff - tmp));
}

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

static void	ft_exec_cd(char *cd, t_list **local_env)
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

static void	ft_search_in_list(t_list *list, t_list **local_env)
{
	if (list)
	{
		while (list)
		{
			if (!ft_strcmp(list->data, "env"))
				ft_putlist(*local_env);
			else if (!ft_strcmp(ft_begin_str(list->data, ' '), "unsetenv"))
				*local_env = ft_unset_env(local_env,
						ft_cut_str(list->data, ' '));
			else if (!ft_strcmp(list->data, "exit"))
				exit(0);
			else if (!ft_strcmp(ft_begin_str(list->data, ' '), "setenv"))
				ft_setenv(local_env, ft_cut_str(list->data, ' '), NULL);
			else if (!ft_strcmp(ft_begin_str(list->data, ' '), "cd"))
				ft_exec_cd(list->data, local_env);
			else if (ft_find(list->data, local_env) < 0)
				ft_putendl("lol");
			else if (!ft_strcmp(list->data, ""))
				ft_putendl("command not found");
			list = list->next;
		}
	}
}

static void	ft_print_prompt(t_list *local_env)
{
	char	*prompt;
	char	*env_value;

	env_value = ft_cut_str(ft_get_env(local_env, "PWD"), '=');
	prompt = (!env_value) ? ft_strjoin(getcwd(NULL, 42), " ")
		: ft_strjoin(env_value, " ");
	ft_putstr(prompt);
	free(prompt);
}

static void	ft_sig_ctrl_c(int sig)
{
	char	c;

	if (sig == SIGINT)
	{
		ft_putstr("\n\t");
		ft_putstr("Do you really want to quit? [Y/n] ");
	}
	if (1 != read(0, &c, 1))
		ft_putendl("Am error occurred with read function");
	if (c == '\n' || c == 'Y' || c == 'y')
		exit(0);
}

void		ft_sig(void)
{
	signal(SIGINT, ft_sig_ctrl_c);
}

int			main(int argc, char **argv, char **env)
{
	char	*buff;
	t_list	*local_env;
	t_list	*list;

	(void)argc;
	(void)argv;
	buff = NULL;
	list = NULL;
	local_env = NULL;
	ft_init_env(&local_env, env);
	while (1)
	{
		ft_sig();
		ft_print_prompt(local_env);
		if (get_next_line(0, &buff) > 0)
		{
			ft_lex(buff, &list);
			ft_search_in_list(list, &local_env);
		}
		free(buff);
		ft_free_list(&list);
	}
	return (0);
}
