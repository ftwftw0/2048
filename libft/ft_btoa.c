/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 11:40:14 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/02 17:24:14 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpt_decade(unsigned long long n)
{
	unsigned long long	i;
	int					cpt;

	i = n;
	cpt = 0;
	while (i != 0)
	{
		i = i / 2;
		cpt++;
	}
	cpt = (cpt == 0) ? 1 : cpt;
	return (cpt);
}

char		*ft_btoa(unsigned long long j)
{
	unsigned long long	n;
	char				*t;
	int					i;

	n = j;
	i = cpt_decade(j);
	t = ft_strnew(i);
	i--;
	if (n == 0 && t)
		t[0] = '0';
	else if (t)
	{
		while (n != 0)
		{
			t[i] = (n % 2) + '0';
			n = n / 2;
			i--;
		}
	}
	return (t);
}
