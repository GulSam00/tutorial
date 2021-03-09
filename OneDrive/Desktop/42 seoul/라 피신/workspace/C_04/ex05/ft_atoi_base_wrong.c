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
// 공백으로 구분하는 지수 문자열.
char g_list[] = ("0123456789ABCDEF 0123456789 poneyvif 01 ");
// 해당되는 지수를 배열, g_type[i] 형식으로 대입.
int g_type[] = {0, 2, 8, 10, 16};

// 지수를 리턴, 해당되지 않으면 0을 리턴.
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

// 숫자가 시작되는 주소값을 리턴, `-`표시가 있을 때마다 sign값에 -1을 곱해줌.
char*    check_num(char *str, int *sign)
{
    char* temp;
    int num;

    temp = str;
while(*temp)
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
    if (!radix)
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

int main(void)
{
    //check error
    printf ("%d",ft_atoi_base("10", "00"));
    printf ("\n");
    printf ("%d", ft_atoi_base("10", "0123456789+-"));
    printf ("\n");

    printf ("%d",ft_atoi_base("---1AaBv0", "0123456789ABCDEF"));
    printf ("\n");
    printf ("%d", ft_atoi_base("---14A0", "0123456789"));
    printf ("\n");
    printf ("%d", ft_atoi_base("-10c0", "poneyvif"));
    printf ("\n");
    printf ("%d", ft_atoi_base("----10000s0", "01"));
    printf ("\n");
}
