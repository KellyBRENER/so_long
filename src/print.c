/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:36:17 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/23 10:09:16 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_img_to_window(t_mlx_data *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, (x * IMG_WIDTH),
		(y * IMG_HEIGHT));
}

void	ft_print_map(t_mlx_data *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map->tab[y])
	{
		x = 0;
		while (mlx->map->tab[y][x])
		{
			if (mlx->map->tab[y][x] == '1')
				ft_img_to_window(mlx, mlx->all_img->img_W, x, y);
			else if (mlx->map->tab[y][x] == '0')
				ft_img_to_window(mlx, mlx->all_img->img_F, x, y);
			else if (mlx->map->tab[y][x] == 'C')
				ft_img_to_window(mlx, mlx->all_img->img_C, x, y);
			else if (mlx->map->tab[y][x] == 'E')
				ft_img_to_window(mlx, mlx->all_img->img_E, x, y);
			else if (mlx->map->tab[y][x] == 'P')
				ft_img_to_window(mlx, mlx->all_img->img_PR, x, y);
			x++;
		}
		y++;
	}
}
