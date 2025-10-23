/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:09:20 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/23 16:55:02 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_valid_extension(const char *filename, const char *ext)
{
	int		len_file;
	int		len_ext;

	len_file = ft_strlen(filename);
	len_ext = ft_strlen(ext);
	if (len_file <= len_ext)
		return (0);
	return (ft_strncmp(filename + len_file - len_ext, ext, len_ext) == 0);
}

static void	check_file_access(const char *filename)
{
	if (open(filename, O_RDONLY) < 0)
		exit_error("Arquivo inexistente ou sem permissão!");
}

void	check_extension(const char *filename, const char *ext)
{
	if (!has_valid_extension(filename, ext))
		exit_error("Extensão inválida!");
	check_file_access(filename);
}
