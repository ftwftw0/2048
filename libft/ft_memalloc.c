/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:39:09 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 12:30:42 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (size)
	{
		str[size - 1] = 0;
		size--;
	}
	str[size] = 0;
	return (str);
}
