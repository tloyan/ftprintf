/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:53 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/14 15:16:42 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
