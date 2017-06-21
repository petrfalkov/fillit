/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:05:53 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/12/03 17:07:36 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_temp;
	t_list	*temp1;
	t_list	*temp2;

	if (lst)
	{
		temp1 = lst;
		temp2 = temp1->next;
		new_list = f(temp1);
		new_temp = new_list;
		temp1 = temp2;
		while (temp1)
		{
			temp2 = temp1->next;
			new_temp->next = f(temp1);
			temp1 = temp2;
			new_temp = new_temp->next;
		}
		return (new_list);
	}
	return (0);
}
