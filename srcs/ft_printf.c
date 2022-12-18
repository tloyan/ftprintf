/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:18:34 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/18 12:06:29 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_data(va_list *args, t_options options)
{
	if (options.specifier == '%')
		return (write(1, "%%", 1));
	else if (options.specifier == 'c')
		return (print_char(va_arg(*args, int), &options));
	else if (options.specifier == 's')
		return (print_str(va_arg(*args, char *), &options));
	else if (options.specifier == 'p')
		return (print_ptr(va_arg(*args, unsigned long), &options));
	else if (options.specifier == 'd' || options.specifier == 'i')
		return (print_int(va_arg(*args, int), &options));
	else if (options.specifier == 'u')
		return (print_unsigned_int(va_arg(*args, unsigned int), &options));
	else if (options.specifier == 'x' || options.specifier == 'X')
		return (print_hex(va_arg(*args, unsigned int), &options));
	return (0);
}

int	extract_data(const char *format, va_list *args, int *index)
{
	t_options	options;

	(*index) = (*index) + 1;
	get_options(format, &options, &*index);
	return (print_data(&*args, options));
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			size;

	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		if (format[i] != '%')
			size = size + write(1, &format[i], 1);
		if (format[i] == '%')
			size = size + extract_data(format, &args, &i);
		i = i + 1;
	}
	va_end(args);
	return (size);
}
