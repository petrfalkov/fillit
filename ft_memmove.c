/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:37:25 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/11/27 16:19:09 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (len)
	{
		s1 = (char*)dst;
		s2 = (char*)src;
		if (s2 < s1)
		{
			s1 += len;
			s2 += len;
			while (len)
			{
				*--s1 = *--s2;
				len--;
			}
		}
		else
		{
			while (len--)
				*s1++ = *s2++;
		}
	}
	return (dst);
}
