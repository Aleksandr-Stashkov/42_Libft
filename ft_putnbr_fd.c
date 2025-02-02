/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:45:42 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 19:14:45 by astashko         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	int		power;
	int		temp;
	char	output;

	power = 1000000000;
	if (n < 0)
		write(fd, "-", 1);
	temp = n / power;
	while (temp == 0 && power > 1)
	{
		power /= 10;
		temp = n / power;
	}
	while (power >= 1)
	{
		output = abs_v(temp) + '0';
		write(fd, &output, 1);
		if (power == 1)
			break ;
		n = n - temp * power;
		power /= 10;
		temp = n / power;
	}
}
