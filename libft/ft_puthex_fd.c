/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:27:32 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 00:31:51 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned int n, int fd, int upper)
{
	if (n >= 16)
		ft_puthex_fd(n / 16, fd, upper);
	if ((n % 16) >= 10)
	{
		if (upper)
			n = n % 16 - 10 + 'A';
		else
			n = n % 16 - 10 + 'a';
	}
	else
		n = n % 16 + '0';
	write(fd, &n, 1);
}
