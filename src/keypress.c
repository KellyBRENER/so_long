/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:34:36 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/23 13:51:22 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	ft_move(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		player_walk(1, mlx);

}

void	player_walk(int dir, t_mlx_data *mlx)
{
	char	target;
	int	move;
	int	x;
	int	y;

	x = mlx->map->P_x;
	y = mlx->map->P_y;
	if (dir == 1)//mvt vers le haut
		target = mlx.map.tab[y - 1][x];
	if (target == '1')
		return (0);
	else //0 = floor, c = item, E = exit
	{
		if (mlx->map->tab[y][x] == 'E')
		{
			
		}
	}
	}
}
