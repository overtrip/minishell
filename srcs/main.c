/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:21:30 by jealonso          #+#    #+#             */
/*   Updated: 2016/01/19 16:57:42 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static void	ft_my_split_list(t_list **list, char *buff, int size)
{
	char	*tmp;
	char	*tmp_2;

	if (!(buff - 1) || !size)
		return ;
	if (!(tmp = ft_strndup(buff, size)))
		return ;
	tmp_2 = ft_strtrim(tmp);
//	tmp_2 = ft_remove_msp(tmp);
	if (ft_strlen(tmp_2))
		ft_list_push_back(list, ft_create_elem(tmp_2));
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
	if (!*buff && *tmp)
		ft_my_split_list(list, tmp, (buff - tmp));
}


static void	ft_search_in_list(t_list *list, t_list **local_env)
{
	if (list)
	{
		while (list)
		{
			if (!ft_strcmp(list->data, "env"))
				ft_putlist(*local_env);
			if (ft_strstr(list->data, "~"))
			{
				ft_replace(list, *local_env);
	//TODO Comprendre pourquoi en laissant comme ca c'est ok.
	//Mais part en boucle infini avec azerty~uiop.
	//Si on enleve le continue alors cd ~/42 ne fonctionne plus.
				continue ;
			}
			else if (!ft_strcmp(ft_begin_str(list->data, ' '), "unsetenv"))
				*local_env = ft_unset_env(local_env,
						ft_cut_str(list->data, ' '));
			else if (!ft_strcmp(list->data, "exit"))
				exit(0);
			else if (!ft_strcmp(ft_begin_str(list->data, ' '), "setenv"))
				ft_setenv(local_env, ft_cut_str(list->data, ' '), NULL);
			else if (!ft_strcmp(ft_begin_str(list->data, ' '), "cd"))
				ft_exec_cd(list->data, local_env, ft_absolue(*local_env));
			else if (ft_find(list->data, local_env, 0) < 1)
				ft_putendl("\tcommand not found");
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
		else
			ft_sig_kill();
		free(buff);
		ft_free_list(&list);
	}
	return (0);
}
