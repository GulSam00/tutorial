/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:25:44 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 20:41:22 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int len;
	int i;
	int *p;

	len = 0;
	i = 0;
	if (min >= max)
		return (0);
	while (min + len < max)
	{
		len++;
	}
	p = (int*)malloc(sizeof(int) * len);
	if (p == NULL)
		return (0);
	while (i < len)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}
