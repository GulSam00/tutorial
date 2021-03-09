/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sham <sham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:46:25 by sham              #+#    #+#             */
/*   Updated: 2021/03/08 13:03:24 by sham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int len_dest;
	unsigned int len_src;
	unsigned int i;

	len_dest = 0;
	len_src = 0;
	i = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	while (src[i] && i + len_dest + 1 < size)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (len_dest < size)
	{
		dest[len_dest + i] = '\0';
		return (len_src + len_dest);
	}
	return (len_src + size);
}
