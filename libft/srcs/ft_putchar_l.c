/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:46:40 by jealonso          #+#    #+#             */
/*   Updated: 2015/10/31 15:01:15 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_l(char c)
{
	const char tab[3] = {c, '\n', '\0'};
	int i;

	i = -1;
	while (tab[++i])
		write(1, &tab[i], 1);
}
