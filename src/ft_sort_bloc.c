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

void		ft_sort_bloc(t_pile **pile, t_pile **pile2, int size, int first)
{
	int		i;
	int		back;

	back = 0;
	i = 0;
	// printf("Size %d\n", (size >> 1) + (size & 1));
	if (!(*pile2))
		return ;
	if (!first)
	{
		while (i != (size >> 1) && ++i)
		{
			if (back && (*pile)->nbr > end_pile(*pile2) && (*pile)->nbr > (*pile2)->nbr)
			{
				while (back > 0 && (*pile)->nbr > end_pile(*pile2) && back--)
					ft_rrb(pile2, 1);
				ft_pb(pile, pile2, 1);
			}
			else if ((*pile)->nbr < end_pile(*pile2) && (*pile)->nbr > (*pile)->nbr)
				ft_pb(pile, pile2, 1);
			else if ((*pile)->nbr > (*pile2)->nbr)
				ft_pb(pile, pile2, 1);
			else
			{
				// printf("Size %d\n", (size >> 1) + (size & 1));
				// printf("Back %d\n",back );
				while ((*pile)->nbr < (*pile2)->nbr && back != (size >> 1) + (size & 1) && ++back)
					ft_rb(pile2, 1);
				ft_pb(pile, pile2, 1);
			}
		}
		while (back > 0 && back--)
			ft_rrb(pile2, 1);
	}
	else
	{
		while (i != (size >> 1) + (size & 1) && ++i)
		{
			if (back && (*pile2)->nbr < end_pile(*pile) && (*pile2)->nbr < (*pile)->nbr)
			{
				// printf("Back %d\n",back );
				while (back >= 0 + (size & 1) && (*pile2)->nbr < end_pile(*pile) && back--)
					ft_rra(pile, 1);
				ft_pa(pile, pile2, 1);
			}
			else if ((*pile2)->nbr > end_pile(*pile) && (*pile2)->nbr < (*pile)->nbr)
				ft_pa(pile, pile2, 1);
			else if ((*pile2)->nbr < (*pile)->nbr)
				ft_pa(pile, pile2, 1);
			else
			{
				while ((*pile2)->nbr > (*pile)->nbr && back != (size >> 1) && ++back)
					ft_ra(pile, 1);
				ft_pa(pile, pile2, 1);
			}
		}
		while (back >= (size & 1) && back--)
			ft_rra(pile, 1);
	}
	// printf("Stop\n");
}
