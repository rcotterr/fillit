/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:46:55 by rcotter-          #+#    #+#             */
/*   Updated: 2019/01/19 18:52:24 by mferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			error_check(int argc)
{
	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	long	ret;
	char	buf[BUFF_SIZE + 1];
	char	**terminos;
	int		number_of_terminos;

	number_of_terminos = 0;
	fd = open(argv[1], O_RDONLY);
	if (error_check(argc) || fd < 0 || read(fd, buf, 0))
		return (1);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	number_of_terminos = (int)ret / 20;
	if (ft_strlen(buf) % 20 != (unsigned)(number_of_terminos - 1))
	{
		write(1, "error\n", 6);
		return (1);
	}
	terminos = (char **)malloc(sizeof(char *) * number_of_terminos + 1);
	terminos = get_terminos(terminos, buf, number_of_terminos);
	if (ft_valid(terminos) == 0)
		return (1);
	create_arrays(terminos, number_of_terminos);
	close(fd);
	return (0);
}
