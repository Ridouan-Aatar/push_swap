/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:17:49 by raatar            #+#    #+#             */
/*   Updated: 2025/12/11 20:21:11 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str, int *result);
typedef struct s_stack
{
	int			val;
	struct s_stack	*next;
}	t_stack;
t_stack	*ft_lstnew(int val);
int		ft_lstadd_front(t_stack **lst, int new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstadd_back(t_stack **lst, int new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);

void	ft_pop(t_stack **lst);
void	swap(t_stack **a, char name, int both);
void	push(t_stack **a, t_stack **b, char name, int verbose);
void	rotate(t_stack **a, char name, int both);
void	reverse_rotate(t_stack **a, char name, int both);
void	stack_operations(t_stack **a, t_stack **b, int mode);
#endif
