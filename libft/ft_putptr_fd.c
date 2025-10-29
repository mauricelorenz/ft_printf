/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 23:20:35 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 00:47:38 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putptr_hex(unsigned long n, int fd);

void	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	write(fd, "0x", 2);
	putptr_hex(n, fd);
}

static void	putptr_hex(unsigned long n, int fd)
{
	if (n >= 16)
		putptr_hex(n / 16, fd);
	if ((n % 16) >= 10)
		n = n % 16 - 10 + 'a';
	else
		n = n % 16 + '0';
	write(fd, &n, 1);
}
