/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:15:36 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/12/25 15:03:34 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_open_file(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) != -1)
		return (fd);
	else
		return (0);
}

char	*ft_get_input(int fd)
{
	int		ret;
	char	buf[547];
	char	*str;

	if ((ret = read(fd, buf, 547)) != 0)
		buf[ret] = '\0';
	else
		return (NULL);
	str = ft_strdup(buf);
	return (str);
}

char	*ft_read_file(char *str)
{
	int		fd;
	char	*input;

	if ((fd = ft_open_file(str)) == 0)
		return (0);
	if ((ft_validate(fd)) == 0)
		return (0);
	close(fd);
	fd = ft_open_file(str);
	if (!(input = ft_get_input(fd)))
		return (0);
	return (input);
}

t_list	*ft_splitter(t_list *elem)
{
	t_list	*new;

	new = ft_lstnew(elem->content, elem->content_size);
	new->content = ft_strsplit(new->content, '\n');
	new->content = fig_norm(new->content);
	return (new);
}

t_list	*ft_split_input(char *input)
{
	t_list	*lst;
	char	*str;
	int		num;
	int		start;
	int		letter;

	start = 0;
	letter = 65;
	num = (ft_strlen(input) + 1) / 21;
	str = ft_strsub(input, start, 20);
	ft_replace(str, '#', letter);
	lst = ft_lstnew(str, 20);
	letter++;
	start += 21;
	while (--num > 0)
	{
		str = ft_strsub(input, start, 20);
		ft_replace(str, '#', letter);
		ft_lstpush_back(&lst, ft_lstnew(str, 20));
		start += 21;
		letter++;
	}
	lst = ft_lstmap(lst, &ft_splitter);
	return (lst);
}
