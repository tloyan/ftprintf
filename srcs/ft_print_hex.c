/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:29:02 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/14 15:17:34 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_width_hex(long long int nbr, t_options *options)
{
	int	size;
	int	max;

	size = 0;
	max = ft_nbrlen_base(ft_abs(nbr), 16);
	if (options->precision && options->precision_width > max)
		max = options->precision_width;
	while (options->width-- > max)
	{
		if (options->flag_zero)
			size = size + write(1, "0", 1);
		else
			size = size + write(1, " ", 1);
	}
	return (size);
}

static int	print_sharp(unsigned int nbr, t_options *options)
{
	int	size;

	size = 0;
	if (options->flag_sharp && nbr != 0)
	{
		options->width = options->width - 2;
		if (options->flag_minus == 0 && options->flag_zero == 0)
			size = size + print_width_hex(nbr, options);
		if (options->specifier == 'X')
			size = size + write(1, "0X", 2);
		else
			size = size + write(1, "0x", 2);
	}
	else
	{
		if (options->flag_minus == 0 && options->flag_zero == 0)
			size = size + print_width_hex(nbr, options);
	}
	return (size);
}

int	print_hex(unsigned int nbr, t_options *options)
{
	int		size;

	size = 0;
	if (options->precision && options->precision_width >= 0)
		options->flag_zero = 0;
	size = size + print_sharp(nbr, options);
	if (options->flag_minus == 0 && options->flag_zero == 1)
		size = size + print_width_hex(nbr, options);
	while (options->precision
		&& (options->precision_width-- > ft_nbrlen_base(ft_abs(nbr), 16)))
		size = size + write(1, "0", 1);
	if (options->specifier == 'X')
		size = size + ft_putnbr_ul_base(ft_abs(nbr), "0123456789ABCDEF");
	else
		size = size + ft_putnbr_ul_base(ft_abs(nbr), "0123456789abcdef");
	if (options->flag_minus == 1)
		size = size + print_width_hex(nbr, options);
	return (size);
}