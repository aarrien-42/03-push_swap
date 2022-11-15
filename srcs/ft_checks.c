/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:29:42 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 09:46:28 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_list_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_check_maxint(char **argv)
{
	if (ft_long_atoi(*argv) > 2147483647)
		return (0);
	if (ft_long_atoi(*argv) < -2147483648)
		return (0);
	return (1);
}

int	ft_check_sorted(char **argv)
{
	while (*argv)
	{
		if (!argv[1])
			return (0);
		if (ft_atoi(*argv) < ft_atoi(argv[1]))
			argv++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_elements(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[j])
	{
		if (!ft_check_maxint(&argv[j]))
			return (0);
		if (argv[j][i] == '-')
			i++;
		while (argv[j][i])
		{
			if (ft_isdigit(argv[j][i]) == 0)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	ft_check_repeat(char **argv)
{
	int	i;

	i = 1;
	while (*argv)
	{
		while (argv[i])
		{
			if (ft_atoi(*argv) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
		i = 1;
		argv++;
	}
	return (1);
}
