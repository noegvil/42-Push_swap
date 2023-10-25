/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:29:36 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:45:27 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_checker.h"

int	execute_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		swap_a(stack_a);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap_b(stack_b);
	else if (!ft_strncmp(move, "ss\n", 3))
		swap_ab(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa\n", 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(move, "pb\n", 3))
		push_b(stack_b, stack_a);
	else if (!ft_strncmp(move, "ra\n", 3))
		rotate_a(stack_a);
	else if (!ft_strncmp(move, "rb\n", 3))
		rotate_b(stack_b);
	else if (!ft_strncmp(move, "rr\n", 3))
		rotate_ab(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra\n", 4))
		reverse_rotate_a(stack_a);
	else if (!ft_strncmp(move, "rrb\n", 4))
		reverse_rotate_b(stack_b);
	else if (!ft_strncmp(move, "rrr\n", 4))
		reverse_rotate_ab(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	check_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (execute_move(stack_a, stack_b, move) == 0)
		return (0);
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
}

void	push_swap_checker(t_stack *stack_a, t_stack *stack_b)
{
	char		*move;
	int			flag;

	move = get_next_line(0);
	while (move)
	{
		flag = check_move(stack_a, stack_b, move);
		free (move);
		if (flag == 1)
		{
			delete_stack(stack_a);
			delete_stack(stack_b);
			exit(1);
		}
		move = get_next_line(0);
	}
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
		write(1, "OK\n", 3);
		return (0);
	}
	stack_b = new_stack();
	push_swap_checker(stack_a, stack_b);
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}
