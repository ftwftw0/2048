/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 11:36:58 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:20:42 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_bin(t_pf *t, va_list va)
** Modify the t->s and t->l variables for the conversions b / B.
** If b is given, the argument (va_arg(va, int)) is converted to unsigned
** binary, if B is given, the conversion is long unsigned binary.
** For more informations about the precision, width or modifier : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int	cpt_new_str(t_pf *t, int l)
{
	if (t->width > l || t->precision > l || t->zero > l)
		return (ft_pf_max(t->width, t->precision, t->zero));
	else
		return (l);
}

static int	ft_padding_before_bin(char *new, t_pf *t, char *s)
{
	int		i;
	size_t	l;
	size_t	p;

	i = 0;
	l = ft_strlen(s);
	p = t->precision;
	if (!t->flag[5] && !t->flag[1])
	{
		while (i < t->width - MAX((int)l, (int)p))
			new[i++] = ' ';
	}
	if (t->flag[5] && !t->flag[1])
	{
		while (i < MAX(t->width, t->zero) - (int)l)
			new[i++] = '0';
	}
	while ((int)l < (int)p)
	{
		new[i++] = '0';
		p--;
	}
	return (i);
}

static char	*ft_treat_bin(t_pf *t, char *s)
{
	int		len;
	int		i;
	char	*new;

	len = cpt_new_str(t, ft_strlen(s));
	if (len == (int)ft_strlen(s))
		return (s);
	new = ft_strnew(len);
	len = ft_padding_before_bin(new, t, s);
	i = 0;
	while (s[i])
		new[len++] = s[i++];
	ft_pf_padding_after(new, t, len);
	free(s);
	s = NULL;
	return (new);
}

void		ft_pf_treat_arg_bin(t_pf *t, va_list va)
{
	unsigned long long	i;
	char				*s;

	i = va_arg(va, unsigned long long);
	if (t->m == NONE)
		s = ft_btoa((unsigned int)i);
	else if (t->m == HH)
		s = ft_btoa((unsigned char)i);
	else if (t->m == H)
		s = ft_btoa((unsigned short)i);
	else if (t->m == L)
		s = ft_btoa((unsigned long)i);
	else if (t->m == Z)
		s = ft_btoa((size_t)i);
	else
		s = ft_btoa(i);
	s = ft_treat_bin(t, s);
	(t->s[t->l - 1] == 'X') ? ft_capitalize(s) : 0;
	free(t->s);
	t->s = NULL;
	t->s = s;
	t->l = ft_strlen(t->s);
}
