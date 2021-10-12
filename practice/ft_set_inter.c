/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:26:33 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 17:14:05 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copy_list(t_elem *b, t_elem **copy)
{
	t_elem	*tmp;

	tmp = b;
	while (tmp)
	{
		*copy = ft_eadd_tolist(*copy, tmp->val);
		tmp = tmp->nxt;
	}
}

int		ft_is_set_inter(t_elem *b, int *tab, int val)
{
	t_elem	*tmp;
	int		*sort;
	int		j;
	int		i;

	sort = ft_list_to_tab(b);
	tmp = b;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	sort = ft_sort(sort, i);
	j = 0;
	while (sort[j] < val)
		j++;
	/*printf("sort[i] = %d\n", sort[j]);
	printf("tab[0] = %d\n", tab[0]);*/
	if (tab[i - 1] == sort[j])
		return (1);
	else
		return (0);
	/*printf("i0 = %d, i = %d\n", tab[0], tab[i]);*/
	/*if (tab[0] > val && tab[i] < val)
		return (1);
	else if (tab[0] < val && tab[i] > val)
		return (1);
	else
		return (0);*/
}

int		ft_rb_or_rrb(t_elem *b, int val)
{
	t_elem	*tmp;
	int		*tab;
	int		i;
	int		j;

	tab = ft_list_to_tab(b);
	tmp = malloc(sizeof(t_elem));
	tmp = NULL;
	ft_copy_list(b, &tmp);
	i = 0;
	while (!ft_is_set_inter(tmp, tab, val))
	{
		tmp = ft_reverse_rotate(tmp, 't');
		free(tab);
		tab = ft_list_to_tab(tmp);
		i++;
	}
	if (i > 0)
	{
		free(tmp);
		tmp = malloc(sizeof(t_elem));
		tmp = NULL;
		ft_copy_list(b, &tmp);
		free(tab);
		tab = ft_list_to_tab(tmp);
	}
	j = 0;
	while (!ft_is_set_inter(tmp, tab, val))
	{
		tmp = ft_rotate(tmp, 't');
		free(tab);
		tab = ft_list_to_tab(tmp);
		j++;
	}
	if (i == 0 || j == 0)
		return (0);
	else if (i < j)
		return (2);
	else
		return (1);
}

t_elem	*ft_set_inter_before_pb(t_elem *b, int val)
{
	int		set;

	if (b == NULL)
		return (NULL);
	else if (b->nxt == NULL)
		return (b);
	set = ft_rb_or_rrb(b, val);
	while (set == 1)
	{
		b = ft_rotate(b, 'b');
		set = ft_rb_or_rrb(b, val);
	}
	while (set == 2)
	{
		b = ft_reverse_rotate(b, 'b');
		set = ft_rb_or_rrb(b, val);
	}
	return (b);
}
