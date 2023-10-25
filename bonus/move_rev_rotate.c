/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:19:01 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:45:56 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*pre_last_node;
	t_node	*last_node;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		pre_last_node = NULL;
		last_node = stack->top;
		while (last_node->next != NULL)
		{
			pre_last_node = last_node;
			last_node = last_node->next;
		}
		last_node->next = stack->top;
		stack->top = last_node;
		pre_last_node->next = NULL;
	}
}

void	reverse_rotate_a(t_stack *stack)
{
	if (stack->top != NULL && stack->top->next != NULL)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack *stack)
{
	if (stack->top != NULL && stack->top->next != NULL)
	{
		reverse_rotate(stack);
		write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->top != NULL && stack_a->top->next != NULL)
		&& (stack_b->top != NULL && stack_b->top->next != NULL))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
