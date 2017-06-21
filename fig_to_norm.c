/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_to_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:07:39 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/15 20:55:12 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_top(char **fig)
{
	int		i;
	int		j;

	i = 0;
	while (fig[i])
	{
		j = 0;
		while (!(fig[i][j] >= 65 && fig[i][j] <= 90)
				&& fig[i][j] != 0)
			j++;
		if (j != 4)
			return (i);
		i++;
	}
	return (i);
}

static int	check_left(char **fig)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	min = 2147483647;
	while (fig[i])
	{
		j = 0;
		while (!(fig[i][j] >= 65 && fig[i][j] <= 90)
				&& fig[i][j] != 0)
			j++;
		if (min > j)
			min = j;
		i++;
	}
	return (min);
}

char		**fig_norm(char **fig)
{
	char	**ret;
	int		i;
	int		x;
	int		y;
	int		j;

	i = 0;
	y = check_top(fig);
	ret = (char**)malloc(sizeof(char*) * 4 + 1);
	while (i < 4)
		ret[i++] = ft_strnew(4);
	i = 0;
	while (fig[y])
	{
		j = 0;
		x = check_left(fig);
		while (fig[y][x] != '\0')
			ret[i][j++] = fig[y][x++];
		ret[i++][j] = '\0';
		y++;
	}
	ret[i] = 0;
	ret = cut_arr(ret);
	return (ret);
}
