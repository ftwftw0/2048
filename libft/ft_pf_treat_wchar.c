/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 12:24:40 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:43:39 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_wchar(t_pf *t, va_list va)
** Modify the t->s (or set t->swchar) and t->l variables for the conversion C
** or c conversion with the l modifier.
** The argument (va_arg(va, wint_t)) is converted so it can be write
** safely.
** For more informations : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int	cpt_new_str(t_pf *t, int i)
{
	if (t->width > i || t->zero > i)
		return (MAX(t->width, t->zero));
	else
		return (i);
}

int			*ft_pf_treat_wchar(int i, int cnt)
{
	int		*tab;
	int		k;
	int		l;

	if (!(tab = (int *)malloc(sizeof(int) * (cnt + 2))))
		return (NULL);
	tab[0] = i;
	tab[1] = cnt;
	k = cnt + 1;
	l = 0;
	while (k > 2)
	{
		tab[k--] = ((i >> l) | 128) & 191;
		l += 6;
	}
	if (cnt == 1)
		tab[2] = i & 255;
	else if (cnt == 2)
		tab[2] = ((i >> l) | 192);
	else if (cnt == 3)
		tab[2] = ((i >> l) | 224);
	else if (cnt == 4)
		tab[2] = ((i >> l) | 240);
	return (tab);
}

char		*ft_pf_padding_wchar(t_pf *t, int i, int test)
{
	int		j;
	char	*str;

	j = 0;
	if (t->flag[5] && test)
	{
		if (!(str = (char *)malloc(sizeof(char) *
						(MAX(t->zero, t->width) - i))))
			return (NULL);
		while (j < MAX(t->zero, t->width) - i)
			str[j++] = '0';
		str[j] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (t->width - i))))
		return (NULL);
	while (j < MAX(t->zero, t->width) - i)
		str[j++] = ' ';
	str[j] = '\0';
	return (str);
}

static void	ft_treat_arg_wchar_temp(t_pf *t, int *tab)
{
	int		len;
	t_wchar	*wc;

	if (!tab)
	{
		free(t->s);
		t->s = ft_strnew(0);
		t->l = -1;
	}
	else
	{
		len = cpt_new_str(t, tab[1]);
		wc = ft_pf_init_wchar(tab, len, t);
		free(t->s);
		t->s = NULL;
		t->l = len;
		t->swch = wc;
	}
}

void		ft_pf_treat_arg_wchar(t_pf *t, va_list va)
{
	wint_t	i;
	int		*tab;

	i = va_arg(va, wint_t);
	tab = NULL;
	if (i <= 0X7F)
		tab = ft_pf_treat_wchar((int)i, 1);
	else if (i <= 0X7FF)
		tab = ft_pf_treat_wchar((int)i, 2);
	else if (i <= 0XFFFF)
		tab = ft_pf_treat_wchar((int)i, 3);
	else if (i <= 0X10FFFF)
		tab = ft_pf_treat_wchar((int)i, 4);
	ft_treat_arg_wchar_temp(t, tab);
}
