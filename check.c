/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:21:53 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/12/23 19:04:57 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_len(int len)
{
	if (len > 546)
		return (0);
	if ((len + 1) % 21 != 0)
		return (0);
	return (1);
}

int		check_symb(char *str)
{
	while (*str)
	{
		if (*str == '.' || *str == '#' || *str == '\n')
			str++;
		else
			return (0);
	}
	return (1);
}

int		check_nn(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		if (*(temp - 1) == '\n' && *temp == '\n' &&
				*(temp + 1) == '\n')
			return (0);
		temp++;
	}
	return (1);
}

int		check_points(const char *str)
{
	int		i;
	int		count;
	int		count_n;

	i = 0;
	count = 0;
	count_n = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			count++;
		else
			count_n++;
		if (count_n == 5 && count != 16)
			return (0);
		if (count_n == 5 && count == 16)
		{
			count_n = 0;
			count = 0;
		}
		i++;
	}
	return (1);
}

int		ft_check(const char *str)
{
	if (str[0] == '\n')
		return (0);
	if (!(check_len(ft_strlen(str))))
		return (0);
	if (!(check_symb((char*)str)))
		return (0);
	if (!(check_nn((char*)str)))
		return (0);
	if (!(check_points((char*)str)))
		return (0);
	return (1);
}
