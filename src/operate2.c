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

void	ft_ra(t_pile **pile)
{
	int tmp;

	if (!*pile || !(*pile)->next)
		return ;
	tmp = (*pile)->nbr;
	free(*pile);
	*pile = (*pile)->next;
	add_pile(pile, tmp);
}

void	ft_rb(t_pile **pile2)
{
	int		tmp;
	t_pile	*new;

	if (!*pile2 || !(*pile2)->next)
		return ;
	new = *pile2;
	tmp = (*pile2)->nbr;
	free(*pile2);
	*pile2 = (*pile2)->next;
	while (new)
		new = new->next;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Error\n");
	new->nbr = tmp;
	new->next = NULL;
	ft_affichage(*pile2);
}

void	ft_rr(t_pile **pile, t_pile **pile2)
{
	if (!*pile || !(*pile)->next || !*pile2 || !(*pile2)->next)
		return ;
	ft_ra(pile);
	ft_rb(pile2);
}
