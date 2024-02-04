/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:12:30 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/04 04:16:53 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

void	ft_handle_c(va_list args, int *count_ptr, const char ptr);
void	ft_handle_str(va_list args, int *count_ptr);
void	ft_handle_ptr(va_list args, int *count_ptr);
void	ft_handle_diu(va_list args, int *count_ptr, const char ptr);
void	ft_handle_x(va_list args, int *count_ptr, const char ptr);
int		ft_printf(const char *ptr, ...);
size_t	ft_strlen(const char *s);
void	ft_puthex_upper(unsigned long ul, int *count_ptr);
void	ft_puthex_lower(unsigned long ul, int *count_ptr);
void	ft_putnbr_count(int n, int *count_ptr);
void	ft_putunsigned_count(unsigned int n, int *count_ptr);
void	ft_putchar_count(char c, int *count_ptr);
void	ft_putstr_count(char *s, int *count_ptr);
#endif
