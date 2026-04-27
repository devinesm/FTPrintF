/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 08:49:17 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 10:02:04 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_numbers(int number, int fd)
{
	long		nb;
	int			len;
	int			temp;

	len = 0;
	nb = number;
	if (nb < 0)
	{
		temp = ft_print_char('-', fd);
		if (temp == -1)
			return (-1);
		len += temp;
		nb = -nb;
	}
	if (nb >= 10)
	{
		temp = ft_print_numbers((nb / 10), fd);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_print_char((nb % 10) + '0', fd);
	if (temp == -1)
		return (-1);
	return (temp);
}

int	ft_print_unsigned(unsigned int number, int fd)
{
	int	len;
	int	temp;

	len = 0;
	if (number >= 10)
	{
		temp = ft_print_unsigned(number / 10, fd);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_print_char((number % 10) + '0', 1);
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
