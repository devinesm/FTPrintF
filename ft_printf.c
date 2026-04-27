/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:39:11 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 09:59:04 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	get_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int), 1));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *), 1));
	if (c == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long), 1));
	if (c == 'd' || c == 'i')
		return (ft_print_numbers(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int), 1));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c, 1));
	if (c == '%')
		return (ft_print_char('%', 1));
	else
		return (ft_print_char(c, 1));
}

static int	error(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			format;
	int			count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			format = get_format(s[i + 1], args);
			i++;
		}
		else
			format = ft_print_char(s[i], 1);
		if (format == -1)
			return (error(&args));
		count += format;
		i++;
	}
	va_end(args);
	return (count);
}
