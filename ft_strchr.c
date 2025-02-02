/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:12:16 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 16:10:57 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*temp;

	temp = (unsigned char *)src;
	while (*temp != (unsigned char)c)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return ((char *)temp);
}
