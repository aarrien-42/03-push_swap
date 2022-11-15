/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:17:58 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 10:57:11 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_little(t_list **lst)
{
	if (ft_find(*lst, 1)->p == 0)
		ft_rotate(&*lst, 1);
	else if (ft_find(*lst, 1)->p == 1)
		ft_inverse_rotate(&*lst, 1);
	if (ft_find(*lst, 1)->p == -1 && !ft_check_list_sorted(*lst))
		ft_swap(&*lst, 1);
}

void	ft_solve_medium(t_list **a, t_list **b, int size)
{
	int	i;

	i = -1;
	while (size - 4 - i++ != 0)
		ft_push(&*a, &*b);
	ft_solve_little(&*a);
	while (i-- > 0)
		ft_insert_sorted(&*a, &*b);
	ft_repos_list(&*a);
}

void	ft_solve_large(t_list **a, t_list **b)
{
	a = 0;
	b = 0;
}

void	ft_push_swap(int size, char **input)
{
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	ft_create_list(&list_a, input);
	printf("\n|INICIO|:\n");
	ft_print_lists(list_a, list_b);
	printf("\n|MOVIMIENTOS|:\n");
	if (size <= 3 && size > 1)
		ft_solve_little(&list_a);
	else if (size <= 5 && size > 1)
		ft_solve_medium(&list_a, &list_b, size);
	else
		ft_solve_large(&list_a, &list_b);
	printf("\n|FINAL|:\n");
	ft_print_lists(list_a, list_b);
	printf("solved = %d\n", ft_check_list_sorted(list_a));
	printf("SIZE = %d\n", size);
}

int	main(int argc, char **argv)
{
	int	size;

	size = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!ft_check_repeat(argv) || !ft_check_elements(argv))
			return (ft_putstr("Error\n"), 0);
		if (!ft_check_sorted(argv))
			return (0);
		while (argv[size])
			size++;
		ft_push_swap(size, argv);
	}
	else
	{
		if (!ft_check_repeat(&argv[1]) || !ft_check_elements(&argv[1]))
			return (ft_putstr("Error\n"), 0);
		if (!ft_check_sorted(&argv[1]))
			return (0);
		ft_push_swap(argc - 1, &argv[1]);
	}
	return (0);
}
