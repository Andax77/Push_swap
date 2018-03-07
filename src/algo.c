/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:56:02 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/07 15:56:03 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		end_pile(t_pile *pile)
{
	while (pile->next)
		pile = pile->next;
	return (pile->nbr);
}

int		check_pile2(t_pile **pile2)
{
	int i;

	i = 0;
	if ((*pile2)->nbr < end_pile(*pile2) && ++i)
		ft_rb(pile2);
	if ((*pile2)->nbr > (*pile2)->next->nbr && ++i)
		ft_sa(pile2);
	return (i);
}

void	ft_algo(t_pile **pile, t_pile **pile2, int argc)
{
	int i;
	int a;

	a = 1;
	i = 0;
	printf("%d < %d\n",(*pile)->nbr, end_pile(*pile));
	while (a != 10)
	{
		ft_affichage(*pile);
		if (*pile2 && (*pile2)->next)
			i += check_pile2(pile2);
		if (*pile2)
			ft_affichage(*pile2);
		printf("Stop ? Argc %d < %d\n", a, argc);
		if (((*pile)->nbr < (*pile)->next->nbr) && ((*pile)->nbr < end_pile(*pile))
			&& ((*pile)->next->nbr < end_pile(*pile)) && ++i)
			ft_pb(pile, pile2);
		if ((*pile)->nbr > (*pile)->next->nbr && ++i)
			ft_sa(pile);
		while ((*pile)->nbr > end_pile(*pile) && ++i)
			ft_rra(pile);
		while ((*pile)->next->nbr > end_pile(*pile))
		{
			i += 2;
			ft_rra(pile);
			ft_sa(pile);
			// ft_pb(pile, pile2);
		}
		a++;
	}
	while (*pile2 && ++i)
		ft_pa(pile, pile2);
	printf("Instructions : %d\n", i);
}