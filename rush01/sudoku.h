/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 19:26:42 by jshi              #+#    #+#             */
/*   Updated: 2016/08/21 19:30:53 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <unistd.h>

void	fill(int arr[9][9], int val);
int		filled(int arr[9][9]);
void	copy(int dst[9][9], int src[9][9]);
int		get_bit(int a);
int		add_num(int to_solve[9][9], int valid_pos[9][9], int a, int val);
int		solve_obvious(int to_solve[9][9], int valid_pos[9][9]);
int		solve(int to_solve[9][9], int solved[9][9], int valid_pos[9][9]);
#endif
