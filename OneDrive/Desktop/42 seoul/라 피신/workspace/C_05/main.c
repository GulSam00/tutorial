/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:02:37 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 14:03:46 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_iterative_factorial(int nb);
int     ft_recursive_factorial(int nb);
int     ft_iterative_power(int nb, int power);
int     ft_recursive_power(int nb, int power);
int     ft_fibonacci(int index);
int     ft_sqrt(int nb);
int     ft_is_prime(int nb);
int     ft_find_next_prime(int nb);
int     ft_find_next_prime(int nb);
int     ft_ten_queens_puzzle(void);

int     main(void)
{
 for (int i = -2; i < 16; i++)
        printf ("%d : %d\n",i, ft_iterative_factorial(i));

    for (int i = -2; i < 10; i++)
        printf ("%d : %d\n",i, ft_recursive_factorial(i));

	for (int i = -2; i < 10; i++)
		printf ("%d : %d\n",i, ft_iterative_power(-3, i));

	for (int i = -2; i < 10; i++)
		printf ("%d : %d\n",i, ft_recursive_power(-3, i));

    for (int i = -2; i < 10; i++)
        printf ("%d\n", ft_fibonacci(i));

    for (int i = 0; i < 100; i++)
    {
        if (ft_sqrt(i))
            printf ("yes %d - %d\n", i, ft_sqrt(i));
    }

    for(int i=0; i<101; i++)
    {
        printf("%d\n",ft_is_prime(i));
    }

    for(int i=0; i<101; i++)
    {
        printf("%d\n",ft_find_next_prime(i));
    }

    printf ("g_count : %d\n", ft_ten_queens_puzzle());

}

   