/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raatar <raatar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:09:28 by raatar            #+#    #+#             */
/*   Updated: 2025/12/10 16:37:48 by raatar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overlimit_overflow_check(long long res, char c, int sign)
{
	if (res > (9223372036854775807LL - c + '0') / 10)
	{
		return (0);
	}
	return (1);
}

static int	clear(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str, int *result)
{
	long long	res;
	int			sign;
	size_t		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str && *str)
	{
		sign = clear(str, &i);
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (!overlimit_overflow_check(res, str[i], sign))
				return (0);
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	if (!str || str[i] || !*str)
		return (0);
	*result = sign * res;
	return (1);
}
