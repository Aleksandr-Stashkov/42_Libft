/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:14:18 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 18:01:29 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*function)(unsigned int, char))
{
	unsigned int	i;
	char			*str_mod;

	if (str == NULL)
		return (NULL);
	str_mod = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str_mod == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		str_mod[i] = (*function)(i, str[i]);
		i++;
	}
	str_mod[i] = '\0';
	return (str_mod);
}
