/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:32:35 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 14:31:22 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int		ft_is_min(t_elem *b, int d)
{
	t_elem	*tmp;
	int		*tab;

	if (b == NULL)
		return (0);
	tmp = b;
	while (tmp)
	{
		if (tmp->val < d)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}*/

t_elem	*ft_push_x_to_y(t_elem **x, t_elem *y, char c)
{
	int		xval;

	if (*x == NULL)
		return (y);
	xval = (*x)->val;
	y = ft_hadd_tolist(y, xval);
	*x = ft_hdelete_inlist(*x);
	if (c == 'a')
		printf("pa\n");
	else if (c == 'b')
		printf("pb\n");
	return (y);
}
