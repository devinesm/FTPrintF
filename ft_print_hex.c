/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:10:55 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 09:29:30 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex(unsigned long number, char format, int fd)
{
	char		*base;
	int			len;
	int			temp;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (number >= 16)
	{
		temp = ft_print_hex(number / 16, format, fd);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_print_char(base[number % 16], fd);
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}

int	ft_print_pointer(unsigned long ptr, int fd)
{
	int	len;
	int	temp;

	len = 0;
	if (!ptr)
		return (ft_print_str("(nil)", fd));
	temp = ft_print_str("0x", fd);
	if (temp == -1)
		return (-1);
	len += temp;
	temp = ft_print_hex(ptr, 'x', fd);
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
