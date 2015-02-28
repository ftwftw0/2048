/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:55:21 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:23:18 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || (*s1 == *s2 && *s1 == '\0'))
		return (1);
	if (*s1 != *s2)
		return (0);
	return (ft_strnequ(s1 + 1, s2 + 1, n - 1));
}