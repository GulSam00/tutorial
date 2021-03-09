/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:08:06 by marvin            #+#    #+#             */
/*   Updated: 2021/03/02 16:08:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char *temp;    
    int len;
    int i;

    temp = src;
    len = 1;
    i = 0;
    while (temp[i])
    {
        len++;
        i++;
    }
    temp = (char*)malloc(len);
    i = 0;
    while (src[i])
    {
        temp[i] = src[i];
        printf ("%c -> %c\n", src[i], temp[i]);
        i++;
    }
    temp[i] = '\0';
    return (temp);
}

int     main(void)
{
    char *p;
    char str[] = "qwerty";
    p = ft_strdup("qwerty");
    printf ("%s\n",p);
}