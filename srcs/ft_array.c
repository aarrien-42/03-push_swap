/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:21:53 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 09:46:21 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_array_gen(t_list *lst)
{
	int	*str;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(lst);
	str = (int *)malloc(sizeof(int) * size);
	while (lst)
	{
		str[i] = lst->value;
		lst = lst->next;
		i++;
	}
	return (str);
}

int	*ft_array_sorting(int *str, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			i++;
		}
		i = j + 1;
		j++;
	}
	return (str);
}
