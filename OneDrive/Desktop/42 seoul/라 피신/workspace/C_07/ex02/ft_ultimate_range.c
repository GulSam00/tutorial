/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:47 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 20:45:00 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int i;
	int *temp;

	len = 0;
	i = 0;
	if (min >= max)
		return (0);
	while (min + len < max)
	{
		len++;
	}
	*range = (int*)malloc(sizeof(int) * len);
	if (range == NULL)
		return (0);
	temp = *range;
	while (i < len)
	{
		*temp = min + i;
		i++;
		temp++;
	}
	return (len);
}
