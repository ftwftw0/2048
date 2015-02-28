/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 11:25:57 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:01:37 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, size_t n)
{
	char *str;

	if (ft_strlen(s1) <= n)
		return (ft_strdup(s1));
	if (!(str = ft_strnew(n)))
		return (NULL);
	while (n--)
		str[n] = s1[n];
	return (str);
}
