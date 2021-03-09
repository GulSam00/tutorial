/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:50:41 by sham              #+#    #+#             */
/*   Updated: 2021/03/06 15:02:54 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);


int     main()
{
    char a1[10];
    char a2[10];

    printf ("test_ft_strcpy\n");
    printf ("%s\n",ft_strcpy(a1,"12345"));
    printf ("ft_strncpy\n");
    printf ("%s\n",ft_strncpy(a2,"12345", 6));
    printf("test_ft_str_is_alpha\n");
    printf ("%d\n", ft_str_is_alpha("FAZ"));
	printf ("%d\n", ft_str_is_alpha("azfz"));
	printf ("%d\n", ft_str_is_alpha("azsdfz"));
    printf ("test_ft_str_is_numeric\n");
    printf ("%d\n", ft_str_is_numeric("14451"));
	printf ("%d\n", ft_str_is_numeric("144fa"));
	printf ("%d\n", ft_str_is_numeric("a1a4451"));	
	printf ("%d\n", ft_str_is_numeric(" "));
    printf ("test_ft_str_is_lowercase\n");
    printf ("%d\n",ft_str_is_lowercase("afhjz"));
	printf ("%d\n",ft_str_is_lowercase("afs hjz"));
	printf ("%d\n",ft_str_is_lowercase("afsAShjz"));
    printf ("%d\n", ft_str_is_numeric(""));
    printf ("test_ft_str_is_uppercase\n");
    printf ("%d\n", ft_str_is_uppercase("aASdf"));
	printf ("%d\n", ft_str_is_uppercase("AS"));
	printf ("%d\n", ft_str_is_uppercase("A S  D FS F"));
	printf ("%d\n", ft_str_is_uppercase(""));
    printf ("test_ft_str_is_printable\n");
    printf("%d \n", ft_str_is_printable("FAS#@$! VZ X")); 
	printf("%d \n", ft_str_is_printable("~"));
	printf("%d \n", ft_str_is_printable("  "));
    printf("test_ft_strupcase\n");
    char str1[] = "asADM_ df,(anoTher), -#@! g.";
	char *p = str1;
	printf ("%s \n", (ft_strupcase(p)));
    printf("test_ft_strlowcase\n");
    char str2[] = "DM_df,(anoTher), -#@! g.";
	p = str2;
	printf ("%s \n", (ft_strlowcase(p)));
    printf("test_ft_strcapitalize\n");
	char str[]="he l sdj -fsd = f=df=f-f-fs F adFAS FCXs sfF";
	ft_strcapitalize(str);
	printf ("%s\n", str);
    printf("test_ft_strlcpy\n");
    char a[10] = "adfg";
	char b[10] = "qweryyyy";
	printf ("%d \n", ft_strlcpy(a, b, 3));
	// printf ("%d \n", ft_strlcpy(a, b, 6));
	// printf ("%d \n", ft_strlcpy(a, b, 8));
	printf ("%s %s \n", a, b);
    printf("ft_putstr_non_printable\n");
	char arr[10] = "h\ti\ti a\nm";
	int i = 0;
	while (i < 10)
	{
	printf ("%c:%d \n",arr[i], arr[i]);
	i++;
	}
	printf ("\n");
	ft_putstr_non_printable(arr);	
	printf ("\n");
    }
