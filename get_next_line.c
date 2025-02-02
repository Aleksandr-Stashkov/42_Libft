/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astashko <astashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:56:26 by astashko          #+#    #+#             */
/*   Updated: 2025/01/12 18:40:03 by astashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*store_leftover(char *from, char *left, size_t end_index)
{
	char	*tmp;
	size_t	leftover_length;
	size_t	i;

	leftover_length = ft_strlen(from) - end_index;
	if (leftover_length <= 1)
	{
		free_guarded(left);
		return (NULL);
	}
	tmp = (char *)malloc(leftover_length * sizeof(char));
	if (tmp == NULL)
	{
		free_guarded(left);
		return (NULL);
	}
	i = 0;
	while (i < leftover_length - 1)
	{
		tmp[i] = from[end_index + 1 + i];
		i++;
	}
	tmp[i] = '\0';
	free_guarded(left);
	return (tmp);
}

char	*append_line(char *from, char *to, size_t end_index)
{
	char	*tmp;
	size_t	to_length;
	size_t	i;

	to_length = ft_strlen(to);
	tmp = (char *)malloc((to_length + end_index + 2) * sizeof(char));
	if (tmp == NULL)
	{
		free_guarded(to);
		return (NULL);
	}
	i = 0;
	while (i < to_length)
	{
		tmp[i] = to[i];
		i++;
	}
	while (i <= to_length + end_index)
	{
		tmp[i] = from[i - to_length];
		i++;
	}
	tmp[i] = '\0';
	free_guarded(to);
	return (tmp);
}

size_t	collected_line(char *from, char **to, char **left)
{
	size_t	i;
	size_t	from_length;

	from_length = ft_strlen(from);
	i = 0;
	while (i < from_length)
	{
		if (from[i] == '\n')
		{
			*to = append_line(from, *to, i);
			if (*to == NULL)
				return (clear(left), 1);
			*left = store_leftover(from, *left, i);
			return (1);
		}
		i++;
	}
	*to = append_line(from, *to, i - 1);
	if (*to == NULL)
		return (clear(left), 1);
	return (0);
}

size_t	read_line(int fd, char **line, char **leftover)
{
	int		read_size;
	size_t	read_result;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		clear(line);
		clear(leftover);
		return (1);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size <= 0)
	{
		clear(leftover);
		free(buffer);
		if (read_size < 0 || (*line != NULL && ft_strlen(*line) == 0))
			clear(line);
		return (1);
	}
	buffer[read_size] = '\0';
	read_result = collected_line(buffer, line, leftover);
	free(buffer);
	return (read_result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftovers[1024];
	size_t		stop_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		clear(&leftovers[fd]);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char));
	if (line == NULL)
	{
		clear(&leftovers[fd]);
		return (NULL);
	}
	line[0] = '\0';
	stop_read = 0;
	if (leftovers[fd] != NULL && ft_strlen(leftovers[fd]) != 0)
		stop_read = collected_line(leftovers[fd], &line, &leftovers[fd]);
	while (stop_read == 0)
		stop_read = read_line(fd, &line, &leftovers[fd]);
	return (line);
}
