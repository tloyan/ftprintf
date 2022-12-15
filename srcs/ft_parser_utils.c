/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:49:44 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/15 13:36:04 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_signed(int nbr, t_options *options)
{
	if (nbr < 0)
		return (1);
	else if (options->flag_plus)
		return (1);
	else if (options->flag_space)
		return (1);
	return (0);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i'
		|| c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == ' ' || c == '0')
		return (c);
	return (0);
}
