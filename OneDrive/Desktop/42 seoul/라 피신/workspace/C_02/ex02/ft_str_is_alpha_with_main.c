/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha_with_main.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:08:55 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 10:46:31 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (('A' > str[i] || str[i] > 'Z') && ('a' > str[i] || str[i] > 'z'))
			if (str[i] != ' ')
				return 0;
		i++;
	}
	return 1;
}

int		main(void)
{
	char none = ' ';
	char space = ' ';
	char null = '\0';
	printf ("%d \n", ft_str_is_alpha("FAZ"));
	printf ("%d \n", ft_str_is_alpha("azasdfz"));
	printf ("%d \n", ft_str_is_alpha("aza sdfz"));

	printf ("%c\n", 0);
	printf ("%c\n", 32);
	printf ("%d : %d \n", none,ft_str_is_alpha(""));
	printf ("%d : %d \n", space,ft_str_is_alpha(" "));
	printf ("%d : %d \n", null,ft_str_is_alpha("\0"));
	printf ("'\\t' : %d \n", ft_str_is_alpha("\t"));
	printf ("'\\b' : %d \n", ft_str_is_alpha("\b"));
	printf ("'\\n' : %d \n", ft_str_is_alpha("\n"));
	printf ("'\\v' : %d \n", ft_str_is_alpha("\v"));
	printf ("'\\r' : %d \n", ft_str_is_alpha("\r"));
	printf ("'\\f' : %d \n", ft_str_is_alpha("\f"));
}
