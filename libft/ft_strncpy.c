/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:03:13 by lchenut           #+#    #+#             */
/*   Updated: 2014/11/06 15:25:01 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		j;

	i = n;
	j = 0;
	while (i > 0 && src[j] != '\0')
	{
		dst[j] = src[j];
		i--;
		j++;
	}
	while (i > 0)
	{
		dst[j] = '\0';
		i--;
		j++;
	}
	return (dst);
}
