/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 17:29:12 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/28 18:09:28 by jealonso         ###   ########.fr       */
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
