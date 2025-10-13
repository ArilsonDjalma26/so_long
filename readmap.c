/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:18:24 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/13 12:11:37 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free (line);
		line = get_next_line(fd);
	}
	return (count);
}

static char	*remove_newline(char *line)
{
	int		len;
	char	*clean_line;

	len = ft_strlen (line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	clean_line = ft_strdup (line);
	free (line);
	return (clean_line);
}

char	**fill_map(int fd, int height)
{
	char	**map;
	char	*line;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i++] = remove_newline(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(char *file)
{
	int		fd;
	int		height;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	height = count_line (fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = fill_map(fd, height);
	close (fd);
	if (!map || map[0] == NULL)
		exit_error("Arquivo vazio ou inesistente!");
	return (map);
}
