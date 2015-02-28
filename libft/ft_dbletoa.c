/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbletoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 16:31:32 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 12:16:44 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dbletoa(double i, int j)
{
	double	l;
	char	*str;
	char	*join;
	char	*end;

	str = ft_itoa((int)i);
	l = i - (double)((int)i);
	l = (l < 0.0) ? l * -1.0 : l;
	if ((int)j == 0)
		return (str);
	end = ft_strjoin(str, ".");
	free(str);
	while (j > 0)
	{
		l = l * 10.0;
		str = ft_itoa(((int)l) % 10);
		join = ft_strjoin(end, str);
		free(end);
		end = ft_strdup(join);
		free(str);
		free(join);
		j--;
	}
	return (end);
}
