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

void		ft_min_up(t_pile **pile, int *a)
{
	t_pile	*tmp;
	int		argc;
	int		i;

	i = 0;
	tmp = *pile;
	argc = 0;
	while (tmp && ++argc)
		tmp = tmp->next;
	tmp = *pile;
	while (tmp->nbr != ft_min_num(*pile) && ++i)
		tmp = tmp->next;
	if (i > argc / 2)
		while (i != argc && ++i && ++(*a))
			ft_rra(pile);
	else
		while (i != 0 && i-- && ++(*a))
			ft_ra(pile);
	// Enlever le a
}

void		ft_big_up(t_pile **pile, int *a)
{
	t_pile	*tmp;
	int		argc;
	int		i;

	i = 0;
	tmp = *pile;
	argc = 0;
	while (tmp && ++argc)
		tmp = tmp->next;
	tmp = *pile;
	while (tmp->nbr != ft_big_num(*pile) && ++i)
		tmp = tmp->next;
	if (i > argc / 2)
		while (i != argc && ++i && ++(*a))
			ft_rra(pile);
	else
		while (i != 0 && i-- && ++(*a))
			ft_ra(pile);
	// Enlever le a
}

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
	if ((*pile2)->nbr < end_pile(*pile2) &&  ++i)
		ft_rb(pile2);
	if ((*pile2)->nbr < (*pile2)->next->nbr && ++i)
		ft_sb(pile2);
	return (i);
}

void	ft_algo(t_pile **pile, t_pile **pile2, int argc)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (a != argc)
	{
		if (*pile2 && (*pile2)->next)
			i += check_pile2(pile);
		if (((*pile)->nbr < (*pile)->next->nbr) && ((*pile)->nbr < end_pile(*pile))
			&& ((*pile)->next->nbr < end_pile(*pile)) && !ft_check_sort(*pile) && ++i)
			ft_pb(pile, pile2);
		if ((*pile)->nbr > (*pile)->next->nbr && !ft_check_sort(*pile) && ++i)
			ft_sa(pile);
		while ((*pile)->nbr > end_pile(*pile) && !ft_check_sort(*pile) && ++i)
			ft_rra(pile);
		if ((*pile)->next->nbr > end_pile(*pile) && !ft_check_sort(*pile))
		{
			i += 2;
			ft_rra(pile);
			ft_sa(pile);
		}
		a++;
	}
	while (*pile2 && ++i)
		ft_pa(pile, pile2);
	printf("Instructions : %d\n", i);
//Enlever les i pour Instructions
}
