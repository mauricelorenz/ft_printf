/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:45:55 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/29 19:17:27 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static int	handle_format(const char c, va_list args);
static int	handle_escape(const char c);

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (handle_format(*(str + 1), args))
				return (1);
			str = str + 2;
		}
		else if (*str == '\\')
		{
			if (handle_escape(*(str + 1)))
				return (1);
			str = str + 2;
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
	return (0);
}

static int	handle_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 0);
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1), 0);
	// else if (c == 'p')
	// // puthex adress value
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1), 0);
	// else if (c == 'u')
	// // putunbr
	// else if (c == 'x')
	// // puthex lower
	// else if (c == 'X')
	// // toupper(puthex lower)
	else if (c == '%')
		return (ft_putchar_fd('%', 1), 0);
	return (1);
}

static int	handle_escape(const char c)
{
	if (c == 'a')
		return (ft_putchar_fd('\a', 1), 0);
	else if (c == 'b')
		return (ft_putchar_fd('\b', 1), 0);
	else if (c == 't')
		return (ft_putchar_fd('\t', 1), 0);
	else if (c == 'n')
		return (ft_putchar_fd('\n', 1), 0);
	else if (c == 'v')
		return (ft_putchar_fd('\v', 1), 0);
	else if (c == 'f')
		return (ft_putchar_fd('\f', 1), 0);
	else if (c == 'r')
		return (ft_putchar_fd('\r', 1), 0);
	return (1);
}
