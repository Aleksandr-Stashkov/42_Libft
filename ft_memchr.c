/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:38:20 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 15:57:47 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (NULL);
	i = 0;
	while (i < n && ((unsigned char *)src)[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)(src + i));
}
