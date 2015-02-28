/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:10:03 by lchenut           #+#    #+#             */
/*   Updated: 2014/11/06 16:33:03 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpt(char **dst_temp, size_t *i)
{
	while (**dst_temp != '\0' && *i != 0)
	{
		(*dst_temp)++;
		(*i)--;
	}
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_temp;
	const char	*src_temp;
	size_t		i;
	size_t		dst_len;

	dst_temp = dst;
	src_temp = src;
	i = size;
	cpt(&dst_temp, &i);
	dst_len = ft_strlen(dst) - ft_strlen(dst_temp);
	i = size - dst_len;
	if (i == 0)
		return (ft_strlen(src_temp) + dst_len);
	while (*src_temp != '\0')
	{
		if (i != 1)
		{
			*dst_temp = *src_temp;
			dst_temp++;
			i--;
		}
		src_temp++;
	}
	*dst_temp = '\0';
	return (ft_strlen(src) - ft_strlen(src_temp) + dst_len);
}
