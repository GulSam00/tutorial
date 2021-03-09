/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_with_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:42:12 by sham              #+#    #+#             */
/*   Updated: 2021/02/22 22:56:48 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	trans_num(int nb);
void	ft_putnbr(int nb);

int		main(void)
{
	ft_putnbr(-348);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		trans_num(nb);
	}
	else
	{
		trans_num(nb);
	}
}

void	trans_num(int nb)
{
	int		number;
	char	write_num;

	number = nb % 10;
	if (nb / 10 == 0)
	{
		write_num = number + '0';
		write(1, &write_num, 1);
		return ;
	}
	else if (nb / 10 != 0)
	{
		write_num = number + '0';
		trans_num(nb / 10);
		write(1, &write_num, 1);
	}
}
