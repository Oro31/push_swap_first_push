/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:57:58 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/09 16:59:03 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_swap(t_elem *list, char c)
{
	int		fval;
	int		sval;

	if (list == NULL)
		return (NULL);
	else if (list->nxt == NULL)
		return (list);
	fval = list->val;
	sval = list->nxt->val;
	list = ft_hdelete_inlist(list);
	list = ft_hdelete_inlist(list);
	list = ft_hadd_tolist(list, fval);
	list = ft_hadd_tolist(list, sval);
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
	return (list);
}
