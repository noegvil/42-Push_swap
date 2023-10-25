/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:51:26 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/25 12:44:40 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/* INT_MAX and INT_MIN */

# define INT_MAX_VALUE 2147483647
# define INT_MIN_VALUE -2147483648

typedef struct s_node {
	int				num;
	int				simple;
	struct s_node	*next;
}				t_node;

typedef struct s_stack {
	t_node	*top;
	int		len;
}				t_stack;

/* utils */

void	ft_error(char *str);
void	free_table(char **table);
char	*strjoin_table(char **table);
size_t	table_len(char **table);
int		is_sorted(t_stack *stack);

/* check */

int		check_digit(char *str);
int		check_digit_table(char **table);
char	**check_argv(int argc, char **argv);
int		check_dup(t_stack *stack);
void	check_stack_a(t_stack *stack_a);

/* basic stack operations */

t_node	*create_node(int num);
void	delete_node(t_node *node);
void	push_element(t_stack *stack, t_node *to_add);
t_node	*pop_element(t_stack *stack);
t_stack	*new_stack(void);

/* stack utils */

void	fill_stack_a(t_stack *stack, char **input);
t_node	*find_min_node(t_stack *stack);
t_node	*min_node_above_limit(t_stack *stack, int limit);
void	number_simplifier(t_stack *stack);
void	delete_stack(t_stack *stack);

/* stack moves allowed */

void	swap(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);

void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_b, t_stack *stack_a);

void	rotate(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);

void	reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

/* simple sort */

void	sort_3(t_stack	*stack);
void	put_min_on_top(t_stack *stack_a, int target);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);

/* radix_sort */

int		count_max_bits(t_stack *stack_a);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif