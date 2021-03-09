/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:16:30 by sham              #+#    #+#             */
/*   Updated: 2021/02/21 22:23:42 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int idx_alpha;

	idx_alpha = 122;
	while (idx_alpha > 96)
	{
		write(1, &idx_alpha, 1);
		idx_alpha--;
	}
}
