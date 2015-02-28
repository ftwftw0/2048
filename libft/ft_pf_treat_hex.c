/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 16:40:57 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:39:05 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_hex(t_pf *t, va_list va)
** Modify the t->s and t->l variables for the conversions x / X.
** If x or X are given, the argument (va_arg(va, int)) is converted to unsigned
** hexadecimal, if X is given, the letters are capitalize.
** For more informations : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int	cpt_new_str(t_pf *t, int l)
{
	if ((t->width > l || t->precision > l || t->zero > l) && !t->flag[0])
		return (ft_pf_max(t->width, t->precision, t->zero));
	else if (!t->flag[0])
		return (l);
	else
	{
		if (t->width > l + 2 || t->precision > l || t->zero > l + 2)
			return (ft_pf_max(t->width, t->precision + 2, t->zero));
		return (l + 2);
	}
}

static int	ft_padding_before_hex_temp(char *new, t_pf *t, char *s, int i)
{
	if (t->flag[0] && s[0] != '0')
	{
		new[i++] = '0';
		new[i++] = 'x';
	}
	return (i);
}

static int	ft_padding_before_hex(char *new, t_pf *t, char *s)
{
	int		i;
	size_t	l;
	size_t	p;

	i = 0;
	l = (t->flag[0] && s[0] != '0') ? ft_strlen(s) + 2 : ft_strlen(s);
	p = (t->flag[0] && s[0] != '0') ? t->precision + 2 : t->precision;
	if (!t->flag[5] && !t->flag[1])
	{
		while (i < t->width - MAX((int)l, (int)p))
			new[i++] = ' ';
	}
	i = ft_padding_before_hex_temp(new, t, s, i);
	if (t->flag[5] && !t->flag[1])
	{
		while (i < MAX(t->width, t->zero) - (int)ft_strlen(s))
			new[i++] = '0';
	}
	while ((int)ft_strlen(s) < t->precision)
	{
		new[i++] = '0';
		t->precision--;
	}
	return (i);
}

char		*ft_pf_treat_hex(t_pf *t, char *s)
{
	int		len;
	int		i;
	char	*new;

	len = cpt_new_str(t, ft_strlen(s));
	if (len == (int)ft_strlen(s))
		return (s);
	new = ft_strnew(len);
	len = ft_padding_before_hex(new, t, s);
	i = 0;
	while (s[i])
		new[len++] = s[i++];
	ft_pf_padding_after(new, t, len);
	free(s);
	s = NULL;
	return (new);
}

void		ft_pf_treat_arg_hex(t_pf *t, va_list va)
{
	unsigned long long	i;
	char				*s;

	i = va_arg(va, unsigned long long);
	if (t->m == NONE)
		s = ft_htoa((unsigned int)i);
	else if (t->m == HH)
		s = ft_htoa((unsigned char)i);
	else if (t->m == H)
		s = ft_htoa((unsigned short)i);
	else if (t->m == L)
		s = ft_htoa((unsigned long)i);
	else if (t->m == Z)
		s = ft_htoa((size_t)i);
	else
		s = ft_htoa(i);
	s = (t->flag[4] && i == 0 && t->precision == 0) ?
		ft_pf_strfnew_temp(t, ' ', s) : ft_pf_treat_hex(t, s);
	(t->s[t->l - 1] == 'X') ? ft_capitalize(s) : 0;
	free(t->s);
	t->s = NULL;
	t->s = s;
	t->l = ft_strlen(t->s);
}
