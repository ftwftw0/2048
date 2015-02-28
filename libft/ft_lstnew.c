/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:02:49 by lchenut           #+#    #+#             */
/*   Updated: 2014/11/30 14:56:19 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(const void *content, size_t content_size)
{
	t_list	*dst;
	void	*temp;

	temp = (void *)ft_memalloc(content_size + 1);
	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		dst->content = NULL;
		dst->content_size = 0;
	}
	else
	{
		dst->content = ft_memcpy(temp, content, content_size);
		dst->content_size = content_size;
	}
	dst->next = NULL;
	return (dst);
}
