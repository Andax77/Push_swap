/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:42:00 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/28 10:42:21 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(char **str, int a)
{
	int i;

	i = 1;
	while (str[a])
	{
		while (str[a + i])
		{
			if (ft_atoi(str[a]) == ft_atoi(str[a + i]))
				ft_error("Error\n");
			i++;
		}
		i = 1;
		a++;
	}
}

void	check_pile(char **str, int a)
{
	int		i;
	long	nbr;
	int		check;

	while (str[a] && !(check = 0))
	{
		i = 0;
		if (!(nbr = 0) && str[a][i] == '-' && ++i)
			check = 1;
		!ft_isdigit(str[a][i]) ? ft_error("Error\n") : 1;
		while (str[a][i])
		{
			if (!ft_isdigit(str[a][i]) || (str[a][i] == '-' && check == 1))
				ft_error("Error\n");
			nbr = nbr * 10 + (str[a][i] - '0');
			i++;
		}
		if (check)
			nbr = -nbr;
		if (nbr < -2147483648 || nbr > 2147483647)
			ft_error("Error\n");
		a++;
	}
}

void	add_pile(t_pile **begin, int value)
{
	static	t_pile	*last;
	t_pile			*new;

	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		ft_error("Error\n");
	new->nbr = value;
	new->next = NULL;
	if (last == NULL)
	{
		*begin = new;
		last = *begin;
	}
	else
	{
		last->next = new;
		last = new;
	}
}

void	ft_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(0);
}

void	init_pile(char *argv[], t_pile **begin, int a)
{
	int		i;

	i = 0;
	check_pile(argv, a);
	if (argv[0] && argv[1])
		check_double(argv, a);
	while (argv[a])
	{
		add_pile(begin, ft_atoi(argv[a]));
		a++;
	}
}
