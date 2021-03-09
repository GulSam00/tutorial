/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:10:08 by sham              #+#    #+#             */
/*   Updated: 2021/02/24 10:35:41 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
void	ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

int		main()
{
	int nbr;
	
	nbr = 0;
	ft_ft(&nbr);
	printf ("%d \n", nbr);

	int a;
	int *b = &a;
	int **c = &b;
	int ***d = &c;
	int ****e = &d;
	int *****f = &e;
	int ******g = &f;
	int *******h = &g;
	int ********i = &h;
	ft_ultimate_ft(&i);
	printf ("%d \n", a);

	int aa;
	int bb;

	aa = 3;
	bb = 4;
	ft_swap(&aa, &bb);
	printf ("%d %d \n", aa, bb);

	int str[]={1,2,3,4,5,6};
	int j = 0;
	ft_rev_int_tab(str, 6);
	while (j < 6)
	{
		printf ("%d \n", str[j]);
		j++;
	}

	j = 0;
	ft_sort_int_tab(str, 6);
	while (j < 6)
	{
		printf ("%d \n", str[j]);
		j++;
	}

}
