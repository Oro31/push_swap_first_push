/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:48:39 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/12 18:41:21 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	t_elem	*tmp;
	int		*tab;
	int		*chunk;
	int		i;

	a = malloc(sizeof(t_elem));
	if (!a)
		return (0);
	a = NULL;
	b = malloc(sizeof(t_elem));
	if (!b)
		return (0);
	b = NULL;
	i = 0;
	while (++i < argc)
		a = ft_eadd_tolist(a, atoi(argv[i]));
	tab = ft_list_to_tab(a);
	tab = ft_sort(tab, (argc - 1));
	chunk = ft_get_chunk(5, (argc - 1), tab);
	ft_chunk_a(&a, &b, chunk, 5);
	b = ft_set_b_before_fill_a(b);
	ft_fill_a(&a, &b);
	ft_print_list(a);
	return (0);
}
