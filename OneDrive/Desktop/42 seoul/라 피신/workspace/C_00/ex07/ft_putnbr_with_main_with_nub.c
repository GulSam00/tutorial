/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_with_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:42:12 by sham              #+#    #+#             */
/*   Updated: 2021/02/22 21:20:43 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	trans_num(int nb, int count, char nub[]);

void	ft_putnbr(int nb);
{
	char nub[11];
	int count;
	
	count = 0;
	trans_num(nub, nb, count);
}

void	trans_num(int nb, int count, char nub[])
{
	int number;
	
	number = nb % 10;
	if (nb / 10 == 0)
	{
		return;
	}
	else if (nb / 10 != 0)
		{
		count++;
		trans_num(nb / 10, count, nub);
		nub[count] = number;
		count--;
		}
}


int		main(void)
{

}
