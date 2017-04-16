/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:24:28 by jshi              #+#    #+#             */
/*   Updated: 2016/08/21 14:24:29 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** Split from add_num
** Checks if the number added causes a contradiction
*/

int		can_add_num(int valid_pos[9][9], int a, int val)
{
	int		b;
	int		c;
	int		d;

	b = -1;
	c = (a / 27) * 3;
	d = ((a % 9) / 3) * 3;
	while (++b < 9)
	{
		if (a % 9 != b && valid_pos[a / 9][b] == (1 << val))
			return (0);
		if (a / 9 != b && valid_pos[b][a % 9] == (1 << val))
			return (0);
		if ((a / 9 - c != b / 3 || a % 3 != b % 3) &&
			valid_pos[c + b / 3][d + b % 3] == (1 << val))
			return (0);
	}
	return (1);
}

/*
** Attempts to add a number to the puzzle
** Returns 1 if the number is added successfully
** Otherwise returns 0 is the number can't be added
*/

int		add_num(int to_solve[9][9], int valid_pos[9][9], int a, int val)
{
	int		b;
	int		c;
	int		d;

	if (!(valid_pos[a / 9][a % 9] & (1 << val)))
		return (0);
	b = -1;
	c = (a / 27) * 3;
	d = ((a % 9) / 3) * 3;
	if (!can_add_num(valid_pos, a, val))
		return (0);
	while (++b < 9)
	{
		valid_pos[a / 9][b] &= 1022 - (1 << val);
		valid_pos[b][a % 9] &= 1022 - (1 << val);
		valid_pos[c + b / 3][d + b % 3] &= 1022 - (1 << val);
	}
	valid_pos[a / 9][a % 9] = 0;
	to_solve[a / 9][a % 9] = val;
	return (1);
}

/*
** Fills in all the obvious numbers
** This is all cells that have only one possible number
** Returns 1 if no error, 0 if there is an error
*/

int		solve_obvious(int to_solve[9][9], int valid_pos[9][9])
{
	int		a;
	int		b;
	int		c;

	a = 0;
	while (!a)
	{
		a = 1;
		b = -1;
		while (++b < 81)
		{
			c = get_bit(valid_pos[b / 9][b % 9]);
			if (!to_solve[b / 9][b % 9] && c)
			{
				if (!add_num(to_solve, valid_pos, b, c))
					return (0);
				a = 0;
			}
		}
	}
	return (1);
}

/*
** Split from solve
** Does the recursive part of solve
*/

int		recurse(int to_solve[9][9], int solved[9][9], int valid_pos[9][9])
{
	int		a;
	int		b;
	int		c;
	int		solve_cpy[9][9];
	int		valid_cpy[9][9];

	a = 0;
	while (a < 81 && !valid_pos[a / 9][a % 9])
		a++;
	b = valid_pos[a / 9][a % 9];
	while (b)
	{
		c = get_bit(b - (b & (b - 1)));
		copy(solve_cpy, to_solve);
		copy(valid_cpy, valid_pos);
		if (add_num(solve_cpy, valid_cpy, a, c))
			solve(solve_cpy, solved, valid_cpy);
		b &= b - 1;
	}
	if (solved[0][0] > 0 && solved[0][0] < 10)
		return (1);
	return (0);
}

/*
** Solves the puzzle recursively
** Returns 0 if not exactly 1 solution so far
** Returns 1 if solution found so far
*/

int		solve(int to_solve[9][9], int solved[9][9], int valid_pos[9][9])
{
	if (solved[0][0] == 10)
		return (0);
	if (!solve_obvious(to_solve, valid_pos))
		return (0);
	if (filled(to_solve) && solved[0][0] != 0)
	{
		solved[0][0] = 10;
		return (0);
	}
	if (filled(to_solve))
	{
		copy(solved, to_solve);
		return (1);
	}
	return (recurse(to_solve, solved, valid_pos));
}
