/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:33:34 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/16 16:30:44 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_1_H
# define SH_1_H
# include <unistd.h>
# include <pwd.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include "libft.h"

t_list	*ft_create_elem(char *data);
void	ft_display_env(t_list *env);
char	*ft_cut_str(char *str, char c);
void	ft_init_env(t_list **local_env, char **env);
void	ft_linker(t_list **list, t_list *new);
t_list	*ft_unset_env(t_list **env, char *str);
void	ft_setenv(t_list **env, char *str1, char *str2);
char	*ft_begin_str(char *str, char c);
void	ft_free_list(t_list **list);
int		ft_find(char *list, t_list **local_env);
char	*ft_get_env(t_list *env, char *str);
void	ft_exec_cd(char *cd, t_list **local_env);
void	ft_free_tab(char **tab);
void	ft_sig(void);
void	ft_sig_kill(void);

#endif
