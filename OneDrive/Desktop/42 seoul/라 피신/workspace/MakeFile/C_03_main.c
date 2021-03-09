/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_03_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:08:53 by sham              #+#    #+#             */
/*   Updated: 2021/03/06 21:53:05 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{
	printf("%d\n", ft_strcmp("1245", "124"));
	printf("%d\n", ft_strcmp("123456", "123456"));
	printf("%d\n", ft_strcmp("aav", "aava"));
	printf("\n---------------\n");
	char arr[][10] = {"those", "thief", "throw", "thz"};
	for (int i =0; i < 4; i++)
	{
		printf("%d ", ft_strncmp(arr[i], "thr",3));
		printf("found %s\n", arr[i]);
	}
	printf ("\n---------------\n");
	char str1[] = "abc";
	char str2[] = "def";
	char *p = ft_strcat(str1, str2);
	printf ("%s\n", p);

	printf("\n---------------\n");
	char stra[20]="hello";
	char strb[20]=" world!";
	
	ft_strncat(stra, strb, 4);

printf ("%s\n",stra);

printf("\n---------------\n");

p = ft_strstr("strdfg","r");
printf ("%s\n",p);

printf("\n---------------\n");
	char arr1[] = "123456";
	char arr2[] = "abcdef";
	printf ("%d\n", ft_strlcat(arr1, arr2, 10));
	printf ("%s\n%s\n", arr1, arr2);
  	
}