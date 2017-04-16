/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:58:06 by eliu              #+#    #+#             */
/*   Updated: 2016/12/03 11:03:13 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>


void		ft_putstr(char *str, int x)
{
	while (str[x])
		write(1, &str[x++], 1);
}

int		main()
{
	char *str = "Hello world";	
	ft_putstr(str, 0);

	return (0);
}
