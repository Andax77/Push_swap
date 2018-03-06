/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:42:00 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/28 10:42:21 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_pile **lst)
{
	while (*lst)
	{
		free(*lst);
		*lst = (*lst)->next;
	}
}

int		main(int argc, char *argv[])
{
	t_pile *pile;
	t_pile *pile2;

	if (argc == 1)
		return (0);
	if (argc > 2)
		init_pile(argv, &pile, 1);
	else
		init_pile(ft_strsplit(argv[1], ' '), &pile, 0);
	ft_pb(&pile, &pile2);
	ft_pa(&pile, &pile2);
	ft_pb(&pile, &pile2);
	ft_pa(&pile, &pile2);
	ft_pb(&pile, &pile2);
	while (pile)
	{
		printf("%d\n", pile->nbr);
		pile = pile->next;
	}
	printf("\n");
	while (pile2)
	{
		printf("%d\n", pile2->nbr);
		pile2 = pile2->next;
	}
	ft_clear(&pile);
	ft_clear(&pile2);
	return (1);
}
