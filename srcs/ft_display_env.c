/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 17:29:12 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/02 16:33:34 by jealonso         ###   ########.fr       */
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
	if (str)
		while (*str && *str != c)
			++str;
	++str;
	return (ft_strcpy(str, str));
}

char	*ft_begin_str(char *str, char c)
{
	char	*begin;

	begin = str;
	while (*str && *str != c)
		++str;
	return (ft_strndup(begin, str - begin));
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
