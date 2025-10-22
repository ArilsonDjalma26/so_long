/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:25:21 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/22 12:25:25 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t      ft_strspn(const char *s, const char *accept)
{
    int     found;
    size_t  j;
    size_t  i;

    i = 0;
    while (s[i])
    {
        found = 0;
        j = 0;
       while (accept[j])
       {
            if (s[i] == accept[j])
            {
                found = 1;
                break ;
            }
            j++;
       }
       if (!found)
        break ;
       i++;
    }
    return (i);
}