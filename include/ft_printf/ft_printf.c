/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:01:21 by nuferron          #+#    #+#             */
/*   Updated: 2023/05/14 00:01:23 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	eval_printf_variable2(char c, va_list args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_string(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (print_num(va_arg(args, int)));
	if (c == 'p')
		return (print_pointer(va_arg(args, unsigned long long)));
	if (c == 'u')
		return (print_unsigned_num(va_arg(args, unsigned int)));
	if (c == 'x')
		return (print_hex_min(va_arg(args, unsigned int)));
	if (c == 'X')
		return (print_hex_cap(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg_ptr;
	int		i;
	int		wr_len;
	int		aux;

	i = 0;
	wr_len = 0;
	va_start(arg_ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			aux = eval_printf_variable2(format[i], arg_ptr);
		}
		else
			aux = write(1, &format[i], 1);
		wr_len += aux;
		if (aux == -1)
			return (-1);
		i++;
	}
	va_end(arg_ptr);
	return (wr_len);
}
