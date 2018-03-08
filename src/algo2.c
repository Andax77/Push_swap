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

void		ft_min_num(t_pile **pile, t_pile *tmp, int *min)
{
	tmp = *pile;
	*min = (*pile)->nbr;
	tmp = tmp->next;
	while (tmp)
	{
		if (*min > tmp->nbr)
			*min = tmp->nbr;
		tmp = tmp->next;
	}
}

void		ft_algo2(t_pile **pile, t_pile **pile2, int argc)
{
	int i;
	t_pile	*tmp;
	int		min;
	int a;

	a = 0;
	if (argc == 0)
		return ;
	while (argc != 1 && !(i = 0))
	{
		ft_min_num(pile, tmp, &min);
		tmp = *pile;
		while (tmp->nbr != min && ++i)
			tmp = tmp->next;
		if (i > argc / 2)
			while (i != argc && ++i && ++a)
				ft_rra(pile);
		else
			while (i != 0 && i-- && ++a)
				ft_ra(pile);
		ft_pb(pile, pile2);
		a++;
		argc--;
	}
	while (*pile2 && ++a)
		ft_pa(pile, pile2);
		printf("Instructions %d\n",a );
// Enlever le a
}
