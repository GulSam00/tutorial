/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyeo <seungyeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:43:12 by seungyeo          #+#    #+#             */
/*   Updated: 2021/02/20 20:52:30 by mijkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	check(int x, int y, int last_c, int last_r);
void	first_row(int x, int last_c);
void	last_row(int x, int last_c);
void	middle_row(int x, int last_c);

void	rush(int last_c, int last_r)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < last_r)
	{
		while (x < last_c)
		{
			check(x, y, last_c, last_r);
			x++;
		}
		x = 0;
		y++;
		ft_putchar('\n');
	}
}

void	check(int x, int y, int last_c, int last_r)
{
	if (y < 1)
	{
		first_row(x, last_c);
	}
	else if (y == last_r - 1)
	{
		last_row(x, last_c);
	}
	else
	{
		middle_row(x, last_c);
	}
}

void	first_row(int x, int last_c)
{
	if (x == 0)
	{
		ft_putchar('/');
	}
	else if (x == last_c - 1)
	{
		ft_putchar('\\');
	}
	else
	{
		ft_putchar('*');
	}
}

void	last_row(int x, int last_c)
{
	if (x == 0)
	{
		ft_putchar('\\');
	}
	else if (x == (last_c - 1))
	{
		ft_putchar('/');
	}
	else
	{
		ft_putchar('*');
	}
}

void	middle_row(int x, int last_c)
{
	if (x != 0 && x != last_c - 1)
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('*');
	}
}
