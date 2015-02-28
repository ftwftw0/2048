/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:21:26 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 13:40:33 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (n))))
		return (NULL);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dst, tmp, n);
	free(tmp);
	return (dst);
}
