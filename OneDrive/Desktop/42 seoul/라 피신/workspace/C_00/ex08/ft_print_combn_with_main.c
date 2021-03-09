/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn_with_main.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:08:34 by sham              #+#    #+#             */
/*   Updated: 2021/02/22 23:45:21 by sham             ###   ########.fr       */
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
	ascending_order(arr, range);	
}

void	ascending_order(char arr[], int range)
{
	while (arr[0] < '0' - range)
	{
		arr[range]++;
		if (arr[range] == ':')
		{
			arr[range - 1]++;
			arr[range] -= 10;
		}
	}
}
