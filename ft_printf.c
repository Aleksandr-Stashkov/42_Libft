/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:05:09 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 14:47:15 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(const char key, va_list args, char *flags, int *width)
{
	if (key == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (key == 'c')
		return (print_char(va_arg(args, int), flags, width[0]));
	if (key == 's')
		return (print_string(va_arg(args, char *), flags, width));
	if (key == 'd' || key == 'i')
		return (print_int(va_arg(args, int), flags, width));
	if (key == 'u')
		return (print_unsigned(va_arg(args, unsigned int), flags, width));
	if (key == 'x' || key == 'X')
		return (print_hex(va_arg(args, unsigned int), flags, width, key
				- 'X'));
	if (key == 'p')
		return (print_pointer(va_arg(args, unsigned long), flags, width));
	return (0);
}

int	read_width(const char *format, int *width)
{
	int	i;

	i = 0;
	*width = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		*width = *width * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

int	read_precision(const char *format, va_list args, int *precision)
{
	int	i;

	i = 0;
	*precision = 0;
	if (format[i] == '*')
	{
		*precision = va_arg(args, int);
		return (2);
	}
	while (format[i] >= '0' && format[i] <= '9')
	{
		*precision = *precision * 10 + (format[i] - '0');
		i++;
	}
	return (i + 1);
}

int	conversion(const char *format, va_list args, int *printed_size)
{
	int		i;
	char	flags[3];
	int		width[2];

	intialize_flags(flags);
	width[0] = 0;
	width[1] = -1;
	i = 0;
	if (format[i] == '#' || format[i] == '-' || format[i] == '0'
		|| format[i] == '+' || format[i] == ' ')
		i += read_flag(&format[i], flags);
	if (format[i] >= '1' && format[i] <= '9')
		i += read_width(&format[i], &width[0]);
	if (format[i] == '.')
		i += read_precision(&format[i + 1], args, &width[1]);
	if (format[i] == '%' || format[i] == 'c' || format[i] == 's'
		|| format[i] == 'p' || format[i] == 'd' || format[i] == 'i'
		|| format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
	{
		*printed_size = *printed_size + convert(format[i], args, flags, width);
		return (i + 1);
	}
	else
		return (*printed_size = -1, -1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_size;
	int		i;
	int		tmp;

	if (format == NULL)
		return (-1);
	printed_size = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			tmp = conversion(&format[i + 1], args, &printed_size);
			if (tmp <= 0)
				break ;
			else
				i += tmp + 1;
		}
		else
			i += direct_print(format[i], &printed_size);
	}
	va_end(args);
	return (printed_size);
}
