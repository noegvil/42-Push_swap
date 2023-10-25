/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:17:10 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:45:41 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

int	process_buffer(char *buffer, char **stash, char **pline)
{
	char	**splitted;
	char	*previous_line;
	int		endline;

	endline = 0;
	splitted = split_in_two(buffer, '\n');
	if (splitted == NULL)
	{
		*pline = NULL;
		return (1);
	}
	previous_line = *pline;
	*pline = ft_strjoin(*pline, splitted[0]);
	free(previous_line);
	if (*pline == NULL)
		endline = 1;
	else if (splitted[1] != NULL)
	{
		*stash = ft_strdup(splitted[1]);
		endline = 1;
	}
	free_splitted(splitted);
	return (endline);
}

int	loop_iteration(int fd, char *buffer, char **pstash, char **pline)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
	if (*pstash != NULL)
	{
		ft_strlcpy(buffer, *pstash, BUFFER_SIZE + 1);
		free(*pstash);
		*pstash = NULL;
	}
	else
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			return (1);
		else if (i < 0)
		{
			free(*pline);
			*pline = NULL;
			return (1);
		}
	}
	return (process_buffer(buffer, pstash, pline));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s3;

	len_s1 = ft_strlen(s1);
	len_s3 = len_s1 + ft_strlen(s2) + 1;
	s3 = (char *)malloc((len_s3) * sizeof(char));
	if (!s3)
	{
		return (NULL);
	}
	ft_strlcpy((char *)s3, (char *)s1, len_s3);
	ft_strlcpy((char *)&s3[len_s1], (char *)s2, len_s3);
	return (s3);
}

char	**free_splitted(char **splitted)
{
	int	i;

	i = 0;
	if (splitted != NULL)
	{
		while (splitted[i] != NULL)
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			endline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	endline = 0;
	while (endline == 0)
		endline = loop_iteration(fd, buffer, &stash, &line);
	free(buffer);
	if (line == NULL || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
