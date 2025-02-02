/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:23:31 by astashko          #+#    #+#             */
/*   Updated: 2024/10/13 16:18:48 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int search_for)
{
	char			*temp;
	unsigned int	i;

	i = 0;
	temp = NULL;
	while (src[i] != '\0')
	{
		if ((unsigned char)src[i] == (unsigned char)search_for)
			temp = (char *)src + i;
		i++;
	}
	if ((unsigned char)src[i] == (unsigned char)search_for)
		temp = (char *)src + i;
	return (temp);
}
