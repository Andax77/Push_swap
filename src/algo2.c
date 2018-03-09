/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:18:08 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/08 14:18:09 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_mediane(t_pile *pile, int argc)
{
	int		ret;
	int		i;
	t_pile	*tmp;
	int		min;

	i = 0;
	ret = ft_min_num(pile);
	i++;
	while (i != argc / 2)
	{
		tmp = pile;
		min = tmp->nbr;
		tmp = tmp->next;
		while (tmp)
		{
			if (min > tmp->nbr && tmp->nbr != ret && tmp->nbr > ret)
				min = tmp->nbr;
			tmp = tmp->next;
		}
		ret = min;
		i++;
	}
	return (ret);
}

int			ft_min_num(t_pile *pile)
{
	int		min;

	min = pile->nbr;
	pile = pile->next;
	while (pile)
	{
		if (min > pile->nbr)
			min = pile->nbr;
		pile = pile->next;
	}
	return (min);
}

int			ft_big_num(t_pile *pile)
{
	int		big;

	big = pile->nbr;
	pile = pile->next;
	while (pile)
	{
		if (big < pile->nbr)
			big = pile->nbr;
		pile = pile->next;
	}
	return (big);
}

void		ft_algo2(t_pile **pile, t_pile **pile2, int argc)
{
	int a;

	a = 0;
	if (argc == 0)
		return ;
	while (argc != 1)
	{
		ft_min_up(pile, &a);
		ft_pb(pile, pile2);
		a++;
		argc--;
	}
	while (*pile2 && ++a)
		ft_pa(pile, pile2);
	printf("Instructions %d\n",a );
// Enlever le a
}
