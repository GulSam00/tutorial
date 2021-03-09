/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2_with_main.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:11:20 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 17:08:09 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char*    check_num(char *str, int *sign)
{
    char* temp;
    int num;

    temp = str;
    while (*temp)
    {
        if (*temp == '-')
            *sign *= -1;
        if (*temp >= '0' && *temp <= '9')
        {
            return (temp);
        }
        temp++;
    }
    *sign = 0;
    return NULL;
}

int write_num(char *start_num, int radix)
{
    int total_num;

    total_num = 0;
    while (*start_num && *start_num >= '0' && *start_num <= '9')
    {
        total_num = radix * total_num + (*start_num - '0');
        start_num++;
    }
    return total_num;
}

int write_num_sixteen(char *start_num, int radix)
{
    int total_num;

    total_num = 0;
    while (*start_num && (*start_num >= '0' && *start_num <= '9' || *start_num >= 'A' && *start_num <= 'F'))
    {
        if (*start_num >= 'A' && *start_num <= 'F')
            // A ~ F������ ���ڿ� 7�� ���ָ� ������������ 10 ~ 15�̱⿡ int�� ����ȯ�� ����������.
            total_num = radix * total_num + (*start_num - '7');
        else
            total_num = radix * total_num + (*start_num - '0');
        start_num++;
    }
    return total_num;
}

int    ft_atoi_base_from(char *str, int radix)
{
    int total_num;
    char *start_num;
    int sign;

    sign = 1;
    // ���ڰ� ���۵Ǵ� �ּҰ��� ����
    start_num = check_num(str, &sign);
    // �������� 0, 1�� ���
    if (radix < 2)
        return (0);
    // ���ڰ� �������� ���� ���
    if (sign == 0)
        return (0);
    // char������ ���ڸ� 10�������� ��ȯ
    if (radix > 10)
        return (write_num_sixteen(start_num, radix) * sign);
    // 16 ������ ��� ���� ó�� �Լ�
    else
        return (write_num(start_num, radix) * sign);
}