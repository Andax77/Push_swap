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

void	ft_rra(t_pile **pile)
{
	t_pile	*new;

	if (!*pile || !(*pile)->next)
		return ;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->nbr = ft_rmtake_pile(*pile);
	new->next = *pile;
	*pile = new;
}

void	ft_rrb(t_pile **pile2)
{
	t_pile	*new;

	if (!*pile2 || !(*pile2)->next)
		return ;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->nbr = ft_rmtake_pile(*pile2);
	new->next = *pile2;
	*pile2 = new;
}

void	ft_rrr(t_pile **pile, t_pile **pile2)
{
	if (!(*pile) || !(*pile)->next || !(*pile2) || !(*pile2)->next)
		return ;
	ft_ra(pile);
	ft_rb(pile2);
}
