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

int			ft_check_sort(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
	while (ft_big_num(*pile) > med)
	{
		while ((*pile)->nbr > med && ++(*a))
			ft_pb(pile, pile2);
		while (end_pile(*pile) > med)
		{
			ft_rra(pile);
			ft_pb(pile, pile2);
			*a += 2;
		}
		while ((*pile)->next->nbr > med)
		{
			ft_sa(pile);
			ft_pb(pile, pile2);
			*a += 2;
		}
		if (ft_big_num(*pile) > med && ++(*a))
			ft_rra(pile);
	}
}
//Enlever a

void		ft_algo3(t_pile **pile, t_pile **pile2, int argc)
{
	t_pile	*tmp;
	int		a;
	int		med;

	med = ft_mediane(*pile, argc);
	a = 0;
	if (!(ft_check_sort(*pile)))
	{
		ft_separate_pile(pile, pile2, med, &a);
		ft_min_up(pile, &a);
		while (*pile2)
		{
			ft_min_up2(pile2, &a);
			ft_pa(pile, pile2);
			ft_ra(pile);
			a += 2;
		}
		tmp = *pile;
		if (!ft_check_sort(*pile))
		{
			while (tmp->nbr <= med)
			{
				ft_pb(pile, pile2);
				tmp = tmp->next;
				a++;
			}
			while (*pile2)
			{
				ft_big_up2(pile2, &a);
				ft_pa(pile, pile2);
				a++;
			}
		}
	}
	//Enlver le a
	printf("Instrucitons %d\n", a);
}
