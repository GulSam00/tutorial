/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:31:25 by marvin            #+#    #+#             */
/*   Updated: 2021/03/06 17:44:22 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_dup_temp(int *dup, int i)
{
	int	j;

	j = 0;
	while (j < 256)
		if (dup[j++] > 1)
			return (0);
	return (i);
}

int		check_radix_temp(char *base)
{
	int i;
	int num;
	int dup[256];

	i = 0;
	while (i < 256)
		dup[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		num = base[i];
		dup[num]++;
		i++;
	}
	return (check_dup_temp(dup, i));
}

void	write_num_temp(int nbr, int radix)
{
	char c;

	if (nbr / radix)
	{
		write_num_temp(nbr / radix, radix);
	}
	c = nbr % radix + '0';
	if (c > '9')
		c += 7;
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		radix;

	radix = check_radix_temp(base);
	if (radix < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	write_num_temp(nbr, radix);
}

int		main(void)
{
	ft_putnbr_base(31, "qwerasdfzxcv1234");
}
