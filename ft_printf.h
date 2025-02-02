/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:27:33 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 16:08:10 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	intialize_flags(char *flags);
int		read_flag(const char *format, char *flags);
int		is_flag(char flag, char *flags);
int		direct_print(char c, int *printed_size);
int		print_char(char c, char *flags, int width);
int		print_string(char *str, char *flags, int *width);
int		print_int(int number, char *flags, int *width);
int		print_unsigned(unsigned int n, char *flags, int *width);
int		print_hex(unsigned int n, char *flags, int *width, int case_dif);
int		print_pointer(unsigned long ptr, char *flags, int *width);
void	number_length(int *n_length, int n, int precision);
void	hex_length(int *n_length, unsigned int n, int precision);
void	fill_output(char symbol, int width);
void	write_number(int n, int n_length, int fill_0_size);
void	write_hex(unsigned long n, int hex_length, int fill_0_size,
			int case_dif);

#endif