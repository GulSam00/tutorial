/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle_custom.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:29:07 by marvin            #+#    #+#             */
/*   Updated: 2021/03/07 23:38:09 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define N 10

void	complite(int *line)
{
	int	i;

	i = 0;
	while (i < N)
	{
		write(1, &line[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		diagonal_check(int com_pos, int cur_pos)
{
	if (com_pos < cur_pos)
		return (com_pos - cur_pos);
	else
		return (cur_pos - com_pos);
}

int		promising(int k, int i, int *line)
{
	int x;

	x = 0;
	while (x < k)
	{
		if (line[x] == i || diagonal_check(line[x], i) == x - k)
			return (0);
		x++;
	}
	return (1);
}

void	queen(int k, int *count, int *line)
{
	int	i;

	printf ("check");
	i = 0;
	if (k == N)
	{
	printf ("k == N");
		count++;
		complite(line);
		return ;
	}
	while (i < N)
	{
		if (promising(k, i, line))
		{
			line[k] = i;
			queen(k + 1, count, line);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int sum;
	int line[N];

	sum = 0;
	while (sum < N)
		line[sum] = 0;
	sum = 0;
	printf ("check");
	queen(0, &sum, line);
	return (sum);
}

int main(void)
{
	printf ("%d\n", ft_ten_queens_puzzle());
}
