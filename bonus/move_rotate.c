/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:18:25 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:46:01 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

void	rotate(t_stack *stack)
{
	t_node	*current;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		current = stack->top;
		while (current->next != NULL)
			current = current->next;
		current->next = stack->top;
		stack->top = stack->top->next;
		current->next->next = NULL;
	}
}

void	rotate_a(t_stack *stack)
{
	if (stack->top != NULL && stack->top->next != NULL)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack *stack)
{
	if (stack->top != NULL && stack->top->next != NULL)
	{
		rotate(stack);
		write(1, "rb\n", 3);
	}
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->top != NULL && stack_a->top->next != NULL)
		&& (stack_b->top != NULL && stack_b->top->next != NULL))
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
