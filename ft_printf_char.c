/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:15:52 by astashko          #+#    #+#             */
/*   Updated: 2025/01/24 15:04:09 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, char *flags, int width)
{
	int	output_length;

	if (width > 1)
		output_length = width;
	else
		output_length = 1;
	if (is_flag('-', flags))
		ft_putchar_fd(c, 1);
	width--;
	while (width > 0)
	{
		ft_putchar_fd(' ', 1);
		width--;
	}
	if (!is_flag('-', flags))
		ft_putchar_fd(c, 1);
	return (output_length);
}

int	direct_print(char c, int *printed_size)
{
	ft_putchar_fd(c, 1);
	*printed_size = *printed_size + 1;
	return (1);
}
