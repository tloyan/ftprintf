/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:10 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/14 15:18:36 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, t_options *options)
{
	int		size;
	int		len;
	int		i;

	i = 0;
	if (str == NULL)
		str = "(null)";
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