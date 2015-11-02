/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:46:41 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/02 17:23:22 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	len;
	int	counter;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		counter = 0;
		while (counter < len)
		{
			(*f)(counter, s);
			s++;
			counter++;
		}
	}
}
