/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:27:40 by sham              #+#    #+#             */
/*   Updated: 2021/03/08 15:28:31 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_list[] = "0123456789abcdef\\";

int		check_printable(unsigned char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	else
		return (0);
}

void	print_sixteen(unsigned char c)
{
	int mod;
	int rem;

	mod = c / 16;
	rem = c % 16;
	write(1, &g_list[16], 1);
	write(1, &g_list[mod], 1);
	write(1, &g_list[rem], 1);
}

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
