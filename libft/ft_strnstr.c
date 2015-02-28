/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:50:43 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:12:32 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (i + len_s2 <= len_s1 && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j] && s2[j] && i + j < n)
				j++;
			if (!s2[j])
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
