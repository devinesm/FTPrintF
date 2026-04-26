/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:39:11 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/26 14:11:59 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	get_format(char c, va_list args)
{

}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	int	format;

	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			format = get_format(s[i + 1], args);
		i++;
	}
	return (i);
}
