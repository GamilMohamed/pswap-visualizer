/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 05:47:02 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/26 22:02:41 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checksortav(t_pile *pile_a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile_a->size)
	{
		j = i + 1;
		while (j < pile_a->size)
		{
			if (pile_a->tab[i] > pile_a->tab[j])
				return ;
			j++;
		}
		i++;
	}
	if (i == size)
	{
		free(pile_a->tab);
		exit(1);
	}
}

void	ft_checksort(t_pile *pile_a, t_pile *pile_b, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile_a->size)
	{
		j = i + 1;
		while (j < pile_a->size)
		{
			if (pile_a->tab[i] > pile_a->tab[j])
				ft_exit(pile_a, pile_b, 0);
			j++;
		}
		i++;
	}
	// if (i == size)
	// 	ft_exit(pile_a, pile_b, 1);
	// ft_exit(pile_a, pile_b, 0);
}

void	ft_exit(t_pile *pile_a, t_pile *pile_b, int boolean)
{
	// free(pile_a->tab);
	// free(pile_b->tab);
	ft_printab(*pile_a, *pile_b, "DONE");
	// if (boolean == 1)
	// 	;
	// else if (boolean == 2)
	// 	ft_printf("%rmalloc failed%0\n");
	// else
	// 	ft_printf("%rSort failed%0\n");
	exit(EXIT_SUCCESS);
}
