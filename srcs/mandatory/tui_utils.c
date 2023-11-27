/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:41:14 by mgamil            #+#    #+#             */
/*   Updated: 2023/11/27 00:49:02 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int randomValue;

	srand(time(NULL));
	for (int i = 0; i < max; i++)
	{
		do
		{
			randomValue = rand() % (max + 1);
		} while (randomValue == 0 || isDuplicate(arr, i, randomValue));
		arr[i] = randomValue;
	}
}