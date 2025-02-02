/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:07:57 by astashko          #+#    #+#             */
/*   Updated: 2024/10/10 15:13:42 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	if (n > 0)
	{
		while (i < n - 1
			&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	}
	else
		diff = 0;
	return (diff);
}
