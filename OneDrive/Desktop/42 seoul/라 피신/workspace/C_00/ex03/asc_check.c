/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:45:33 by sham              #+#    #+#             */
/*   Updated: 2021/02/21 23:15:22 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int num;
	char asc;
	char num_asc;

	num = 97;
	asc = 'a';
	num_asc = 97;

	printf ("'a' to digits : %d \n", asc);
	printf ("97 to char : %c \n", num);
	printf ("97(char) to digits : %d \n", num_asc);
	printf ("97(char) to char : %c \n", num_asc);
	printf ("size of varialbe %c", 10);
	
	printf ("%d %d %d \n", sizeof('\0'), sizeof('a'), sizeof('\n'));
}
