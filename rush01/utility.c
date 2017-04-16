/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:09:51 by jshi              #+#    #+#             */
/*   Updated: 2016/08/21 14:10:03 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fills the array with a number
*/

void	fill(int arr[9][9], int val)
{
	int		a;

	a = -1;
	while (++a < 81)
		arr[a / 9][a % 9] = val;
}

/*
** Checks if the array is filled
*/

int		filled(int arr[9][9])
{
	int		a;

	a = -1;
	while (++a < 81)
	{
		if (!arr[a / 9][a % 9])
			return (0);
	}
	return (1);
}

/*
** Copies src to dst
*/

void	copy(int dst[9][9], int src[9][9])
{
	int		a;

	a = -1;
	while (++a < 81)
		dst[a / 9][a % 9] = src[a / 9][a % 9];
}

/*
** Returns the position of the bit in the number
** If there isn't exactly one bit, then return 0
*/

int		get_bit(int a)
{
	int		b;

	if (!a || a & (a - 1))
		return (0);
	b = -1;
	while (a)
	{
		b++;
		a >>= 1;
	}
	return (b);
}
