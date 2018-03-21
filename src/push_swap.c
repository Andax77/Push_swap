/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:42:00 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/28 10:42:21 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_stack(char **argv, int fre)
{
	int		ret;

	ret = 0;
	while (argv[ret])
		ret++;
	ret--;
	if (fre)
		ft_splitclear(argv);
	return (ret + 1);
}

void		ft_go(t_pile **pile, t_pile **pile2, int a, int argc)
{
	if (a == 1)
		return ;
	else if (a < 6)
		ft_algo(pile, pile2, argc - 1);
	else if (a < 25)
		ft_algo2(pile, pile2, argc - 1);
	else
		ft_algo3(pile, pile2, argc);
}

int			main(int argc, char *argv[])
{
	t_pile	*pile;
	t_pile	*pile2;
	int		a;

	pile = NULL;
	pile2 = NULL;
	if (argc < 2)
		return (0);
	if (argc > 2 && (a = ft_stack(argv, 0)))
		init_pile(argv, &pile, 1, 0);
	else
	{
		if (go_split(argv[1]) && (a = ft_stack(ft_strsplit(argv[1], ' '), 1)))
			init_pile(ft_strsplit(argv[1], ' '), &pile, 0, 1);
		else if ((a = 1))
			add_pile(&pile, ft_atoi(argv[1]));
	}
	ft_go(&pile, &pile2, a, pile_size(pile));
	ft_clear(pile);
	if (pile2)
		ft_clear(pile2);
	return (1);
}
