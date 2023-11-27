/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:34:30 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/26 23:30:03 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double(long long int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (tab[i] == tab[j])
				return (0);
	}
	return (1);
}

int	ft_freetab(char **tab, int boolean)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	if (boolean)
		return (0);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	*ft_duptab(long long int *tab, int size)
{
	int	*new;
	int	i;

	if (!ft_double(tab, size))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	new = malloc(sizeof(int) * size);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < size)
		new[i] = tab[i];
	return (new);
}

int	ft_whileresij(char **res, int i)
{
	int	j;

	j = 0;
	while (res[i][j] == ' ')
		j++;
	if (res[i][j] == '-' || res[i][j] == '+')
		j++;
	if (res[i][j] == '-' || res[i][j] == '+')
		return (1);
	while (ft_isdigit(res[i][j]))
		j++;
	return (res[i][j] != '\0');
}

int	*parse_args(char *str, int *size)
{
	long long int		tab[10000];
	char	**res;
	int		i;
	int		n;

	i = 0;
	n = 0;
	res = ft_split(str, ' ');
	if (!res)
		exit(1);
	while (res[n])
	{
		if (ft_whileresij(res, n))
			return (ft_freetab(res, 1), NULL);
		tab[i] = ft_atoi(res[n++]);
		if (tab[i++] == INT32_MIN)
			return (ft_freetab(res, 1), NULL);
	}
	ft_freetab(res, 1);
	return (ft_duptab(tab, (*size) = n));
}
