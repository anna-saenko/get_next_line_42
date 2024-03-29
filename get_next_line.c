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

static char	*set_line(char *buffer)
{
	char	*remainder;
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != 0)
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	remainder = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (*remainder == 0)
	{
		free(remainder);
		remainder = NULL;
	}
	buffer[i + 1] = 0;
	return (remainder);
}

static char	*fill_buffer(int fd, char *remainder, char *buffer)
{
	ssize_t	chars_read;
	char	*temp;

	chars_read = read(fd, buffer, BUFFER_SIZE);
	if (chars_read == -1)
	{
		free(remainder);
		return (NULL);
	}
	else if (chars_read == 0)
		return (remainder);
	buffer[chars_read] = '\0';
	if (!remainder)
		remainder = ft_strdup("");
	temp = remainder;
	remainder = ft_strjoin(temp, buffer);
	free(temp);
	temp = NULL;
	if (ft_strchr(buffer, '\n'))
		return (remainder);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_buffer(fd, remainder, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder = set_line(line);
	return (line);
}
