/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:24:16 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:25:11 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **str)
{
	char	**new;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
