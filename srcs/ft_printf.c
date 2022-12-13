/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloyan <tloyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:18:34 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/13 00:26:09 by tloyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	get_width(const char *format, int *index)
{
	int		i;
	char	buffer[13];

	i = 0;
	while (format[*index + i] != 0 && ft_isdigit(format[*index + i]))
	{
		buffer[i] = format[*index + i];
		i = i + 1;
	}
	buffer[i] = 0;
	(*index) = (*index) + i - 1;
	return (ft_atoi(buffer));
}

int	get_precision(const char *format, int *index)
{
	int		i;
	char	buffer[13];

	i = 0;
	(*index) = (*index) + 1;
	while (format[*index + i] != 0 && ft_isdigit(format[*index + i]))
	{
		buffer[i] = format[*index + i];
		i = i + 1;
	}
	buffer[i] = 0;
	(*index) = (*index) + i - 1;
	return (ft_atoi(buffer));
}

void	init_options(t_options **options)
{
	(*options)->flag_minus = 0;
	(*options)->flag_plus = 0;
	(*options)->flag_space = 0;
	(*options)->flag_sharp = 0;
	(*options)->flag_zero = 0;

	(*options)->precision = 0;

	(*options)->width = 0;
	(*options)->precision_width = 0;
	(*options)->specifier = 0;
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i'
		 || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

void	get_options(const char *format, t_options *options, int *index)
{
	int	i;

	i = (*index);
	init_options(&options);
	while (format[i] != 0)
	{
		// ft_putchar_fd(format[i], 1);
		if (format[i] == '-')
			options->flag_minus = 1;
		if (format[i] == '+')
			options->flag_plus = 1;
		if (format[i] == '#')
			options->flag_sharp = 1;
		if (format[i] == ' ')
			options->flag_space = 1;
		if (format[i] == '0')
			options->flag_zero = 1;
		if (ft_isdigit(format[i]))
			options->width = get_width(format, &i);
		if (format[i] == '.')
		{
			options->precision = 1;
			options->precision_width = get_precision(format, &i);
		}
		if (is_specifier(format[i]))
		{
			options->specifier = format[i];
			break ;
		}
		// ft_putchar_fd(format[i], 1);
		// ft_putchar_fd(format[i + 1], 1);
		i = i + 1;
	}
	(*index) = i;
}

int	print_char(char c, t_options *options)
{
	int	size;

	size = options->width - 1;
	while (!options->flag_minus && --options->width)
	{
		if (options->flag_zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	size = size + write(1, &c, 1);
	while (options->flag_minus && --options->width)
		write(1, " ", 1);
	return (size);
}

int	print_str(char *str, t_options *options)
{
	int		size;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (options->precision && options->precision_width < len)
		len = options->precision_width;
	size = len;
	if (options->width > len)
		size = options->width;
	while (!options->flag_minus && --options->width >= len)
	{
		if (options->flag_zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	while (i < len)
		write(1, &str[i++], 1);
	while (options->flag_minus && --options->width >= len)
		write(1, " ", 1);
	return (size);
}

int	print_addr(unsigned long ptr, t_options *options)
{
	int		size;
	int		len;

	len = 9;
	if (options->precision && options->precision_width > len)
		len = options->precision_width;
	size = len;
	if (options->width > len)
		size = options->width;
	while (!options->flag_minus && --options->width > len + 1)
	{
		if (options->flag_zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	write(1, "0x", 2);
	while (len-- > 9)
		write(1, "0", 1);
	write(1, "1", 1);
	write(1, "0", 1);
	ft_putnbr_ul_base(ptr, "0123456789abcdef");
	while (options->flag_minus && --options->width > len)
		write(1, " ", 1);
	return (size);
}

int print_int(int nbr, t_options *options)
{
	int		size;
	int		len;
	int		intlen;
	int		is_negative;

	is_negative = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		is_negative = 1;
	}
	intlen = ft_intlen(nbr) + is_negative;
	len = intlen;
	if (options->precision && options->precision_width > len)
		len = options->precision_width;
	size = len;
	if (options->width > len)
		size = options->width;
	while (!options->flag_minus && --options->width >= len)
	{
		if (options->flag_zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}

	if (is_negative == 1)
		write(1, "-", 1);
	else if (options->flag_plus)
		write(1, "+", 1);
	else if (options->flag_space)
		write(1, " ", 1);
	while (intlen++ < len)
		write(1, "0", 1);
	ft_putnbr(nbr);
	while (options->flag_minus && --options->width >= len)
		write(1, " ", 1);
	return (size);
}

int	print_data(va_list *args, t_options options)
{
	if (options.specifier == '%')
		return (write(1, "%%", 1));
	else if (options.specifier == 'c')
		return (print_char(va_arg(*args, int), &options));
	else if (options.specifier == 's')
		return (print_str(va_arg(*args, char *), &options));
	// else if (options.specifier == 'p')
	// 	return (print_addr(va_arg(*args, unsigned long long), &options));
	else if (options.specifier == 'd')
		return (print_int(va_arg(*args, int), &options));
	return (0);
}

int	extract_data(const char *format, va_list *args, int *index)
{
	t_options	options;

	(*index) = (*index) + 1;
	// printf("char => %c \n", format[*index]);
	get_options(format, &options, &*index);
	// printf("char => %c \n", format[*index]);
	// printf("options->specifier => %c \n", options.specifier);
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
