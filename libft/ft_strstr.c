/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:27:57 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:22:27 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	size_t l;

	if (!*s2)
		return ((char *)s1);
	l = ft_strlen(s2);
	while (*s1)
	{
		if (!ft_memcmp(s1, s2, l))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
