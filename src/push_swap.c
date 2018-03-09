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

void	ft_affichage(t_pile *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nbr);
		lst = lst->next;
	}
	printf("\n");
}

void	ft_clear(t_pile *lst)
{
	t_pile *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int		ft_stack(char **argv)
{
	int	ret;

	ret = 0;
	while (argv[ret])
		ret++;
	ret--;
	return (ret);;
}

void	ft_go(t_pile **pile, t_pile **pile2, int a, int argc)
{
	if (a < 6)
		ft_algo(pile, pile2, argc - 1);
	else if (a < 25)
		ft_algo2(pile, pile2, argc - 1);
	else
		ft_algo3(pile, pile2, argc - 1);
}

int		main(int argc, char *argv[])
{
	t_pile	*pile;
	t_pile	*pile2;
	int		a;

	pile2 = NULL;
	if (argc == 1)
		return (0);
	if (argc > 2)
	{
		init_pile(argv, &pile, 1);
		if (!(a = ft_stack(argv)))
			ft_error("Strsplit Error\n");
	}
	else
	{
		init_pile(ft_strsplit(argv[1], ' '), &pile, 0);
		if (!(a = ft_stack(ft_strsplit(argv[1], ' '))))
			ft_error("Strsplit Error\n");
	}
	ft_affichage(pile);
	ft_go(&pile, &pile2, a, argc);
	ft_affichage(pile);
	if (pile2)
	{
		printf("PAS FINI\n");
		ft_affichage(pile2);
	}
	ft_clear(pile);
	ft_clear(pile2);
	return (1);
}
