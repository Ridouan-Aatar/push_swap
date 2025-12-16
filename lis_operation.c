/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:20:17 by raatar            #+#    #+#             */
/*   Updated: 2025/12/16 04:44:27 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int binary_search(t_stack *temp,int value)
{
    int high = ft_lstsize(temp)-1,low = 0;
    int mid = 0;
    int res = 0;

    while(low <= high)
    {
        mid = low + (high - low)/ 2;
        if(index_search(temp,mid)->val >= value) {
            res = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return res;
}

t_stack *lengthOfLIS(t_stack *nums) 
{
    t_stack *temp;
    int size = 1;
    int index = 0;
    int num_size = ft_lstsize(nums);

    temp = NULL;
    ft_lstadd_back(&temp, index_search(nums,0) -> val);
    for(int i = 1;i < num_size;i++)
    {
        if(index_search(temp, size - 1)->val < index_search(nums, i)->val)
        {
            ft_lstadd_back(&temp, index_search(nums,i) -> val);
            size++;
        }
        else
        {
            index = binary_search(temp,index_search(nums,i) -> val);
            index_search(temp, index) -> val = index_search(nums,i) -> val;
        }
    }
    return temp;
}