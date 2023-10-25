/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:16:12 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:42:42 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*current;
	t_node	*new_top;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		current = stack->top;
		new_top = current->next;
		current->next = current->next->next;
		new_top->next = current;
		stack->top = new_top;
	}
}

void	swap_a(t_stack *stack)
{
	if (stack->top != NULL && stack->top->next != NULL)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack *stack)
{
	if (stack->top != NULL && stack->top->next != NULL)
	{
		swap(stack);
		write(1, "sb\n", 3);
	}
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->top != NULL && stack_a->top->next != NULL)
		&& (stack_b->top != NULL && stack_b->top->next != NULL))
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}
