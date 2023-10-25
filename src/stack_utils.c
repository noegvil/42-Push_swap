/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:21:33 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:43:00 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_stack_a(t_stack *stack, char **input)
{
	int			i;
	int			count;
	long int	value;
	t_node		*new_node;

	i = 0;
	count = 0;
	while (input[count])
		count++;
	i = count - 1;
	while (i >= 0)
	{
		value = ft_atoi(input[i]);
		if (value < INT_MIN_VALUE || value > INT_MAX_VALUE)
		{
			free_table(input);
			ft_error("Error\n");
		}
		new_node = create_node((int)value);
		push_element(stack, new_node);
		i--;
	}
	free_table(input);
}

t_node	*find_min_node(t_stack *stack)
{
	t_node	*min_node;
	t_node	*current;

	if (stack->top == NULL || stack == NULL)
		return (NULL);
	min_node = stack->top;
	current = stack->top->next;
	while (current != NULL)
	{
		if (current->num < min_node->num)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*min_node_above_limit(t_stack *stack, int limit)
{
	t_node	*current;
	t_node	*min_node;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	current = stack->top;
	min_node = NULL;
	while (current != NULL)
	{
		if (current->num > limit)
		{
			if (min_node == NULL || current->num < min_node->num)
				min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	number_simplifier(t_stack *stack)
{
	int		i;
	t_node	*min;
	t_node	*current;

	if (stack->top == NULL || stack == NULL)
		return ;
	current = stack->top;
	min = find_min_node(stack);
	i = 1;
	while (i <= stack->len)
	{
		current = min;
		current->simple = i;
		min = min_node_above_limit(stack, current->num);
		i++;
	}
}

void	delete_stack(t_stack *stack)
{
	t_node	*to_delete;

	while (stack->top != NULL)
	{	
		to_delete = pop_element(stack);
		delete_node(to_delete);
	}
	free(stack);
}
