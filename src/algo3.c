/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:41:19 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/08 16:41:20 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_sort2(t_pile *pile2)
{
	t_pile	*tmp;

	tmp = pile2;
	while (tmp->next)
	{
		if (tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_separate_pile(t_pile **pile, t_pile **pile2, int med, int *a)
{
	while (ft_big_num(*pile) >= med)
	{
		while ((*pile)->nbr >= med && ++(*a))
			ft_pb(pile, pile2, 1);
		if (end_pile(*pile) >= med && (*a += 2))
		{
			ft_rra(pile, 1);
			ft_pb(pile, pile2, 1);
		}
		else if ((*pile)->next->nbr >= med && (*a += 2))
		{
			ft_sa(pile, 1);
			ft_pb(pile, pile2, 1);
		}
		while ((*pile)->nbr < med && ft_big_num(*pile) >= med && ++(*a))
			ft_ra(pile, 1);
	}
}

int			ft_next_min(t_pile *pile, int old)
{
	int		new;

	new = ft_big_num(pile);
	while (pile)
	{
		if (new > pile->nbr && pile->nbr > old)
			new = pile->nbr;
		pile = pile->next;
	}
	return (new);
}

void		ft_partb(t_pile **pile, t_pile **pile2, int med, int *a)
{
	t_pile	*tmp;

	tmp = *pile;
	while (tmp->nbr <= med && ++a)
	{
		ft_pb(pile, pile2, 1);
		tmp = tmp->next;
	}
	while (*pile2 && ++a)
	{
		ft_big_up2(pile2, a);
		ft_pa(pile, pile2, 1);
	}
}

void		ft_algo3(t_pile **pile, t_pile **pile2, int argc)
{
	int		med;
	int		min;
	int		a;

	min = ft_min_num(*pile);
	med = ft_mediane(*pile, argc);
	a = 0;
	if (!(ft_check_sort(*pile)))
	{
		ft_separate_pile(pile, pile2, med, &a);
		ft_min_up(pile, &a);
		while (*pile2)
		{
			ft_min_up2(pile2, &a);
			ft_pa(pile, pile2, 1);
			ft_ra(pile, 1);
		}
		if (!ft_check_sort(*pile))
			ft_partb(pile, pile2, med, &a);
	}
}
