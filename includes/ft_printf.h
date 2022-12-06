/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:17:08 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/06 20:15:11 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_options {
	va_list				*arg;
	int					flag_minus;
	int					flag_plus;
	int					flag_space;
	int					flag_sharp;
	int					flag_zero;

	int					width;
	int					precision_width;
	int					(*func)(va_list);
}	t_options;

int			ft_printf(const char *format, ...);
t_options	*extract_data(const char *format, va_list *args);

#endif