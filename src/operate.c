/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:42:00 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/28 10:42:21 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_pile **pile)
{
	int data;

	if (!(*pile) || !((*pile)->next))
		return ;
	data = (*pile)->nbr;
	(*pile)->nbr = (*pile)->next->nbr;
	(*pile)->next->nbr = data;
}

void	ft_sb(t_pile **pile2)
{
	int data;

	if (!(*pile2) || !((*pile2)->next))
		return ;
	data = (*pile2)->nbr;
	(*pile2)->nbr = (*pile2)->next->nbr;
	(*pile2)->next->nbr = data;
}

void	ft_ss(t_pile **pile, t_pile **pile2)
{
	if (!(*pile) || !(*pile)->next || !(*pile2) || !(*pile2)->next)
		return ;
	ft_sa(pile);
	ft_sb(pile2);
}

void	ft_pa(t_pile **pile, t_pile **pile2)
{
	t_pile *new;
	t_pile *fre;

	if (!*pile2)
		return ;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->nbr = (*pile2)->nbr;
	new->next = *pile;
	*pile = new;
	fre = *pile2;
	*pile2 = (*pile2)->next;
	free(fre);
}

void	ft_pb(t_pile **pile, t_pile **pile2)
{
	t_pile *new;
	t_pile *fre;

	if (!*pile)
		return ;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->nbr = (*pile)->nbr;
	new->next = *pile2;
	*pile2 = new;
	fre = *pile;
	*pile = (*pile)->next;
	free(fre);
}
