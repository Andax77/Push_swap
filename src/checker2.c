/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:17:49 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/13 16:17:51 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_clear(t_pile *lst)
{
	t_pile	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void		ft_splitclear(char **str)
{
	int a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a++;
	}
	free(str);
}

int			ft_check_sort(t_pile *pile, int size)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next && --size)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			go_split(char *str)
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

void		ft_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(0);
}
