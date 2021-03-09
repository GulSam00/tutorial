/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_with_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:46:25 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 23:17:18 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int len_dest;
	unsigned int len_src;
	unsigned int i;

	len_dest = 0;
	len_src = 0;
	i = 0;
	while(dest[len_dest])
	{
		printf ("%c\n", dest[len_dest]);
		len_dest++;
	}
		while(src[len_src])
		{
		printf ("%c\n", src[len_src]);
		len_src++;
		}
		while(src[i] && i + len_dest < size - 1)
	{
		printf ("%c %c\n", dest[len_dest + i], src[i]);
		dest[len_dest + i] = src[i];
		i++;
	}
	if (len_dest < size)
	{	
		dest[len_dest + i] = '\0';
		return (len_src + len_dest);
	}
	return (len_src + size);
}

int		main(void)
{
	char arr1[] = "123456";
	char arr2[] = "abcdef";
	printf ("%d\n", ft_strlcat(arr1, arr2, 2));
	printf ("%s\n%s\n", arr1, arr2);
}
