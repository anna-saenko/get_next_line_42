/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:16:15 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/20 14:16:17 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_storage(int fd, char *storage)
{
	int		chars_read;
	char	*buffer;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	chars_read = 1;
	while (!ft_strchr(storage, '\n') && chars_read > 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0 && !ft_strlen(storage))
			return (free(buffer), free(storage), NULL);
		buffer[chars_read] = '\0';
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char *storage)
{
	char	*line;
	char	*temp;
	char	*newline;

	newline = ft_strchr(storage, '\n');
	if (newline)
	{
		temp = storage;
		line = ft_substr(temp, 0, newline - temp + 1);
		free(temp);
		temp = NULL;
	}
	else
	{
		line = ft_strdup(storage);
		free(storage);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	if (!storage)
		storage = ft_strdup("");
	storage = fill_storage(fd, storage);
	if (!storage)
		return (free(storage), NULL);
	line = extract_line(storage);
	if (!line)
		return (free(storage), NULL);
	storage = ft_substr(storage, ft_strlen(line), ft_strlen(storage)
			- ft_strlen(line));
	return (line);
}
