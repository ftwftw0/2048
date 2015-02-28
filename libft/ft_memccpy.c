/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:36:16 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 12:41:27 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int	cmp;

	cmp = 1;
	while (n && cmp)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		if (*((unsigned char *)src) == (unsigned char)c)
			cmp = 0;
		dst++;
		src++;
		n--;
	}
	return ((cmp) ? NULL : dst);
}
