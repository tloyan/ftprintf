/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:43:34 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/14 15:08:19 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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


void	get_flag(char c, t_options *options)
{
	if (c == '-')
		options->flag_minus = 1;
	if (c == '+')
		options->flag_plus = 1;
	if (c == '#')
		options->flag_sharp = 1;
	if (c == ' ')
		options->flag_space = 1;
	if (c == '0')
		options->flag_zero = 1;
	if (options->flag_minus)
		options->flag_zero = 0;
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

void	get_options(const char *format, t_options *options, int *index)
{
	int	i;

	i = (*index);
	init_options(&options);
	while (format[i] != 0)
	{
		if (is_flag(format[i]))
			get_flag(format[i], options);
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
		i = i + 1;
	}
	(*index) = i;
}

