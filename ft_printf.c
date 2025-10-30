/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:45:55 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 14:19:31 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	handle_format(const char c, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (handle_format(*(str + 1), args))
				return (va_end(args), 1);
			str = str + 2;
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
	return (va_end(args), 0);
}

static int	handle_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 0);
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1), 0);
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1), 0);
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1), 0);
	else if (c == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1), 0);
	else if (c == 'x')
		return (ft_puthex_fd(va_arg(args, int), 1, 0), 0);
	else if (c == 'X')
		return (ft_puthex_fd(va_arg(args, int), 1, 1), 0);
	else if (c == '%')
		return (ft_putchar_fd('%', 1), 0);
	return (1);
}
