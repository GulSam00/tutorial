/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:11:06 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 20:47:35 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_len_str(int size, char **strs)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			len++;
			j++;
		}
		j = 0;
		i++;
	}
	return (len);
}

int		get_len_sep(char *sep)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (sep[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	write_str(char **strs, char *sep, char *total_str, int total_len)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (len < total_len - 1)
	{
		j = 0;
		while (strs[i][j] && len < total_len - 1)
		{
			total_str[len] = strs[i][j];
			len++;
			j++;
		}
		j = 0;
		while (sep[j] && len < total_len - 1)
		{
			total_str[len] = sep[j];
			len++;
			j++;
		}
		i++;
	}
	total_str[len] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		str_len;
	int		sep_len;
	int		total_len;
	char	*total_str;

	if (size == 0)
		return ((char*)malloc(sizeof(char)));
	sep_len = get_len_sep(sep);
	str_len = get_len_str(size, strs);
	total_len = str_len + sep_len * (size - 1) + 1;
	total_str = (char*)malloc(sizeof(char) * total_len);
	if (total_str == NULL)
		return (0);
	write_str(strs, sep, total_str, total_len);
	return (total_str);
}
