/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:02:32 by sham              #+#    #+#             */
/*   Updated: 2021/03/08 13:02:58 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *p_str;
	char *p_find;

	p_str = str;
	p_find = to_find;
	if (*p_find == '\0')
		return (str);
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
