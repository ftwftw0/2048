/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:32:51 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/03 16:21:14 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_qs_swap(int *tab, int i, int j)
{
	int tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void		ft_quick_sort(int *tab, int start, int end)
{
	int left;
	int right;
	int i;

	i = tab[start];
	left = start;
	right = end;
	if (start >= end)
		return ;
	while (1)
	{
		while (tab[right] > i)
			right--;
		while (tab[left] < i)
			left++;
		if (left < right)
			ft_qs_swap(tab, left, right);
		else
			break ;
	}
	ft_quick_sort(tab, start, right);
	ft_quick_sort(tab, right + 1, end);
}
