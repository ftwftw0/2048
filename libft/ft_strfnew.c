/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:32:29 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 16:28:32 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfnew(size_t len, char c)
{
	char	*t;

	if (!(t = ft_strnew(len)))
		return (NULL);
	ft_memset(t, c, len);
	return (t);
}
