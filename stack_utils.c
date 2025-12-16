/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:34:06 by raatar            #+#    #+#             */
/*   Updated: 2025/12/16 06:15:11 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void index_assign(t_stack **lst)
{
	t_stack	*ptr;
	int			index;

	index = 0;
	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr -> index = index++;
		ptr = ptr -> next;
	}
}

t_stack *index_search(t_stack *lst,int index)
{
	t_stack	*ptr;

	ptr = lst;
	while(ptr && index != ptr ->index)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

int	ft_lstcontains(t_stack *lst,int val)
{
	t_stack	*ptr;

	ptr = lst;
	while(ptr)
	{
		if(ptr->val == val)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	fake_sort(t_stack **lst)
{
	t_stack	*ptr1;
	t_stack	*ptr2;
	int		temp;

	ptr1 = *lst;
	temp = 0;
	while(ptr1)
	{
		ptr2 = ptr1->next;
		while(ptr2)
		{
			if(ptr2 -> val < ptr1 -> val)
			{
				temp = ptr2 -> val;
				ptr2 -> val = ptr1 -> val;
				ptr1 -> val = temp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

t_stack	*ft_lstcpy(t_stack *lst)
{
	t_stack	*copy;

	copy = NULL;
	while(lst)
	{
		ft_lstadd_back(&copy,lst ->val);
		lst = lst -> next;
	}
	return (copy);
}

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while(lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack	*ft_lstnew(int val)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem -> index = 0;
	elem -> val = val;
	elem -> next = NULL;
	elem -> prev = NULL;
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
		return (ft_lstadd_front(lst, new));
	else
	{
		ptr = *lst;
		while (ptr -> next)
		{
			ptr = ptr -> next;
		}
		elem = ft_lstnew(new);
		if (!elem)
			return (0);
		ptr -> next = elem;
		elem -> prev = ptr;
		elem -> index = ptr -> index + 1;
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
	ptr -> prev = NULL;
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
