/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:54:04 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:46:32 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	if (table == NULL)
		return ;
	while (table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free (table);
}

char	*strjoin_table(char **table)
{
	char	*str;
	int		i;
	size_t	total_length;

	i = 0;
	if (table == NULL)
		return (NULL);
	total_length = table_len(table);
	while (table[i] != NULL)
		i++;
	str = (char *)malloc(sizeof(char) * (total_length + i));
	if (str != NULL)
	{
		i = 0;
		while (table[i] != NULL)
		{
			ft_strlcat(str, table[i], total_length + i + 1);
			if (table[i + 1] != NULL)
				ft_strlcat(str, " ", total_length + i + 1);
			i++;
		}
	}
	return (str);
}

size_t	table_len(char **table)
{
	int		i;
	size_t	total_length;

	i = 0;
	total_length = 0;
	while (table[i] != NULL)
	{
		total_length = total_length + ft_strlen(table[i]);
		i++;
	}
	return (total_length);
}
