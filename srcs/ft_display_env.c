/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 17:29:12 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/14 17:46:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

int		ft_count_env(char **env)
{
	int	count;

	count = 0;
	if (env)
		while (env++)
			++count;
	return (count);
}

char	*ft_cut_str(char *str, char c)
{
	char	*ptr;

	ptr = NULL;
	if (str)
		ptr = ft_strchr(str, c);
	if (ptr)
		return (++ptr);
	else
		return (ptr);
}

char	*ft_begin_str(char *str, char c)
{
	char	*begin;
	int		size;

	begin = str;
	if (!str)
		return (begin);
	str = ft_strchr(str, c);
	size = (str) ? str - begin : ft_strlen(begin);
	return (ft_strndup(begin, size));
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

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
