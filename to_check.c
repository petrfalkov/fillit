/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:35:52 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/23 18:39:06 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		ft_putendl(arr[i++]);
}

void	w_l(int *wide, int *length, char **fig)
{
	int		i;

	i = 0;
	while (fig[i])
		i++;
	*wide = i;
	*length = ft_strlen(fig[0]);
}

char	*bpoint(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
		str[i++] = '.';
	return (str);
}
