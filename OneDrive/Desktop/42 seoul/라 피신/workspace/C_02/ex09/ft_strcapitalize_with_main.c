/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_with_main.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:49:23 by sham              #+#    #+#             */
/*   Updated: 2021/02/25 11:03:54 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_alpha_char(char c);
int		check_num_char(char c);
void	trans_alpha(char *c, int f_word);

char	*ft_strcapitalize(char *str)
{
	int i;
	int f_word;

	i = 0;
	f_word = 1;
	while (str[i] != '\0')
	{
		if (check_alpha_char(str[i]) || check_num_char(str[i]))
		{
			trans_alpha(&str[i], f_word);
			f_word = 0;
			i++;
		}
		else
		{
			f_word = 1;
			i++;
		}
	}
	return (str);
}

int		check_alpha_char(char c)
{
	if ('A' <= c && c <= 'Z')
		return (2);
	else if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}

int		check_num_char(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

void	trans_alpha(char *c, int f_word)
{
	int check;

	check = (check_alpha_char(*c));
	if (check > 0)
	{
		if (f_word && check == 2)
			return ;
		else if (f_word && check == 1)
			*c -= 32;
		else if (check == 2)
			*c += 32;
	}
}

int main(void)
{
	char *p;
	char str[]="he l sdj -fsd = f=df=f-f-fs F adFAS FCXs sfF";
	ft_strcapitalize(str);
	printf ("%s", str);
}
