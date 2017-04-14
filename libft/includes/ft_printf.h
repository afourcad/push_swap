/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:32:43 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/29 17:34:51 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

# define ERROR 0
# define GOOD 1
# define NO 0

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

# define F_BLACK "\033[40m"
# define F_RED "\033[41m"
# define F_GREEN "\033[42m"
# define F_YELLOW "\033[43m"
# define F_BLUE "\033[44m"
# define F_MAGENTA "\033[45m"
# define F_CYAN "\033[46m"
# define F_WHITE "\033[47m"

# define EOC "\033[0m"

typedef enum	e_specifier
{
	NOP,
	WRONG,
	YES,
	S_NULL,
	PERCENT
}				t_specifier;

typedef union	u_type
{
	intmax_t	my_int;
	uintmax_t	my_uint;
	char		*my_ptrchar;
	int			my_char;
	wint_t		my_wint_t;
	wchar_t		*my_wchar_t;
}				t_type;

typedef enum	e_length
{
	NONE,
	H,
	HH,
	L,
	LL,
	J,
	Z
}				t_length;

typedef	enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_arg
{
	t_bool			param_good;
	t_bool			sharp;
	t_bool			null;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
	t_bool			is_width;
	int				width;
	t_bool			is_pre;
	int				precision;
	int				ln_block;
	int				nbr_utf8_char;
	t_length		len;
	t_bool			is_spec;
	t_specifier		spec;
	char			specifier;
	struct s_arg	*next;
	t_type			type;
}				t_arg;

int				ft_printf(const char *format, ...);

int				ft_check_flags(char **str, t_arg *param);
int				ft_check_width(char **str, t_arg *param);
int				ft_check_precision(char **str, t_arg *param);
int				ft_check_length(char **str, t_arg *param);

int				ft_convert_size(va_list *ap, t_arg *param, int ln_tmp);
int				ft_find_specifier(char **str, t_arg *param);
int				ft_signed_decimal(va_list *ap, intmax_t *my_int, t_length len,
		int base);
int				ft_unsigned_decimal(va_list *ap, uintmax_t *my_uint,
		t_length len, int base);
int				ft_ln_flags(char specifier, t_arg *param);
int				ft_w_arg(va_list *ap, t_arg *param, int ln_tmp);

int				ft_write_on_buff(const char *format, char *buff, t_arg *param);
char			*ft_write_dec_with_flags(char *buff, t_arg *param, char *nbr,
		int neg);
char			*ft_decimal(char *buff, t_arg *param);
char			*ft_convert_decimal(char *buff, t_arg *param);
char			*ft_write_dec_plus(char *buff, int is_neg);
char			*ft_write_dec_space(char *buff);
char			*ft_width_and_pre(char *buff, t_arg *param, char *nbr, int neg);
char			*ft_only_width(char *buff, t_arg *param, char *nbr, int neg);
char			*ft_only_pre(char *buff, t_arg *param, char *nbr, int neg);
char			*ft_no_pre_no_width(char *buff, t_arg *param, char *nbr,
		int neg);
char			*ft_string(char *buff, t_arg *param);
char			*ft_write_str_with_flags(char *buff, t_arg *param, int ln_str);
char			*ft_write_char_with_flags(char *buff, t_arg *param);

char			*ft_utf8(wint_t nb, char *buff);
char			*ft_unicode(char *buff, t_arg *param);
char			*ft_write_unicode_with_flags(char *buff, t_arg *param);
void			ft_free_printf(char *buff, t_arg *param);
void			ft_free_param(t_arg *param);
void			ft_set_param(t_arg *param);

#endif
