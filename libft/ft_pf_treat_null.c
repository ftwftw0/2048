/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 16:15:15 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:17:38 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** int
**		ft_is_null(t_pf *f)
** Check if one of the conversion performed are false. Return 0 if there is no
** errors, else, return 1.
** ----------------------------------------------------------------------------
** void
**		ft_treat_null(t_pf *f)
** If an error is found in one of the conversion performed, the function treats
** it.
** ----------------------------------------------------------------------------
*/
int		ft_pf_is_null(t_pf *f)
{
	t_pf	*t;

	t = f;
	while (t)
	{
		if (t->l == -1)
			return (1);
		t = t->next;
	}
	return (0);
}

void	ft_pf_treat_null(t_pf *f)
{
	t_pf *t;
	t_pf *t2;
	t_pf *t3;

	t = f;
	while (t)
	{
		t2 = t;
		while (t2->width == 0 && t2)
			t2 = t2->next;
		if (t2->l == -1)
		{
			t3 = t;
			while (t3)
			{
				t3->precision = -1;
				t3 = t3->next;
			}
			break ;
		}
		t = t->next;
	}
}
