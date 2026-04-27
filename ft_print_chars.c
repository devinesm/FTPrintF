/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 08:35:42 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 08:43:53 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(char c, int fd)
{
	if (write(fd, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_print_str(char *s, int fd)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		if (ft_print_char(s[i], fd) != 1)
			return (-1);
		i++;
	}
	return (i);
}
