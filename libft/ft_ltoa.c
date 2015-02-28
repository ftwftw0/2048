/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:06:51 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/02 17:23:26 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpt_decade(long long n)
{
	long long	i;
	int			cpt;

	i = n;
	cpt = 0;
	while (i != 0)
	{
		i = i / 10;
		cpt++;
	}
	cpt = (cpt == 0) ? 1 : cpt;
	cpt = (n < 0) ? cpt + 1 : cpt;
	return (cpt);
}

char		*ft_ltoa(long long j)
{
	long long	n;
	char		*t;
	int			i;

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
			t[i] = (n > 0) ? (n % 10) + '0' : ((n % 10) * -1) + '0';
			n = n / 10;
			i--;
		}
		if (j < 0)
			t[i] = '-';
	}
	return (t);
}
