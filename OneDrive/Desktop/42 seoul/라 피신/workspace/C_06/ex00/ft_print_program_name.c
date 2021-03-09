/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:17:12 by marvin            #+#    #+#             */
/*   Updated: 2021/03/07 23:47:21 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	argc = 0;
	while (*argv[argc])
	{
		write(1, argv[argc], 1);
		argv[argc]++;
	}
	write(1, "\n", 1);
	return (0);
}
