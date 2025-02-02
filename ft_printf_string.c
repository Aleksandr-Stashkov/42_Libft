/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:34:46 by astashko          #+#    #+#             */
/*   Updated: 2025/02/02 14:46:31 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepared_string(char *str, int *width, int *used_malloc)
{
	int		i;
	char	*tmp;

	if (str == NULL)
	{
		if (width[1] >= 0 && width[1] < 6)
			return (NULL);
		else
			return ("(null)");
	}
	if (width[1] >= 0 && width[1] < (int)ft_strlen(str))
	{
		tmp = malloc((width[1] + 1) * sizeof(char));
		if (tmp == NULL)
			return (str);
		i = 0;
		while (i < width[1])
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
		return (*used_malloc = 1, tmp);
	}
	return (str);
}

int	print_string(char *str, char *flags, int *width)
{
	int	output_length;
	int	used_malloc;

	used_malloc = 0;
	str = prepared_string(str, width, &used_malloc);
	if (width[0] > (int)ft_strlen(str))
		output_length = width[0];
	else
		output_length = (int)ft_strlen(str);
	if (is_flag('-', flags))
		ft_putstr_fd(str, 1);
	width[0] -= (int)ft_strlen(str);
	while (width[0] > 0)
	{
		ft_putchar_fd(' ', 1);
		width[0]--;
	}
	if (!is_flag('-', flags))
		ft_putstr_fd(str, 1);
	if (used_malloc)
		free(str);
	return (output_length);
}
