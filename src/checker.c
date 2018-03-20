/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:24:15 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/09 14:24:15 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_cmd_pile(t_pile **pile, t_pile **pile2, char *arg)
{
	if (ft_strcmp(arg, "sa") == 0)
		ft_sa(pile, 0);
	else if (ft_strcmp(arg, "sb") == 0)
		ft_sb(pile2, 0);
	else if (ft_strcmp(arg, "ss") == 0)
		ft_ss(pile, pile2, 0);
	else if (ft_strcmp(arg, "pa") == 0)
		ft_pa(pile, pile2, 0);
	else if (ft_strcmp(arg, "pb") == 0)
		ft_pb(pile, pile2, 0);
	else if (ft_strcmp(arg, "ra") == 0)
		ft_ra(pile, 0);
	else if (ft_strcmp(arg, "rb") == 0)
		ft_rb(pile2, 0);
	else if (ft_strcmp(arg, "rr") == 0)
		ft_rr(pile, pile2, 0);
	else if (ft_strcmp(arg, "rra") == 0)
		ft_rra(pile, 0);
	else if (ft_strcmp(arg, "rrb") == 0)
		ft_rrb(pile2, 0);
	else if (ft_strcmp(arg, "rrr") == 0)
		ft_rrr(pile, pile2, 0);
}

static void		ft_read_cmd(t_pile **pile, t_pile **pile2)
{
	char	*arg;
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(STDIN_FILENO, &arg)) == 1)
	{
		i++;
		ft_cmd_pile(pile, pile2, arg);
		free(arg);
	}
	if (ret == -1)
		ft_error("Error\n");
}

void			ft_end(t_pile *pile, t_pile *pile2, int size)
{
	if (ft_check_sort(pile, size))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_clear(pile);
	if (pile2)
		ft_clear(pile2);
}

int				main(int argc, char *argv[])
{
	t_pile		*pile;
	t_pile		*pile2;

	pile2 = NULL;
	if (argc == 1)
		return (0);
	if (argc > 2 && !go_split(argv[1]))
		init_pile(argv, &pile, 1, 0);
	else
	{
		if (go_split(argv[1]))
			init_pile(ft_strsplit(argv[1], ' '), &pile, 0, 1);
		else
			add_pile(&pile, ft_atoi(argv[1]));
	}
	ft_read_cmd(&pile, &pile2);
	ft_end(pile, pile2, pile_size(pile));
}
