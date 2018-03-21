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
		ft_rb(pile2, 1);
	if ((*pile2)->nbr < (*pile2)->next->nbr && ++i)
		ft_sb(pile2, 1);
	return (i);
}

void	ft_algo(t_pile **pile, t_pile **pile2, int argc)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while ((a != argc + 9 || !ft_check_sort(*pile, argc)))
	{
		if (*pile2 && (*pile)->nbr < (*pile2)->nbr)
			ft_pb(pile, pile2, 1);
		if (*pile2 && (*pile2)->next)
			i += check_pile2(pile2);
		if (((*pile)->nbr < (*pile)->next->nbr) &&
		((*pile)->nbr < end_pile(*pile)) && !ft_check_sort(*pile, argc + 1) &&
																			++i)
			ft_pb(pile, pile2, 1);
		if ((*pile)->nbr > (*pile)->next->nbr && !ft_check_sort(*pile, argc + 1)
																		&& ++i)
			ft_sa(pile, 1);
		while ((*pile)->nbr > end_pile(*pile) && !ft_check_sort(*pile, argc + 1)
																		&& ++i)
			ft_rra(pile, 1);
		a++;
	}
	while (*pile2 && ++i)
		ft_pa(pile, pile2, 1);
}
