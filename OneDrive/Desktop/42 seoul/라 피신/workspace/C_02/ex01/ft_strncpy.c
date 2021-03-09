/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:09:15 by sham              #+#    #+#             */
/*   Updated: 2021/03/06 10:26:23 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *temp;

	temp = dest;
	while (n && *src)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (temp);
}