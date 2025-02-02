/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:53:18 by astashko          #+#    #+#             */
/*   Updated: 2024/10/15 14:58:48 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char delimit)
{
	int	expecting_word;
	int	i;
	int	count;

	i = 0;
	count = 0;
	expecting_word = 1;
	while (str[i] != '\0')
	{
		if (expecting_word == 1 && str[i] != delimit)
		{
			expecting_word = 0;
			count++;
		}
		else if (expecting_word == 0 && str[i] == delimit)
			expecting_word = 1;
		i++;
	}
	return (count);
}

static void	clear_all(char **output, unsigned int last_written)
{
	unsigned int	i;

	i = 0;
	while (i <= last_written)
	{
		free(output[i]);
		i++;
	}
	free(output);
}

static size_t	write_word(char const *word, char **output, unsigned int n,
		char delimit)
{
	unsigned int	length;
	unsigned int	i;

	length = 0;
	while (word[length] != '\0' && word[length] != delimit)
		length++;
	output[n] = (char *)malloc(sizeof(char) * (length + 1));
	if (output[n] == NULL)
	{
		clear_all(output, n);
		return (0);
	}
	i = 0;
	while (i < length)
	{
		output[n][i] = word[i];
		i++;
	}
	output[n][i] = '\0';
	return (1);
}

char	**ft_split(char const *str, char delimit)
{
	int		i;
	int		j;
	int		expecting_word;
	char	**output;

	output = (char **)malloc((count_words(str, delimit) + 1) * sizeof(char *));
	if (output == NULL)
		return (NULL);
	i = -1;
	j = 0;
	expecting_word = 1;
	while (str[++i] != '\0')
	{
		if (expecting_word == 1 && str[i] != delimit)
		{
			if (write_word(&str[i], output, j, delimit) == 0)
				return (NULL);
			expecting_word = 0;
			j++;
		}
		else if (expecting_word == 0 && str[i] == delimit)
			expecting_word = 1;
	}
	output[j] = NULL;
	return (output);
}
