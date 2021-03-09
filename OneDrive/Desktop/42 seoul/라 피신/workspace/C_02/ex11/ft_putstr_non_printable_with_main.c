/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable_with_main.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:27:40 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 12:42:49 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		check_printable(char c);
void	print_sixteen(char c);

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (check_printable(str[i]))
			write(1, &str[i], 1);
		else
			print_sixteen(str[i]);
		i++;	
	}
}

int		check_printable(char c)
{
	if (31 < c && c < 127)
		return 1;
	else
		return 0;
}

void	print_sixteen(char c)
{
	char c_list[] ="0123456789abcdef/";
	int mod;
	int rem;
	
	mod = c / 16;
	rem = c % 16;
	write(1, &c_list[16], 1);
	write(1, &c_list[mod], 1);
	write(1, &c_list[rem], 1);
}

int main(void)
{
	char arr[10] = "h\ti\ti a\nm";
	char un1= -13;
	int i = 0;
	while (i < 10)
	{
	printf ("%c:%d \n",arr[i], arr[i]);
	i++;
	}
	printf ("\n");
	ft_putstr_non_printable(arr);	
	printf ("\n");
	i = -128;
	while(i < 128)
	{
	un1 = i;
	ft_putstr_non_printable(&un1);
	printf ("%x \n ", un1);
	i++;
	}
}
