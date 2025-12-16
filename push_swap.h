/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:17:49 by raatar            #+#    #+#             */
/*   Updated: 2025/12/16 06:15:20 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
#include<stdio.h>

int		ft_atoi(const char *str, int *result);
typedef struct s_stack
{
	int 		index;
	int			val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
t_stack	*ft_lstnew(int val);
int		ft_lstadd_front(t_stack **lst, int new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstadd_back(t_stack **lst, int new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
int	ft_lstsize(t_stack *lst);
t_stack	*ft_lstcpy(t_stack *lst);
int	ft_lstcontains(t_stack *lst,int val);

void	fake_sort(t_stack **lst);

t_stack *index_search(t_stack *lst,int index);
void	index_assign(t_stack **lst);
void	ft_pop(t_stack **lst);
void	swap(t_stack **a, char name, int both);
void	push(t_stack **a, t_stack **b, char name, int verbose);
void	rotate(t_stack **a, char name, int both);
void	reverse_rotate(t_stack **a, char name, int both);
void	stack_operations(t_stack **a, t_stack **b, int mode);

t_stack *lengthOfLIS(t_stack *nums);


void print(t_stack *a);
void print_index(t_stack *a);
#endif
