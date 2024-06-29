/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:46:15 by musozer           #+#    #+#             */
/*   Updated: 2024/02/25 15:46:47 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = (long)n;
	if (number == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number *= -1;
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putnbr_fd(number % 10, fd);
	}
	else
		ft_putchar_fd(number + 48, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
