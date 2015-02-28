/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_effect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 15:02:03 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/19 15:52:16 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** char *
**		after_effect(t_pf *t, char *s)
** Garbage function... It treats the printf("%p", (void *) 0) case, that is
** awful.
** ----------------------------------------------------------------------------
*/
static int	cpt_char(char *s, char c)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] == c)
			cpt++;
		i++;
	}
	return (cpt);
}

static int	fd_index(char *s)
{
	int i;

	i = 0;
	while (s[i] != '0' && s[i])
		i++;
	return (i);
}

static void	after_effect_temp_next(char *s, int i, int j, int index)
{
	if (i == 0)
	{
		s[1] = 'x';
		s[j] = '0';
		s[j + 1] = '0';
	}
	else if (i == 2)
	{
		s[index - 1] = 'x';
		s[index - 2] = '0';
	}
	else if (i == 3)
		s[index + 1] = 'x';
	else
	{
		s[1] = 'x';
		s[2] = '0';
	}
}

static char	*after_effect_temp(t_pf *t, char *s, int i, int j)
{
	char *str;

	if (i == j)
	{
		str = ft_strjoin("0x", s);
		free(s);
	}
	else
	{
		s[0] = 'x';
		if (t->flag[1])
			s[i - 1] = '0';
		str = ft_strjoin("0", s);
		free(s);
	}
	return (str);
}

char		*ft_pf_after_effect(t_pf *t, char *s)
{
	int		index;
	int		i;
	int		j;

	index = fd_index(s);
	i = ft_strlen(s);
	j = cpt_char(s, '0');
	if ((i == j || i == j + 1) && !t->flag[5])
		return (after_effect_temp(t, s, i, j));
	else if (t->flag[4])
		(t->flag[1]) ? after_effect_temp_next(s, 1, j, index)
								: after_effect_temp_next(s, 2, j, index);
	else if (t->flag[5])
	{
		if (i < 2)
			return (after_effect_temp(t, s, i, j));
		after_effect_temp_next(s, 3, j, index);
	}
	else
		(t->flag[1]) ? after_effect_temp_next(s, 4, j, index)
								: after_effect_temp_next(s, 2, j, index);
	return (s);
}
