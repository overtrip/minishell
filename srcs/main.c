/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:21:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/28 18:53:48 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"
#include <stdio.h>
void	ft_my_split_list(t_list **list, char *buff, int size)
{
	char	*tmp;

	if (!(tmp = ft_strndup(buff, size)))
		return ;
	(*list) = ft_list_push_back((*list), ft_create_elem(ft_strtrim(tmp)));
}

void	ft_lex(char *buff, t_list **list)
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

void	ft_free_list(t_list **list)
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

int		main(int argc, char **argv, char **env)
{
	char	*buff;
	t_list	*local_env;
	t_list	*list;

	(void)argc;
	(void)argv;
	(void)env;
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
			free(buff);
			ft_free_list(&list);
		}
	}
	ft_free_list(&local_env);
	free(&buff);
	return (0);
}
