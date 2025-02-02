/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:33:11 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 15:02:00 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrote_prefix(unsigned int n, char *flags, int case_dif)
{
	if (n != 0 && is_flag('#', flags))
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('X' + case_dif, 1);
		return (2);
	}
	return (0);
}

int	measured_output_hex(unsigned int n, char *flags, int width, int n_length)
{
	if (n != 0 && is_flag('#', flags))
	{
		if (width > n_length + 2)
			return (width);
		else
			return (n_length + 2);
	}
	else
	{
		if (width > n_length)
			return (width);
		else
			return (n_length);
	}
}

int	width_corrected(int width, int n_length, char *flags)
{
	if (is_flag('#', flags))
		return (width - n_length - 2);
	else
		return (width - n_length);
}

int	print_hex(unsigned int n, char *flags, int *width, int case_dif)
{
	int	output_length;
	int	n_length[2];

	hex_length(n_length, n, width[1]);
	output_length = measured_output_hex(n, flags, width[0], n_length[0]);
	if (is_flag('-', flags))
	{
		width[0] -= wrote_prefix(n, flags, case_dif) + n_length[0];
		write_hex((unsigned long)n, n_length[0], n_length[1], case_dif);
		fill_output(' ', width[0]);
	}
	else if (width[1] < 0 && is_flag('0', flags))
	{
		width[0] -= wrote_prefix(n, flags, case_dif) + n_length[0];
		fill_output('0', width[0]);
		write_hex((unsigned long)n, n_length[0], n_length[1], case_dif);
	}
	else
	{
		fill_output(' ', width_corrected(width[0], n_length[0], flags));
		wrote_prefix(n, flags, case_dif);
		write_hex((unsigned long)n, n_length[0], n_length[1], case_dif);
	}
	return (output_length);
}
