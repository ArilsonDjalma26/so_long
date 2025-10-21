/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:09:20 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/20 19:09:24 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_extension(char *file, const char *ext)
{
    int     len_ext;
    int     len_file;
    int     i;

    i = 0;
    len_ext = ft_strlen(ext);
    len_file = ft_strlen(file);

    while (ext[i])
    {
        if (len_file < len_ext)
            exit_error("Mapa deve ter a extencao .ber");
        if (file[len_file] != ext[len_ext])
            exit_error("Mapa deve ter a extencao .ber");
        len_ext--;
        len_file--;
        i++;
    }
}