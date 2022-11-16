/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:20:13 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 19:28:48 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_select(t_list *lst, t_list *b)
{
	t_list	*selected;
	int		moves;

	moves = ft_absolute(lst->p) + ft_absolute(lst->b);
	selected = lst;
	while (lst)
	{
		if (ft_absolute(lst->p) + ft_absolute(lst->b) == moves)
		{
			if (b && ((ft_find(b, 1)->p > 0 && lst->p > 0) \
			|| (ft_find(b, 1)->p < 0 && lst->p < 0)))
				selected = lst;
			if (b && ((lst->p < 0 && lst->b < 0) || (lst->p > 0 && lst->b > 0)) \
			&& ft_absolute(lst->p) > ft_absolute(lst->b))
				selected = lst;
		}
		if (ft_absolute(lst->p) + ft_absolute(lst->b) < moves)
		{
			moves = ft_absolute(lst->p) + ft_absolute(lst->b);
			selected = lst;
		}
		lst = lst->next;
	}
	return (selected);
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
