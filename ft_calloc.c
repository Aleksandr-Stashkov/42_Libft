/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:19:14 by astashko          #+#    #+#             */
/*   Updated: 2024/10/15 15:27:48 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t array_length, size_t size)
{
	void	*array;

	if (array_length == 0 || size == 0)
		return ((void *)malloc(0));
	if ((size * array_length) / array_length != size)
		return (NULL);
	array = (void *)malloc(array_length * size);
	if (array != NULL)
		ft_bzero(array, array_length * size);
	return (array);
}
