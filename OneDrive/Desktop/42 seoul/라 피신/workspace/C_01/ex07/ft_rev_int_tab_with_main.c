/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:15:43 by sham              #+#    #+#             */
/*   Updated: 2021/02/23 11:37:33 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int i;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = temp;
		i++;
	}
	i = 0;
	while(i < size)
	{
		printf ("%d \n", tab[i]);
		i++;
	}
}

int		main(void)
{
	int tab[7] = {1, 2, 3, 4, 5, 6, 7};
	int size = 7;
	ft_rev_int_tab(tab, size);
}
