/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:31:39 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 16:46:39 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_count(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}
