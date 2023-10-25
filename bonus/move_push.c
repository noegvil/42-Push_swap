/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:17:29 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:45:48 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*to_add;

	if (stack_b->top != NULL)
	{
		to_add = pop_element(stack_b);
		push_element(stack_a, to_add);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*to_add;

	if (stack_a->top != NULL)
	{
		to_add = pop_element(stack_a);
		push_element(stack_b, to_add);
		write(1, "pb\n", 3);
	}
}
