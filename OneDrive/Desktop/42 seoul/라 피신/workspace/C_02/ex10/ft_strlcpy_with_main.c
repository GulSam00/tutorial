/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_with_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:39:41 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 15:35:13 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int len;
	unsigned int i;

	len = 0;
	i = 0;
	
	if (dest == '\0' || src == '\0')
		return (0);
	while (src[len])
		len++;
	while (i < len && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (len);
}

int main(void)
{
	char a[10] = "adfg";
	char b[10] = "qwert";
	printf ("%d \n", ft_strlcpy(a, b, 3));
	printf ("%d \n", ft_strlcpy(a, b, 6));
	printf ("%d \n", ft_strlcpy(a, b, 8));
	printf ("%s %s \n", a, b);
}
