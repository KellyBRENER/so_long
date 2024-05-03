/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:36:17 by kbrener-          #+#    #+#             */
/*   Updated: 2024/05/03 14:24:04 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*affiche une image a un coordonnee precis sur la map*/
void	ft_img_to_window(t_mlx_data *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, (x * IMG_WIDTH),
		(y * IMG_HEIGHT));
}

/*parcours la map et affiche chaque image en fonction du charactere trouve*/
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
				ft_img_to_window(mlx, mlx->all_img->img_w, x, y);
			else if (mlx->map->tab[y][x] == '0')
				ft_img_to_window(mlx, mlx->all_img->img_f, x, y);
			else if (mlx->map->tab[y][x] == 'C')
				ft_img_to_window(mlx, mlx->all_img->img_c, x, y);
			else if (mlx->map->tab[y][x] == 'E')
				ft_img_to_window(mlx, mlx->all_img->img_e, x, y);
			else if (mlx->map->tab[y][x] == 'P')
				ft_img_to_window(mlx, mlx->all_img->img_pr, x, y);
			x++;
		}
		y++;
	}
	ft_img_to_window(mlx, mlx->all_img->img_black, 7, 17);
}

/*affiche les changements sur la map et le nombre de mvt effectues*/
void	ft_print_move(t_mlx_data *mlx, int dir, void *img)
{
	int	x;
	int	y;
	char	*moves;

	x = mlx->map->p_x;
	y = mlx->map->p_y;
	if (mlx->map->tab[y][x] == 'E')
		ft_img_to_window(mlx, mlx->all_img->img_e, x, y);
	else
		ft_img_to_window(mlx, mlx->all_img->img_f, x, y);
	if (dir == 1)
		ft_img_to_window(mlx, img, x, y - 1);
	else if (dir == 2)
		ft_img_to_window(mlx, img, x, y + 1);
	else if (dir == 3)
		ft_img_to_window(mlx, img, x - 1, y);
	else if (dir == 4)
		ft_img_to_window(mlx, img, x + 1, y);
	mlx->move++;
	moves = ft_itoa(mlx->move);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 9, 19, 0x00FF00, "MOVES :");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 49, 19, 0x00FF00, moves);
	free(moves);
}
