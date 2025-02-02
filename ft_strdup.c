/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:43:12 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 17:45:03 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*duplicate;
	unsigned int	i;
	unsigned int	length;

	length = ft_strlen(str) + 1;
	duplicate = malloc(length * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		duplicate[i] = str[i];
		i++;
	}
	return (duplicate);
}
