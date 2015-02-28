/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:42:49 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 16:49:25 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*tmp;

	i = ft_strlen(s1);
	tmp = s1;
	while (*s2 && n)
	{
		*((s1++) + i) = *(s2++);
		n--;
	}
	*((s1) + i) = 0;
	return (tmp);
}
