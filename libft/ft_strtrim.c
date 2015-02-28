/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:15:57 by lchenut           #+#    #+#             */
/*   Updated: 2014/12/01 12:21:48 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp_whitespace(const char *s, size_t len, int i)
{
	size_t j;

	j = 0;
	if (i == 0)
	{
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			j++;
		return (j);
	}
	if (i == 1)
	{
		while ((s[len - j - 1] == ' ' || s[len - j - 1] == '\t'
					|| s[len - j - 1] == '\n') && j <= len)
			j++;
		return (j);
	}
	return (0);
}

static char	*ft_trim(const char *s, int wsb, int wse, int len)
{
	char	*ret;
	int		i;

	if (!(ret = (char *)malloc(sizeof(char) * (len - wse - wsb))))
		return (NULL);
	i = 0;
	while (i + wsb < len - wse)
	{
		ret[i] = s[i + wsb];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*ft_strtrim(const char *s)
{
	int		white_spaces_beg;
	int		white_spaces_end;
	size_t	len;
	char	*ret;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	white_spaces_beg = ft_cmp_whitespace(s, len, 0);
	white_spaces_end = ft_cmp_whitespace(s, len, 1);
	if ((int)len == white_spaces_end)
	{
		if (!(ret = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	else if (white_spaces_end + white_spaces_beg == 0)
		return (ft_strdup(s));
	ret = ft_trim(s, white_spaces_beg, white_spaces_end, len);
	return (ret);
}
