/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:54:55 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:42:47 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_max_bits(t_stack *stack_a)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = stack_a->len;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	number_simplifier(stack_a);
	max_bits = count_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = stack_a->len;
		while (j < size)
		{
			if (((stack_a->top->simple >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_b, stack_a);
			j++;
		}
		while (stack_b->len != 0)
			push_a(stack_a, stack_b);
		i++;
	}
}
