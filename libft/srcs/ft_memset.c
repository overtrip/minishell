/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:12:09 by jealonso          #+#    #+#             */
/*   Updated: 2015/11/28 13:17:08 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p1;
	size_t			i;

	p1 = (unsigned char *)s;
	i = -1;
	if (n == 0)
		return (s);
	while (++i <= n)
		p1[i] = c;
	p1[++i] = c;
	return (s);
}
