/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:23:46 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 16:42:45 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*tmp;

	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	tmp = str;
	while (*s)
		*(str++) = (*f)(*(s++));
	return (tmp);
}
