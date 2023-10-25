/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:57:05 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:41:46 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_digit(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0' || (*str < '0' || *str > '9'))
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	check_digit_table(char **table)
{
	char	**current_input;

	current_input = table;
	while (*current_input != NULL)
	{
		if (!check_digit(*current_input))
			return (0);
		current_input++;
	}
	return (1);
}

char	**check_argv(int argc, char **argv)
{
	char	**input;
	char	*str;

	if (argc <= 1)
		return (NULL);
	else
	{
		str = strjoin_table(&argv[1]);
		if (!str)
			return (NULL);
		input = ft_split(str, ' ');
		free(str);
		if (!input)
			return (NULL);
	}
	if (!check_digit_table(input))
	{
		free_table(input);
		input = NULL;
	}
	return (input);
}

int	check_dup(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		value;

	current = stack->top;
	while (current != NULL)
	{
		value = current->num;
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->num == value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

void	check_stack_a(t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->top == NULL)
		ft_error("Error\n");
	if (check_dup(stack_a))
	{
		delete_stack(stack_a);
		ft_error("Error\n");
	}
}
