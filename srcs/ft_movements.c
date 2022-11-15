/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:29 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 10:53:58 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_repos_list(t_list **lst)
{
	if (ft_find(*lst, -1)->p > 0)
		while (ft_find(*lst, -1)->p != 0)
			ft_rotate(&*lst, 1);
	else if (ft_find(*lst, -1)->p < 0)
		while (ft_find(*lst, -1)->p != 0)
			ft_inverse_rotate(&*lst, 1);
}

void	ft_swap(t_list **lst, int mode)
{
	t_list	*temp;

	if ((*lst)->next)
	{
		if (mode == 1)
		{
			ft_putchar('s');
			ft_putchar((*lst)->l);
			ft_putchar('\n');
		}
		temp = *lst;
		temp = temp->next;
		(*lst)->next = temp->next;
		temp->next = *lst;
		*lst = &*temp;
	}
	ft_mark_relpos(*lst);
}

void	ft_rotate(t_list **lst, int mode)
{
	t_list	*temp;

	if ((*lst)->next)
	{
		if (mode == 1)
		{
			ft_putchar('r');
			ft_putchar((*lst)->l);
			ft_putchar('\n');
		}
		temp = *lst;
		temp = ft_lstlast(temp);
		temp->next = *lst;
		temp = temp->next;
		*lst = temp->next;
		temp->next = NULL;
	}
	ft_mark_relpos(*lst);
}

void	ft_inverse_rotate(t_list **lst, int mode)
{
	t_list	*temp;

	if ((*lst)->next)
	{
		if (mode == 1)
		{
			ft_putstr("rr");
			ft_putchar((*lst)->l);
			ft_putchar('\n');
		}
		temp = *lst;
		temp = ft_lstlast(temp);
		temp->next = *lst;
		*lst = temp;
		while (temp->next != *lst)
			temp = temp->next;
		temp->next = NULL;
	}
	ft_mark_relpos(*lst);
}

void	ft_push(t_list **src, t_list **dst)
{
	t_list	*temp;
	char	lst;

	if (*src && (*src)->l == 'a')
		lst = 'b';
	else
		lst = 'a';
	if (*src && ft_putchar('p') \
	&& ft_putchar(lst) && ft_putchar('\n'))
	{
		temp = *dst;
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = temp;
		(*dst)->l = lst;
		(*dst)->m = 0;
	}
	ft_mark(&*src);
	ft_mark(&*dst);
}
