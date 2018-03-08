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

int			ft_check_sort(t_pile **pile)
{
	while (*pile)
	{
		if ((*pile)->nbr > (*pile)->next->nbr)
			return (0);
		*pile = (*pile)->next;
	}
	return (1);
}

void		ft_count_sort(t_pile *pile, int *i)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return ;
		(*i)++;
		tmp = tmp->next;
	}
}

// void		ft_go_sort(t_pile **pile, int i, int argc)
// {
// 	int		nbr;
// 	t_pile	*tmp;
//
// 	tmp = *pile;
// 	while (i != 0)
//
// }

void		ft_algo3(t_pile **pile, int argc)
{
	t_pile	*tmp;
	// t_pile	*new;
	int		i;

	while (!ft_check_sort(pile) && !(i = 0))
	{
		argc--;
		tmp = *pile;
		while (tmp)
		{
			ft_count_sort(tmp, &i);
			// ft_go_sort(&tmp, i, argc);
			tmp = tmp->next;
		}
		ft_affichage(*pile);
	}
}
