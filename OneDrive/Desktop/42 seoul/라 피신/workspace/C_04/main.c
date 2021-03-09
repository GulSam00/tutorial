/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:12:42 by marvin            #+#    #+#             */
/*   Updated: 2021/03/06 18:46:23 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int     ft_atoi(char *str);
void    ft_putnbr_base(int nbr, char *base);
int    ft_atoi_base(char *str, char *base);

int     main(void)
{
	printf ("test_ft_strlen\n");
	printf ("%d\n", ft_strlen("hello"));
	printf ("%d\n", ft_strlen("helloguy"));
	printf ("%d\n", ft_strlen("helloworld"));

	printf ("ft_putstr\n");
	ft_putstr("Aiasdf");

	printf ("ft_putnbr\n");
	ft_putnbr(123);
	printf ("\n");
	ft_putnbr(-345);
	printf ("\n");
	ft_putnbr(0);
	printf ("\n");
	ft_putnbr(2147483647);
	printf ("\n");
	ft_putnbr(-2147483648);
	printf ("\n");

    printf ("\ntest_ft_atoi\n");
    printf ("%d\n", ft_atoi("---+1213ff3"));
    printf ("%d\n", ft_atoi("+12ff3"));
    

    printf ("\ntest_ft_putnbr_base\n");
    ft_putnbr_base(10, "qweras");
    printf ("\n");
    ft_putnbr_base(-10, "qwerasdf");
    printf ("\n");
    ft_putnbr_base(-10, "qwerasdfzx");
  
    // 같은 함수 이름을 다른 파일에서 쓰면 에러 발생.
    // ft_atoi_base의 파일의 중복되는 함수의 끝에 temp를 붙여놓았음.
    printf ("\ntest_ft_atoi_base\n");
    printf ("%d",ft_atoi_base("10", "00"));
    printf ("\n");
    printf ("%d", ft_atoi_base("10", "0123456789+-"));
    printf ("\n");

    printf ("%d", ft_atoi_base("-10c0", "qwerasdfzx"));
    printf ("\n");
    printf ("%d", ft_atoi_base("10d0s0", "01"));
    printf ("\n");
}