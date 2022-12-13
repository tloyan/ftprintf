/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloyan <tloyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:27:26 by tloyan            #+#    #+#             */
/*   Updated: 2022/12/12 23:29:48 by tloyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_base(int n, int baselen)
{
	int	len;

	len = 1;
	while (n / baselen)
	{
		n = n / baselen;
		len++;
	}
	return (len);
}

int	ft_putnbr_ul_base(unsigned long n, char *base)
{
	char	buffer[20];
	int		len;
	int		baselen;

	baselen = ft_strlen(base);
	len = ft_intlen_base(n, baselen);
	buffer[len] = 0;
	while (len-- > 0)
	{
		buffer[len] = base[n % baselen];
		n = n / baselen;
	}
	return (write(1, buffer, ft_strlen(buffer)));
}

int	ft_putnbr(int n)
{
	char	buffer[12];
	int		len;
	int		is_negative;

	len = ft_intlen(n);
	is_negative = 0;
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		is_negative = 1;
		n = n * -1;
		buffer[0] = '-';
	}
	buffer[len + is_negative] = 0;
	while (len-- > 0)
	{
		buffer[len + is_negative] = ((n % 10) + '0');
		n = n / 10;
	}
	return (write(1, buffer, ft_strlen(buffer)));
}
