/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 15:33:34 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/17 15:59:48 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SH_1_H
# define SH_1_H
# include <unistd.h>
# include <pwd.h>
# include "libft.h"

t_list	*ft_create_elem(char *data);
void	ft_display_env(char **env);
void	ft_get_env(t_list *local_env, char **env);
void    ft_search_in_list(t_list *list, char **env);

#endif
