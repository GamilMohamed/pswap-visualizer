/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/26 20:19:39 by mgamil           ###   ########.fr       */
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
#define INPUT_TOO_LOW "Value too low\n"
#define INPUT_INVALID "Invalid input!\n"
#define QUIT_OK "Quitted successfully!\n"

typedef struct s_data
{
	int	arr[50];
	int	size;

	int	barr[50];
	int	bsize;

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

void	randomnumbergenerator(int arr[50], int max)
{
	int	randomValue;

	srand(time(NULL));
	for (int i = 0; i < max; i++)
	{
		do
		{
			randomValue = rand() % (max + 1);
		} while (randomValue == 0 || isDuplicate(arr, i, randomValue));
		fprintf(stderr, "i=%i\n", i);
		arr[i] = randomValue;
	}
}

#define COL_RE 9
#define COL_ER 10
#define COL_OK 11
#define COL_ST 12
#define COL_SU 13
#define OPTIONS 5

int	valid(char *str)
{
	if (strlen(str) == 1 && strchr("yY", str[0]))
		return (1);
	if (strlen(str) == 1 && strchr("nN", str[0]))
		return (2);
	if (!strcmp(str, "yes") || !strcmp(str, "Yes"))
		return (1);
	if (!strcmp(str, "no") || !strcmp(str, "No"))
		return (2);
	return (0);
}

int	home(void)
{
	long long int	tmp;
	char			str[2];

	static char *values[5] = {
		"Run your code with random arguments",
		"Run your code with defined arguments",
		"Interactive mode with random numbers",
		"Interactive mode with defined numbers",
		"Quit"};
	attron(COLOR_PAIR(8));
	for (int i = 0; i < OPTIONS; i++)
	{
		attron(A_NORMAL);
		attron(COLOR_PAIR(COL_RE));
		printw("[%i]", i + 1);
		attron(COLOR_PAIR(COL_ST));
		attron(A_BOLD);
		printw("%s\n", values[i]);
		attroff(A_BOLD);
	}
	attron(COLOR_PAIR(COL_OK));
	do
	{
		attron(COLOR_PAIR(COL_OK));
		printw("Index: ");
		getnstr(str, 1);
		tmp = ft_atoi(str);
		if (tmp < 1 || tmp > OPTIONS)
		{
			attron(COLOR_PAIR(COL_ER));
			printw("input must be between 1 and %i: {%s}\n", OPTIONS, str);
			continue ;
		}
		do
		{
			attron(COLOR_PAIR(COL_SU));
			printw("You selected [");
			attron(COLOR_PAIR(COL_ST));
			attron(A_BOLD | A_BLINK);
			printw("%s", values[tmp - 1]);
			attroff(A_BOLD | A_BLINK);
			attroff(COLOR_PAIR(COL_ST));
			attron(COLOR_PAIR(COL_SU));
			printw("]\nconfirm(y/n): ");
			attroff(COLOR_PAIR(COL_SU));
			getnstr(str, 1);
			if (strchr("nNyY", str[0]))
			{
				if (str[0] == 'n' || str[0] == 'N')
					tmp = 6;
				break ;
			}
			attron(COLOR_PAIR(COL_ER));
			printw("y/n?\n");
		} while (strlen(str) != 1 || !strchr("yn", str[0]));
	} while (tmp < 1 || tmp > OPTIONS);
	clear();
	refresh();
	return (tmp);
}

void	init(void)
{
	initscr(); /* start the curses mode */
	start_color();
	for (int i = 1; i < 8; i++)
		init_pair(i, i, i);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(11, COLOR_GREEN, COLOR_BLACK);
	init_pair(12, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(13, COLOR_CYAN, COLOR_BLACK);
}

int	menu(t_data *data)
{
	int	val[2];

	getmaxyx(stdscr, data->row, data->col);
	// mvprintw(0, COLS - 10, "r:%i|c:%i", LINES, COLS);
	val[0] = data->col / 2 - 4;
	val[1] = data->row - 2;
	return (val[0] < val[1] ? val[0] : val[1]);
}

// void	ft_printab2(t_pile pile_a, t_pile pile_b);

int	push_swap(int tab[], int size, int barr[])
{
	t_pile	pile_a;
	t_pile	pile_b;

	pile_a.tab = tab;
	pile_a.total = size;
	pile_a.size = size;
	pile_b.tab = ft_calloc(sizeof(int), size);
	pile_b.size = 0;
	ft_printab(pile_a, pile_b, "");
	ft_algo(&pile_a, &pile_b);
	return (0);
}

int		handleRandomArg(data) t_data *data;
{
	char str[3];
	int y, x;
	int val = menu(data);
	if (val < 0)
		return (printf(WIN_TOO_SMALL), 1);
	long long int tmp;
	do
	{
		mvprintw(0, 0, "Enter how many number to be generated (max %i): ", val);
		getyx(stdscr, y, x);
		getnstr(str, 2);
		tmp = ft_atoi(str);
		if (tmp < val && tmp > 1)
			break ;
		attron(COLOR_PAIR(COL_ER));
		tmp > val ? printw("%s", INPUT_TOO_HIGH) : printw("%s", INPUT_INVALID);
		attroff(COLOR_PAIR(COL_ER));
		move(y, 0);
		clrtoeol();
	} while (tmp > val || tmp < 2 || !*str);
	val = tmp;
	randomnumbergenerator(data->arr, val);
	data->size = val;
	move(LINES / 2, COLS / 2);
	push_swap(data->arr, val, data->barr);
	return (0);
}

void	header(void)
{ //70
	// mvprintw(0, 0, "%i", COLS);
	if (COLS < 74)
	{
		mvprintw(1, COLS / 2 - 21, " _   _ _                 _ _              ");
		mvprintw(2, COLS / 2 - 21, "| | | (_)               | (_)             ");
		mvprintw(3, COLS / 2 - 21, "| | | |_ ___ _   _  __ _| |_ _______ _ __ ");
		mvprintw(4, COLS / 2 - 21, "| | | | / __| | | |/ _` | | |_  / _ \\ '__|");
		mvprintw(5, COLS / 2 - 21, "\\ \\_/ / \\__ \\ |_| | (_| | | |/ /  __/ |   ");
		mvprintw(6, COLS / 2 - 21, " \\___/|_|___/\\__,_|\\__,_|_|_/___\\___|_|   \n");
		return ;
	}
	mvprintw(1, COLS / 2 - 37, "M\"\"MMMMM\"\"M oo                            dP oo                       ");
	mvprintw(2, COLS / 2 - 37, "M  MMMMM  M                               88                              ");
	mvprintw(3, COLS / 2 - 37, "M  MMMMP  M dP .d8888b. dP    dP .d8888b. 88 dP d888888b .d8888b. 88d888b.");
	mvprintw(4, COLS / 2 - 37, "M  MMMM' .M 88 Y8ooooo. 88    88 88'  `88 88 88    .d8P' 88ooood8 88'  `88");
	mvprintw(5, COLS / 2 - 37, "M  MMP' .MM 88       88 88.  .88 88.  .88 88 88  .Y8P    88.  ... 88      ");
	mvprintw(6, COLS / 2 - 37, "M     .dMMM dP `88888P' `88888P' `88888P8 dP dP d888888P `88888P' dP      ");
	mvprintw(7, COLS / 2 - 37, "MMMMMMMMMMM                                                               \n");
}

int	main(void)
{
	static t_data data = {1};

	init();
	header();
	int option = home();
	if (option == 1)
		handleRandomArg(&data);
	if (option == 2)
		handleRandomArg(&data);
	if (option == 3)
		handleRandomArg(&data);
	if (option == 4)
		handleRandomArg(&data);
	if (option == 5)
		return (endwin(), printf(QUIT_OK), 0);
	// int val = menu(&data);
	// if (val < 0)
	// 	return (printf(WIN_TOO_SMALL), 1);
	// printw("Enter how many number to be generated (max %i): ", val);
	// getstr(str);
	// if (!*str)
	// 	return (endwin(), printf(INPUT_INVALID), 1);
	// long long int tmp = ft_atoi(str);
	// if (tmp > val)
	// 	return (endwin(), printf(INPUT_TOO_HIGH), 1);
	// if (tmp == 0)
	// 	return (endwin(), printf(INPUT_INVALID), 1);
	// val = tmp;
	// randomnumbergenerator(data.arr, data.color, val);
	// data.size = val;
	// push_swap(data.arr, val, data.barr, data.color);
	// getch();
	endwin();

	return (0);
}