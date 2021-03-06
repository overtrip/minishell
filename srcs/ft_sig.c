/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:30:24 by jealonso          #+#    #+#             */
/*   Updated: 2016/01/18 18:02:44 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static void	ft_sig_ctrl_z(int sig)
{
	char	*tmp;

	tmp = ft_strjoin(getcwd(NULL, 42), " ");
	if (sig == SIGTSTP)
	{
		ft_putstr("\n\tYou press to suspend execution but ignored\n");
		ft_putstr(tmp);
	}
	free(tmp);
}

static void	ft_sig_ctrl_c(int sig)
{
	char	*tmp;

	tmp = ft_strjoin(getcwd(NULL, 42), " ");
	if (sig == SIGINT)
	{
		ft_putnbr_fd(EOF, 4);
		ft_putchar('\n');
		ft_putstr(tmp);
	}
	free(tmp);
}

static void	ft_sig_ctrl_b(int sig)
{
	char	c;

	if (sig == SIGQUIT)
		ft_putstr("\n\tDo you really want to terminate and dump core? [Y/n] ");
	if (1 != read(0, &c, 1))
		ft_putendl("Am error occurred with read function");
	if (c == '\n' || c == 'Y' || c == 'y')
		exit(0);
}

void		ft_sig_kill(void)
{
	char	c;

	ft_putstr("\n\tAre you sure to exit programe ? [Y/n]");
	if (1 != read(0, &c, 1))
		ft_sig_kill();
	if (c == '\n' || c == 'Y' || c == 'y')
		exit(0);
	read(0, &c, 1);
}

void		ft_sig(void)
{
	signal(SIGINT, ft_sig_ctrl_c);
	signal(SIGQUIT, ft_sig_ctrl_b);
	signal(SIGTSTP, ft_sig_ctrl_z);
}
