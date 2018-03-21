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

int			pile_size(t_pile *pile)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = pile;
	while (tmp && ++i)
		tmp = tmp->next;
	return (i);
}

static void	ft_sort_int(t_pile **pile, int size)
{
	if (size == 2)
	{
		if ((*pile)->nbr > (*pile)->next->nbr)
			ft_sa(pile, 1);
	}
	else
	{
		while (!ft_check_sort(*pile, size))
		{
			if ((*pile)->next->nbr > (*pile)->next->next->nbr)
				ft_ra(pile, 1) && ft_sa(pile, 1) && ft_rra(pile, 1);
			if ((*pile)->nbr > (*pile)->next->nbr)
				ft_sa(pile, 1);
		}
	}
}

static void	ft_sort_int2(t_pile **pile2, int size)
{
	if (size == 2)
	{
		if ((*pile2)->nbr < (*pile2)->next->nbr)
			ft_sb(pile2, 1);
	}
	else
	{
		while (!ft_check_sort2(*pile2, size))
		{
			if ((*pile2)->next->nbr < (*pile2)->next->next->nbr)
				ft_rb(pile2, 1) && ft_sb(pile2, 1) && ft_rrb(pile2, 1);
			if ((*pile2)->nbr < (*pile2)->next->nbr)
				ft_sb(pile2, 1);
		}
	}
}

void		merge_sort(t_pile **pile, t_pile **pile2, int first, int size)
{
	if (size <= 3)
	{
		if (first)
			ft_sort_int(pile, size);
		else
			ft_sort_int2(pile2, size);
		return ;
	}
	ft_separate_pile(pile, pile2, first, size);
	merge_sort(pile, pile2, 1, size >> 1);
	merge_sort(pile, pile2, 0, (size >> 1) + (size & 1));
	ft_sort_bloc(pile, pile2, size, first);
}

void		ft_algo3(t_pile **pile, t_pile **pile2, int argc)
{
	int		a;

	a = 0;
	if (!(ft_check_sort(*pile, argc)))
		merge_sort(pile, pile2, 1, argc);
}
