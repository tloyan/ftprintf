/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:17:08 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/14 15:26:08 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_options {
	int					flag_minus;
	int					flag_plus;
	int					flag_space;
	int					flag_sharp;
	int					flag_zero;

	int					precision;

	int					width;
	int					precision_width;
	char				specifier;
}	t_options;

int				ft_printf(const char *format, ...);
int				extract_data(const char *format, va_list *args, int *index);
int				print_data(va_list *args, t_options options);

void			get_options(const char *format, t_options *options, int *index);
void			init_options(t_options **options);
void			get_flag(char c, t_options *options);
int				get_precision(const char *format, int *index);
int				get_width(const char *format, int *index);

int				is_signed(int nbr, t_options *options);
int				is_specifier(char c);
int				is_flag(char c);

int				print_char(char c, t_options *options);

int				print_hex(unsigned int nbr, t_options *options);

int				print_int(int nbr, t_options *options);
int				print_unsigned_int(unsigned int nbr, t_options *options);

int				print_str(char *str, t_options *options);

int				ft_nbrlen_base(long int nb, int baselen);
int				ft_putnbr_ul_base(unsigned long n, char *base);
long long int	ft_abs(long long int nb);
int				ft_nbrlen(long long int nb);
int				ft_putnbr_ul(unsigned long n);










int	print_hex(unsigned int nbr, t_options *options);

// int	ft_intlen_base(int n, int baselen);
int	ft_putnbr_ul_base(unsigned long n, char *base);
int	ft_putnbr(unsigned long n);
void	display_options(t_options *options);
int	ft_nbrlen(long long int nb);
int	ft_nbrlen_base(long int nb, int baselen);

#endif