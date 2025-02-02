/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:14 by astashko          #+#    #+#             */
/*   Updated: 2025/01/24 16:16:11 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_flag(char flag, char *flags)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (flags[i] == flag)
			return (1);
		i++;
	}
	return (0);
}

void	add_flag(char flag, char *flags)
{
	int	i;

	i = 0;
	if (flag == '#' && flags[0] != '#')
		flags[0] = '#';
	else if (flag == '0' && flags[1] != '-')
		flags[1] = '0';
	else if (flag == '-' && flags[1] != '-')
		flags[1] = '-';
	else if (flag == ' ' && flags[2] != '+')
		flags[2] = ' ';
	else if (flag == '+' && flags[2] != '+')
		flags[2] = '+';
}

int	read_flag(const char *format, char *flags)
{
	int	i;

	i = 0;
	while (format[i] == '#' || format[i] == '-' || format[i] == '0'
		|| format[i] == '+' || format[i] == ' ')
	{
		if (!is_flag(format[i], flags))
			add_flag(format[i], flags);
		i++;
	}
	return (i);
}

void	intialize_flags(char *flags)
{
	flags[0] = '\n';
	flags[1] = '\n';
	flags[2] = '\n';
}
