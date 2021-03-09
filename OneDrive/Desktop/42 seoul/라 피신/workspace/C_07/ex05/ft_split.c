/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:07:44 by marvin            #+#    #+#             */
/*   Updated: 2021/03/08 20:57:15 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		check_str(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
		str++;
	}
	return (count);
}

void	put_div_str(char *arr, char *start_add, int word_len)
{
	int i;

	i = 0;
	while (i < word_len)
	{
		arr[i] = start_add[i];
		i++;
	}
	arr[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		arr_index;
	char	*start_add;
	int		word_len;

	arr = (char **)malloc(sizeof(char *) * check_str(str, charset) + 1);
	arr_index = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			word_len = 0;
			start_add = str;
			while (*str && !is_charset(*str, charset))
			{
				str++;
				word_len++;
			}
			arr[arr_index] = (char *)malloc(word_len + 1);
			put_div_str(arr[arr_index++], start_add, word_len);
		}
		str++;
	}
	return (arr);
}

