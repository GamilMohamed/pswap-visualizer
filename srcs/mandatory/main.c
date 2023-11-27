/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/27 03:59:40 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static char	*values[5] = {"Run your code with random arguments",
		"Run your code with defined arguments",
		"Interactive mode with random numbers",
		"Interactive mode with defined numbers", "Quit"};

void		printoptions(values) char *values[5];
{
	for (int i = 0; i < OPTIONS; i++)
	{
		RESET_TEXT;		
		printw("[%i] ", i + 1);
		MAGENTA_TEXT;
		attron(A_DIM);
		printw("%s\n", values[i]);
	}
}

int	getUserInput(void)
{
	char			str[2];
	long long int	tmp;

	attron(COLOR_PAIR(COL_OK));
	printw("Index: ");
	attroff(COLOR_PAIR(COL_OK));
	getnstr(str, 1);
	tmp = atoll(str);
	if (tmp < 1 || tmp > OPTIONS)
	{
		attron(COLOR_PAIR(COL_ER));
		printw("Input must be between 1 and %i: {%s}\n", OPTIONS, str);
		return (-1);
	}
	return (tmp);
}

int	confirmSelection(void)
{
	char	str[2];

	do
	{
		attron(COLOR_PAIR(COL_SU));
		printw("Confirm (y/n): ");
		attroff(COLOR_PAIR(COL_SU));
		getnstr(str, 1);
		if (strchr("nNyY", str[0]))
		{
			if (str[0] == 'n' || str[0] == 'N')
				return (6);
			break ;
		}
		attron(COLOR_PAIR(COL_ER));
		printw("Invalid input. Please enter 'y' or 'n'.\n");
	} while (strlen(str) != 1 || !strchr("yn", str[0]));
	return (0);
}

int	home(void)
{
	long long int	tmp;
	char			str[2];

	printoptions(values);
	do
	{
		tmp = getUserInput();
		if (tmp != -1)
		{
			attron(COLOR_PAIR(COL_SU));
			printw("You selected [");
			attron(COLOR_PAIR(COL_ST));
			attron(A_BOLD);
			printw("%s", values[tmp - 1]);
			attroff(A_BOLD);
			attroff(COLOR_PAIR(COL_ST));
			attron(COLOR_PAIR(COL_SU));
			printw("]\n");
			if (confirmSelection() == 6)
				tmp = -1;
		}
	} while (tmp < 1 || tmp > OPTIONS);
	clear();
	refresh();
	return (tmp);
}

int	push_swap(int tab[], int size)
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

int			handleRandomArg(data) t_data *data;
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
	data->arr = malloc(sizeof(int) * val);
	data->size = val;
	randomnumbergenerator(data->arr, val);
	move(LINES / 2, COLS / 2);
	push_swap(data->arr, val);
	return (0);
}

int			handleDefinedArg(data) t_data *data;
{
	char str[30000];
	int y, x;
	int val = menu(data);
	if (val < 0)
		return (printf(WIN_TOO_SMALL), 1);
	long long int tmp;
	mvprintw(0, 0, "Enter numbers separated by spaces (max %i):\n", val);
	getstr(str);
	data->arr = parse_args(str, &data->size);
	if (!data->arr)
		return (endwin(), printf(INPUT_INVALID), exit(1), 1);
	for (int i = 0; i < data->size; i++)
		fprintf(stderr, "%i%i\n", data->arr[i], data->size);
	push_swap(data->arr, data->size);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_data data = {0};

	init();
	// init_color(900, 360, 82, 1);
	// printw("%i\n", can_change_color());
	header();
	int option = home();
	if (option == 1)
		handleRandomArg(&data);
	if (option == 2)
		handleDefinedArg(&data);
	if (option == 3)
		handleRandomArg(&data);
	if (option == 4)
		handleRandomArg(&data);
	if (option == 5)
		return (endwin(), printf(QUIT_OK), 0);
	endwin();
	return (0);
}