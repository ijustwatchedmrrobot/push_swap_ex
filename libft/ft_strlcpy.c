/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:16:12 by sozdamar          #+#    #+#             */
/*   Updated: 2023/10/09 18:31:04 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size > 0)
	{
		while (*(src + count) && count < (size - 1))
		{
			*(dest + count) = *(src + count);
			count++;
		}
		*(dest + count) = '\0';
	}
	while (*(src + count))
		count++;
	return (count);
}
