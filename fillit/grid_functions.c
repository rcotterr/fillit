/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:56:50 by rcotter-          #+#    #+#             */
/*   Updated: 2019/01/19 15:53:30 by mferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_print(char **grid, struct s_parameters grid_params)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < grid_params.length)
	{
		while (j < grid_params.width)
		{
			write(1, &grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

char				**clean(char **grid, int index,
					struct s_parameters grid_params)
{
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (i < grid_params.length)
	{
		while (k < grid_params.width)
		{
			if (grid[i][k] == 65 + index)
				grid[i][k] = '.';
			k++;
		}
		i++;
		k = 0;
	}
	return (grid);
}

char				**fill_dots(struct s_parameters grid_params)
{
	int				i;
	int				j;
	char			**grid;

	i = 0;
	j = 0;
	grid = (char **)malloc(sizeof(char *) * grid_params.length);
	while (i < grid_params.length)
	{
		grid[i] = (char *)malloc(sizeof(char) * grid_params.width + 1);
		while (j < grid_params.width)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\n';
		i++;
		j = 0;
	}
	return (grid);
}

struct s_index_map	find_previous_index_pos(char **grid, struct s_index_map map,
						struct s_parameters grid_params, int *index_mod)
{
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (i < grid_params.length)
	{
		while (k < grid_params.width)
		{
			if (grid[i][k] == 65 + map.index)
			{
				map.x = k - index_mod[f_index(index_mod)];
				map.y = i;
				return (map);
			}
			k++;
		}
		i++;
		k = 0;
	}
	return (map);
}
