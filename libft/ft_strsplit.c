/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:24:45 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:15:06 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpt_tab(const char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 1;
	while (s[j])
	{
		if (s[j] != c && k)
		{
			k = 0;
			i++;
		}
		else if (s[j] == c && !k)
			k = 1;
		j++;
	}
	return (i);
}

static int	cpt_word(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s)
		return (NULL);
	i = cpt_tab(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	str[i] = NULL;
	j = 0;
	k = 0;
	while (k < i)
	{
		while (s[j] == c)
			j++;
		str[k] = ft_strndup((char *)(s + j), cpt_word(s + j, c));
		j = j + cpt_word(s + j, c);
		k++;
	}
	return (str);
}
