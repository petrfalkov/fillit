/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:04:11 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/22 16:08:10 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_arr(int count_f)
{
	int		ichigo;

	ichigo = 15;
	while (ichigo * ichigo >= count_f * 4)
	{
		ichigo--;
	}
	ichigo++;
	return (ichigo);
}

char	**arr_all(void)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * 16);
	while (i < 15)
		arr[i++] = ft_memset(ft_strnew(15), '.', 15);
	arr[i] = 0;
	return (arr);
}
