/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:24:09 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/14 22:29:24 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
int ft_printf(const char *ptr, ...);
size_t ft_strlen(const char *s);
void hex_upper(unsigned long ul, int *count_ptr);
void hex_lower(unsigned long ul, int *count_ptr);
void ft_putnbr_count(int n, int *count_ptr);
void ft_putunsigned_count(long long n, int *count_ptr);
void ft_putchar_fd(char c, int fd, int *count_ptr);
void ft_putstr_fd(char *s, int fd, int *count_ptr);

#endif