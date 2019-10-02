/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:01:39 by rcotter-          #+#    #+#             */
/*   Updated: 2019/01/19 19:21:05 by mferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				**if_index_map_is_min1(char **grid,
					struct s_parameters *grid_params, struct s_index_map *map)
{
	grid_params->width++;
	grid_params->length++;
	map->index = 0;
	map->x = 0;
	map->y = 0;
	free_grid(grid, *grid_params);
	grid = fill_dots(*grid_params);
	return (grid);
}

char				**move_previous_letter(char **grid, int **index_mod,
					struct s_parameters *grid_params, struct s_index_map *map)
{
	*map = find_previous_index_pos(grid, *map, *grid_params,
			index_mod[map->index]);
	grid = clean(grid, map->index, *grid_params);
	if (map->x < grid_params->width - 1)
		map->x++;
	else if (map->x == grid_params->width - 1)
	{
		map->y++;
		map->x = 0;
	}
	return (grid);
}

int					count_hashes(struct s_counts iter, int *index_mod,
					struct s_index_map *map, char **grid)
{
	int				j;
	int				count;

	j = 0;
	count = 0;
	map->x = iter.k;
	map->y = iter.i;
	while (j < 8 && count < 4 && iter.i < iter.tmp)
	{
		if (index_mod[j] != 5 && map->x + index_mod[j] <
				iter.tmp && grid[iter.i][map->x + index_mod[j]] == '.')
		{
			grid[iter.i][map->x + index_mod[j]] = 65 + map->index;
			count++;
			map->count++;
		}
		if (index_mod[j] == 5 && count != 0)
			iter.i = iter.i + 1;
		j++;
	}
	return (count);
}

struct s_index_map	possibility_to_put_terminos(char **grid, int *index_mod,
					struct s_index_map map, struct s_parameters grid_params)
{
	struct s_counts	iter;

	iter.i = map.y;
	iter.k = map.x;
	iter.tmp = grid_params.length;
	iter.count = 0;
	iter.j = 0;
	while (iter.i < grid_params.length)
	{
		while (iter.k < grid_params.width)
		{
			if (grid[iter.i][iter.k + index_mod[f_index(index_mod)]] == '.')
			{
				iter.count = count_hashes(iter, index_mod, &map, grid);
				grid = clean_grid(&iter, grid, map, grid_params);
				if (iter.count == 4)
					return (map);
			}
			iter.k++;
		}
		iter.k = 0;
		iter.i++;
	}
	map.index--;
	return (map);
}

void				solver(char **grid, int **index_mod, struct s_parameters
					grid_params, struct s_index_map map)
{
	map.previous_index = map.index;
	map = possibility_to_put_terminos(grid, index_mod[map.index], map,
			grid_params);
	if (map.index == -1 || (map.count > grid_params.number_of_terminos *
				4 * grid_params.length * 4 * grid_params.width * 4))
	{
		grid = if_index_map_is_min1(grid, &grid_params, &map);
		return (solver(grid, index_mod, grid_params, map));
	}
	else if (map.previous_index == map.index)
	{
		if (map.index != grid_params.number_of_terminos - 1)
		{
			map = change_map(map);
			return (solver(grid, index_mod, grid_params, map));
		}
		else if (map.index == grid_params.number_of_terminos - 1)
			return (ft_print(grid, grid_params));
	}
	else if (map.previous_index > map.index)
	{
		grid = move_previous_letter(grid, index_mod, &grid_params, &map);
		return (solver(grid, index_mod, grid_params, map));
	}
	return (ft_print(grid, grid_params));
}
