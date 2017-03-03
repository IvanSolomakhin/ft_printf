/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:52:40 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 17:44:07 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"
# include "stdarg.h"

typedef struct	s_flags
{
	int			dot;
	size_t		width;
	size_t		precision;
	int			sign;
	int			left_justify;
	int			plus;
	int			space;
	int			hash;
	int			left_pads;
}				t_flags;

typedef struct	s_len
{
	size_t hh;
	size_t h;
	size_t l;
	size_t ll;
	size_t j;
	size_t z;
}				t_len;

typedef struct	s_data
{
	const char	*form;
	char		*spec;
	size_t		count;
	size_t		index;
	int			percent;
	t_flags		flags;
	t_len		length;
}				t_data;

int				ft_printf(const char *format, ...);
void			read_data(t_data *data, va_list args);
void			create_data(const char *format, t_data *data);
void			create_all(t_data *data);
int				hesh_flag(t_flags *flags, t_data *data);
int				left_justify_flag(t_flags *flags, t_data *data);
int				plus_flag(t_flags *flags, t_data *data);
int				space_flag(t_flags *flags, t_data *data);
int				left_pads(t_flags *flags, t_data *data);
int				flag_check(t_data *data, char c, t_flags *flags);
int				nbr_check(t_data *data);
int				length_check(t_data *data, size_t i);
int				form_check(char c, t_data *data, va_list args);
int				precision_check(t_data *data, size_t i);
int				width_check(t_data *data);
char			*check_null(intmax_t i, t_flags *flags, int base);
char			*check_null_unsigned(uintmax_t i, t_flags *flags, int base);
int				len_hh(t_len *length, t_data *data);
int				len_h(t_len *length, t_data *data);
int				len_ll(t_len *length, t_data *data);
int				len_l(t_len *length, t_data *data);
int				len_jz(char c, t_data *data);
char			*add_precision_str(char *str, t_flags *flags, t_data *data);
char			*add_precision_int(char *str, t_flags *flags);
char			*add_left_justify(char *str, t_flags *flags);
char			*add_width(char *str, t_flags *flags, char c, int zero);
char			*add_hash(char *str, t_flags *flags, char form);
char			*add_sign(char *str, t_data *data, t_flags *flags);
char			*add_space(char *str, t_flags *flags, char c);
char			*ft_manage_wint(wint_t wint);
char			*ft_putwstr(wchar_t *s);
void			manage_str(t_data *data, va_list args);
void			manage_nbr(t_data *data, va_list args);
void			manage_ptr(t_data *data, va_list args);
char			*manage_width(char *str, t_data *data, char c, int zero);
void			manage_d_i(intmax_t i, t_data *data, int length, va_list args);
void			manage_o(intmax_t i, t_data *data, int length, va_list args);
void			manage_x(intmax_t i, t_data *data, int length, va_list args);
void			manage_u(intmax_t i, t_data *data, int length, va_list args);
char			*process_char(char *str, t_data *data, char c);
char			*process_int(char *str, t_data *data, char c);
intmax_t		get_arg_signed(int length, va_list args);
uintmax_t		get_arg_unsigned(int length, va_list args);
int				get_length(t_len *len);
intmax_t		get_sign(intmax_t i, t_flags *flags);
char			*put_width_str(char *ptr, t_flags *flags, int zero);
char			*ft_itoa_base(uintmax_t nb, int base);
int				main();

#endif
