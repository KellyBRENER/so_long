/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <kbrener-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:25:24 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/15 11:49:02 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_map(char   *argv)
{
    if (ft_file_is_ber(argv) == 1)
        return (-1);
}

int ft_file_is_ber(char *argv)
{
    while (*argv)
    {
        if (ft_strncmp(argv, ".ber", 4) == 0)
            return (0);
        argv++;
    }
    return (1);
}