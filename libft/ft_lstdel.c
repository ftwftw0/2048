/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:30:38 by lchenut           #+#    #+#             */
/*   Updated: 2014/12/03 10:26:51 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		if (*alst && del)
		{
			ft_lstdel(&((*alst)->next), (*del));
			ft_lstdelone(alst, (*del));
		}
	}
}
