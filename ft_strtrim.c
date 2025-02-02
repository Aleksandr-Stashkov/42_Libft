/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:32:20 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 17:54:44 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char c, const char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;

	if (str == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (str[start] != '\0' && in_set(str[start], set) == 1)
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && in_set(str[end], set) == 1)
		end--;
	return (ft_substr(str, start, end - start + 1));
}
