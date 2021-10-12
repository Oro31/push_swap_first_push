/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:54:08 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 18:38:54 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_chunk(int c, t_elem *list)
{
	t_elem	*tmp;

	if (list == NULL)
		return (0);
	tmp = list;
	while (tmp->val > c && tmp->nxt)
		tmp = tmp->nxt;
	if (tmp->val < c)
		return (1);
	return (0);
}

int		*ft_get_chunk(int n, int size, int *sorted)
{
	int		*chunk;
	int		alpha;
	int		i;

	chunk = malloc(sizeof(int) * (n + 1));
	if (!chunk)
		return (0);
	alpha = size / (n + 1);
	i = -1;
	while (++i < n)
		chunk[i] = sorted[alpha * (i + 1)];
	chunk[n] = sorted[size - 1] + 1;
	return (chunk);
}

/*int		ft_is_set(t_elem *b, int *tab, int val)
{
	t_elem	*tmp;
	int		i;

	tmp = b;
	i = 0;
	while (tmp->nxt)
	{
		tmp = tmp->nxt;
		i++;
	}
	if (tab[0] > val && tab[i] < val)
		return (1);
	else 
		return (0);
}

int		ft_rb_or_rrb(t_elem *b, int val)
{
	t_elem	*tmp;
	int		*tab;
	int		i;
	int		j;

	tab = ft_list_to_tab(b);*/
	/*tmp = b;
	j = 0;
	while (tmp->nxt)
	{
		tmp = tmp->nxt;
		j++;
	}*/
/*	tmp = b;
	i = 0;
	while (!ft_is_set(tmp, tab, val))
	{
		tmp = ft_reverse_rotate(tmp, 't');
		i++;
	}
	tmp = b;
	j = 0;
	while (!ft_is_set(tmp, tab, val))
	{
		tmp = ft_rotate(tmp, 't');
		j++;
	}*/
	/*i = 0;
	while (tab[j] > val)
	{
		j--;
		i++;
	}
	j = 0;
	while (tab[j] < val)
		j++;*/
/*	printf("rrb = %d, rb = %d\n", i, j);
	if (i == 0 || j == 0)
		return (0);
	else if (i < j)
		return (2);
	else
		return (1);
}*/

/*t_elem	*ft_set_before_pb(t_elem *b, int val)
{
	t_elem	*tmp;
	int		set;
	int		x;
	int		y;

	if (b == NULL)
		return (NULL);
	else if (b->nxt == NULL)
		return (b);
	set = ft_rb_or_rrb(b, val);
	while (set == 1)
	{
		b = ft_rotate(b, 'b');
		set = ft_rb_or_rrb(b, val);*/
		/*tmp = b;
		x = tmp->val;
		while (tmp->nxt)
			tmp = tmp->nxt;
		y = tmp->val;*/
		/*printf("x = %d, y = %d, val = %d\n", x, y, val);*/
		/*if (x > val && y < val)
			set = 0;
		else if (x > y)
			b = ft_rotate(b, 'b');*/
		/*else if (x <= y)
			set = 0;*/
/*	}
	while (set == 2)
	{
		b = ft_reverse_rotate(b, 'b');
		set = ft_rb_or_rrb(b, val);*/
		/*tmp = b;
		while (tmp->nxt)
			tmp = tmp->nxt;*/
		/*if (tmp->val > val)
			b = ft_reverse_rotate(b, 'b');
		else
			set = 0;*/
		/*if (tmp->val <= val)
			set = 0;*/
/*	}
	return (b);
}*/

/*t_elem	*ft_set_min_before_pb(t_elem *b, int val)
{
	t_elem	*tmp;
	int		*tab;
	int		i;

	if (b == NULL)
		return (NULL);
	else if (b->nxt == NULL)
		return (b);
	tmp = b;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	tab = ft_list_to_tab(b);
	tab = ft_sort(tab, i);
	tmp = b;
	while (tmp->val != tab[0])
	{
		tmp = tmp->nxt;
		b = ft_rotate(b, 'b');
	}
	return (b);
}*/

void	ft_chunk_a(t_elem **a, t_elem **b, int *chunk, int lastchunk)
{
	t_elem	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (ft_is_chunk(chunk[lastchunk], *a))
	{
		while (ft_is_chunk(chunk[i], *a))
		{
			if (tmp->val < chunk[i])
			{
				if (ft_is_min(*b, tmp->val))
					*b = ft_set_min_before_pb(*b, tmp->val);
				else
					*b = ft_set_inter_before_pb(*b, tmp->val);
				/*if (ft_is_min(*b, tmp->val))
					*b = ft_set_min_before_pb(*b, tmp->val);
				else
				{
					*b = ft_set_before_pb(*b, tmp->val);
				}*/
				*b = ft_push_x_to_y(a, *b, 'b');
				/*tmp = tmp->nxt;*/
				tmp = *a;
			}
			else
			{
				*a = ft_ra_or_rra(*a, chunk[i]);
				tmp = *a;
			}
		}
		i++;
	}
}
