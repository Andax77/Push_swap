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

void	ft_sa(t_pile **pile, int dis)
{
	int data;

	if (!(*pile) || !((*pile)->next))
		return ;
	data = (*pile)->nbr;
	(*pile)->nbr = (*pile)->next->nbr;
	(*pile)->next->nbr = data;
	if (dis)
		ft_putstr("sa\n");
}

void	ft_sb(t_pile **pile2, int dis)
{
	int data;

	if (!(*pile2) || !((*pile2)->next))
		return ;
	data = (*pile2)->nbr;
	(*pile2)->nbr = (*pile2)->next->nbr;
	(*pile2)->next->nbr = data;
	if (dis)
		ft_putstr("sb\n");
}

void	ft_ss(t_pile **pile, t_pile **pile2, int dis)
{
	if (!(*pile) || !(*pile)->next || !(*pile2) || !(*pile2)->next)
		return ;
	ft_sa(pile, 0);
	ft_sb(pile2, 0);
	if (dis)
		ft_putstr("ss\n");
}

void	ft_pa(t_pile **pile, t_pile **pile2, int dis)
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
	if (dis)
		ft_putstr("pa\n");
}

void	ft_pb(t_pile **pile, t_pile **pile2, int dis)
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
	if (dis)
		ft_putstr("pb\n");
}
