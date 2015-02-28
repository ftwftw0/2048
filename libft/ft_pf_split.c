/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:06:23 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:32:14 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** t_pf *
**		ft_pf_split.c(char *f, t_pf *pf)
** Function that parses the string f and return a t_pf *pf structure with
** the string cut that permit to make simpler the treatment of printf.
** Example:
** "Bonjour %10.3s mes% d petits %ls\n"
** become:
** t->s		: "Bonjour " "%10.3s" " mes"   "% d"    " petits " "%ls"    "\n"
** t->flag	: "000000"   "000010" "000000" "000100" "000000"   "000000" "000000"
** 		t->flag <=> "#-+ .0" respectively.
** t->l		: 8           6        4        3        8         3         1
**		t->l : ft_strlen(t->s);
** All the other variables are set to null or zero but are used later.
** ----------------------------------------------------------------------------
*/
static int	ft_cpt_char_before(char *f, char *s)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (!*f)
		return (0);
	while (f[i] && !k)
	{
		if (ft_is_in(s, f[i]))
			i++;
		else
			k = 1;
	}
	return ((!f[i]) ? i : i + 1);
}

static char	*ft_check_flag(char *str)
{
	char *s;

	s = ft_strnew(5);
	if (ft_is_in(str, '#'))
		s[0] = 1;
	if (ft_is_in(str, '-'))
		s[1] = 1;
	if (ft_is_in(str, '+'))
		s[2] = 1;
	if (ft_is_in(str, ' ') && !s[2])
		s[3] = 1;
	if (ft_is_in(str, '.'))
		s[4] = 1;
	if (ft_pf_is_zero(str) && !s[1])
		s[5] = 1;
	return (s);
}

static t_pf *ft_parse_percent_temp(char *f, int i)
{
	t_pf	*t;

	if (!(t = (t_pf *)malloc(sizeof(t_pf))))
		return (NULL);
	t->s = ft_strndup(f, i);
	t->l = ft_strlen(t->s);
	t->width = 0;
	t->precision = 0;
	t->zero = 0;
	t->swch = NULL;
	t->swstr = NULL;
	t->next = NULL;
	t->flag = ft_check_flag(t->s);
	return (t);
}

static t_pf	*ft_parse_percent(char *f, t_pf *pf, int j)
{
	int		i;
	t_pf	*t;

	if (j)
		i = ft_cpt_char_before(f + 1, FLAGS_MODIF) + 1;
	else
	{
		i = 0;
		while (f[i] != '\0' && f[i] != '%')
			i++;
	}
	t = ft_parse_percent_temp(f, i);
	ft_pf_pushback(&pf, t);
	if (!f[i])
		return (pf);
	return (ft_pf_split(f + i, pf));
}

t_pf		*ft_pf_split(char *f, t_pf *pf)
{
	if (f[0] == '%')
		return (ft_parse_percent(f, pf, 1));
	else
		return (ft_parse_percent(f, pf, 0));
	return (NULL);
}
