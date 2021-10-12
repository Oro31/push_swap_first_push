/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:23:55 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 18:17:20 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_set_b_before_fill_a(t_elem *b)
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
	while (tmp->val != tab[i - 1])
	{
		tmp = tmp->nxt;
		b = ft_rotate(b, 'b');
	}
	return (b);
}

t_elem	*ft_ra_or_rra(t_elem *a, int chunk)
{
	t_elem	*tmp;
	int		*tab;
	int		i;
	int		j;

	if (a == NULL)
		return (NULL);
	else if (a->nxt == NULL)
		return (a);
	tab = ft_list_to_tab(a);
	tmp = a;
	j = 0;
	while (tmp->nxt)
	{
		tmp = tmp->nxt;
		j++;
	}
	i = 0;
	while (tab[j] > chunk)
	{
		j--;
		i++;
	}
	j = 0;
	while (tab[j] > chunk)
		j++;
	if (i < j)
	{
		while (i >= 0)
		{
			a = ft_reverse_rotate(a, 'a');
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			a = ft_rotate(a, 'a');
			j--;
		}
	}
	return (a);
}

void	ft_fill_a(t_elem **a, t_elem **b)
{
	while (*b)
	{
		*a = ft_push_x_to_y(b, *a, 'a');
		/**b = ft_reverse_rotate(*b, 'b');*/
	}
}
