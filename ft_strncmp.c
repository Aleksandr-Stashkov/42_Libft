/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:33:01 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 15:57:28 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	if (n > 0)
	{
		while (i < n - 1 && (unsigned char)s1[i] == (unsigned char)s2[i]
			&& (s1[i] != '\0' || s2[i] != '\0'))
			i++;
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (diff);
}
