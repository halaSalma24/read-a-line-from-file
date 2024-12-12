/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:17:41 by slakhrou          #+#    #+#             */
/*   Updated: 2024/12/10 23:29:01 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*free_static_string(char	**next_line)
{
	if (next_line && *next_line)
	{
		free(*next_line);
		*next_line = NULL;
	}
	return (NULL);
}

static char	*read_bytes(char	*buffer, char	**next_line, int fd)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (free_static_string(next_line));
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(*next_line, buffer);
		if (!tmp)
			return (free(buffer), free_static_string(next_line));
		free(*next_line);
		*next_line = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (*next_line);
}

static	char	*extract_line(char	**next_line)
{
	char	*line;
	char	*tmp;
	char	*newline_pos;

	if (!*next_line || **next_line == '\0')
		return (NULL);
	newline_pos = ft_strchr(*next_line, '\n');
	if (newline_pos)
	{
		line = ft_substr(*next_line, 0, (newline_pos - *next_line + 1));
		if (!line)
			return (free_static_string(next_line));
		tmp = ft_strdup(newline_pos + 1);
		if (!tmp)
			return (free(line), free_static_string(next_line));
		free(*next_line);
		*next_line = tmp;
	}
	else
	{
		line = ft_strdup(*next_line);
		free_static_string(next_line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[OPEN_MAX];
	char		*returned_line;
	char		*buffer;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX)
		return (NULL);
	buffer = (char *)malloc((size_t)(BUFFER_SIZE)+ 1);
	if (!buffer)
		return (free_static_string(&next_line[fd]));
	next_line[fd] = read_bytes(buffer, &next_line[fd], fd);
	if (!next_line[fd])
		return (NULL);
	returned_line = extract_line(&next_line[fd]);
	if (!next_line[fd] || *next_line[fd] == '\0')
	{
		free(next_line[fd]);
		next_line[fd] = NULL;
	}
	return (returned_line);
}
