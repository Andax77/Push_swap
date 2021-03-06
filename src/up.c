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

int		ft_min_up(t_pile **pile)
{
	t_pile	*tmp;
	int		argc;
	int		i;

	tmp = *pile;
	argc = 0;
	while (tmp && ++argc && !(i = 0))
		tmp = tmp->next;
	tmp = *pile;
	while (tmp->nbr != ft_min_num(*pile) && ++i)
		tmp = tmp->next;
	if (i > argc / 2)
		while (i != argc && ++i)
			ft_rra(pile, 1);
	else
		while (i != 0 && i--)
			ft_ra(pile, 1);
	return (1);
}

int		ft_big_up(t_pile **pile)
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
		while (i != argc && ++i)
			ft_rra(pile, 1);
	else
		while (i != 0 && i--)
			ft_ra(pile, 1);
	return (1);
}

int		ft_min_up2(t_pile **pile)
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
		while (i != argc && ++i)
			ft_rrb(pile, 1);
	else
		while (i != 0 && i--)
			ft_rb(pile, 1);
	return (1);
}

int		ft_big_up2(t_pile **pile)
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
		while (i != argc && ++i)
			ft_rrb(pile, 1);
	else
		while (i != 0 && i--)
			ft_rb(pile, 1);
	return (1);
}
