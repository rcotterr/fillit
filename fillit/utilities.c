/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:53:14 by rcotter-          #+#    #+#             */
/*   Updated: 2019/01/19 18:12:04 by mferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int					f_index(int *index_mod)
{
	int				i;

	i = 0;
	while (index_mod[i] == 5)
	{
		i++;
	}
	return (i);
}

void				free_grid(char **grid, struct s_parameters grid_params)
{
	int				i;

	i = 0;
	while (i < grid_params.length)
	{
		grid[i] = NULL;
		i++;
	}
	free(grid);
}

struct s_index_map	change_map(struct s_index_map map)
{
	map.index++;
	map.x = 0;
	map.y = 0;
	return (map);
}

char				**clean_grid(struct s_counts *iter, char **grid,
					struct s_index_map map, struct s_parameters grid_params)
{
	if (iter->count != 4)
	{
		iter->j = 0;
		iter->k = map.x;
		iter->count = 0;
		iter->i = map.y;
		iter->tmp = grid_params.length;
		grid = clean(grid, map.index, grid_params);
	}
	return (grid);
}
