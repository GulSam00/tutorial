/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:29:07 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 14:05:14 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define N 10

int		g_line[N];
int		g_count;

void	complite(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < N)
	{
		c = g_line[i] + '0';
		write(1, &c, 1);
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

int		promising(int k, int i)
{
	int x;

	x = 0;
	while (x < k)
	{
		if (g_line[x] == i || diagonal_check(g_line[x], i) == x - k)
			return (0);
		x++;
	}
	return (1);
}

void	queen(int k)
{
	int	i;

	i = 0;
	if (k == N)
	{
		g_count++;
		complite();
		return ;
	}
	while (i < N)
	{
		if (promising(k, i))
		{
			g_line[k] = i;
			queen(k + 1);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	queen(0);
	return (g_count);
}
