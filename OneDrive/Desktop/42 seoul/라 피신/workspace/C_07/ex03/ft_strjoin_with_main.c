/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:11:06 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 17:14:25 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     get_len_str(int size, char **strs)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = 0;
    while (i < size)
    {
        printf ("going to get len of strs[%d] - [%s]\n", i, strs[i]);
        while(strs[i][j])
        {
            printf ("now char is %c\n", strs[i][j]);
            len++;
            j++;
        }
        printf("now len is : %d\n", len);
        j = 0;
        i++;
    }   
return (len);
}

int     get_len_sep(char *sep)
{
    int i;
    int len;

    i = 0;
    len = 0;
    printf ("going to get len of sep[%s]\n", sep);
    while(sep[i])
    {
        printf ("now char is %c\n", sep[i]);
        len++;
        i++;
    }
    return (len);
}

void    write_str(char **strs, char *sep, char *total_str, int total_len)
{
    int i;
    int j;
    int len;

    i = 0;
    len = 0;
    printf ("going to put length is %d\n", total_len);
    // ������ �ΰ��� �� ��ŭ ä��Բ� ���ǹ� �ۼ�
    while (len < total_len - 1)
    {
        j = 0;
        printf ("going to put strs[%s]\n",strs[i]);
        while(strs[i][j] && len < total_len - 1)
        {
            printf ("now char is %c\n", strs[i][j]);
            total_str[len] = strs[i][j];
            len++;
            j++;
        }
        printf ("going to put sep[%s]\n",sep);
        j = 0;
        while(sep[j] && len < total_len - 1)
        {
            printf ("now char is %c\n",sep[j]);
            total_str[len] = sep[j];
            len++;
            j++;
        }
        i++;
    }
    total_str[len] = 0;
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
    // **strs�� �迭 ������ (*p)[i]�� �ƴ� ������ �迭! *p[i]
    int str_len;
    int sep_len;
    int total_len;
    char *total_str;

    if (size == 0)
        return (0);
    sep_len = get_len_sep(sep); 
    // �������� ����
    str_len = get_len_str(size, strs); 
    // ���ڿ��� ����
    total_len = str_len + sep_len * (size - 1) + 1;
    // total_len���� NULL���� ������ ���̸� �����ش�.
    total_str = (char*)malloc(sizeof(char) * total_len);
    printf ("sep_len is %d\n",sep_len);
    printf ("str_len is %d\n",str_len);
    printf ("total_str is %d\n",total_len);
    write_str(strs, sep, total_str, total_len);

    return (total_str);
    // total_len -> strs�� �� ���� | size -> size - 1��ŭ sep�� �� ���� + ������ NULL
    // sep�� ���� �ϳ��� �ƴϴ�!
}

int     main(void)
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