/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:25:23 by sozdamar          #+#    #+#             */
/*   Updated: 2023/10/09 21:25:24 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!res)
		return (NULL);
	while (*(s + i))
	{
		*(res + i) = f(i, *(s + i));
		i++;
	}
	*(res + i) = '\0';
	return (res);
}
