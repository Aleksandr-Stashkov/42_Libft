/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:14:24 by astashko          #+#    #+#             */
/*   Updated: 2024/10/15 14:41:12 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_length;
	char	dummy;

	little_length = ft_strlen(little);
	if (little_length == 0)
		return ((char *)big);
	i = 0;
	dummy = big[1];
	if (len > 0 && len >= little_length)
	{
		while (i <= len - little_length && big[i] != '\0')
		{
			if (ft_strncmp(big + i, little, little_length) == 0)
				return ((char *)(big + i));
			i++;
		}
	}
	return (NULL);
}
