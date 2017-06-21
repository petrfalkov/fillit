/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:25:54 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/11/27 16:22:57 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strdup(const char *s1)
{
	size_t	k;
	char	*s2;

	k = 0;
	if (!(s2 = (char*)malloc(sizeof(*s2) * ft_strlen(s1) + 1)))
		return (NULL);
	while (k < ft_strlen(s1))
	{
		s2[k] = s1[k];
		k++;
	}
	s2[k] = '\0';
	return (s2);
}
