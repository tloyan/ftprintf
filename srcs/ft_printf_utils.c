/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:27:26 by tloyan            #+#    #+#             */
/*   Updated: 2022/12/18 11:50:12 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_nbrlen_base(long int nb, int baselen)
{
	int	len;

	len = 1;
	while (nb / baselen)
	{
		len = len + 1;
		nb = nb / baselen;
	}
	return (len);
}

int	ft_putnbr_ul_base(unsigned long n, char *base)
{
	char	buffer[20];
	int		len;
	int		baselen;

	baselen = ft_strlen(base);
	len = ft_nbrlen_base(n, baselen);
	buffer[len] = 0;
	while (len-- > 0)
	{
		buffer[len] = base[n % baselen];
		n = n / baselen;
	}
	return (write(1, buffer, ft_strlen(buffer)));
}

long long int	ft_abs(long long int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_nbrlen(long long int nb)
{
	int	len;

	len = 1;
	while (nb / 10)
	{
		len = len + 1;
		nb = nb / 10;
	}
	return (len);
}

int	ft_putnbr_ul(unsigned long n)
{
	char	buffer[13];
	int		len;

	len = ft_nbrlen(n);
	buffer[len] = 0;
	while (len-- > 0)
	{
		buffer[len] = ((n % 10) + '0');
		n = n / 10;
	}
	return (write(1, buffer, ft_strlen(buffer)));
}
