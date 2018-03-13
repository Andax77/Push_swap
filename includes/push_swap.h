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

typedef struct	s_bonus
{
	int				i;
	char			*cmd;
}				t_bonus;

void			ft_affichage(t_pile *lst);
void			ft_end(t_pile *pile, t_pile *pile2);
void			ft_clear(t_pile *lst);
int				ft_check_sort(t_pile *pile);
void			ft_error(char *str);

int				go_split(char *str);
int				go_split2(char *str);
void			add_pile(t_pile **pile, int value);
int				get_numbers(char *str);
void			init_pile(char *argv[], t_pile **pile, int a);
void			check_pile(char **str, int a);
void			check_double(char **str, int a);
int				ft_rmtake_pile(t_pile *begin);
void			ft_algo(t_pile **pile, t_pile **pile2, int argc);
void			ft_algo2(t_pile **pile, t_pile **pile2, int argc);
void			ft_algo3(t_pile **pile, t_pile **pile2, int argc);
int				end_pile(t_pile *pile);
int				ft_min_num(t_pile *pile);
int				ft_big_num(t_pile *pile);
int				ft_check_sort2(t_pile *pile2);
int				check_pile2(t_pile **pile2);
int				ft_mediane(t_pile *pile, int argc);
void			ft_separate_pile(t_pile **pile, t_pile **pile2, int med,
																		int *a);
void			ft_big_up(t_pile **pile, int *a);
void			ft_big_up2(t_pile **pile, int *a);
void			ft_min_up(t_pile **pile, int *a);
void			ft_min_up2(t_pile **pile, int *a);

void			ft_sa(t_pile **begin);
void			ft_sb(t_pile **pile2);
void			ft_ss(t_pile **pile, t_pile **pile2);
void			ft_pa(t_pile **pile, t_pile **pile2);
void			ft_pb(t_pile **pile, t_pile **pile2);
void			ft_ra(t_pile **pile);
void			ft_rb(t_pile **pile2);
void			ft_rr(t_pile **pile, t_pile **pile2);
void			ft_rra(t_pile **pile);
void			ft_rrb(t_pile **pile2);
void			ft_rrr(t_pile **pile, t_pile **pile2);

#endif
