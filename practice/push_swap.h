/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:58 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 16:30:55 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_elem t_elem;

struct	s_elem
{
	int			val;
	t_elem		*nxt;
};

t_elem	*ft_hadd_tolist(t_elem *list, int value);
t_elem	*ft_eadd_tolist(t_elem *list, int value);
t_elem	*ft_hdelete_inlist(t_elem *list);
t_elem	*ft_edelete_inlist(t_elem *list);
void	ft_print_list(t_elem *list);

t_elem	*ft_swap(t_elem *list, char c);

t_elem	*ft_rotate(t_elem *list, char c);

t_elem	*ft_push_x_to_y(t_elem **x, t_elem *y, char c);

t_elem	*ft_reverse_rotate(t_elem *list, char c);

int		ft_is_list_sort(t_elem *list);
int		ft_is_tab_sort(int *tab, int size);
int		*ft_list_to_tab(t_elem *list);
int		*ft_sort(int *tab, int size);

t_elem	*ft_set_min_before_pb(t_elem *b, int val);
int		ft_is_min(t_elem *b, int d);

void	ft_copy_list(t_elem *b, t_elem **copy);
int		ft_is_set_inter(t_elem *b, int *tab, int val);
int		ft_rb_or_rrb(t_elem *b, int val);
t_elem	*ft_set_inter_before_pb(t_elem *b, int val);

int		ft_is_chunk(int c, t_elem *list);
int		*ft_get_chunk(int n, int size, int *sorted);
void	ft_chunk_a(t_elem **a, t_elem **b, int *chunk, int lastchunk);

t_elem	*ft_set_b_before_fill_a(t_elem *b);
t_elem	*ft_ra_or_rra(t_elem *a, int chunk);
void	ft_fill_a(t_elem **a, t_elem **b);

#endif
