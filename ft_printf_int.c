/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:59:42 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 12:48:30 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrote_sign(int n, char *flags)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		return (1);
	}
	if (is_flag('+', flags))
	{
		ft_putchar_fd('+', 1);
		return (1);
	}
	if (is_flag(' ', flags))
	{
		ft_putchar_fd(' ', 1);
		return (1);
	}
	return (0);
}

int	measured_output(int n, char *flags, int width, int n_length)
{
	if (width > n_length)
		return (width);
	else
	{
		if (n < 0 || is_flag('+', flags) || is_flag(' ', flags))
			return (n_length + 1);
		else
			return (n_length);
	}
}

void	basic_sequence(int n, char *flags, int *width, int *n_length)
{
	if (n < 0 || is_flag('+', flags) || is_flag(' ', flags))
		width[0] -= n_length[0] + 1;
	else
		width[0] -= n_length[0];
	fill_output(' ', width[0]);
	wrote_sign(n, flags);
	write_number(n, n_length[0], n_length[1]);
	return ;
}

int	print_int(int n, char *flags, int *width)
{
	int	output_length;
	int	n_length[2];

	number_length(n_length, n, width[1]);
	output_length = measured_output(n, flags, width[0], n_length[0]);
	if (is_flag('-', flags))
	{
		width[0] -= wrote_sign(n, flags) + n_length[0];
		write_number(n, n_length[0], n_length[1]);
		fill_output(' ', width[0]);
	}
	else if (width[1] < 0 && is_flag('0', flags))
	{
		width[0] -= wrote_sign(n, flags) + n_length[0];
		fill_output('0', width[0]);
		write_number(n, n_length[0], n_length[1]);
	}
	else
		basic_sequence(n, flags, width, n_length);
	return (output_length);
}
