/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:33:27 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/18 12:03:41 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_nbrlen_ull_base(unsigned long long nb, int baselen)
{
	int	len;

	len = 1;
	if (nb == 0)
		return (5);
	while (nb / baselen)
	{
		len = len + 1;
		nb = nb / baselen;
	}
	return (len);
}

static int	ft_putnbr_ull_base(unsigned long long n, char *base)
{
	char	buffer[30];
	int		len;
	int		baselen;

	baselen = ft_strlen(base);
	len = ft_nbrlen_ull_base(n, baselen);
	buffer[len] = 0;
	while (len-- > 0)
	{
		buffer[len] = base[n % baselen];
		n = n / baselen;
	}
	return (write(1, buffer, ft_strlen(buffer)));
}

static int	print_width_ptr(unsigned long nbr, t_options *options)
{
	int	size;
	int	max;

	size = 0;
	max = ft_nbrlen_ull_base(nbr, 16);
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

static int	print_sharp(unsigned long nbr, t_options *options)
{
	int	size;

	size = 0;
	if (nbr != 0)
	{
		options->width = options->width - 2;
		if (options->flag_minus == 0 && options->flag_zero == 0)
			size = size + print_width_ptr(nbr, options);
		size = size + write(1, "0x", 2);
	}
	else
	{
		if (options->flag_minus == 0 && options->flag_zero == 0)
			size = size + print_width_ptr(nbr, options);
	}
	return (size);
}

int	print_ptr(unsigned long nbr, t_options *options)
{
	int		size;

	size = 0;
	if (options->precision && options->precision_width >= 0)
		options->flag_zero = 0;
	size = size + print_sharp(nbr, options);
	if (options->flag_minus == 0 && options->flag_zero == 1)
		size = size + print_width_ptr(nbr, options);
	while (options->precision
		&& (options->precision_width-- > ft_nbrlen_ull_base(nbr, 16)))
		size = size + write(1, "0", 1);
	if (nbr == 0)
		size = size + write(1, "(nil)", 5);
	else
		size = size + ft_putnbr_ull_base(nbr, "0123456789abcdef");
	if (options->flag_minus == 1)
		size = size + print_width_ptr(nbr, options);
	return (size);
}
