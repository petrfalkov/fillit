/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:37:30 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/12/02 14:38:09 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strrev(char const *str)
{
	char	*ret_str;
	size_t	len;
	size_t	i;

	ret_str = 0;
	if (str)
	{
		len = ft_strlen(str);
		ret_str = ft_strnew(len);
		i = 0;
		while (i != len)
		{
			ret_str[i] = str[len - 1 - i];
			i++;
		}
	}
	return (ret_str);
}
