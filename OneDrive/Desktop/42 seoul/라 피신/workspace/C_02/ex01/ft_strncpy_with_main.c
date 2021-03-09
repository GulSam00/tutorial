/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_with_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:09:15 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 10:43:24 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	while (n && *src)
	{
		printf ("before : %c %c %d \n", *dest, *src, n);
		*dest = *src;
		printf ("after : %c %c %d \n", *dest, *src, n);
		dest++;
		src++;
		n--;
	}
		printf ("done : %c %c %d \n", *dest, *src, n);
	while (n) 
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return dest;
}

int main(void)
{
	char src[10] = "1234";
	char dest[10] = "abcdefghi";
	char dummy[20];
	ft_strncpy(dest, src, 5);
	ft_strncpy(dummy, src, 5);
	printf ("%s\n", dest);
	printf ("%s\n", dummy);
	for(int i =0; i<10; i++)
	{
	printf ("%02x, ",dest[i]&0x00FF);
	}
	printf ("\n");
	for(int i =0; i<10; i++)
	{
	printf ("%02x, ",dummy[i]&0x00FF);
	}
	// check is there char after NULL?
	/*
	char dest[] = "EDCiDASDB";
	char src[] = "abc";
	char *p;
	p = ft_strncpy(dest, src, sizeof(src));
	printf ("%s\n", dest);
	printf ("%c \n", dest[3]);
	printf ("%c \n",dest[4]);
	dest[3] = 'S';
	printf ("%s \n",dest);
	*/
}
