/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:26:48 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 18:13:53 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_count(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putunbr_count(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
	return (i + 1);
}
