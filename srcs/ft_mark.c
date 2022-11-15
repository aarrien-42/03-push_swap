/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:45:06 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 16:12:34 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mark(t_list **lst)
{
	if (*lst)
	{
		ft_mark_relpos(*lst);
		ft_mark_maxmin(*lst);
	}
}

void	ft_mark_relpos(t_list *lst)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(lst);
	if (size == 1)
		lst->p = 0;
	while (lst->next)
	{
		if (i <= size / 2)
			lst->p = i;
		else
			lst->p = (size - i) * -1;
		i++;
		lst = lst->next;
		lst->p = -1;
	}
}

void	ft_mark_maxmin(t_list *lst)
{
	int		max;
	int		min;
	t_list	*tmp;

	max = lst->value;
	min = lst->value;
	tmp = lst;
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	while (tmp)
	{
		if (tmp->value == max)
			tmp->m = 1;
		else if (tmp->value == min)
			tmp->m = -1;
		else
			tmp->m = 0;
		tmp = tmp->next;
	}
}

void	ft_mark_insert(t_list *src, t_list *dst)
{
	t_list	*temp;

	temp = dst;
	while (src && dst && dst->next)
	{
		if (src->value > ft_find(dst, 1)->value \
		|| src->value < ft_find(dst, -1)->value)
			src->b = ft_find(dst, 1)->p;
		else
		{
			if (src->value < ft_lstlast(dst)->value && src->value > dst->value)
				src->b = 0;
			while (dst->next)
			{
				if (src->value < dst->value \
				&& src->value > dst->next->value)
					src->b = dst->next->p;
				dst = dst->next;
			}
			dst = temp;
		}
		src = src->next;
	}
}
