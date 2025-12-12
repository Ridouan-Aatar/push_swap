/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:07:22 by raatar            #+#    #+#             */
/*   Updated: 2025/12/12 21:46:35 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

void print(t_stack *a)
{
		t_stack	*temp = a;
		while(temp)
		{
			printf(" %d",temp->val);
			temp = temp->next;
		}
		printf("\n");
}

void	push_swap(t_stack **a,int length)
{
	t_stack	*b;
	int		temp;

	b = NULL;

	while()

}
// void	push_swap(t_stack **a)
// {
// 	t_stack	*b;
// 	int		temp;

// 	b = NULL;
// 	temp = 0;
// 	while (*a != NULL)
// 	{
// 		temp = (*a)->val;
// 		if (b && temp < b->val)
// 		{
// 			rotate(a);
// 			write(1,"ra\n",3);
// 			while (b != NULL)
// 			{
// 				push(&b,a);
// 				write(1, "pa\n", 3);
// 			}
// 			reverse_rotate(a);
// 			write(1,"ra\n",3);
// 		}
// 		push(a,&b);
// 		write(1,"pb\n",3);
// 	}
// 	while (b != NULL)
// 	{
// 		push(&b,a);
// 		write(1,"pa\n",3);
// 	}
// }

// int isvalid(int argc,char **argv)
// {

// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		num;
	int		num2;
	int		i;
	int		j;

	a = NULL;
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			num = 0;
			if (ft_atoi(argv[i], &num))
			{
				j = 1;
				while (j < i)
				{
					num2 = -1;
					ft_atoi(argv[j], &num2);
					if (num2 == num)
					{
						write(2, "Error duplication\n", 19);
						ft_lstclear(&a);
						exit(42);
					}
					j++;
				}
				if (!ft_lstadd_back(&a, num))
				{
					write(2, "Error\n", 6);
					ft_lstclear(&a);
					exit(42);
				}
			}
			else
			{
				write(2, "Error\n", 6);
				ft_lstclear(&a);
				exit(42);
			}
		}
		print(a);
		// push_swap(&a);
		stack_operations(&a,NULL,3);
		print(a);

	}
	return (0);
}