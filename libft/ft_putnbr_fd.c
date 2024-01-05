/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:25:23 by sozdamar          #+#    #+#             */
/*   Updated: 2023/10/09 21:25:24 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	num_writer(int num, int fd)
{
	char	c;

	c = num + '0';
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write (fd, "-2147483648", 11);
	else if (nb < 0)
	{
		write (fd, "-", 1);
		nb *= -1;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		num_writer(nb, fd);
}
