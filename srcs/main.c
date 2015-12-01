/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:21:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/01 17:47:08 by jealonso         ###   ########.fr       */
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

static void	ft_free_list(t_list **list)
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

static void	ft_search_in_list(t_list *list, t_list **local_env)
{
	if (list)
	{
		while (list)
		{
			if (!ft_strcmp(list->data, "env"))
				ft_putlist(*local_env);
			if (!ft_strcmp(ft_begin_str(list->data, ' '), "unsetenv"))
				*local_env = ft_unset_env(local_env, ft_cut_str(list->data, ' '));
			if (!ft_strcmp(list->data, "exit"))
				exit(0);
			if (!ft_strcmp(ft_begin_str(list->data, ' '), "setenv"))
				ft_setenv(local_env, ft_cut_str(list->data, ' '), NULL);
			list = list->next;
		}
	}
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
		ft_putstr("?> ");
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
