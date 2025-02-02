/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:30:02 by astashko          #+#    #+#             */
/*   Updated: 2024/10/10 21:38:31 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*function)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		(*function)(i, &str[i]);
		i++;
	}
}
