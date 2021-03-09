/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:49:53 by sham              #+#    #+#             */
/*   Updated: 2021/02/21 22:11:37 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int idx_alpha;

	idx_alpha = 97;
	while (idx_alpha < 123)
	{
		write(1, &idx_alpha, 1);
		idx_alpha++;
	}
}
