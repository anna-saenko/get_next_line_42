/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:41:37 by asaenko           #+#    #+#             */
/*   Updated: 2024/04/08 11:41:40 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		if (chars_read <= 0 && !storage[0])
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
	char	*newline;

	newline = ft_strchr(storage, '\n');
	if (newline)
	{
		line = ft_substr(storage, 0, newline - storage + 1);
	}
	else
	{
		line = ft_strdup(storage);
	}
	return (line);
}
char	*get_remainder(char *line, char *storage)
{
	char	*temp;
	size_t	line_len;

	temp = storage;
	line_len = ft_strlen(line);
	storage = ft_substr(temp, line_len, ft_strlen(temp)
			- line_len);
	free(temp);
	if(*storage == 0)
	{
		free(storage);
		storage = NULL;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	storage[fd] = fill_storage(fd, storage[fd]);
	if (!storage[fd])
		return (free(storage[fd]), NULL);
	line = extract_line(storage[fd]);
	if (!line)
		return (free(storage[fd]), NULL);
	storage[fd] = get_remainder(line, storage[fd]);
	return (line);
}
