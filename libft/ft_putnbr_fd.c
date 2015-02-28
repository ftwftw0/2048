/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:24:47 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 16:16:54 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_temp(int nb, int test, int fd)
{
	int		div;
	int		mod;
	char	c;

	div = nb / 10;
	mod = nb % 10;
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_temp(nb * (-1), 1, fd);
	}
	else if (nb == 0 && test == 0)
		write(fd, "0", 1);
	else if (nb != 0)
	{
		ft_putnbr_temp(div, 1, fd);
		c = mod + 48;
		write(fd, &c, 1);
	}
}

void ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
		ft_putnbr_temp(n, 0, fd);
}
