/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:16:02 by asaenko           #+#    #+#             */
/*   Updated: 2024/03/20 14:16:06 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	char	*res_ptr;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res_ptr = res;
	while (*s1)
	{
		*res++ = *s1++;
	}
	while (*s2)
	{
		*res++ = *s2++;
	}
	*res = '\0';
	return (res_ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	while (*s_cpy)
	{
		if (*s_cpy == (unsigned char)c)
		{
			return ((char *)s_cpy);
		}
		s_cpy++;
	}
	if (*s_cpy == '\0' && (unsigned char)c == '\0')
		return ((char *)s_cpy);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i])
	{
		i++;
	}
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen((char *)s);
	if (s_len < start)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
