/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:34:40 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 13:35:46 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if (*((unsigned char *)s1++) != *((unsigned char *)s2++))
			return (*((unsigned char *)--s1) - *((unsigned char *)--s2));
		n--;
	}
	return (0);
}
