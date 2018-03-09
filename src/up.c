/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:21:15 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/09 14:21:17 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_min_up(t_pile **pile, int *a)
{
	t_pile	*tmp;
	int		argc;
	int		i;

	i = 0;
	tmp = *pile;
	argc = 0;
	while (tmp && ++argc)
		tmp = tmp->next;
	tmp = *pile;
	while (tmp->nbr != ft_min_num(*pile) && ++i)
		tmp = tmp->next;
	if (i > argc / 2)
		while (i != argc && ++i && ++(*a))
			ft_rra(pile);
	else
		while (i != 0 && i-- && ++(*a))
			ft_ra(pile);
	// Enlever le a
}

void		ft_big_up(t_pile **pile, int *a)
{
	t_pile	*tmp;
	int		argc;
	int		i;

	i = 0;
	tmp = *pile;
	argc = 0;
	while (tmp && ++argc)
		tmp = tmp->next;
	tmp = *pile;
	while (tmp->nbr != ft_big_num(*pile) && ++i)
		tmp = tmp->next;
	if (i > argc / 2)
		while (i != argc && ++i && ++(*a))
			ft_rra(pile);
	else
		while (i != 0 && i-- && ++(*a))
			ft_ra(pile);
	// Enlever le a
}

void		ft_min_up2(t_pile **pile, int *a)
{
	t_pile	*tmp;
	int		argc;
	int		i;

	i = 0;
	tmp = *pile;
	argc = 0;
	while (tmp && ++argc)
		tmp = tmp->next;
	tmp = *pile;
	while (tmp->nbr != ft_min_num(*pile) && ++i)
		tmp = tmp->next;
	if (i > argc / 2)
		while (i != argc && ++i && ++(*a))
			ft_rrb(pile);
	else
		while (i != 0 && i-- && ++(*a))
			ft_rb(pile);
	// Enlever le a
}

void		ft_big_up2(t_pile **pile, int *a)
{
	t_pile	*tmp;
	int		argc;
	int		i;

	i = 0;
	tmp = *pile;
	argc = 0;
	while (tmp && ++argc)
		tmp = tmp->next;
	tmp = *pile;
	while (tmp->nbr != ft_big_num(*pile) && ++i)
		tmp = tmp->next;
	if (i > argc / 2)
		while (i != argc && ++i && ++(*a))
			ft_rrb(pile);
	else
		while (i != 0 && i-- && ++(*a))
			ft_rb(pile);
	// Enlever le a
}
