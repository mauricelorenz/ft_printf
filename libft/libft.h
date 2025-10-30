/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:59:57 by mlorenz           #+#    #+#             */
/*   Updated: 2025/10/30 15:26:10 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar_count(char c);
int		ft_puthex_count(unsigned int n, int upper);
int		ft_putnbr_count(int n);
int		ft_putptr_count(void *ptr);
int		ft_putstr_count(char *s);
int		ft_putunbr_count(unsigned int n);
#endif