/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:52:34 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/25 15:03:06 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lstlen(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		find_let(char **fig)
{
	int		letter;
	int		i;
	int		j;

	i = 0;
	letter = 0;
	while (fig[i])
	{
		j = 0;
		while (fig[i][j])
		{
			if (fig[i][j] != '.')
				letter = (int)fig[i][j];
			j++;
		}
		i++;
	}
	return (letter);
}

char	**delete(char **arr, int letter)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == letter)
				arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (arr);
}

char	**erase(char **arr, t_list *elem)
{
	int		letter;

	letter = find_let(elem->content);
	arr = delete(arr, letter);
	return (arr);
}

int		main(int argc, char **argv)
{
	char	*res;
	t_list	*lst;
	char	**arr;

	arr = arr_all();
	if ((res = ft_read_file(argv[1])) == 0 || argc != 2)
	{
		ft_putendl("error");
		return (0);
	}
	lst = ft_split_input(res);
	fillit(ft_lstlen(lst), arr, lst);
	arr = cut_arr(arr);
	arr = cut_final(arr);
	show(arr);
	return (0);
}
