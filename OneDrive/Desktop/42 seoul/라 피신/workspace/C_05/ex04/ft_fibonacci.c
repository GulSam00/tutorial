/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:21:11 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 15:51:01 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sum(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (sum(index - 1) + sum(index - 2));
}

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 1)
		return (1);
	else
		return (sum(index));
}
