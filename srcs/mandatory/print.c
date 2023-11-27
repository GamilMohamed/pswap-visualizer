/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:18:08 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/27 04:30:25 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ncurses.h>

void	menuprintab()
{
	RESET_TEXT;
	printw("q: quit\tm: menu\nn: next\tb:back\na: auto\ts:stop\n");
	RESET_TEXT;
}

void	ft_printab(t_pile pile_a, t_pile pile_b, char *str)
{
	static int count;
	char val[2];
	
	clear();
	menuprintab();
	move(3,0);
	attron(COLOR_PAIR(9));
	mvprintw(0, COLS / 2 - 1, "%s", str);
	mvprintw(1, COLS / 2 - 1, "%i", ++count);
	attron(A_BOLD);
	attron(COLOR_PAIR(10));
	mvprintw(LINES - 1, 0, "%i PILE_A", pile_a.size);
	mvprintw(LINES - 1, COLS - 9, "PILE_B %0.2i", pile_b.size);
	attroff(A_BOLD);
	move(0, 0);
	// mvprintw(0, COLS / 2 + 15, "[A:%p|B:%p", pile_a.tab, pile_b.tab);
	for (int i = 0; i < pile_a.size; i++)
	{
		attron(COLOR_PAIR(9));
		mvprintw(LINES - 1 - pile_a.size + i, 0, "%0.2i:", pile_a.tab[i]);
		attron(COLOR_PAIR(pile_a.tab[i] % 8 + 1));
		for (int j = 0; j < pile_a.tab[i]; j++)
			mvprintw(LINES - 1 - pile_a.size + i, j + 3, " ");
	}
	// pile B
	for (int i = 0; i < pile_b.size; i++)
	{
		attron(COLOR_PAIR(9));
		mvprintw(LINES - 1 - pile_b.size + i, COLS - 3, ":%0.2i", pile_b.tab[i]);
		attron(COLOR_PAIR(pile_b.tab[i] % 8 + 1));
		for (int j = 0; j < pile_b.tab[i]; j++)
			mvprintw(LINES - 1 - pile_b.size + i, COLS - j - 4, " ");
	}
	move(3,0);
	RESET_TEXT;
	getnstr(val, 2);
	if (val[0] == 'q')
	{
		endwin();
		exit(0);		
	}
	// getch();
	refresh();
}
