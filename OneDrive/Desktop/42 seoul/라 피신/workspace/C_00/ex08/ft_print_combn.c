/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:08:34 by sham              #+#    #+#             */
/*   Updated: 2021/02/22 23:14:27 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ascending_order(char arr[], int range);

void	ft_print_combn(int n)
{
	char arr[n];
	int range;

	range = 0;
	while (range < n)
	{
	arr[range] = '0';
	range++;
	}
	while (arr[0] < '0' - range)
	{
	ascending_order(arr, range);	
	}

}

void	ascending_order(char arr[], int range)
{
	while (arr[0] < '0' - range)
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
		arr[range]++;
		if (arr[range] == ':')
		{
			arr[range - 1]++;
			arr[range] -= 10;
		}
	}
}
