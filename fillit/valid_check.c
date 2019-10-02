/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:54:23 by rcotter-          #+#    #+#             */
/*   Updated: 2019/01/18 16:54:37 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_basic_check(char **str, int j)
{
	int i;
	int count_block;
	int count_new_line;

	i = 0;
	count_block = 0;
	count_new_line = 0;
	while (str[j][i])
	{
		if (str[j][i] != '.' && str[j][i] != '#' && str[j][i] != '\n')
			return (0);
		if ((i == 4 || i == 9 || i == 14 || i == 19) && str[j][i] != '\n')
			return (0);
		if (str[j][i] == '#')
			count_block++;
		if (str[j][i] == '\n')
			count_new_line++;
		i++;
	}
	if (count_block != 4 || count_new_line != 4)
		return (0);
	return (1);
}

int		ft_check_connections(char **str, int j)
{
	int i;
	int count_connections;
	int kvadrat;

	i = 0;
	count_connections = 0;
	kvadrat = 0;
	while (i < 20)
	{
		if (str[j][i] == '#')
		{
			if (str[j][i + 1] == '#' && str[j][i + 5] == '#'
				&& str[j][i + 6] == '#')
				kvadrat++;
			if (str[j][i + 1] == '#')
				count_connections++;
			if (str[j][i + 5] == '#')
				count_connections++;
		}
		i++;
	}
	if ((kvadrat && count_connections != 4) ||
		(kvadrat == 0 && count_connections != 3))
		return (0);
	return (1);
}

int		ft_valid(char **str)
{
	int j;

	j = 0;
	while (str[j])
	{
		if (ft_basic_check(str, j) == 0 || ft_check_connections(str, j) == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		j++;
	}
	return (1);
}
