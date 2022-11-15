/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:13 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 10:54:18 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exist(t_list *lst, int max, int min)
{
	while (lst)
	{
		if (lst->value <= max && lst->value >= min)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_insert_sorted(t_list **dst, t_list **src)
{
	t_list	*temp;

	temp = *dst;
	if ((*src)->value > ft_find(*dst, 1)->value \
	|| (*src)->value < ft_find(*dst, -1)->value)
		ft_insert(&*src, &*dst, ft_find(*dst, -1));
	else
	{
		if ((*src)->value > ft_lstlast(*dst)->value \
		&& (*src)->value < (*dst)->value)
			ft_push(&*src, &*dst);
		else
		{
			while ((*src)->value < temp->value \
			|| (*src)->value > temp->next->value)
				temp = temp->next;
			temp = temp->next;
			ft_insert(&*src, &*dst, temp);
		}
	}
}

void	ft_insert(t_list **src, t_list **dst, t_list *node)
{
	if (node->p > 0)
		while (node->p != 0)
			ft_rotate(&*dst, 1);
	else if (node->p < 0)
		while (node->p != 0)
			ft_inverse_rotate(&*dst, 1);
	ft_push(&*src, &*dst);
}
