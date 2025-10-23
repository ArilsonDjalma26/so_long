/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:18:25 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/23 16:27:13 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(char c, int *lines, int *empty_line)
{
	if (c == '\n')
	{
		if (*empty_line)
			exit_error("Linha vazia no mapa!");
		(*lines)++;
		*empty_line = 1;
	}
	else
		*empty_line = 0;
}

static int	count_line_map(char *filename)
{
	ssize_t	readed;
	int		fd;
	char	c;
	int		lines ;
	int		empty_line;

	lines = 0;
	empty_line = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Mapa inexistente!");
	readed = read(fd, &c, 1);
	if (readed == 0)
		exit_error("Mapa vazio!");
	while (readed > 0)
	{
		check_char(c, &lines, &empty_line);
		readed = read(fd, &c, 1);
	}
	if (!empty_line)
		lines++;
	close(fd);
	if (lines == 0)
		exit_error("Mapa vazio!");
	return (lines);
}

static char	*read_map_content(char *filename)
{
	int		fd;
	char	c;
	int		size;
	char	*str;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Mapa inexistente!");
	while (read(fd, &c, 1) > 0)
		size++;
	close(fd);
	if (size == 0)
		exit_error ("Mapa vazio!");
	fd = open(filename, O_RDONLY);
	str = malloc(size + 1);
	if (!str)
		exit_error("Erro de memória!");
	read(fd, str, size);
	str[size] = '\0';
	close(fd);
	return (str);
}

char	**get_map(char *filename)
{
	int		size;
	char	*str;
	char	**vet;

	size = count_line_map(filename);
	if (size < 1)
		exit_error("Mapa inválido!");
	str = read_map_content(filename);
	if (str[0] == '\n')
	{
		free(str);
		exit_error("Mapa inválido!");
	}
	vet = ft_split(str, '\n');
	free(str);
	if (!vet)
		exit_error("Erro ao dividir o mapa!");
	return (vet);
}
