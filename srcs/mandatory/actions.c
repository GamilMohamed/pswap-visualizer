/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:15:51 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/26 16:17:11 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h> /* ncurses.h includes stdio.h */
#include "push_swap.h"

void	pushswap_rotate(t_pile *pile, t_pile *autre, char c)
{
	int	first;

	if (!pile->size)
		return ;
	first = pile->tab[pile->size - 1];
	first = pile->tab[0];
	ft_rotateup(pile);
	pile->tab[pile->size - 1] = first;
	if (c == 'b')
		ft_printab(*autre, *pile, "rb");
	else if (c == 'a')
		ft_printab(*pile, *autre, "ra");
	else if (c == 'r')
		ft_printab(*pile, *autre, "rr");
}

void	pushswap_rrotate(t_pile *pile, t_pile *autre, char c)
{
	int	last;

	if (!pile->size)
		return ;
	last = pile->tab[pile->size - 1];
	ft_rotatedown(pile);
	pile->tab[0] = last;
	if (c == 'b')
		ft_printab(*autre, *pile, "rrb");
	else if (c == 'a')
		ft_printab(*pile, *autre, "rra");
	else if (c == 'r')
		ft_printab(*pile, *autre, "rrr");
}

int	pushswap_push(t_pile *dest, t_pile *src, char c, int *tab)
{
	int	temp;
	int	i;

	if (!src->size)
		return (ft_printf("%r\t\tpush %c FAILED%0\n", c));
	temp = src->size--;
	dest->size++;
	ft_rotatedown(dest);
	dest->tab[0] = tab[0];
	i = 0;
	while (++i < temp)
		tab[i - 1] = tab[i];
	if (c == 'a')
		ft_printab(*dest, *src, "pa");
	else if (c == 'b')
		ft_printab(*src, *dest, "pb");
	return (1);
}

void	pushswap_swap(t_pile *pile, char c, t_pile *autre)
{
	int	temp;

	if (!pile->size)
		return ;
	if (pile->size < 2)
	{
		ft_printf("%r\t\tswap %c failed%0\n", c);
		return ;
	}
	temp = pile->tab[0];
	pile->tab[0] = pile->tab[1];
	pile->tab[1] = temp;
	if (c == 'a')
		ft_printab(*pile, *autre, "sa");
	else if (c == 'b')
		ft_printab(*autre, *pile, "sb");
	else if (c == 's')
		ft_printab(*autre, *pile, "ss");
}
