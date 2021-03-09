/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:41:22 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 13:59:34 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		check(char *arg1, char *arg2)
{
	while (*arg1 && *arg2)
	{
		printf ("%c - %c = %d\n", *arg1, *arg2, *arg1 - *arg2);
		if (*arg1 != *arg2)
			return (*arg1 - *arg2);
		arg1++;
		arg2++;
	}
	return (0);
}

void	sort(int argc, char *argv[])
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (j < argc - i)
		{
			if (check(argv[j], argv[j + 1]) > 0)
			{
				printf("%s > %s\n", argv[j], argv[j + 1]);
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	sort(argc, argv);
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i]++, 1);
			//argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
