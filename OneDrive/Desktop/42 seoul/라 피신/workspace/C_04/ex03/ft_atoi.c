/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:23:36 by sham              #+#    #+#             */
/*   Updated: 2021/03/06 16:51:46 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*check(char *str, int *sign)
{
	int		num;

	while (*str == "\t"
		|| *str == "\n"
		|| *str == "\v"
		|| *str == "\f"
		|| *str == "\r"
		|| *str == 32)
		*str++;
	while (*str)
	{
		if (*str == '-')
			*sign *= -1;
		if (*str >= '0' && *str <= '9')
		{
			return (str);
		}
		str++;
	}
	*sign = 0;
	return (0);
}

int		ft_atoi(char *str)
{
	char	*start_num;
	int		sign;
	int		num;

	sign = 1;
	num = 0;
	start_num = check(str, &sign);
	if (sign == 0)
		return (0);
	while (*start_num && *start_num >= '0' && *start_num <= '9')
	{
		num = 10 * num + (*start_num - '0');
		start_num++;
	}
	return (num * sign);
}
