/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:03:46 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:42:51 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_stack	*stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->num;
	b = stack->top->next->num;
	c = stack->top->next->next->num;
	if (a > b && b < c && a < c)
		swap_a(stack);
	else if (a > b && b < c && a > c)
		rotate_a(stack);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack);
	else if (a > b && b > c && a > c)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (a < b && b > c && a < c)
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

void	put_min_on_top(t_stack *stack_a, int target)
{
	t_node	*current;
	int		i;

	current = stack_a->top;
	i = 0;
	while (current != NULL)
	{
		if (current->num == target && current != stack_a->top)
		{
			if (i < stack_a->len / 2)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
			current = stack_a->top;
		}
		else
		{
			current = current->next;
			i++;
		}
	}
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;
	int		target;

	while (stack_a->len > 3)
	{
		if (find_min_node(stack_a))
		{
			min_node = find_min_node(stack_a);
			target = min_node->num;
		}
		else
			return ;
		put_min_on_top(stack_a, target);
		push_b(stack_b, stack_a);
	}
	sort_3(stack_a);
	while (stack_a->len >= 3 && stack_b->top != NULL)
		push_a(stack_a, stack_b);
}
