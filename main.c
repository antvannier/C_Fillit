/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:58:06 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/27 12:24:16 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		end(t_tetri **first)
{
	if (*first)
		free_tetri(*first);
	return (1);
}

void	free_tetri(t_tetri *first)
{
	if (first->next)
		free_tetri(first->next);
	free(first);
	first = NULL;
}

int		main(int argc, char **argv)
{
	if (argc != 2 || sub_function(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
