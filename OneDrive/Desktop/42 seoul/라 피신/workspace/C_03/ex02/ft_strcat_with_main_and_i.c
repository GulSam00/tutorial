/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_with_main_and_i.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:47:50 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 16:06:58 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char *ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;	
	while (*src)
	{
		dest[i] = *(src++);
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	char str1[] = "abc";
	char str2[] = "def";
	char *p = ft_strcat(str1, str2);
	write(1, p, 6);
	printf ("\n%s", p);
}
