/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:45:47 by tloyan            #+#    #+#             */
/*   Updated: 2022/12/14 14:19:24 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int res0;
	int res1;

	// res0 = printf("%-+ 0 5c\n", 'h', 'e', 'l', 'l', 'o');
	// res1 = ft_printf("%-+ 0 5c\n", 'h', 'e', 'l', 'l', 'o');

	// res0 = printf("%0 50s\n", "hello world everyone that's ok ??? I think so");
	// res1 = ft_printf("%0 50s\n", "hello world everyone that's ok ??? I think so");

	// res0 = printf(" %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");
	// res1 = ft_printf(" %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");

	// char *str;
	// res0 = printf("%.3 30p\n", str);
	// res1 = ft_printf("%.3 30p\n", str);


	// res0 = printf("%.10 30d\n", -125);
	// res1 = ft_printf("%.10 30d\n", -125);

	// res0 = printf("|||%-3d|||\n", 1);
	// res1 = ft_printf("|||%-3d|||\n", 1);


	// res0 = printf("|||% 5.3d|||\n", -1);
	// res1 = ft_printf("|||% 5.3d|||\n", -1);


	// res0 = printf("|||% 5.2d|||\n", -1);
	// res1 = ft_printf("|||% 5.2d|||\n", -1);

	// res0 = printf("|||% 5.2u|||\n", 7);
	// res1 = ft_printf("|||%5.2u|||\n", 7);

	// res0 = printf("|||%-4u|||\n", -14);
	// res1 = ft_printf("|||%-4u|||\n", -14);

	// res0 = printf("|||%-2u|||\n", -10);
	// res1 = ft_printf("|||%-2u|||\n", -10);

	// res0 = printf("|||%#10.4X|||\n", 23);
	// res1 = ft_printf("|||%#10.4x|||\n", 23);

	// res0 = printf("|||%#x|||\n", 0);
	// res1 = ft_printf("|||%#x|||\n", 0);

	int n = 5;

	res0 = printf("|||%p|||\n", -1);
	res1 = ft_printf("|||%p|||\n", -1);

	printf("res => %d %d\n", res0, res1);
}
