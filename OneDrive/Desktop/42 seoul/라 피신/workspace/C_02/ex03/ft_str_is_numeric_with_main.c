/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric_with_main.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:50:16 by sham              #+#    #+#             */
/*   Updated: 2021/03/06 10:25:55 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('0' > str[i] || str[i] > '9')
			if (str[i] != ' ')
				return 0;
		i++;
	}
	return 1;
}

int		main(void)
{
	printf ("%d \n", ft_str_is_numeric("14 451"));
	printf ("%d \n", ft_str_is_numeric("14 4fa"));
	printf ("%d \n", ft_str_is_numeric("a1a4 451"));	
	printf ("%d \n", ft_str_is_numeric(" "));
	printf ("%d \n", ft_str_is_numeric(""));

}
