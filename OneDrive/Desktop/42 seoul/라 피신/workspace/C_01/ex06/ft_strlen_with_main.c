/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 00:00:59 by sham              #+#    #+#             */
/*   Updated: 2021/02/23 11:12:36 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);

int		main(void)
{
	char str[3] = "hi\0";
	printf ("%d \n", ft_strlen(str));
}

int		ft_strlen(char *str)
{
	int amount;

	amount = 0;
	while (*str)
	{
		printf ("%c", *str);
		str++;
		amount++;
		
	}
	return amount;
}
