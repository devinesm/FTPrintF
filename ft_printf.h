/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipinto-m <ipinto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:40:34 by ipinto-m          #+#    #+#             */
/*   Updated: 2026/04/27 09:59:37 by ipinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_print_char(char c, int fd);
int	ft_print_str(char *s, int fd);
int	ft_print_numbers(int number, int fd);
int	ft_print_unsigned(unsigned int number, int fd);
int	ft_print_hex(unsigned long number, char format, int fd);
int	ft_print_pointer(unsigned long number, int fd);

#endif
