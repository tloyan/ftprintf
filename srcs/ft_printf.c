/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:18:34 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/06 22:06:15 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// pass linked list in params 
// t_option and assign it in the first elem
void	extract_standard_string(const char *format, int	*index)
{
	t_options	data;
	char		*str;
	int			len;
	int			i;

	len = 0;
	while (format[*index + len] != 0 && format[*index + len] != '%')
		len = len + 1;
	str = malloc((len + 1) * sizeof(*str));
	if (!str) // create garbage collector ?
		return ;
	str[len] = 0;
	i = 0;
	while (i < len)
	{
		str[i] = format[*index + i];
		i = i + 1;
	}
	(*index) = (*index) + 1;
}

t_options	*extract_data(const char *format, va_list *args)
{
	int		i;

	i = 0;
	while (format[i] != 0)
	{

		i = i + 1;
	}
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_options	*options_list;

	va_start(args, format);
	options_list = extract_data(format, &args);
	va_end(args);
	return (0);
}
