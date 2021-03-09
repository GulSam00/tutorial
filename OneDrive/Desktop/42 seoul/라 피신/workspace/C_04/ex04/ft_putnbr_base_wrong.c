/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:31:25 by marvin            #+#    #+#             */
/*   Updated: 2021/03/01 12:31:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char g_list[] = ("0123456789ABCDEF 0123456789 poneyvif 01 ");
int g_type[] = {0, 2, 8, 10, 16};

int     check_radix(char *base)
{
    char *p_list;
    char *p_base;
    int i;
    int correct;

    i = 4;
    p_list = g_list;
    while(i > 0)
    {
        correct = 1;
        p_base = base;
        while (*p_list != ' ')
        {
            if (*p_list != *p_base)
                correct = 0;
            p_list++;
            p_base++;
        }
        if (correct && *p_base == '\0')
            return (g_type[i]);
        p_list++;
        i--;
    }
    return (g_type[i]);
}

void    write_num(char *arr, int i)
{
    while (i >= 0)
    {
        if (arr[i] > 9)
            printf ("%c", arr[i] + '7');
        else
            printf ("%c", arr[i] + '0');
        i--;
    }
}

void    ft_putnbr_base(int nbr, char *base)
{
    int radix;
    char arr[100];
    int i;

    i = 0;
    radix = check_radix(base);

    if (!radix)
        return ;
    if (nbr < 0)
    {
        printf ("%c", '-');
        nbr *= -1;
    }
    while (nbr >= radix)
    {
        arr[i] = nbr % radix;
        nbr /= radix;
        i++;
    }
    arr[i] = nbr;
    write_num(arr, i);
}

int main(void)
{
    //check error
    ft_putnbr_base(10, "00");
    printf ("\n");
    ft_putnbr_base(10, "0123456789+-");
    printf ("\n");
    ft_putnbr_base(10, "012345678999");
    printf ("\n");

    ft_putnbr_base(10, "0123456789ABCDEF");
    printf ("\n");
    ft_putnbr_base(-10, "0123456789");
    printf ("\n");
    ft_putnbr_base(-10, "poneyvif");
    printf ("\n");
    ft_putnbr_base(-10, "01");
}