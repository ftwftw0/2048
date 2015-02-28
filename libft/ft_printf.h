/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:24:11 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/12 17:43:25 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define FLAGS_MODIF ".0123456789hljz#-+ *"
# define CONV "sSpdDioOuUxXcC"
# define DIGITS "dDioOuUxXbB"

# define ABS(a) ((a) < 0) ? -(a) : a
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef enum		e_modif
{
	NONE,
	HH,
	H,
	L,
	LL,
	J,
	Z
}					t_modif;

typedef struct		s_pf
{
	char			*s;
	char			*flag;
	int				l;
	int				width;
	int				precision;
	int				zero;
	t_modif			m;
	struct s_wchar	*swch;
	struct s_wstr	*swstr;
	struct s_pf		*next;
}					t_pf;

typedef struct		s_wchar
{
	int				*tabwc;
	char			*befwc;
	char			*aftwc;
}					t_wchar;

typedef struct		s_wstr
{
	int				len;
	char			*befwc;
	char			*aftwc;
	int				*tabwc;
	struct s_wstr	*next;
}					t_wstr;

int					ft_printf(const char *format, ...);
t_pf				*ft_pf_split(char *f, t_pf *pf);

void				ft_pf_check_digits(t_pf *t, va_list va);
void				ft_pf_check_char(t_pf *t, va_list va);
t_modif				ft_pf_check_modifier(t_pf *t);
int					ft_pf_is_lh(char *s, char c);

int					ft_pf_prt_all(t_pf *f);
void				ft_pf_close_all(t_pf *f);
void				ft_pf_clean_tab(t_wstr *f);

void				ft_pf_treat_arg_int(t_pf *t, va_list va);
void				ft_pf_treat_arg_oct(t_pf *t, va_list va);
void				ft_pf_treat_arg_hex(t_pf *t, va_list va);
char				*ft_pf_treat_hex(t_pf *t, char *s);
void				ft_pf_treat_arg_uns(t_pf *t, va_list va);
void				ft_pf_treat_arg_bin(t_pf *t, va_list va);
void				ft_pf_treat_arg_str(t_pf *t, va_list va);
void				ft_pf_treat_arg_char(t_pf *t, va_list va);
void				ft_pf_treat_arg_wstr(t_pf *t, va_list va);
void				ft_pf_treat_arg_wchar(t_pf *t, va_list va);
int					*ft_pf_treat_wchar(int i, int cnt);
void				ft_pf_treat_arg_strange(t_pf *f, t_pf *t, va_list va);
void				ft_pf_treat_arg_other(t_pf *t, va_list va);

int					ft_pf_is_null(t_pf *f);
void				ft_pf_treat_null(t_pf *f);

int					ft_pf_max(int i, int j, int k);
void				ft_pf_padding_after(char *new, t_pf *t, int i);
char				*ft_pf_padding_wchar(t_pf *t, int l, int i);
void				ft_pf_pushback(t_pf **pf, t_pf *new);
int					ft_pf_is_zero(char *s);
char				*ft_pf_after_effect(t_pf *t, char *s);
int					*ft_pf_tabdup(int *tab);
t_wchar				*ft_pf_init_wchar(int *tab, int len, t_pf *t);
void				ft_pf_treat_wstr(t_pf *t, t_wstr *f, int i);
t_wstr				*ft_pf_init_wstr(t_wstr *f, int *tab);
wchar_t				*ft_pf_init_wnull(void);
void				ft_pf_treat_wstr_null(t_pf *t);
char				*ft_pf_strfnew_temp(t_pf *t, char c, char *str);

#endif
