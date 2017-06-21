/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:33:40 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/23 18:42:43 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_bot(char **arr)
{
	int		i;
	int		j;
	int		len;
	int		cutter;

	i = 0;
	cutter = 0;
	while (arr[i])
		i++;
	i--;
	len = ft_strlen(arr[i]);
	while (i > 0)
	{
		j = 0;
		while (!(arr[i][j] >= 65 && arr[i][j] <= 90)
				&& arr[i][j] != 0)
			j++;
		if (j == len)
			cutter++;
		else
			return (cutter);
		i--;
	}
	return (cutter);
}

static int	check_right(char **arr)
{
	int		i;
	int		j;
	int		cutter;
	int		last;

	i = 0;
	last = ft_strlen(arr[i]) - 1;
	cutter = 0;
	j = 0;
	while (arr[j])
		j++;
	while (last >= 0)
	{
		i = 0;
		while (arr[i] != 0 && !(arr[i][last] >= 65
					&& arr[i][last] <= 90) && i < j)
			i++;
		if (i == j)
			cutter++;
		else
			return (cutter);
		last--;
	}
	return (cutter);
}

void		check_both(char **ret, char **fig, int check_b, int check_r)
{
	int		i;
	int		j;

	i = 0;
	malloc(0);
	while (i < check_b)
	{
		j = 0;
		ret[i] = ft_strnew(check_r);
		while (j < check_r)
		{
			ret[i][j] = fig[i][j];
			j++;
		}
		ret[i][j] = '\0';
		i++;
	}
	ret[i] = 0;
}

char		**cut_arr(char **fig)
{
	char	**ret;
	int		cur_len;
	int		len_str;
	int		check_b;
	int		check_r;

	cur_len = 0;
	len_str = ft_strlen(fig[0]);
	while (fig[cur_len])
		cur_len++;
	check_b = (int)(cur_len - check_bot(fig));
	check_r = (int)(len_str - check_right(fig));
	ret = (char**)malloc(sizeof(char*) * cur_len + 1 - check_b);
	check_both(ret, fig, check_b, check_r);
	return (ret);
}

char		**cut_final(char **arr)
{
	int		i;
	int		j;
	int		square;
	char	**res;

	i = 0;
	j = 0;
	while (arr[i])
		i++;
	while (arr[0][j])
		j++;
	square = i < j ? j : i;
	res = (char**)malloc(sizeof(char*) * square + 1);
	i = 0;
	while (i < square)
		res[i++] = bpoint(ft_strnew(square), square);
	putin(res, arr, 0, 0);
	return (res);
}
