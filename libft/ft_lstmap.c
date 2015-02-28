/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:51:31 by lchenut           #+#    #+#             */
/*   Updated: 2014/11/07 15:22:30 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*parcours;
	t_list	*begin;
	t_list	*parcours_rep;

	if (!lst || !f)
		return (NULL);
	parcours = lst;
	temp = ft_lstnew(parcours->content, parcours->content_size);
	begin = (*f)(temp);
	free(temp);
	parcours_rep = begin;
	parcours = parcours->next;
	while (parcours != NULL)
	{
		temp = ft_lstnew(parcours->content, parcours->content_size);
		parcours_rep->next = (*f)(temp);
		free(temp);
		parcours = parcours->next;
		parcours_rep = parcours_rep->next;
	}
	return (begin);
}
