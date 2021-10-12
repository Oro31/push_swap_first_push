/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:58:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 16:22:25 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_rotate(t_elem *list, char c)
{
	int		val;

	if (list == NULL)
		return (NULL);
	else if (list->nxt == NULL)
		return (list);
	val = list->val;
	list = ft_hdelete_inlist(list);
	list = ft_eadd_tolist(list, val);
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
	return (list);
}
