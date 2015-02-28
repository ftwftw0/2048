/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 12:14:38 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 11:59:58 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fill_whitespace(const char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static int	treat_too_long(long long res, const char *str, int i)
{
	if (res > 922337203685477580 && ft_isdigit(str[i + 1]))
		return (1);
	if (res == 922337203685477580)
	{
		if (str[i + 1])
		{
			if (str[i + 2])
			{
				if (ft_isdigit(str[i + 1]) && ft_isdigit(str[i + 2]))
					return (1);
			}
			if (ft_isdigit(str[i + 1]) && str[i + 1] - '0' > 7)
				return (1);
		}
	}
	return (0);
}

long long	ft_atol(const char *str)
{
	long long int	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = fill_whitespace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (sign * res);
		res = res * 10 + str[i] - '0';
		if (res >= 922337203685477580)
		{
			if (treat_too_long(res, str, i))
				return ((sign == 1) ? -1 : 0);
		}
		i++;
	}
	return (sign * res);
}
