/* ************************************************************************** */
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

	if (!(*pile)->nbr || (*pile)->next->nbr)
		return ;
	data = (*pile)->nbr;
	(*pile)->nbr = (*pile)->next->nbr;
	(*pile)->next->nbr = data;
}

void	ft_sb(t_pile **pile2)
{
	int data;

	if (!(*pile2)->nbr || (*pile2)->next->nbr)
		return ;
	data = (*pile2)->nbr;
	(*pile2)->nbr = (*pile2)->next->nbr;
	(*pile2)->next->nbr = data;
}

void	ft_ss(t_pile **pile, t_pile **pile2)
{
	if (!(*pile)->nbr || (*pile)->next->nbr ||
		!(*pile2)->nbr || (*pile2)->next->nbr)
		return ;
	ft_sa(pile);
	ft_sb(pile2);
}

void	ft_pa(t_pile **pile, t_pile **pile2)
{
	t_pile *new;

	if (!*pile2)
		return ;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Error\n");
	new->nbr = (*pile2)->nbr;
	new->next = *pile;
	*pile = new;
	free(*pile2);
	*pile2 = (*pile2)->next;
}

void	ft_pb(t_pile **pile, t_pile **pile2)
{
	static	t_pile	*last;
	t_pile			*new;

	if (!*pile)
		return ;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Error\n");
	new->nbr = (*pile)->nbr;
	free(*pile);
	*pile = (*pile)->next;
	if (last == NULL)
	{
		*pile2 = new;
		last = *pile2;
	}
	else
	{
		new->next = *pile2;
		*pile2 = new;
	}
}
