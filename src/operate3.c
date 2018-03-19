/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:29:18 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/07 11:29:19 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rmtake_pile(t_pile *begin)
{
	t_pile	*tmp;
	int		nbr;

	while (begin->next)
	{
		tmp = begin;
		begin = begin->next;
	}
	tmp->next = NULL;
	nbr = begin->nbr;
	free(begin);
	return (nbr);
}

int		ft_rra(t_pile **pile, int dis)
{
	t_pile	*new;

	if (!*pile || !(*pile)->next)
		return (1);
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->nbr = ft_rmtake_pile(*pile);
	new->next = *pile;
	*pile = new;
	if (dis)
		ft_putstr("rra\n");
	return (1);
}

int		ft_rrb(t_pile **pile2, int dis)
{
	t_pile	*new;

	if (!*pile2 || !(*pile2)->next)
		return (1);
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->nbr = ft_rmtake_pile(*pile2);
	new->next = *pile2;
	*pile2 = new;
	if (dis)
		ft_putstr("rrb\n");
	return (1);
}

int		ft_rrr(t_pile **pile, t_pile **pile2, int dis)
{
	if (!(*pile) || !(*pile)->next || !(*pile2) || !(*pile2)->next)
		return (1);
	ft_ra(pile, 0);
	ft_rb(pile2, 0);
	if (dis)
		ft_putstr("rrr\n");
	return (1);
}
