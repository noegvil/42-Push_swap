/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:19:17 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:45:38 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if (s2 != NULL)
	{
		ft_strlcpy(s2, (char *)s1, len + 1);
	}
	return (s2);
}

char	**split_in_two(char *str, char c)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = init_splitted(ft_strlen(str));
	while (splitted && str[i])
	{
		splitted[0][i] = str[i];
		splitted[0][i + 1] = '\0';
		if (str[i] == c)
		{
			splitted[1] = ft_strdup(str + i + 1);
			if (splitted[1] == NULL)
				return (free_splitted(splitted));
			break ;
		}
		i++;
	}
	return (splitted);
}

char	**init_splitted(size_t len)
{
	char	**splitted;

	splitted = (char **) malloc(3 * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	splitted[0] = (char *) malloc((len + 1) * sizeof(char));
	if (splitted[0] == NULL)
		return (free_splitted(splitted));
	splitted[0][0] = '\0';
	splitted[1] = NULL;
	splitted[2] = NULL;
	return (splitted);
}
