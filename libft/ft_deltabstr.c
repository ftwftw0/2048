/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:23:33 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 12:18:19 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltabstr(char **str)
{
	while (*str)
	{
		free(*str);
		*(str++) = NULL;
	}
	free(*str);
	*str = NULL;
	free(str);
	str = NULL;
}
