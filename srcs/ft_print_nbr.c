/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:36:27 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/18 12:06:20 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	print_sign(int nbr, t_options *options)
{
	if (nbr < 0)
		return (write(1, "-", 1));
	else if (options->flag_plus)
		return (write(1, "+", 1));
	else if (options->flag_space)
		return (write(1, " ", 1));
	return (0);
}

static int	print_width(long int nbr, t_options *options)
{
	int	size;
	int	max;

	size = 0;
	max = ft_nbrlen(ft_abs(nbr));
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

int	print_int(int nbr, t_options *options)
{
	int		size;

	size = 0;
	if (options->precision && options->precision_width >= 0)
		options->flag_zero = 0;
	if (nbr < 0 || options->flag_plus || options->flag_space)
		options->width = options->width - 1;
	if (options->flag_minus == 0 && options->flag_zero == 0)
		size = size + print_width(nbr, options);
	size = size + print_sign(nbr, options);
	if (options->flag_minus == 0 && options->flag_zero == 1)
		size = size + print_width(nbr, options);
	while (options->precision
		&& (options->precision_width-- > ft_nbrlen(ft_abs(nbr))))
		size = size + write(1, "0", 1);
	size = size + ft_putnbr_ul(ft_abs(nbr));
	if (options->flag_minus == 1)
		size = size + print_width(nbr, options);
	return (size);
}

int	print_unsigned_int(unsigned int nbr, t_options *options)
{
	int		size;

	size = 0;
	if (options->precision && options->precision_width >= 0)
		options->flag_zero = 0;
	if (options->flag_minus == 0 && options->flag_zero == 0)
		size = size + print_width(nbr, options);
	if (options->flag_minus == 0 && options->flag_zero == 1)
		size = size + print_width(nbr, options);
	while (options->precision
		&& (options->precision_width-- > ft_nbrlen(ft_abs(nbr))))
		size = size + write(1, "0", 1);
	size = size + ft_putnbr_ul(ft_abs(nbr));
	if (options->flag_minus == 1)
		size = size + print_width(nbr, options);
	return (size);
}
