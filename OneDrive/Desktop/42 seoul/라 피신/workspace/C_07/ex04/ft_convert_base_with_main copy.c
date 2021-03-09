/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_with_main.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:11:20 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 17:09:24 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     write_num(char *start_num, int radix);
int     write_num_sixteen(char *start_num, int radix);
int     ft_atoi_base_from(char *str, int radix);
char*   check_num(char *str, int *sign);

int     check_dup(int *dup)
{
    int j;
    
    j = 0;
    while (j < 256)
        if (dup[j++] > 1)
            return (0);
    printf ("not duped\n");
    return (1);
}
int     check_radix(char *base, int *radix)
{
    int i;
    int num;
    int dup[256];
    printf ("-----check radix------\n");
    i = 0;
    while (i < 256)
        dup[i++] = 0;
    i = 0;
    while(base[i])
    {
        if (base[i] == '+' || base[i] == '-' || base[i] <= ' ' || base[i] == 127)
            return (0);
        num = base[i];
        dup[num]++;
        printf ("ascii of %c : %d\n", base[i], num);
        printf ("dup[%d] : %d\n", num, dup[num]);
        i++;
    }
        *radix = i;
        return (check_dup(dup));
}

void ft_number_char_arr(char *char_arr, int *int_arr, int i, int sign)
{
    int j;
    int k;

    j = 0;
    k = 0;
    while (k <= i)
    {
        if (sign)
        {
            char_arr[j] = '-';
            sign = 0;
            j++;
        }
        char_arr[j] = int_arr[i - k] + '0';
        j++;
        k++;
    }
    char_arr[j] = '\0';
}

char *ft_atoi_base_to(int number, int radix_to)
{
    // ������ �� ���̳ʽ� ó��?
    printf ("\ncheck\n");
    int sign;
    int temp_arr[11];
    int i;
    char *final_arr;

    sign = 0;
    if (!number)
        {
            number *= -1;
            sign = 1;
        }
    i = 0;
    while (number >= radix_to)
    {
        printf("number : %d radix_to : %d\n", number, radix_to);
        temp_arr[i] = number % radix_to;
        number /= radix_to;
        i++;
    }
    temp_arr[i] = number;
    final_arr = (char*)malloc(i + sign + 1);
    printf ("address is %p\n", final_arr);
    ft_number_char_arr(final_arr, temp_arr, i, sign);
    return (final_arr);
}

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int radix_from;
    int radix_to;
    int number;
    char *result;
    if (!check_radix(base_from, &radix_from) || !check_radix(base_to, &radix_to))
        return (0);
    printf ("radix_from : %d, radix_to : %d\n", radix_from, radix_to);
    // char�� �迭 ������ nbr�� ���� base_from�� ������ ���� int�� ���� number�� �����Ѵ�.
    number = (ft_atoi_base_from(nbr, radix_from));
    printf ("until trans number : %d\n", number);
    // int�� ������ ����� number�� base_to�� �������� ��ȯ�� ���� char������ �ٲٰ� �����Ҵ�� result�� �ο��Ѵ�.
    result = ft_atoi_base_to(number, radix_to);
    printf ("address is %p\n", result);
    return (result);
}

int     main(void)
{
    char *p;
    p = ft_convert_base("1100100", "01","01234567");
    printf ("%s\n", p);
    printf ("address is %p\n", p);
}