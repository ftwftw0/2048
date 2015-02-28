/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:05:54 by lchenut           #+#    #+#             */
/*   Updated: 2014/12/03 11:25:27 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_temp(int nb, int test)
{
	int		div;
	int		mod;
	char	c;

	div = nb / 10;
	mod = nb % 10;
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_temp(nb * (-1), 1);
	}
	else if (nb == 0 && test == 0)
		write(1, "0", 1);
	else if (nb != 0)
	{
		ft_putnbr_temp(div, 1);
		c = mod + 48;
		write(1, &c, 1);
	}
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
		ft_putnbr_temp(n, 0);
}
