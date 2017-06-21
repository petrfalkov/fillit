/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:09:29 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/18 17:45:24 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	putin(char **arr, char **fig, int tshift, int lshift)
{
	int		i;
	int		j;

	i = 0;
	while (fig[i])
	{
		j = 0;
		while (fig[i][j])
		{
			if (fig[i][j] != '.')
				arr[i + tshift][j + lshift] = fig[i][j];
			j++;
		}
		i++;
	}
}
