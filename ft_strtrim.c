/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:52:56 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/12/25 14:58:10 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	end;
	size_t	begin;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		begin = 0;
		end = ft_strlen(s) - 1;
		while ((s[begin] == '\t' || s[begin] == '\n' || s[begin] == ' ' ||
					s[begin] == '.') && begin < end + 1)
			begin++;
		while ((s[end] == '\t' || s[end] == '\n' || s[end] == ' ' ||
					s[end] == '.') && &s[end] != s)
			end--;
		if (begin >= end || begin == ft_strlen(s))
			return (ft_strnew(1));
		if ((str = ft_strnew(end - begin + 1)))
		{
			ft_strncpy(str, s + begin, end - begin + 1);
			return (str);
		}
	}
	return (NULL);
}
