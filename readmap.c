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

static char    *remove_newline(char *line)
{
    int len;
    char    *clean_line;
    
    len = ft_strlen(line);
    if(line[len - 1] == '\n')
        line[len - 1] = '\0';
    clean_line = ft_strdup(line);
    free(line);
    return (clean_line);
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
        map[i] = remove_newline(line);
        i++;
    }
    map[i] = NULL;
    close(fd);

    if (!map || map[0] == NULL)
        exit_error("Arquivo vazio ou inesistente!");
    return(map);
}