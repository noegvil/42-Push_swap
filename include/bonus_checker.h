/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:51:26 by noelgarc          #+#    #+#             */
/*   Updated: 2023/07/06 19:17:35 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000

# endif

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
int		is_sorted(t_stack *stack);
void	delete_stack(t_stack *stack);

/* stack moves */

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

/* get_next_line */

int		process_buffer(char *buffer, char **stash, char **pline);
int		loop_iteration(int fd, char *buffer, char **pstash, char **pline);
char	*ft_strjoin(char const *s1, char const *s2);
char	**free_splitted(char **splitted);
char	*get_next_line(int fd);

/* get_next_line_utils */

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strdup(const char *s1);
char	**split_in_two(char *str, char c);
char	**init_splitted(size_t len);

#endif