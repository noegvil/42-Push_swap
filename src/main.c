/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:26:56 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:41:55 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort(t_stack	*stack_a, t_stack	*stack_b)
{
	if (stack_a->len == 2)
		swap_a(stack_a);
	if (stack_a->len > 2 && stack_a->len <= 5)
		simple_sort(stack_a, stack_b);
	if (stack_a->len > 5)
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**input;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	input = check_argv(argc, argv);
	if (!input)
		ft_error("Error\n");
	stack_a = new_stack();
	fill_stack_a(stack_a, input);
	check_stack_a(stack_a);
	if (is_sorted(stack_a))
	{
		delete_stack(stack_a);
		return (0);
	}
	stack_b = new_stack();
	ft_sort(stack_a, stack_b);
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}
