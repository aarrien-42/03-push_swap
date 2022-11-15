/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:40:22 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 10:53:14 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_swap(t_list **a, t_list **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		ft_swap(&*a, 0);
		ft_swap(&*b, 0);
		ft_putstr("ss\n");
	}
}

void	ft_double_rotate(t_list **a, t_list **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		ft_rotate(&*a, 0);
		ft_rotate(&*b, 0);
		ft_putstr("rr\n");
	}
}

void	ft_double_inverse_rotate(t_list **a, t_list **b)
{
	if (*a && *b && (*a)->next && (*b)->next)
	{
		ft_inverse_rotate(&*a, 0);
		ft_inverse_rotate(&*b, 0);
		ft_putstr("rrr\n");
	}
}
