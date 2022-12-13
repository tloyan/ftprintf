/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloyan <tloyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:17:08 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/12 23:27:36 by tloyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int	ft_printf(const char *format, ...);
int	ft_intlen_base(int n, int baselen);
int	ft_putnbr_ul_base(unsigned long n, char *base);
int	ft_putnbr(int n);

#endif