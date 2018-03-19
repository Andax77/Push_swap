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

int			go_split2(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && ft_isdigit(str[i - 1]))
		{
			while (str[i] == ' ')
				i++;
			if (ft_isdigit(str[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int			ft_ra(t_pile **pile, int dis)
{
	int		tmp;
	t_pile	*new;
	t_pile	*fre;

	if (!*pile || !(*pile)->next)
		return (1);
	tmp = (*pile)->nbr;
	fre = *pile;
	*pile = (*pile)->next;
	free(fre);
	new = *pile;
	while (new->next)
		new = new->next;
	if (!(new->next = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->next->nbr = tmp;
	new->next->next = NULL;
	if (dis)
		ft_putstr("ra\n");
	return (1);
}

int			ft_rb(t_pile **pile2, int dis)
{
	int		tmp;
	t_pile	*new;
	t_pile	*fre;

	if (!*pile2 || !(*pile2)->next)
		return (1);
	tmp = (*pile2)->nbr;
	fre = *pile2;
	*pile2 = (*pile2)->next;
	free(fre);
	new = *pile2;
	while (new->next)
		new = new->next;
	if (!(new->next = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Malloc Error\n");
	new->next->nbr = tmp;
	new->next->next = NULL;
	if (dis)
		ft_putstr("rb\n");
	return (1);
}

int			ft_rr(t_pile **pile, t_pile **pile2, int dis)
{
	if (!*pile || !(*pile)->next || !*pile2 || !(*pile2)->next)
		return (1);
	ft_ra(pile, 0);
	ft_rb(pile2, 0);
	if (dis)
		ft_putstr("rrr\n");
	return (1);
}
