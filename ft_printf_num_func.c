/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:53:01 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 14:46:16 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_length(int *n_length, int n, int precision)
{
	int	length;

	length = 1;
	n_length[1] = 0;
	if (n == 0 && precision == 0)
	{
		n_length[0] = 0;
		return ;
	}
	while (n / 10 != 0)
	{
		length++;
		n /= 10;
	}
	if (precision > length)
	{
		n_length[1] = precision - length;
		length = precision;
	}
	n_length[0] = length;
	return ;
}

void	hex_length(int *n_length, unsigned int n, int precision)
{
	int	length;

	length = 1;
	n_length[1] = 0;
	if (n == 0 && precision == 0)
	{
		n_length[0] = 0;
		return ;
	}
	while (n / 16 != 0)
	{
		length++;
		n /= 16;
	}
	if (precision > length)
	{
		n_length[1] = precision - length;
		length = precision;
	}
	n_length[0] = length;
	return ;
}

void	fill_output(char symbol, int width)
{
	while (width > 0)
	{
		ft_putchar_fd(symbol, 1);
		width--;
	}
}

void	write_number(int n, int n_length, int fill_0_size)
{
	int		tmp;
	char	output;

	if (n_length == 0)
		return ;
	if (fill_0_size > 0)
		fill_output('0', fill_0_size);
	if (n_length > 1)
		write_number(n / 10, n_length - fill_0_size - 1, 0);
	tmp = n % 10;
	if (tmp < 0)
		output = (-tmp) + '0';
	else
		output = tmp + '0';
	write(1, &output, 1);
	return ;
}

void	write_hex(unsigned long n, int hex_length, int fill_0_size,
		int case_dif)
{
	char			output;
	unsigned long	tmp;

	if (hex_length == 0)
		return ;
	if (fill_0_size > 0)
		fill_output('0', fill_0_size);
	if (hex_length > 1)
		write_hex(n / 16, hex_length - fill_0_size - 1, 0, case_dif);
	tmp = n % 16;
	if (tmp < 10)
		output = tmp + '0';
	else
		output = 'A' + case_dif + tmp - 10;
	write(1, &output, 1);
	return ;
}
