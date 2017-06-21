/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:32:58 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/11/27 16:47:33 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	while (*temp1 == *temp2 && *temp1 != '\0' && *temp2 != '\0')
	{
		temp1++;
		temp2++;
	}
	if (*temp1 != *temp2)
		return (*temp1 - *temp2);
	else
		return (0);
}
