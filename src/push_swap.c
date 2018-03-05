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

int		main(int argc, char *argv[])
{
	t_pile *pile;

	if (argc == 1)
		return (0);
	if (argc > 2)
		init_pile(argv, &pile, 1);
	else
		init_pile(ft_strsplit(argv[1], ' '), &pile, 0);

	
	while (pile)
	{
		printf("%d\n", pile->nbr);
		pile = pile->next;
	}
	return (1);
}
