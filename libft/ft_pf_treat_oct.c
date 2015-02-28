/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 16:32:30 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:39:34 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_oct(t_pf *t, va_list va)
** Modify the t->s and t->l variables for the conversions o / O.
** If o is given, the argument (va_arg(va, int)) is converted to unsigned
** octal, if X is given, the conversion is long unsigned octal.
** For more informations : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int	cpt_new_str(t_pf *t, int l)
{
	if (t->width > l || t->precision > l || t->zero > l)
		return (ft_pf_max(t->width, t->precision, t->zero));
	return (l);
}

static int	ft_padding_before_oct(char *new, t_pf *t, char *s)
{
	int i;

	i = 0;
	if (!t->flag[5] && !t->flag[1])
	{
		while (i < t->width - MAX((int)(ft_strlen(s)), t->precision))
			new[i++] = ' ';
	}
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

static char	*ft_treat_oct(t_pf *t, char *s)
{
	int		len;
	int		i;
	char	*new;
	char	*temp;

	new = (t->flag[0] && s[0] != '0') ? ft_strjoin("0", s) : ft_strdup(s);
	free(s);
	s = NULL;
	len = cpt_new_str(t, ft_strlen(new));
	if (len == (int)ft_strlen(new))
		return (new);
	temp = ft_strnew(len);
	len = ft_padding_before_oct(temp, t, new);
	i = 0;
	while (new[i])
		temp[len++] = new[i++];
	ft_pf_padding_after(temp, t, len);
	free(new);
	new = NULL;
	return (temp);
}

void		ft_pf_treat_arg_oct(t_pf *t, va_list va)
{
	unsigned long long	i;
	char				*s;

	i = va_arg(va, unsigned long long);
	if (t->m == NONE)
		s = ft_otoa((unsigned int)i);
	else if (t->m == HH)
		s = ft_otoa((unsigned char)i);
	else if (t->m == H)
		s = ft_otoa((unsigned short)i);
	else if (t->m == L)
		s = ft_otoa((unsigned long)i);
	else if (t->m == Z)
		s = ft_otoa((size_t)i);
	else
		s = ft_otoa(i);
	s = (!t->flag[0] && t->flag[4] && t->precision == 0) ?
		ft_pf_strfnew_temp(t, ' ', s) : ft_treat_oct(t, s);
	free(t->s);
	t->s = NULL;
	t->s = s;
	t->l = ft_strlen(t->s);
}
