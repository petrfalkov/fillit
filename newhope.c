/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newhope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:15:08 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/25 15:07:07 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		in_square(char **fig, int square, int *point)
{
	int		hight;
	int		length;
	int		i;
	int		j;

	i = point[0];
	j = point[1];
	w_l(&hight, &length, fig);
	if (i + hight > square)
		return (0);
	if (j + length > square)
		return (0);
	return (1);
}

int		check_point(char **arr, char **fig, int square, int *point)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	i = point[0];
	if (!in_square(fig, square, point))
		return (0);
	while (fig[x])
	{
		y = 0;
		j = point[1];
		while (fig[x][y])
		{
			if (arr[i][j] != '.' && fig[x][y] != '.')
				return (0);
			j++;
			y++;
		}
		x++;
		i++;
	}
	return (1);
}

int		check_place(char **arr, char **fig, int square, int *to_put)
{
	int		point[2];

	point[0] = to_put[0];
	point[1] = to_put[1];
	while (!check_point(arr, fig, square, point))
	{
		point[1]++;
		if (point[1] == square + 1)
		{
			point[1] = 0;
			point[0]++;
			if (point[0] == square + 1)
			{
				point[0] = 0;
				point[1] = 0;
				return (0);
			}
		}
	}
	to_put[0] = point[0];
	to_put[1] = point[1];
	return (1);
}

int		check(char **arr, t_list *fig, int square)
{
	int		to_put[2];
	int		t_shift;
	int		l_shift;

	t_shift = 0;
	l_shift = 0;
	to_put[0] = 0;
	to_put[1] = 0;
	if (!fig)
		return (1);
	while (check_place(arr, fig->content, square, to_put))
	{
		putin(arr, fig->content, to_put[0] + t_shift, to_put[1] + l_shift);
		if (check(arr, fig->next, square))
			return (1);
		arr = erase(arr, fig);
		if (to_put[1] < square)
			to_put[1]++;
		else if (to_put[0] < square)
		{
			to_put[1] = 0;
			to_put[0]++;
		}
	}
	return (0);
}

void	fillit(int count_f, char **arr, t_list *fig)
{
	int		square;

	square = min_arr(count_f);
	while (!(check(arr, fig, square)))
		square++;
}
