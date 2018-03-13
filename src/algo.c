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
	if ((*pile2)->nbr < (*pile2)->next->nbr && ++i)
	{
		ft_putstr("sb\n");
		ft_sb(pile2);
	}
	if ((*pile2)->nbr < end_pile(*pile2) && ++i)
	{
		ft_putstr("rb\n");
		ft_rb(pile2);
	}
	return (i);
}

void	ft_algo(t_pile **pile, t_pile **pile2, int argc)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while ((a != argc + 10 || !ft_check_sort(*pile)) && (*pile)->next)
	{
		if (*pile2 && (*pile2)->next)
			i += check_pile2(pile2);
		if (((*pile)->nbr < (*pile)->next->nbr) && ((*pile)->nbr < end_pile(*pile))
		&& !ft_check_sort(*pile) && ++i)
		{
			ft_putstr("pb\n");
			ft_pb(pile, pile2);
		}
		if ((*pile)->nbr > (*pile)->next->nbr && !ft_check_sort(*pile) && ++i)
		{
			ft_putstr("sa\n");
			ft_sa(pile);
		}
		while ((*pile)->nbr > end_pile(*pile) && !ft_check_sort(*pile) && ++i)
		{
			ft_putstr("rra\n");
			ft_rra(pile);
		}
		a++;
	}
	while (*pile2 && ++i)
	{
		ft_pa(pile, pile2);
		ft_putstr("pa\n");
	}
	// ft_affichage(*pile);
	// printf("Instructions : %d\n", i);
//Enlever les i pour Instructions
}
