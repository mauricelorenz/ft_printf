/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:27:32 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 16:06:25 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_count(unsigned int n, int upper)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_puthex_count(n / 16, upper);
	if ((n % 16) >= 10)
	{
		if (upper)
			n = n % 16 - 10 + 'A';
		else
			n = n % 16 - 10 + 'a';
	}
	else
		n = n % 16 + '0';
	write(1, &n, 1);
	return (i + 1);
}
