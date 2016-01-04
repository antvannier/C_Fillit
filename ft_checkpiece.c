/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpiece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:00:53 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/27 12:14:04 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_tetri(t_tetri *s)
{
	unsigned char	y;
	unsigned char	x;
	int				ret;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s->map[y][x] == s->letter)
				if (!(ret = check_valid(s, y, x))
						|| (ret == 1 && check_next(s, y, x)))
					return (1);
			x++;
		}
		y++;
	}
	get_mv_to_topleft(s);
	return (0);
}

unsigned char	check_next(t_tetri *s, unsigned char y, unsigned char x)
{
	if (x < 3 && s->map[y][x + 1] == s->letter)
		if (check_valid(s, y, x + 1) < 2)
			return (1);
	if (x && s->map[y][x - 1] == s->letter)
		if (check_valid(s, y, x - 1) < 2)
			return (1);
	if (y < 3 && s->map[y + 1][x] == s->letter)
		if (check_valid(s, y + 1, x) < 2)
			return (1);
	if (y && s->map[y - 1][x] == s->letter)
		if (check_valid(s, y - 1, x) < 2)
			return (1);
	return (0);
}

unsigned char	check_valid(t_tetri *s, unsigned char y, unsigned char x)
{
	unsigned char	counter;

	counter = 0;
	if (x < 3 && s->map[y][x + 1] == s->letter)
		counter++;
	if (x && s->map[y][x - 1] == s->letter)
		counter++;
	if (y < 3 && s->map[y + 1][x] == s->letter)
		counter++;
	if (y && s->map[y - 1][x] == s->letter)
		counter++;
	return (counter);
}

void			get_mv_to_topleft(t_tetri *s)
{
	unsigned char	y;
	unsigned char	y_move;
	unsigned char	x;
	unsigned char	x_move;

	y = 0;
	x_move = 4;
	y_move = 4;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s->map[y][x] == s->letter && (x_move > x))
				x_move = x;
			if (s->map[y][x] == s->letter && (y_move > y))
				y_move = y;
			x++;
		}
		y++;
	}
	move_to_topleft(s, y_move, x_move);
}

void			move_to_topleft(t_tetri *s, unsigned char y_move,
		unsigned char x_move)
{
	unsigned char	y;
	unsigned char	x;

	y = 0;
	s->size_x = 0;
	s->size_y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s->map[y][x] == s->letter)
			{
				if (y_move || x_move)
				{
					s->map[y - y_move][x - x_move] = s->letter;
					s->map[y][x] = '.';
				}
				s->size_x = x - x_move > s->size_x ? x - x_move : s->size_x;
				s->size_y = y - y_move > s->size_y ? y - y_move : s->size_y;
			}
			x++;
		}
		y++;
	}
}
