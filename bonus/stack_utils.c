/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:21:33 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:46:28 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

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

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL && current->next != NULL)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
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
