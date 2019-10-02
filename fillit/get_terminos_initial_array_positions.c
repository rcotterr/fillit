/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grt_terminos_initial_array_positions.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:37:49 by rcotter-          #+#    #+#             */
/*   Updated: 2019/01/19 15:57:46 by mferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

struct s_parameters		min_initial_parameters(struct s_parameters grid_params)
{
	while ((grid_params.number_of_terminos * 4) >
		(grid_params.length * grid_params.width))
	{
		grid_params.length++;
		grid_params.width++;
	}
	return (grid_params);
}

char					**get_terminos(char **terminos,
						char *buf, int number_of_terminos)
{
	int					i;
	int					k;
	int					j;

	i = 0;
	k = 0;
	j = 0;
	while (i < number_of_terminos)
	{
		if (!(terminos[i] = (char *)malloc(sizeof(char) * 20)))
			return (NULL);
		while (k < 20)
		{
			terminos[i][k] = buf[j];
			k++;
			j++;
		}
		terminos[i][20] = '\0';
		i++;
		j++;
		k = 0;
	}
	terminos[i] = NULL;
	return (terminos);
}

int						*make_min(int *index_mod)
{
	int					m;
	int					min;

	m = 0;
	min = 3;
	while (m < 8)
	{
		if (index_mod[m] < min)
			min = index_mod[m];
		m++;
	}
	m = 0;
	while (m < 8)
	{
		if (index_mod[m] != 5)
			index_mod[m] = index_mod[m] - min;
		m++;
	}
	return (index_mod);
}

int						*make_index_mod(char *terminos)
{
	int					j;
	int					n;
	int					*index_mod;

	j = 0;
	n = 0;
	index_mod = (int *)malloc(sizeof(int) * 8);
	while (terminos[j] != '\0')
	{
		if (terminos[j] == '#')
		{
			index_mod[n] = j % 5;
			n++;
		}
		if (terminos[j] == '\n')
		{
			index_mod[n] = 5;
			n++;
		}
		j++;
	}
	index_mod = make_min(index_mod);
	return (index_mod);
}

int						create_arrays(char **terminos, int number_of_terminos)
{
	int					**index_mod;
	char				**grid;
	int					count;
	struct s_parameters	grid_params;
	struct s_index_map	map;

	grid_params.length = 2;
	grid_params.width = 2;
	grid_params.number_of_terminos = number_of_terminos;
	map.index = 0;
	map.x = 0;
	map.y = 0;
	map.count = 0;
	count = 0;
	grid_params = min_initial_parameters(grid_params);
	index_mod = (int **)malloc(sizeof(int *) * grid_params.number_of_terminos);
	while (count < grid_params.number_of_terminos)
	{
		index_mod[count] = make_index_mod(terminos[count]);
		count++;
	}
	grid = fill_dots(grid_params);
	solver(grid, index_mod, grid_params, map);
	return (0);
}
