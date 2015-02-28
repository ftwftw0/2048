/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 13:38:38 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:32:02 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		check_digits(t_pf *t, va_list va);
** void
**		check_char(t_pf *t, va_list va);
** Check the values of the zero padding, the minimum field width and the
** optional precision of each directives, respectively for a digits conversion
** or a string / char conversion.
** The values is put in the variable t->zero, t->width, t->precision.
** ----------------------------------------------------------------------------
*/
static int	check_precision(t_pf *t, va_list va, int i, int test)
{
	if (test)
	{
		t->precision = (t->s[i + 1] == '*') ? va_arg(va, int)
			: ft_atoi((t->s) + i + 1);
		if (t->precision < 0)
		{
			t->flag[4] = 0;
			t->precision = 0;
		}
		i++;
		if (t->s[i] == '*')
			i++;
		else
		{
			while (ft_isdigit(t->s[i]))
				i++;
		}
	}
	else
	{
		t->precision = 0;
		i++;
	}
	return (i);
}

static void	check_temp(t_pf *t, va_list va, int *i)
{
	i[1] = (t->s[i[0]] == '*') ? va_arg(va, int) : ft_atoi((t->s) + i[0]);
	if (i[1] < 0)
	{
		i[1] = i[1] * -1;
		t->flag[1] = 1;
	}
	if (t->s[i[0]] == '*')
		i[0]++;
	else
	{
		while (ft_isdigit(t->s[i[0]]))
			i[0]++;
	}
}

static int	check(t_pf *t, va_list va)
{
	int i[2];

	i[0] = 1;
	i[1] = 0;
	while (t->s[i[0]])
	{
		if (t->s[i[0]] == '.' && t->s[i[0] + 1] != '-')
		{
			t->flag[4] = 1;
			i[0] = check_precision(t, va, i[0], 1);
		}
		else if (t->s[i[0]] == '.')
		{
			t->flag[4] = 1;
			i[0] = check_precision(t, va, i[0], 0);
		}
		else if ((ft_isdigit(t->s[i[0]]) || t->s[i[0]] == '*')
				&& t->s[i[0]] != '0')
			check_temp(t, va, i);
		else
			i[0]++;
	}
	return (i[1]);
}

void		ft_pf_check_digits(t_pf *t, va_list va)
{
	int temp;

	temp = check(t, va);
	if (t->flag[4] || t->flag[1] || !t->flag[5])
	{
		t->flag[5] = 0;
		t->width = temp;
	}
	else if (ft_pf_is_zero(t->s))
		t->zero = temp;
}

void		ft_pf_check_char(t_pf *t, va_list va)
{
	int temp;

	temp = check(t, va);
	if (t->flag[1] || !t->flag[5])
	{
		t->flag[5] = 0;
		t->width = temp;
	}
	else if (ft_pf_is_zero(t->s))
		t->zero = temp;
}
