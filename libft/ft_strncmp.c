/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 15:36:15 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 16:54:25 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t i)
{
	size_t j;

	return (ft_memcmp(s1, s2, ((j = ft_strlen(s1)) < i) ? j + 1 : i));
}
