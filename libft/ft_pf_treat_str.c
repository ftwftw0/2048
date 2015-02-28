/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 15:37:46 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:22:02 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_str(t_pf *t, va_list va)
** Modify the t->s and t->l variables for the conversion s (excluding the
** conversion with the l modifier).
** The argument (va_arg(va, char *)) is converted to string. If a precision is
** specified, no more than the number specified are written.
** For more informations : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int	cpt_new_str(t_pf *t, int l)
{
	if (t->width > l || t->zero > l)
		return (MAX(t->width, t->zero));
	else
		return (l);
}

static char	*ft_treat_precision(char *s, t_pf *t)
{
	char *temp;
	char *temp2;

	if (!s)
		temp2 = ft_strdup("(null)");
	else
		temp2 = ft_strdup(s);
	if (t->flag[4] && (int)ft_strlen(temp2) >= t->precision)
	{
		temp = ft_strndup(temp2, t->precision);
		free(temp2);
		temp2 = NULL;
		return (temp);
	}
	return (temp2);
}

static int	ft_padding_before_str(char *new, t_pf *t, int i)
{
	int j;

	j = 0;
	if (t->flag[5])
	{
		while (j < MAX(t->zero, t->width) - i)
			new[j++] = '0';
	}
	else
	{
		while (j < t->width - i)
			new[j++] = ' ';
	}
	return (j);
}

static char	*ft_treat_str(t_pf *t, char *s, int i, int j)
{
	char	*new;
	int		k;
	int		l;
	int		m;

	if (i == j)
	{
		new = ft_strdup(s);
		return (new);
	}
	m = ft_strlen(s);
	new = ft_strnew(j);
	k = (!t->flag[1]) ? ft_padding_before_str(new, t, i) : 0;
	l = 0;
	while (l < m)
		new[k++] = s[l++];
	ft_pf_padding_after(new, t, k);
	return (new);
}

void		ft_pf_treat_arg_str(t_pf *t, va_list va)
{
	char	*s;
	char	*temp;
	char	*new;
	int		i;
	int		j;

	s = va_arg(va, char *);
	new = ft_treat_precision(s, t);
	i = ft_strlen(new);
	j = cpt_new_str(t, i);
	temp = ft_treat_str(t, new, i, j);
	free(new);
	free(t->s);
	new = NULL;
	t->s = NULL;
	t->s = temp;
	t->l = ft_strlen(t->s);
}
