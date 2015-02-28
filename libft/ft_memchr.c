/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:23:35 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 13:24:19 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	if (!n)
		return (NULL);
	if (*((unsigned char *)s) == (unsigned char)c)
		return ((void *)s);
	return (ft_memchr(s + 1, c, n - 1));
}
