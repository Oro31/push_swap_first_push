/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:36:36 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 18:37:58 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_min(t_elem *b, int d)
{
	t_elem	*tmp;
	int		*tab;
	int		i;

	tmp = b;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	tab = ft_list_to_tab(b);
	tab = ft_sort(tab, i);
	if (d < tab[0])
		return (1);
	else if (d > tab[i - 1])
		return (1);
	return (0);
}

t_elem	*ft_set_min_before_pb(t_elem *b, int val)
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
	b = ft_rotate(b, 'b');
	return (b);
}
