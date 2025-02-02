/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:04:31 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 17:47:21 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_str;
	size_t	str1_length;
	size_t	str2_length;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	str1_length = ft_strlen(str1);
	str2_length = ft_strlen(str2);
	new_str = (char *)malloc((str1_length + str2_length + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, str1, str1_length + 1);
	ft_strlcpy(&new_str[str1_length], str2, str2_length + 1);
	return (new_str);
}
