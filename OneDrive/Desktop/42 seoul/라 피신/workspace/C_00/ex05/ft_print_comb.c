/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:25:01 by sham              #+#    #+#             */
/*   Updated: 2021/02/22 22:01:21 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ascending_order(char num1, char num2, char num3);

void	ft_print_comb(void)
{
	char num_arr[3];

	num_arr[0] = '0';
	num_arr[1] = '0';
	num_arr[2] = '0';
	ascending_order(num_arr[0], num_arr[1], num_arr[2]);
}

void	ascending_order(char num1, char num2, char num3)
{
	while (num1 < '8')
	{
		if (num1 < num2 && num2 < num3)
		{
			write(1, &num1, 1);
			write(1, &num2, 1);
			write(1, &num3, 1);
			if (num1 != '7' || num2 != '8' || num3 != '9')
			{
				write(1, ", ", 2);
			}
		}
		num3++;
		if (num3 == ':')
		{
			num2++;
			num3 -= 10;
		}
		if (num2 == ':')
		{
			num1++;
			num2 -= 10;
		}
	}
}
