/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:31:36 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 20:40:11 by sham             ###   ########.fr       */
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

int		find_prime(int nb)
{
	int max_sqrt;
	int j;

	max_sqrt = find_sqrt(nb);
	j = 2;
	while (j <= max_sqrt)
	{
		if (nb % j == 0)
			return (0);
		j++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!find_prime(nb))
		nb++;
	return (nb);
}
