/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_array_ver.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:46:50 by sham              #+#    #+#             */
/*   Updated: 2021/02/22 18:37:35 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ascending_order(char f_num1, char f_num2, char b_num1, char b_num2);
void	write_number(char f_num1, char f_num2, char b_num1, char b_num2);
void	ft_print_comb2(void);

int		main(void)
{
	ft_print_comb2();
}

void	ft_print_comb2(void)
{
	char f_num[2];
	char b_num[2];

	f_num[0] = '0';
	f_num[1] = '0';
	b_num[0] = '0';
	b_num[1] = '0';
	ascending_order(f_num[0], f_num[1], b_num[0], b_num[1]);
}

void	ascending_order(char f_num1, char f_num2, char b_num1, char b_num2)
{
	while (f_num1 < ':')
	{
		if (f_num1 <= b_num1)
		{
			if (f_num2 < b_num2 || f_num1 < b_num1)
				write_number(f_num1, f_num2, b_num1, b_num2);
		}
		b_num2++;
		if (b_num2 == ':')
		{
			b_num1++;
			b_num2 -= 10;
		}
		if (b_num1 == ':')
		{
			f_num2++;
			b_num1 -= 10;
		}
		if (f_num2 == ':')
		{
			f_num1++;
			f_num2 -= 10;
		}
	}
}

void	write_number(char f_num1, char f_num2, char b_num1, char b_num2)
{
	write(1, &f_num1, 1);
	write(1, &f_num2, 1);
	write(1, " ", 1);
	write(1, &b_num1, 1);
	write(1, &b_num2, 1);
	if (f_num1 != '9' || f_num2 != '8')
		write(1, ", ", 2);
}
