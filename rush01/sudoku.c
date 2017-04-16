/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:11:47 by jshi              #+#    #+#             */
/*   Updated: 2016/11/20 00:35:49 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** Prints solution if found
*/

void	print_sol(int solved[9][9])
{
	int		a;
	char	str[3];

	if (solved[0][0] == 0 || solved[0][0] == 10)
	{
		write(1, "Error\n", 6);
		return ;
	}
	a = -1;
	str[2] = '\0';
	while (++a < 81)
	{
		str[0] = solved[a / 9][a % 9] + '0';
		str[1] = ' ';
		if (a % 9 == 8)
			str[1] = '\n';
		write(1, str, 2);
	}
}

/*
** Checks for invalid input
*/

int		invalid_input(int argc, char *argv[])
{
	int		a;
	char	c;

	if (argc != 10)
		return (1);
	a = -1;
	while (++a < 90)
	{
		c = argv[a / 10 + 1][a % 10];
		if (c != '\0' && a % 10 == 9)
			return (1);
		if (a % 10 == 9 || c == '.' || (c >= '1' && c <= '9'))
			continue ;
		return (1);
	}
	return (0);
}

/*
** Split from main
** Takes care of input
*/

int		input(int to_solve[9][9], int valid_pos[9][9], int argc, char *argv[])
{
	int		a;
	int		b;
	int		c;

	a = 0;
	while (++a < argc)
	{
		b = -1;
		while (argv[a][++b])
		{
			if (argv[a][b] == '.')
			{
				to_solve[a - 1][b] = 0;
				continue;
			}
			c = argv[a][b] - '0';
			if (!add_num(to_solve, valid_pos, 9 * (a - 1) + b, c))
				return (0);
		}
	}
	return (1);
}

/*
** to_solve is the sudoku puzzle that is changed recursively
** solved contains the solution to the puzzle if found
** solved[0][0] == 0 if there are no solutions found so far
** solved[0][0] == 10 if there is more than 1 solution found so far
** solved[0][0] == 1-9 if there is exactly 1 solution found so far
** valid_pos contains the valid positions in each cell
** if a cell is already filled, valid_pos is 0
** otherwise it contains this information in bit form
** Ex: 324 = 0101000100 -> 8, 6, 2 are the only valid numbers in this cell
*/

int		main(int argc, char *argv[])
{
	int		to_solve[9][9];
	int		solved[9][9];
	int		valid_pos[9][9];

	if (invalid_input(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	solved[0][0] = 0;
	fill(valid_pos, 1022);
	if (!input(to_solve, valid_pos, argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	solve(to_solve, solved, valid_pos);
	print_sol(solved);
	return (0);
}
