/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:45:55 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 18:11:28 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char c, va_list *args);

int	ft_printf(const char *str, ...)
{
	int		printed_chars;
	int		chars_total;
	va_list	args;

	printed_chars = 0;
	chars_total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			printed_chars = handle_format(*(str + 1), &args);
			if (printed_chars == -1)
				return (va_end(args), chars_total);
			str = str + 2;
		}
		else
		{
			printed_chars = ft_putchar_count(*str);
			str++;
		}
		chars_total += printed_chars;
	}
	return (va_end(args), chars_total);
}

static int	handle_format(const char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr_count(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putptr_count(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putunbr_count(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_count(va_arg(*args, int), 0));
	else if (c == 'X')
		return (ft_puthex_count(va_arg(*args, int), 1));
	else if (c == '%')
		return (ft_putchar_count('%'));
	return (-1);
}
