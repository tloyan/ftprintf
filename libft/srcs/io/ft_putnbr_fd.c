/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:07:13 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/02 20:10:33 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[12];
	int		len;
	int		is_negative;

	len = ft_intlen(n);
	is_negative = 0;
	if (n == INT_MIN)
		return (write(fd, "-2147483648", 11), (void)0);
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
	write(fd, buffer, ft_strlen(buffer));
}
