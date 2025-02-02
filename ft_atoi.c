/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:58:00 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 16:19:48 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	read_int(const char *int_start)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (int_start[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (int_start[i] == '+')
		i++;
	while (int_start[i] >= '0' && int_start[i] <= '9')
	{
		result = result * 10 + sign * (int_start[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\f' && str[i] != '\n' && str[i] != '\r'
			&& str[i] != '\t' && str[i] != '\v')
			return (read_int(&str[i]));
		i++;
	}
	return (0);
}
