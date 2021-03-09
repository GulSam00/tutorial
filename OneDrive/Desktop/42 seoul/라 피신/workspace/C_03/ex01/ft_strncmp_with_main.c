/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_with_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:14:01 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 15:45:21 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 && *s2 && n)
	{
		if (*s1 > *s2)
			return (1);
		else if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int		main()
{
	char arr[][10] = {"those", "thief", "throw", "teemo"};
	for (int i =0; i < 4; i++)
	{
		printf ("%d ", ft_strncmp(arr[i], "thra",5));
		printf ("found %s\n", arr[i]);
	}

}
