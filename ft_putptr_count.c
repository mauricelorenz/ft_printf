/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 23:20:35 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 18:13:47 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putptr_hex(unsigned long n);

int	ft_putptr_count(void *ptr)
{
	int				i;
	unsigned long	n;

	i = 0;
	n = (unsigned long)ptr;
	if (n == 0)
		return (write(1, "(nil)", 5), 5);
	write(1, "0x", 2);
	i += 2;
	i += putptr_hex(n);
	return (i);
}

static int	putptr_hex(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += putptr_hex(n / 16);
	if ((n % 16) >= 10)
		n = n % 16 - 10 + 'a';
	else
		n = n % 16 + '0';
	write(1, &n, 1);
	return (i + 1);
}
