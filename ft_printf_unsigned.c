/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:15:39 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 13:36:38 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_length(int *n_length, unsigned int n, int precision)
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

void	write_unsigned(unsigned int n, int n_length, int fill_0_size)
{
	unsigned int	tmp;
	char			output;

	if (n_length == 0)
		return ;
	if (fill_0_size > 0)
		fill_output('0', fill_0_size);
	if (n_length > 1)
		write_unsigned(n / 10, n_length - fill_0_size - 1, 0);
	tmp = n % 10;
	output = tmp + '0';
	write(1, &output, 1);
	return ;
}

int	print_unsigned(unsigned int n, char *flags, int *width)
{
	int	output_length;
	int	n_length[2];

	unsigned_length(n_length, n, width[1]);
	if (width[0] > n_length[0])
		output_length = width[0];
	else
		output_length = n_length[0];
	if (is_flag('-', flags))
	{
		write_unsigned(n, n_length[0], n_length[1]);
		width[0] -= n_length[0];
		fill_output(' ', width[0]);
	}
	else
	{
		width[0] -= n_length[0];
		if (width[1] < 0 && is_flag('0', flags))
			fill_output('0', width[0]);
		else
			fill_output(' ', width[0]);
		write_unsigned(n, n_length[0], n_length[1]);
	}
	return (output_length);
}
