/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhlukhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:53:57 by mhlukhov          #+#    #+#             */
/*   Updated: 2016/12/23 19:06:32 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_valid_sample(void)
{
	char	**arr;

	arr = (char**)malloc(sizeof(char*) * 20);
	arr[0] = ft_strdup("##\n..##");
	arr[1] = ft_strdup("##.\n.##");
	arr[2] = ft_strdup("##..\n##");
	arr[3] = ft_strdup("#...\n###");
	arr[4] = ft_strdup("#..\n.###");
	arr[5] = ft_strdup("##..\n#...\n#");
	arr[6] = ft_strdup("##.\n.#..\n.#");
	arr[7] = ft_strdup("##\n..#.\n..#");
	arr[8] = ft_strdup("###.\n#");
	arr[9] = ft_strdup("###\n.#");
	arr[10] = ft_strdup("##..\n.#..\n.#");
	arr[11] = ft_strdup("##.\n..#.\n..#");
	arr[12] = ft_strdup("##\n...#\n...#");
	arr[13] = ft_strdup("#..\n###");
	arr[14] = ft_strdup("#.\n.###");
	arr[15] = ft_strdup("#...\n##..\n#");
	arr[16] = ft_strdup("#..\n.##.\n.#");
	arr[17] = ft_strdup("#.\n..##\n..#");
	arr[18] = ft_strdup("##\n.##");
	arr[19] = ft_strdup("##.\n##");
	return (arr);
}

char	**ft_valid_sample2(void)
{
	char	**arr;

	arr = (char**)malloc(sizeof(char*) * 13);
	arr[0] = ft_strdup("#...\n##..\n.#");
	arr[1] = ft_strdup("#..\n.##.\n..#");
	arr[2] = ft_strdup("#.\n..##\n...#");
	arr[3] = ft_strdup("##..\n.##");
	arr[4] = ft_strdup("##.\n..##");
	arr[5] = ft_strdup("#..\n##..\n#");
	arr[6] = ft_strdup("#.\n.##.\n.#");
	arr[7] = ft_strdup("#\n..##\n..#");
	arr[8] = ft_strdup("#\n...#\n...#\n...#");
	arr[9] = ft_strdup("#.\n..#.\n..#.\n..#");
	arr[10] = ft_strdup("#..\n.#..\n.#..\n.#");
	arr[11] = ft_strdup("#...\n#...\n#...\n#");
	arr[12] = ft_strdup("####");
	return (arr);
}

int		ft_check_sampl(char *str)
{
	char	**samples;
	int		i;

	i = 0;
	samples = ft_valid_sample();
	while (i < 20)
	{
		if (ft_strcmp(str, samples[i]) == 0)
			return (1);
		if (ft_strcmp(str, ft_strrev(samples[i])) == 0)
			return (1);
		i++;
	}
	free(samples);
	samples = ft_valid_sample2();
	while ((i - 20) < 13)
	{
		if (ft_strcmp(str, samples[i - 20]) == 0)
			return (1);
		if (ft_strcmp(str, ft_strrev(samples[i - 20])) == 0)
			return (1);
		i++;
	}
	free(samples);
	return (0);
}

int		ft_validate(int fd)
{
	char	buf[600];
	char	*str;
	int		num;
	int		start;

	start = read(fd, buf, 600);
	buf[start] = '\0';
	start = 0;
	if (!(ft_check(buf)))
		return (0);
	num = (ft_strlen(buf) + 1) / 21;
	while (num-- > 0)
	{
		str = ft_strtrim(ft_strsub(buf, start, 20));
		if (!(ft_check_sampl(str)))
			return (0);
		start += 21;
		free(str);
	}
	return (1);
}

void	ft_replace(char *str, int rep, int ned)
{
	while (*str)
	{
		if (*str == rep)
			*str = ned;
		str++;
	}
}
