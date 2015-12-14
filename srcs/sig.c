/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:30:24 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/14 17:45:22 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

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
