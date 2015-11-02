/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:21:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/02 16:30:54 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

t_list	*ft_create_elem(char *data)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_list	*ft_my_split_list(t_list *list, char *buff, int size)
{
	t_list	*begin;
	char	*tmp;

	begin = list;
	if ((tmp = (char *)malloc(sizeof(char) * size)))
		tmp = ft_strncpy(tmp, buff, size);
	if (!list)
		list = ft_create_elem(tmp);
	if (begin)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(tmp);
	}
	return (list);
}

t_list	*ft_lex(char *buff, t_list *list)
{
	char	*tmp;
	int		parite;

	parite = 0;
	tmp = buff;
	while (buff && *buff)
	{
		if (*buff == '\"' && ++parite == 2)
			parite = 0;
		if (*buff == ';' && !parite)
		{
			list = ft_my_split_list(list, tmp, (buff - tmp));
			tmp = ++buff;
		}
		++buff;
	}
	if (!*buff)
		list = ft_my_split_list(list, tmp, (buff - tmp));
	return (list);
}

int		main(int argc, char **argv, char **env)
{
	char	*buff;
	char	**local_env;
	t_list	*list;

	(void)argc;
	(void)argv;
	buff = NULL;
	list = NULL;
	ft_get_env(&local_env, env);
	while (1)
	{
		ft_putstr("?> ");
		if (get_next_line(0, &buff) > 0)
		{
			list = ft_lex(buff, list);
			ft_putendl(list->data);
			ft_search_in_list(list, env);
		}
	}
	return (0);
}
