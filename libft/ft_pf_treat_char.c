/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 12:18:07 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 13:47:45 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_char(t_pf *t, va_list va)
** Modify the t->s and t->l variables for the conversion c (excluding the
** conversion with the l modifier).
** The argument (va_arg(va, char)) is converted to unsigned character.
** For more informations : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int	ft_padding_after_char(char *new, t_pf *t, int i)
{
	if (t->flag[1])
	{
		while (i < t->width)
			new[i++] = ' ';
	}
	return (i);
}

static int	cpt_new_str(t_pf *t)
{
	if (t->width > 1 || t->zero > 1)
		return (MAX(t->width, t->zero));
	else
		return (1);
}

static int	ft_padding_before_char(char *new, t_pf *t, int i)
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

void		ft_pf_treat_arg_char(t_pf *t, va_list va)
{
	int		c;
	char	*new;
	int		len;

	c = va_arg(va, int);
	c = (unsigned char)c;
	len = cpt_new_str(t);
	new = ft_strnew(len);
	if (len == 1)
		new[0] = c;
	else
	{
		len = (!t->flag[1]) ? ft_padding_before_char(new, t, 1) : 0;
		new[len++] = c;
		len = ft_padding_after_char(new, t, len);
	}
	free(t->s);
	t->s = new;
	t->l = len;
}
