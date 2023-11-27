/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:22:19 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/27 03:42:33 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <ncurses.h>
# include <time.h>
# include <string.h>

# define COL_RE 9
# define COL_ER 10
# define COL_OK 11
# define COL_ST 12
# define COL_SU 13
# define OPTIONS 5
# define WIN_TOO_SMALL "Window should be at least 120 wide\n"
# define INPUT_TOO_HIGH "Value too high\n"
# define INPUT_TOO_LOW "Value too low\n"
# define INPUT_INVALID "Invalid input!\n"
# define QUIT_OK "Quitted successfully!\n"


#define MAGENTA_TEXT attron(COLOR_PAIR(COL_ST))
#define CYAN_TEXT attron(COLOR_PAIR(COL_SU))
#define GREEN_TEXT attron(COLOR_PAIR(COL_OK))
#define RED_TEXT attron(COLOR_PAIR(COL_ER))
#define RESET_TEXT attron(COLOR_PAIR(COL_RE))

#define BOLD attron(A_BOLD);
#define NO_BOLD attroff(A_BOLD);

typedef struct s_pile
{
	int	size;
	int	*tab;
	int	*color;
	int	total;
}		t_pile;

typedef struct s_data
{
	int	*arr;
	int	size;

	int	*barr;
	int	bsize;

	int	row;
	int	col;
}		t_data;

/*	PARSE.C				*/
int		ft_freetab(char **tab, int boolean);
int		ft_double(long long int *tab, int size);
int		*ft_duptab(long long int *tab, int size);
int		ft_whileresij(char **res, int i);
int		*parse_args(char *str, int *size);
/*	MISC.C				*/
void	ft_checksortav(t_pile *pile_a, int size);
int		ft_checkacav(int ac, char **av);
void	ft_checksort(t_pile *pile_a, t_pile *pile_b, int size);
void	ft_exit(t_pile *pile_a, t_pile *pile_b, int boolean);
/*	ACTIONS.C			*/
void	pushswap_rotate(t_pile *pile, t_pile *autre, char c);
void	pushswap_rrotate(t_pile *pile, t_pile *autre, char c);
void	pushswap_swap(t_pile *pile, char c, t_pile *autre);

int		pushswap_push(t_pile *dest, t_pile *src, char c, int *tab);
void	pushswap_swap(t_pile *pile, char c, t_pile *autre);
void	ft_rotatedown(t_pile *pile);
void	ft_rotateup(t_pile *pile);
void	ft_pushmin(t_pile *pile, char c, t_pile *autre);
void	pushswap_rr(t_pile *pile_a, t_pile *pile_b, int x);
void	pushswap_rrr(t_pile *pile_a, t_pile *pile_b, int x);
/*	ALGO.C				*/
void	ft_algo(t_pile *pile_a, t_pile *pile_b);
void	algo_three(t_pile *pile, t_pile *pile_b);
void	algo_two(t_pile *pile_a, t_pile *pile_b);

void	algo_five(t_pile *pile_a, t_pile *pile_b);
/*	PRINT.C				*/
void	ft_printab(t_pile pile_a, t_pile pile_b, char *str);
/*	MATH.C				*/
int		ft_getmin(t_pile pile);
int		ft_getmax(t_pile pile);
int		ft_sup(t_pile pile_a, t_pile pile_b, int index);
/*	LIS.C				*/
void	algo_all(t_pile *pile_a, t_pile *pile_b);
/*	PRICE.C				*/
void	ft_pricecalculator(t_pile *pile_a, t_pile *pile_b);
int		ft_domovement(t_pile *pile_a, t_pile *pile_b, int index[5]);
int		ft_totalprice(int price_a, int price_b);
int		ft_price(t_pile *pile, int index);
/* TUI.C				*/
int	menu(t_data *data);
void	init(void);
void	header(void);
int	valid(char *str);
int	isDuplicate(int *array, int size, int value);
void	randomnumbergenerator(int arr[50], int max);

#endif
