/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 09:52:20 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/07 13:37:37 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> 
# include <limits.h> 
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct numbers
{
	char		**numbers;
	int			argc_number;
}				t_numbers;

void			get_numbers(int ac, char **av, t_numbers *the_numbers);
char			**split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
void			free_exit(char **tmp, char *tmp2);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
size_t			ft_strlen2(char *str);
char			*ft_strcpy(char *dest, char *src);
void			ft_putstr2(char *str);
void			init_stack_a(t_stack_node **a, t_numbers *its_numbers);
int				error_syntax(char *str_n);
void			free_errors(t_stack_node **a);
void			free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *a, int n);
t_stack_node	*find_last(t_stack_node *stack);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			sort_three(t_stack_node **a);
t_stack_node	*find_max(t_stack_node *stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*find_min(t_stack_node *stack);
void			min_on_top(t_stack_node **a);

#endif