/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:02:18 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/12/25 15:01:20 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	void	*temp;
	size_t	iter;

	iter = 0;
	temp = NULL;
	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content_size = content_size;
		link->content = malloc(content_size);
		ft_memmove(link->content, content, content_size);
	}
	link->next = NULL;
	return (link);
}
