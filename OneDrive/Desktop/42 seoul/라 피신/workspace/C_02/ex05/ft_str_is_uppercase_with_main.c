/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase_with_main.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:05:42 by sham              #+#    #+#             */
/*   Updated: 2021/02/26 00:46:50 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
			if (str[i] != ' ')
				return (0);
		i++;
	}
	return (1);
}

int		main(void)
{
	printf ("%d\n", ft_str_is_uppercase("aASdf"));
	printf ("%d\n", ft_str_is_uppercase("AS"));
	printf ("%d\n", ft_str_is_uppercase("A S  D FS F"));
	printf ("%d\n", ft_str_is_uppercase("    "));
	printf ("%d\n", ft_str_is_uppercase(""));
}
