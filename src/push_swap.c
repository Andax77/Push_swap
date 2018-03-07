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

void	ft_affichage(t_pile *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nbr);
		lst = lst->next;
	}
	printf("\n");
}

void	ft_clear(t_pile *lst)
{
	while (lst)
	{
		lst = lst->next;
		free(lst);
	}
}

int		main(int argc, char *argv[])
{
	t_pile *pile;
	t_pile *pile2;

	pile2 = NULL;
	if (argc == 1)
		return (0);
	if (argc > 2)
		init_pile(argv, &pile, 1);
	else
		init_pile(ft_strsplit(argv[1], ' '), &pile, 0);
	ft_affichage(pile);
	ft_pb(&pile, &pile2);
	ft_pb(&pile, &pile2);
	ft_pb(&pile, &pile2);
	ft_affichage(pile2);
	ft_rrb(&pile2);
	ft_affichage(pile2);
	// ft_algo(&pile, &pile2, argc);
	// ft_affichage(pile);
	// if (pile2)
	// 	ft_affichage(pile2);
	ft_clear(pile);
	ft_clear(pile2);
	return (1);
}
