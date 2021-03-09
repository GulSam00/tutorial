/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase_with_main.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:01:31 by sham              #+#    #+#             */
/*   Updated: 2021/03/06 10:34:50 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	printf ("%d \n",ft_str_is_lowercase("afhjz"));
	printf ("%d \n",ft_str_is_lowercase(" afs32hj z"));
	printf ("%d \n",ft_str_is_lowercase("afsA  S hjz"));
	printf ("%d \n",ft_str_is_lowercase(""));
	printf ("%d \n",ft_str_is_lowercase("   "));
}
