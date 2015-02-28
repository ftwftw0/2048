/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:30:50 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/04 11:22:02 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

# define BUFF_SIZE 4096

int					get_next_line(int fd, char **line);

typedef struct		s_gnl
{
	int				size;
	int				index;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

#endif
