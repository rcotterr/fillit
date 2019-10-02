/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:03:58 by rcotter-          #+#    #+#             */
/*   Updated: 2019/01/19 19:05:15 by mferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE	546

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

struct				s_parameters
{
	int				length;
	int				width;
	int				number_of_terminos;
};

struct				s_index_map
{
	int				x;
	int				y;
	int				index;
	int				previous_index;
	int				count;
};

struct				s_counts
{
	int				i;
	int				j;
	int				k;
	int				count;
	int				tmp;
};

int					ft_basic_check(char **str, int j);
int					ft_check_connections(char **str, int j);
int					ft_valid(char **str);
size_t				ft_strlen(const char *s);
int					f_index(int *index_mod);
void				free_grid(char **grid, struct s_parameters grid_params);
char				**get_terminos(char **terminos,
						char *buf, int number_of_terminos);
int					create_arrays(char **terminos, int number_of_terminos);
struct s_parameters	min_initial_parameters(struct s_parameters grid_params);
int					*make_min(int *index_mod);
int					*make_index_mod(char *terminos);
void				ft_print(char **grid, struct s_parameters grid_params);
char				**clean(char **grid, int index,
						struct s_parameters grid_params);
char				**fill_dots(struct s_parameters grid_params);
struct s_index_map	find_previous_index_pos(char **grid, struct s_index_map map,
						struct s_parameters grid_params, int *index_mod);
void				solver(char **grid, int **index_mod, struct s_parameters
						grid_params, struct s_index_map map);
struct s_index_map	possibility_to_put_terminos(char **grid, int *index_mod,
						struct s_index_map map,
								struct s_parameters grid_params);
struct s_index_map	change_map(struct s_index_map map);
char				**clean_grid(struct s_counts *iter, char **grid, struct
						s_index_map map, struct s_parameters grid_params);

#endif
