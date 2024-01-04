/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:50:40 by sozdamar          #+#    #+#             */
/*   Updated: 2023/10/09 20:50:41 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (n > i)
	{
		if (*(unsigned char *)(s1 + i) == (unsigned char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}
