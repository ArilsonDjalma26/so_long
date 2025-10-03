/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:18:24 by aalbano           #+#    #+#             */
/*   Updated: 2025/09/26 14:18:27 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     count_line(int fd)
{
    int     count;
    char    *line;

    count = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        count++;
        free(line);
    }
    return (count);
}

char    **read_map(char *file)
{
    int     fd;
    char    *line;
    char    **map;
    int     height;
    int     i;

    fd = open(file, O_RDONLY);
    i = 0;
    if (fd < 0)
        return (NULL);
    height = count_line(fd);
    close(fd);
    map = malloc (sizeof(char*) * (height + 1));
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    while((line = get_next_line(fd)) != NULL)
    {
        map[i] = line;
        i++;
    }
    map[i] = NULL;
    close(fd);
    return(map);
}