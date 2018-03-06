/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:53:22 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/26 18:59:58 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/ft_printf.h"
# include "../libft/libft.h"

typedef struct	s_pile
{
	int				nbr;
	struct s_pile	*next;
}				t_pile;

void			add_pile(t_pile **pile, int value, int end);
int				get_numbers(char *str);
void			ft_error(char *str);
void			init_pile(char *argv[], t_pile **pile, int a);
void			check_pile(char **str, int a);
void			check_double(char **str, int a);

void			ft_sa(t_pile **begin);
void			ft_sb(t_pile **pile2);
void			ft_ss(t_pile **pile, t_pile **pile2);
void			ft_pa(t_pile **pile, t_pile **pile2);
void			ft_pb(t_pile **pile, t_pile **pile2);

#endif
