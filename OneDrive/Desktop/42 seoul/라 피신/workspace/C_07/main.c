/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:26:18 by marvin            #+#    #+#             */
/*   Updated: 2021/03/05 16:26:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src);
int     *ft_range(int min, int max);
int     ft_ultimate_range(int **range, int min, int max);
char    *ft_strjoin(int size, char **strs, char *sep);
char    *ft_convert_base(char *nbr, char *base_from, char *base_to);
char    **ft_split(char *str, char *charset);



int     test_ft_strdup(void)
{
    char *p;
    char str[] = "qwerty";
    p = ft_strdup("qwerty");
    printf ("%s\n",p);
}


int     test_ft_range(void)
{
    int *p;
    p = ft_range(5, 10);
    for (int i = 0; i < 5; i++) //포인터의 크기는 항상 8바이트, 배열만큼의 크기를 할당받았더라도 sizeof(pointer)의 8바이트로 동일.
        printf ("%d\n", p[i]);
    free(p);
}

int     test_ft_ultimate_range(void)
{
    int *p;
    int len;
    len = ft_ultimate_range(&p, 5, 10);
    for (int i = 0; i < len; i++)
    {
    printf ("%d\n", p[i]);
    }
    free(p);
}

int     test_ft_strjoin(void)
{
    int size = 3;
    char *strs[3];
    strs[0] = "tihs";
    strs[1] = "is";
    strs[2] = "sparata";
    char sep[] = "!!!";
    char *p;
    p = ft_strjoin(size, strs, sep);
    printf ("%s\n", p);
    p = ft_strjoin(0, strs, sep);
    printf ("%s\n", p);
}

int     test_ft_convert_base(void)
{
    char *p;
    p = ft_convert_base("1100100", "01","01234567");
    printf ("%s\n", p);
    printf ("address is %p\n", p);
}


int     test_ft_split(void)
{
    char **p;
    p = ft_split("this*is*amer*ica","#*");
    printf ("%s\n",p[0]);
    printf ("%s\n",p[1]);
    printf ("%s\n",p[2]);
    printf ("%s\n",p[3]);

}


int     main(void)
{
    printf("--test_ft_strdup--\n");
    test_ft_strdup();
    printf("--test_ft_range--\n");
    test_ft_range();
    printf ("--test_ft_ultimate_range--\n");
    test_ft_ultimate_range();
    printf("--test_ft_strjoin--\n");
    test_ft_strjoin();
    printf ("--test_ft_convert_base--\n");
    test_ft_convert_base();
    printf ("--test_ft_split--\n");
    test_ft_split();
}