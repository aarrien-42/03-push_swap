/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:13:19 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/16 09:46:09 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_list(t_list	**head, char **input)
{
	int		i;
	t_list	*temp;

	i = 1;
	*head = ft_lstnew(ft_atoi(*input));
	while (input[i])
	{
		ft_lstadd_back(&*head, ft_lstnew(ft_atoi(input[i])));
		i++;
	}
	temp = *head;
	while (temp)
	{
		temp->l = 'a';
		temp->b = 0;
		temp = temp->next;
	}
	ft_mark_maxmin(*head);
	ft_mark_relpos(*head);
}

t_list	*ft_find(t_list *lst, int m)
{
	while (lst)
	{
		if (lst->m == m)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

long int	ft_long_atoi(const char *str)
{
	size_t		i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_absolute(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	ft_print_lists(t_list *a, t_list *b)
{
	printf("LISTA A:\n\n");
	while (a)
	{
		printf("(%2d) |%2d| (%2d)\n\n", a->p, a->value, a->b);
		if (a->next == 0)
			break ;
		a = a->next;
	}
	printf("LISTA B:\n\n");
	while (b)
	{
		printf("(%2d) |%2d| (%2d)\n\n", b->p, b->value, b->b);
		if (b->next == 0)
			break ;
		b = b->next;
	}
}
