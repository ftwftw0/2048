/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:15:52 by lchenut           #+#    #+#             */
/*   Updated: 2014/11/07 16:41:13 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	void *str;

	str = (void *)ft_memalloc(size + 1);
	if (!str)
		return ((char *)NULL);
	else
		return ((char *)str);
}
