/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:34:36 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/23 09:55:35 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	player_walk(t_mlx_data *mlx, int keysym)
{
	int	x;
	int	y;

	x = mlx->map->P_x;
	y = mlx->map->P_y;
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
	{
		if (mlx->map->tab[y - 1][x] == '1')
			return (0);
		if (mlx->map->tab[y - 1][x] == '0')
		{
			if (mlx->map->tab[y][x] == 'E')
			{
				mlx->map->tab[y + 1][x] = 'P';
			}
		}

	}
}
