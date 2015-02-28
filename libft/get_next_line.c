/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:48:58 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/04 11:21:52 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Function get_next_line
** Synopsis:
** int get_net_line(int fd, char **line)
** Description :
** The get_next_line function attemps to read the object referenced by the
** descriptor fd until the first '\n' character or the end-of-file into
** the buffer pointed by line.
** Return values:
** If successful, 1 is returned. Upon reading end-of-file, 0 is returned. If
** an error ocurred, -1 is returned.
*/

static t_gnl	*ft_read_file(int fd, int j)
{
	char	*str;
	t_gnl	*gnl;
	int		size;

	if (!(gnl = (t_gnl *)malloc(sizeof(t_gnl) * 1)))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * j)))
	{
		free (gnl);
		return (NULL);
	}
	if ((size = read(fd, str, j)) < 0)
	{
		free (gnl);
		free (str);
		return (NULL);
	}
	gnl->size = size;
	gnl->index = 0;
	gnl->str = str;
	gnl->next = NULL;
	return (gnl);
}

static int		ft_cptendline(t_gnl *temp, int fd, int j)
{
	int		cpt;
	int		i;
	t_gnl	*temp2;

	cpt = 0;
	i = temp->index;
	while ((temp->str)[i] != '\n' && i < (temp->size))
	{
		i++;
		cpt++;
		if (i == (temp->size) && (temp->size) == j)
		{
			if (!(temp2 = ft_read_file(fd, j)))
				return (-1);
			temp->next = temp2;
			temp = temp->next;
			i = 0;
		}
	}
	return (cpt);
}

static t_gnl	*ft_rewrite(t_gnl **gnl, int *index)
{
	t_gnl	*temp;

	temp = (*gnl)->next;
	free((*gnl)->str);
	free(*gnl);
	(*gnl) = temp;
	*index = 0;
	return (*gnl);
}

static int		ft_rwgnl(t_gnl **gnl, char **line, int cpt, int j)
{
	int i;
	int index;

	i = 0;
	index = (*gnl)->index;
	if (cpt == -1 || !((*line) = (char *)malloc(sizeof(char) * (cpt + 1))))
		return (-1);
	while (i < cpt)
	{
		(*line)[i] = (*gnl)->str[index];
		i++;
		index++;
		if (index == (*gnl)->size)
			(*gnl) = ft_rewrite(gnl, &index);
	}
	(*line)[i] = '\0';
	if (!(*gnl) || (i == (*gnl)->size && (*gnl)->size != j) ||
			!(*gnl)->str[index])
		return (0);
	(*gnl)->index = index + 1;
	if ((*gnl)->index == (*gnl)->size)
		*gnl = ft_rewrite(gnl, &index);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*temp;
	int				cpt;
	int				j;
	int				k;

	if (line)
	{
		j = (BUFF_SIZE > 4096) ? 4096 : BUFF_SIZE;
		if (fd < 0)
			return (-1);
		if (!gnl)
		{
			if (!(gnl = ft_read_file(fd, j)))
				return (-1);
		}
		temp = gnl;
		cpt = ft_cptendline(temp, fd, j);
		if ((k = ft_rwgnl(&gnl, line, cpt, j)) == 0)
			gnl = NULL;
		return (k);
	}
	return (-1);
}
