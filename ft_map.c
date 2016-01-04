/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:24:09 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/27 12:23:18 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_map(t_tetri **first, unsigned char *nb_tetri)
{
	t_map	*map;

	if (!(map = create_and_init_map(3 + *nb_tetri)))
		return (1);
	map->size = get_sq_min(*nb_tetri, first);
	while (resolve(*first, map))
		map->size += 1;
	display_map(map);
	free(map);
	return (0);
}

t_map			*create_and_init_map(unsigned char size)
{
	char			**mapchar;
	t_map			*map;
	unsigned char	y;
	unsigned char	x;

	y = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(mapchar = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (y < size)
	{
		if (!(mapchar[y] = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		x = 0;
		while (x < size)
		{
			mapchar[y][x] = '.';
			x++;
		}
		y++;
	}
	map->map = mapchar;
	return (map);
}

unsigned char	get_sq_min(unsigned char nb, t_tetri **first)
{
	unsigned char	i;
	t_tetri			*minos;

	i = 0;
	minos = *first;
	while ((i * i) < (nb * 4))
		i++;
	while (minos)
	{
		i = i < minos->y + 1 ? minos->y + 1 : i;
		i = i < minos->x + 1 ? minos->x + 1 : i;
		minos = minos->next;
	}
	return (i);
}

void			display_map(t_map *map)
{
	int x;
	int	y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			ft_putchar(map->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		free(map->map[y]);
		y++;
	}
	free(map->map);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}
