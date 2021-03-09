/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:16:20 by sham              #+#    #+#             */
/*   Updated: 2021/03/06 16:40:09 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_nbr(int nb)
{
	char	nbr;
	int		print_num;

	print_num = nb % 10;
	if (nb / 10)
		get_nbr(nb / 10);
	nbr = print_num + '0';
	write(1, &nbr, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		get_nbr(nb);
	}
	else
		get_nbr(nb);
}
