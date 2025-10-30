/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:26:06 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 18:11:18 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_count(char c);
int		ft_puthex_count(unsigned int n, int upper);
int		ft_putnbr_count(int n);
int		ft_putptr_count(void *ptr);
int		ft_putstr_count(char *s);
int		ft_putunbr_count(unsigned int n);
#endif