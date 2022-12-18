/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:45:53 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/18 12:06:12 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_char(char c, t_options *options)
{
	int	size;

	size = 0;
	while (!options->flag_minus && --options->width > 0)
	{
		if (options->flag_zero)
			size = size + write(1, "0", 1);
		else
			size = size + write(1, " ", 1);
	}
	size = size + write(1, &c, 1);
	while (options->flag_minus && --options->width > 0)
		size = size + write(1, " ", 1);
	return (size);
}
