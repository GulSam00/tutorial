/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:24:31 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 20:40:01 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_sqrt(int nb)
{
	long long i;

	i = 1;
	while (1)
	{
		if (i * i > nb)
			return (i - 1);
		else if (i * i == nb)
			return (i);
		i++;
	}
}

int		ft_is_prime(int nb)
{
	int max_sqrt;
	int i;

	max_sqrt = find_sqrt(nb);
	i = 2;
	if (nb < 2)
		return (0);
	while (i <= max_sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
