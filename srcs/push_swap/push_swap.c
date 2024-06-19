/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:05:16 by mbaypara          #+#    #+#             */
/*   Updated: 2024/06/19 18:26:32 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	destroy_args(char **args)
{
	int	i;

	i = 0;
	if (!args || !*args)
		return ;
}

void	put_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	assert_not_null(void *ptr)
{
	if (ptr == NULL)
		put_error();
	else
		return ;
}

static char	**split_check(char **ptr)
{
	if (ptr == NULL)
		put_error();
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = split_check(ft_split(argv[1], ' '));
		init_stack_a(&a, argv, argc == 2);
	}
	else
		init_stack_a(&a, argv + 1, argc == 2);
	assert_not_null(a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	return (free_stack(&a), 0);
}
