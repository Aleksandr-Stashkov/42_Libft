/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:54:37 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 17:45:30 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_length;
	char	*sub;

	if (len < 0 || str == NULL)
		return (NULL);
	sub_length = 0;
	if (start < ft_strlen(str))
	{
		while (str[start + sub_length] != '\0' && sub_length < len)
			sub_length++;
	}
	sub = (char *)malloc((sub_length + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < sub_length)
	{
		sub[i] = (char)str[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
