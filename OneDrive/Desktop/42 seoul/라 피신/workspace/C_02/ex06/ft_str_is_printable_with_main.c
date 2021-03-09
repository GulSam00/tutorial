/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:11:49 by sham              #+#    #+#             */
/*   Updated: 2021/02/23 18:20:14 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
	if (str[i] < 32 || str[i] > 126)
		return 0;
	i++;
	}
	return 1;
}

int		main(void)
{
	char wave = 126;
	printf("%d \n", ft_str_is_printable("FAS#@$! VZ X")); 
	printf("%d \n", ft_str_is_printable("~"));
	printf("%d \n", ft_str_is_printable("  "));

}
