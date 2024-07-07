/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:00:08 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/07 13:41:31 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

void	algo(t_numbers *its_numbers)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	init_stack_a(&a, its_numbers);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
}

void	get_numbers(int ac, char **av, t_numbers *its_numbers)
{
	int		i;
	int		j;
	char	**tmp;
	char	*tmp2;

	i = 1;
	tmp2 = NULL;
	while (i < ac)
	{
		j = 0;
		tmp = split(av[i], ' ');
		if (!tmp[0])
			free_exit(tmp, tmp2);
		while (tmp[j])
		{
			tmp2 = ft_strjoin(tmp2, " ");
			tmp2 = ft_strjoin(tmp2, tmp[j++]);
		}
		j = 0;
		while (tmp[j])
			free(tmp[j++]);
		(free(tmp), i++);
	}
	its_numbers->numbers = split(tmp2, ' ');
	free(tmp2);
}
void	check_n_args(int ac, char **av)
{
	if (ac == 1)
	{
		exit(1);
	}
	if (!av[1][0])
	{
		ft_putstr2("Error\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_numbers	its_numbers;
	int			j;

	j = 0;
	its_numbers.argc_number = ac;
	check_n_args(ac, av);
	get_numbers(ac, av, &its_numbers);
	algo(&its_numbers);
	while (its_numbers.numbers[j])
	{
		free(its_numbers.numbers[j]);
		j++;
	}
	free(its_numbers.numbers);
    return (0);
}
