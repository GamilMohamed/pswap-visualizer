/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:18:08 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/26 19:10:18 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ncurses.h>

void	ft_printab(t_pile pile_a, t_pile pile_b, char *str)
{
	static int count;
	
	clear();
	attron(COLOR_PAIR(9));
	mvprintw(0, COLS / 2 - 1, "%s", str);
	mvprintw(1, COLS / 2 - 1, "%i", ++count);
	// mvprintw(0, COLS / 2 + 15, "[A:%p|B:%p", pile_a.tab, pile_b.tab);
	for (int i = 0; i < pile_a.size; i++)
	{
		attron(COLOR_PAIR(9));
		mvprintw(LINES - pile_a.size + i, 0, "%0.2i:", pile_a.tab[i]);
		attron(COLOR_PAIR(pile_a.tab[i] % 8 + 1));
		for (int j = 0; j < pile_a.tab[i]; j++)
			mvprintw(LINES - pile_a.size + i, j + 3, " ");
	}
	// pile B
	for (int i = 0; i < pile_b.size; i++)
	{
		attron(COLOR_PAIR(9));
		mvprintw(LINES - pile_b.size + i, COLS - 4, ":%0.2i", pile_b.tab[i]);
		attron(COLOR_PAIR(pile_b.tab[i] % 8 + 1));
		for (int j = 0; j < pile_b.tab[i]; j++)
			mvprintw(LINES - pile_b.size + i, COLS - j - 4, " ");
	}
	getch();
	refresh();
}
