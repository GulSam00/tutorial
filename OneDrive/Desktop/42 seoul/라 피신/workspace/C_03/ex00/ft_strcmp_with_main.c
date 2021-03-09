/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:43:20 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 15:05:30 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	else if (*s1 < *s2)
		return (-1);
	else
		return (0);
}

int main()
{
	printf ("%d\n", ft_strcmp("1245","124"));
	printf ("%d\n", ft_strcmp("123456","123456"));
	printf ("%d\n", ft_strcmp("aaaaaa","aav"));
}
// range of int - test for array int
// char * function test - address return of char?
