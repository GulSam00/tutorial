/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:40:45 by sham              #+#    #+#             */
/*   Updated: 2021/02/23 13:06:05 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;

	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
	
	j = 0;
	while (j < size)
	{
	printf ("%d", tab[j]);
	j++;
	}
	printf ("\n");
}

int		main(void)
{
	int tab1[6] = {1,2,3,4,5,6};
	int tab2[6] = {1,2,3,4,5,6};
	int tab3[6] = {-1,0,2,1,6,4};
	int size = 6;
	ft_sort_int_tab(tab1, size);
	ft_sort_int_tab(tab2, size);
	ft_sort_int_tab(tab3, size);
	int i;
	i = 0;
	while (i < 6)
	{
	printf ("%d", tab1[i]);
	i++;
	}
	i = 0;
	while (i < 6)
	{
	printf ("%d", tab2[i]);
	i++;
	}
	i = 0;
	while (i < 6)
	{
	printf ("%d", tab3[i]);
	i++;
	}
}
