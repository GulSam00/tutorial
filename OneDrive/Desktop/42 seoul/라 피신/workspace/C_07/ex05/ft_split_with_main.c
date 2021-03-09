/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:07:44 by marvin            #+#    #+#             */
/*   Updated: 2021/03/05 11:07:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     is_charset(char c, char *charset)
{
    while(*charset)
    {
        if (c == *charset)
            return (1);
        charset++;
    }
    return (0);
}

int     check_str(char *str, char *charset)
{
    int count;

    count = 0;
    while (*str)
    {
        if (!is_charset(*str, charset))
        {
            printf ("%c is first char of word\n", *str);
            count++;
            while (*str && !is_charset(*str, charset))
                str++;
        }
        str++;
    }
    return (count);
}

void    put_div_str(char *arr, char *start_add, int word_len)
{
    int i;

    i = 0;
    while (i < word_len)
    {
        printf ("going to cp %c\n", start_add[i]);
        arr[i] = start_add[i];
        i++;
    }
    arr[i] = '\0';
}

char    **ft_split(char *str, char *charset)
{
    char **arr;
    int arr_index;
    char *start_add;
    int word_len;

    arr = (char **)malloc(sizeof(char *) * check_str(str, charset) + 1);
    arr_index = 0;
    while (*str)
    {
        if (!is_charset(*str, charset))
        {
            word_len = 0;
            start_add = str;
            while (*str && !is_charset(*str, charset))
            {
                str++;
                word_len++;
            }
            arr[arr_index] = (char *)malloc(word_len + 1);
            put_div_str(arr[arr_index++], start_add, word_len);
        }
        str++;
    }
    printf ("%s\n",arr[0]);
    printf ("%s\n",arr[1]);
    printf ("%s\n",arr[2]);
    return (arr);
}

int     main(void)
{
    char **p;
    p = ft_split("this*is*america","#*");
    printf ("%s\n",p);

}

