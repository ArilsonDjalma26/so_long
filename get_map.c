# include "so_long.h"

static  int count_line_map(char *filename)
{
    ssize_t     readed;
    int     fd;
    char    c;
    int     size;

    size = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        exit_error("Mapa vazio!");//pendente
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
        exit_error("Mapa invalido!");
    fd = open(filename, O_RDONLY);
    str = malloc(size + 1);
    if (!str)
    {
        exit_error("erro");//pendente
        close(fd);
    }
    read(fd, str, size);
    close(fd);
    str[size] = '\0';
    if (str[0] == '\n' || ft_strchr(str, ' '))
    {
         exit_error("Mapa invalido!");
         free(str);
         close(fd);
    }
    vet = ft_split(str, '\n');
    free(str);
    if (!vet)
        {
            perror(NULL);
            free(vet);
            close(fd);
        }
    return (vet);
}