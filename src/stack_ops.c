/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:45:47 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:42:55 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->num = num;
	new->simple = 0;
	new->next = NULL;
	return (new);
}

void	delete_node(t_node *node)
{
	if (node != NULL)
		free(node);
}

void	push_element(t_stack *stack, t_node *to_add)
{
	if (stack != NULL && to_add != NULL)
	{
		to_add->next = stack->top;
		stack->top = to_add;
		stack->len++;
	}
}

t_node	*pop_element(t_stack *stack)
{
	t_node	*to_pop;

	to_pop = NULL;
	if (stack->top != NULL)
	{
		to_pop = stack->top;
		stack->top = stack->top->next;
		to_pop->next = NULL;
		stack->len--;
	}
	return (to_pop);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->len = 0;
	return (stack);
}
