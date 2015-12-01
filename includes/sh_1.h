/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:33:34 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/01 17:47:05 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_1_H
# define SH_1_H
# include <unistd.h>
# include <pwd.h>
# include "libft.h"

t_list	*ft_create_elem(char *data);
void	ft_display_env(t_list *env);
char	*ft_cut_str(char *str, char c);
void	ft_init_env(t_list **local_env, char **env);
void	ft_linker(t_list **list, t_list *new);
t_list	*ft_unset_env(t_list **env, char *str);
void	ft_setenv(t_list **env, char *str1, char *str2);
char	*ft_begin_str(char *str, char c);

#endif
