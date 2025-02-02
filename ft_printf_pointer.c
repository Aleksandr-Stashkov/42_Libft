/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:38:32 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 14:49:07 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrote_ptr_prefix(char *flags)
{
	int	printed_length;

	printed_length = 2;
	if (is_flag('+', flags))
	{
		ft_putchar_fd('+', 1);
		printed_length++;
	}
	if (is_flag(' ', flags))
	{
		ft_putchar_fd(' ', 1);
		printed_length++;
	}
	ft_putstr_fd("0x", 1);
	return (printed_length);
}

int	measured_output_ptr(char *flags, int width, int ptr_length)
{
	if (width > ptr_length + 2)
		return (width);
	else
	{
		if (is_flag('+', flags) || is_flag(' ', flags))
			return (ptr_length + 3);
		else
			return (ptr_length + 2);
	}
}

int	address_length(unsigned long n)
{
	int	length;

	length = 1;
	while (n / 16 != 0)
	{
		length++;
		n /= 16;
	}
	return (length);
}

void	basic_sequence_ptr(unsigned long ptr, char *flags, int width,
		int ptr_length)
{
	if (is_flag('+', flags) || is_flag(' ', flags))
		width -= ptr_length + 3;
	else
		width -= ptr_length + 2;
	fill_output(' ', width);
	wrote_ptr_prefix(flags);
	write_hex(ptr, ptr_length, 0, 'a' - 'A');
	return ;
}

int	print_pointer(unsigned long ptr, char *flags, int *width)
{
	int	output_length;
	int	ptr_length;

	if (ptr == 0)
	{
		width[1] = -1;
		return (print_string("(nil)", flags, width));
	}
	ptr_length = address_length(ptr);
	output_length = measured_output_ptr(flags, width[0], ptr_length);
	if (is_flag('-', flags))
	{
		width[0] -= wrote_ptr_prefix(flags) + ptr_length;
		write_hex(ptr, ptr_length, 0, 'a' - 'A');
		fill_output(' ', width[0]);
	}
	else if (is_flag('0', flags))
	{
		width[0] -= wrote_ptr_prefix(flags) + ptr_length;
		fill_output('0', width[0]);
		write_hex(ptr, ptr_length, 0, 'a' - 'A');
	}
	else
		basic_sequence_ptr(ptr, flags, width[0], ptr_length);
	return (output_length);
}
