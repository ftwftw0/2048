/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:59:46 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 13:18:21 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** ...
** Garbage Functions T1
** ----------------------------------------------------------------------------
*/
void	ft_pf_pushback(t_pf **pf, t_pf *new)
{
	t_pf *t;

	if (new)
	{
		if (!(*pf))
			(*pf) = new;
		else
		{
			t = *pf;
			while (t->next)
				t = t->next;
			t->next = new;
		}
	}
}

int		ft_pf_is_zero(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0' && !ft_isdigit(s[i - 1]) && s[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		ft_pf_max(int i, int j, int k)
{
	if (i >= j && i >= k)
		return (i);
	if (j >= i && j >= k)
		return (j);
	return (k);
}

void	ft_pf_padding_after(char *new, t_pf *t, int i)
{
	if (t->s[1])
	{
		while (i < t->width)
			new[i++] = ' ';
	}
}

int		*ft_pf_tabdup(int *tab)
{
	int *t;
	int i;

	if (!(t = (int *)malloc(sizeof(int) * (tab[1] + 2))))
		return (NULL);
	i = 0;
	while (i < tab[1] + 2)
	{
		t[i] = tab[i];
		i++;
	}
	return (t);
}
