/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/26 05:33:36 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIN_TOO_SMALL "Window should be at least 120 wide\n"
#define INPUT_TOO_HIGH "Value too high\n"
#define INPUT_INVALID "Invalid input!\n"

typedef struct s_data
{
	int	arr[50];
	int	size;

	int	barr[50];
	int	bsize;

	int	color[50];
	int	row;
	int	col;
}		t_data;

int	isDuplicate(int *array, int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
			return (1);
	}
	return (0);
}

void	randomnumbergenerator(int arr[50], int color[50], int max)
{
	int	randomValue;

	srand(time(NULL));
	for (int i = 0; i < max; i++)
	{
		do
		{
			randomValue = rand() % (max + 1);
		} while (randomValue == 0 || isDuplicate(arr, i, randomValue));
		arr[i] = randomValue;
		color[i] = i % 8 + 1;
	}
}
int	init(t_data *data)
{
	int val[2];

	initscr(); /* start the curses mode */
	start_color();
	for (int i = 1; i < 8; i++)
		init_pair(i, i, i);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	getmaxyx(stdscr, data->row, data->col);
	printw("r:%i c:%i\n", data->row, data->col);
	// 100 ok 50 * 2
	val[0] = data->col / 2 - 4;
	val[1] = data->row;
	return (val[0] < val[1] ? val[0] : val[1]);
}

// void	ft_printab2(t_pile pile_a, t_pile pile_b);

int	push_swap(int tab[], int size, int barr[], int color[])
{
	t_pile	pile_a;
	t_pile	pile_b;

	pile_a.tab = tab;
	pile_a.total = size;
	pile_a.size = size;
	pile_a.color = color;
	pile_b.tab = barr;
	pile_b.size = 0;
	ft_printab(pile_a, pile_b);
	ft_algo(&pile_a, &pile_b);
	return (0);
}

void	ft_printab(t_pile pile_a, t_pile pile_b)
{
	clear();
	for (int i = 0; i < pile_a.size; i++)
	{
		attron(COLOR_PAIR(9));
		mvprintw(LINES - pile_a.size + i, 0, "%0.2i:", pile_a.tab[i]);
		attron(COLOR_PAIR(pile_a.tab[i] % 8 + 1));
		for (int j = 0; j < pile_a.tab[i]; j++)
			mvprintw(LINES - pile_a.size + i, j + 3, " ", pile_a.tab[i]);
	}
	// pile B
	for (int i = 0; i < pile_b.size; i++)
	{
		attron(COLOR_PAIR(9));
		mvprintw(LINES - pile_b.size + i, COLS - 3, ":%0.2i", pile_b.tab[i]);
		attron(COLOR_PAIR(pile_b.tab[i] % 8 + 1));
		for (int j = 0; j < pile_b.tab[i]; j++)
			mvprintw(LINES - pile_b.size + i, COLS - j - 4, " ", pile_b.tab[i]);
	}
	getch();
	refresh();
}

int	main(void)
{
	static t_data data = {0};

	char str[1000];
	int val = init(&data);
	if (val < 0)
		return (printf(WIN_TOO_SMALL), 1);
	printw("Enter how many number to be generated (max %i): ", val);
	getstr(str);
	if (!*str)
		return (endwin(), printf(INPUT_INVALID), 1);
	long long int tmp = ft_atoi(str);
	if (tmp > val)
		return (endwin(), printf(INPUT_TOO_HIGH), 1);
	if (tmp == 0)
		return (endwin(), printf(INPUT_INVALID), 1);
	val = tmp;
	randomnumbergenerator(data.arr, data.color, val);
	data.size = val;
	push_swap(data.arr, val, data.barr, data.color);
	getch();
	endwin();

	return (0);
}