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

int     check_dup_temp(int *dup, int i)
{
    int j;

    j = 0;
    while (j < 256)
        if (dup[j++] > 1)
            return (0);
    return (i);
}

int     check_radix_temp(char *base)
{
    int i;
    int num;
    int dup[256];

    i = 0;
    while (i < 256)
        dup[i++] = 0;
    i = 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-' || base[i] <= ' ' || base[i] == 127)
            return (0);
        num = base[i];
        dup[num]++;
        printf ("ascii of %c : %d\n", base[i], num);
        printf ("dup[%d] : %d\n", num, dup[num]);
        i++;
    }
    return (check_dup_temp(dup, i));
}

void    write_num_temp(char *arr, int i)
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
    radix = check_radix_temp(base);

    if (radix < 2)
        return (0);
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
    write_num_temp(arr, i);
}