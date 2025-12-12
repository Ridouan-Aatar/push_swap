/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:34:06 by raatar            #+#    #+#             */
/*   Updated: 2025/12/10 22:27:54 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int val)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem -> val = val;
	elem -> next = NULL;
	return (elem);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}

int	ft_lstadd_back(t_stack **lst, int new)
{
	t_stack	*ptr;
	t_stack	*elem;

	if (lst == NULL)
		return (0);
	if (*lst == NULL)
	{
		return (ft_lstadd_front(lst, new));
	}
	else
	{
		ptr = ft_lstlast(*lst);
		elem = ft_lstnew(new);
		if (!elem)
			return (0);
		ptr -> next = elem;
	}
	return (1);
}

int	ft_lstadd_front(t_stack **lst, int new)
{
	t_stack	*elem;

	if (lst == NULL)
		return (0);
	elem = ft_lstnew(new);
	if (!elem)
		return (0);
	elem -> next = *lst;
	*lst = elem;
	return (1);
}

void	ft_pop(t_stack **lst)
{
	t_stack	*ptr;

	if (lst == NULL || *lst == NULL)
		return ;
	ptr = (*lst)->next;
	free(*lst);
	*lst = ptr;
}

void	ft_lstdelone(t_stack *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
	lst = NULL;
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*temp;

	if (*lst == NULL || lst == NULL)
		return ;
	ptr = *lst;
	while (ptr)
	{
		temp = ptr -> next;
		ft_lstdelone(ptr);
		ptr = temp;
	}
	*lst = NULL;
}
