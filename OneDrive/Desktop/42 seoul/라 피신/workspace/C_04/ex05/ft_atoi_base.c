/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:15:44 by marvin            #+#    #+#             */
/*   Updated: 2021/03/06 18:47:53 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_dup(int *dup, int i)
{
	int j;

	j = 0;
	while (j < 256)
		if (dup[j++] > 1)
			return (0);
	return (i);
}

int		check_radix(char *base)
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
		if (base[i] == '+' ||
			base[i] == '-' || base[i] <= ' ' || base[i] == 127)
			return (0);
		num = base[i];
		dup[num]++;
		i++;
	}
	return (check_dup(dup, i));
}

char		*check_num(char *str, int *sign)
{
	char	*temp;
	int		num;

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
    while (*start_num && ((*start_num >= '0' && *start_num <= '9') || (*start_num >= 'A' && *start_num <= 'F')))
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
    radix = check_radix(base);
    start_num = check_num(str, &sign);
    if (radix < 2)
        return (0);
    if (sign == 0)
        return (0);
    if (radix == 16)
        return (write_num_sixteen(start_num, radix) * sign);
    else
        return (write_num(start_num, radix) * sign);
}
