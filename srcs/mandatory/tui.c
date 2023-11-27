#include "push_swap.h"

int	menu(t_data *data)
{
	int	val[2];

	getmaxyx(stdscr, data->row, data->col);
	val[0] = data->col / 2 - 4;
	val[1] = data->row - 2;
	return (val[0] < val[1] ? val[0] : val[1]);
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

void	header(void)
{
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
	mvprintw(7, COLS / 2 - 37, "MMMMMMMMMMM                                                               \n\n");
}

