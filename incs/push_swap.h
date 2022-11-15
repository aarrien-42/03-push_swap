/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2022/11/15 14:30:27 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/*-UTILS-*/
t_list		*ft_find(t_list *lst, int m);
long int	ft_long_atoi(const char *str);
void		ft_print_lists(t_list *a, t_list *b);
void		ft_create_list(t_list	**head, char **input);
int			ft_get_moves(t_list *lst);
t_list		*ft_select(t_list *lst);

/*-ARRAY-*/
void		ft_print_array(int *str, int size);
int			*ft_array_gen(t_list *lst);
int			*ft_array_sorting(int *str, int size);

/*-MOVEMENTS-*/
void		ft_repos_list(t_list **lst);
void		ft_swap(t_list **lst, int mode);
void		ft_rotate(t_list **lst, int mode);
void		ft_inverse_rotate(t_list **lst, int mode);
void		ft_push(t_list **src, t_list **dst);

/*-DOUBLES-*/
void		ft_double_swap(t_list **a, t_list **b);
void		ft_double_rotate(t_list **a, t_list **b);
void		ft_double_inverse_rotate(t_list **a, t_list **b);

/*-ALGORITHM-*/
int			ft_exist(t_list *lst, int max, int min);
void		ft_insert_sorted(t_list **dst, t_list **src);
void		ft_insert(t_list **src, t_list **dst, t_list *node);

/*-CHECKS-*/
int			ft_check_elements(char **argv);
int			ft_check_repeat(char **argv);
int			ft_check_sorted(char **argv);
int			ft_check_maxint(char **argv);
int			ft_check_list_sorted(t_list *lst);

/*-MARK-*/
void		ft_mark(t_list **lst);
void		ft_mark_maxmin(t_list *lst);
void		ft_mark_relpos(t_list *lst);
void		ft_mark_insert(t_list *src, t_list *dst);

/*-PUSH_SWAP-*/
void		ft_push_swap(int size, char **input);
void		ft_solve_little(t_list **lst);
void		ft_solve_medium(t_list **a, t_list **b, int size);
void		ft_solve_large(t_list **a, t_list **b);

#endif
