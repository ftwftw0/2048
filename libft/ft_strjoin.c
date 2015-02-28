/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:09:36 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 16:34:28 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;

	if (!(dst = (char *)ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	*dst = 0;
	ft_strcat(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}
