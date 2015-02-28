/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:02:18 by lchenut           #+#    #+#             */
/*   Updated: 2014/11/05 10:13:40 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp_dst;
	const char	*tmp_src;
	int			i;

	tmp_dst = dst;
	tmp_src = src;
	i = n - 1;
	while (i > -1)
	{
		tmp_dst[i] = tmp_src[i];
		i--;
	}
	return (dst);
}
