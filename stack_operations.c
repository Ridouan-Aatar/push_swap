/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:03:37 by raatar            #+#    #+#             */
/*   Updated: 2025/12/11 20:21:34 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, char name, int both)
{
	int	temp;
	int	temp2;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->val;
	ft_pop(a);
	temp2 = (*a)->val;
	(*a)->val = temp;
	ft_lstadd_front(a, temp2);
	if (!both)
	{
		write(1, "s", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack **a, t_stack **b, char name, int verbose)
{
	int	temp;

	if (!a || !(*a) || !b)
		return ;
	temp = (*a)->val;
	ft_pop(a);
	ft_lstadd_front(b, temp);
	if(verbose)
	{
		write(1, "p", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack **a, char name, int both)
{
	t_stack	*temp_stack;
	int		temp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp_stack = NULL;
	temp = (*a)->val;
	ft_pop(a);
	while (*a)
	{
		push(a, &temp_stack, '\0', 0);
	}
	ft_lstadd_front(a, temp);
	while (temp_stack)
	{
		push(&temp_stack, a, '\0', 0);
	}
	if (!both)
	{
		write(1, "r", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_stack **a, char name, int both)
{
	t_stack	*temp_stack;
	int		temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp_stack = NULL;
	while ((*a)->next)
	{
		push(a, &temp_stack,'\0',0);
	}
	temp = (*a)->val;
	ft_pop(a);
	while (temp_stack)
	{
		push(&temp_stack, a,'\0',0);
	}
	ft_lstadd_front(a, temp);
	if (!both)
	{
		write(1, "rr", 2);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	stack_operations(t_stack **a, t_stack **b, int mode)
{
	if (mode == 1)
		push(a, b, 'b',1);
	if (mode == 10)
		push(b, a, 'a',1);
	if (mode == 2)
		swap(a, 'a', 0);
	if (mode == 20)
		swap(b, 'b', 0);
	if (mode == 22)
	{
		swap(a, 'a', 1);
		swap(b, 'b', 1);
		write(1, "ss\n", 3);
	}
	if (mode == 3)
		rotate(a, 'a', 0);
	if (mode == 30)
		rotate(b, 'b', 0);
	if (mode == 33)
	{
		rotate(a, 'a', 1);
		rotate(b, 'b', 1);
		write(1, "rr\n", 3);
	}
	if (mode == 4)
		reverse_rotate(a, 'a', 0);
	if (mode == 40)
		reverse_rotate(b, 'b', 0);
	if (mode == 44)
	{
		reverse_rotate(a, 'a', 1);
		reverse_rotate(b, 'b', 1);
		write(1, "rrr\n", 4);
	}
}
