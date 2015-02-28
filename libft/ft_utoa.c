/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 17:25:46 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:27:30 by lchenut          ###   ########.fr       */
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
		i = i / 10;
		cpt++;
	}
	cpt = (cpt == 0) ? 1 : cpt;
	return (cpt);
}

char		*ft_utoa(unsigned long long j)
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
			t[i] = "0123456789"[n % 10];
			n = n / 10;
			i--;
		}
	}
	return (t);
}
