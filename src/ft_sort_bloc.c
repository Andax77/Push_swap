/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:08:15 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/20 13:08:16 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_sort2(t_pile *pile2, int size)
{
	t_pile	*tmp;

	tmp = pile2;
	while (tmp->next && --size)
	{
		if (tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_separate_pile(t_pile **pile, t_pile **pile2, int first, int size)
{
	int		i;

	i = 0;
	if (first)
	{
		while (i != (size >> 1) + (size & 1) && ++i)
			ft_pb(pile, pile2, 1);
	}
	else
	{
		while (i != (size >> 1) && ++i)
			ft_pa(pile, pile2, 1);
	}
}

static void	ft_bloc_a(t_pile **pile, t_pile **pile2, int size)
{
	int		i;
	int		back;

	back = 0;
	i = 0;
	while (i != (size >> 1) && ++i)
	{
		if (back && (*pile)->nbr > end_pile(*pile2) && (*pile)->nbr >
																(*pile2)->nbr)
			while (back > 0 && (*pile)->nbr > end_pile(*pile2) && back--)
				ft_rrb(pile2, 1);
		else
			while ((*pile)->nbr < (*pile2)->nbr && back != (size >> 1) +
														(size & 1) && ++back)
				ft_rb(pile2, 1);
		ft_pb(pile, pile2, 1);
	}
	while (back > 0 && back--)
		ft_rrb(pile2, 1);
}

static void	ft_bloc_b(t_pile **pile, t_pile **pile2, int size)
{
	int		i;
	int		back;

	back = 0;
	i = 0;
	while (i != (size >> 1) + (size & 1) && ++i)
	{
		if (back && (*pile2)->nbr < end_pile(*pile) && (*pile2)->nbr <
																(*pile)->nbr)
			while (back >= 0 + (size & 1) && (*pile2)->nbr < end_pile(*pile) &&
																		back--)
				ft_rra(pile, 1);
		else
			while ((*pile2)->nbr > (*pile)->nbr && back != size / 2 && ++back)
				ft_ra(pile, 1);
		ft_pa(pile, pile2, 1);
	}
	while (back >= (size & 1) && back--)
		ft_rra(pile, 1);
}

void		ft_sort_bloc(t_pile **pile, t_pile **pile2, int size, int first)
{
	if (!(*pile2))
		return ;
	if (!first)
		ft_bloc_a(pile, pile2, size);
	else
		ft_bloc_b(pile, pile2, size);
}
