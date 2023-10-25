/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:52:11 by noelgarc          #+#    #+#             */
/*   Updated: 2023/06/05 18:24:45 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *S)
{
	size_t		i;
	long int	sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((S[i] >= 9 && S[i] <= 13) || S[i] == 32)
	{
		i++;
	}
	if (S[i] == '+' || S[i] == '-')
	{
		if (S[i] == '-')
			sign = -1;
		i++;
	}
	while (S[i] >= '0' && S[i] <= '9')
	{
		num = num * 10 + S[i] - 48;
		i++;
	}
	return (sign * num);
}
