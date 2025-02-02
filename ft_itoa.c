/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:11:42 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 18:59:52 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	abs_v(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static void	write_number(char *output, int n, int n_digits)
{
	int	i;
	int	j;

	j = n_digits - 1;
	if (n < 0)
	{
		output[0] = '-';
		j++;
	}
	output[j + 1] = '\0';
	i = 0;
	while (i < n_digits)
	{
		output[j] = abs_v(n % 10) + '0';
		i++;
		j--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		n_digits;
	int		power;
	char	*output;

	n_digits = 1;
	power = 10;
	while (n / power != 0)
	{
		n_digits++;
		if (power == 1000000000)
			break ;
		power *= 10;
	}
	if (n < 0)
		output = malloc(sizeof(char) * (n_digits + 2));
	else
		output = malloc(sizeof(char) * (n_digits + 1));
	if (output != NULL)
		write_number(output, n, n_digits);
	return (output);
}
