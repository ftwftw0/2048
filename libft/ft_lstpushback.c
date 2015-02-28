/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:48:12 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 16:16:30 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **atls, t_list *new)
{
	t_list *t;

	if (new)
	{
		if (!(*atls))
			(*atls) = new;
		else
		{
			t = *atls;
			while (t->next)
				t = t->next;
			t->next = new;
		}
	}
}
