# include "so_long.h"
# include <stdio.h>

static  int count_line_map(char *filename)
{
    ssize_t     readed;
    int     fd;
    char    c;
    int     size;

    size = 0;
    fd = open(filename, O_RDONLY);
    readed = read(fd, &c, 1);
    while (readed > 0)
    {   
        readed = read(fd, &c, 1);
        size++;
    }
    close(fd);
    return (size);
}

char    **get_map(char *filename)
{
    int     fd;
    char    *str;
    char    **vet;

    int size = count_line_map(filename);
    if (size < 1)
        return (NULL);
    fd = open(filename, O_RDONLY);
    str = malloc(size + 1);
    if (!str)
        return (write(2, "Error\n", 6), NULL);
    read(fd, str, size);
    close(fd);
    str[size] = '\0';
    if (str[0] == '\n' || ft_strchr(str, ' '))
        return (ft_putendl_fd("invalid map\n", 2), NULL);
    vet = ft_split(str, '\n');
    if (!vet)
        return (NULL);
    return (vet);
}