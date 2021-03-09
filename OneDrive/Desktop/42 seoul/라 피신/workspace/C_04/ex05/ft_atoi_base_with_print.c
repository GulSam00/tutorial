/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:15:44 by marvin            #+#    #+#             */
/*   Updated: 2021/03/01 15:15:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     check_dup(int *dup, int i)
{
    int j;

    j = 0;
    while (j < 256)
        if (dup[j++] > 1)
            return (0);
    return (i);
}

int     check_radix(char *base)
{
    int i;
    int num;
    int dup[256];

    i = 0;
    while (i < 256)
        dup[i++] = 0;
    i = 0;
        printf ("------\n");
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
        return (check_dup(dup, i));
}

// 숫자가 시작되는 주소값을 리턴, `-`표시가 있을 때마다 sign값에 -1을 곱해줌.
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
    return (0);
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
    return (total_num);
}

int write_num_sixteen(char *start_num, int radix)
{
    int total_num;

    total_num = 0;
    while (*start_num && (*start_num >= '0' && *start_num <= '9' || *start_num >= 'A' && *start_num <= 'F'))
    {
        if (*start_num >= 'A' && *start_num <= 'F')
            total_num = radix * total_num + (*start_num - '7');
        else
            total_num = radix * total_num + (*start_num - '0');
        start_num++;
    }
    return total_num;
}

int    ft_atoi_base(char *str, char *base)
{
    int radix;
    int total_num;
    char *start_num;
    int sign;

    sign = 1;
    // 지수를 radix에 저장
    radix = check_radix(base);
    // 숫자가 시작되는 주소값을 저장
    start_num = check_num(str, &sign);
    // 지수값이 0일 경우
    if (radix < 2)
        return (0);
    // 숫자가 존재하지 않을 경우
    if (sign == 0)
        return (0);
    // char형태의 숫자를 10진법으로 변환
    if (radix == 16)
        return (write_num_sixteen(start_num, radix) * sign);
    // 16 진법일 경우 예외 처리 함수
    else
        return (write_num(start_num, radix) * sign);
}