/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_with_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:02:32 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 22:05:21 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char *p_str;
	char *p_find;

	p_str = str;
	p_find = to_find;
	
	if (*p_find == '\0')
		return "\0";
	while (*str)
	{
		while (*p_str++ == *p_find++)
			if (*p_find == '\0')
				return (str);
		str++;
		p_str = str;
		p_find = to_find;
	}
	return (0);
}

int		main(void)
{
char *p;
p = ft_strstr("strdfg","rdas");
printf ("%s",p);
}
