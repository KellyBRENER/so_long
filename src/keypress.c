/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:34:36 by kbrener-          #+#    #+#             */
/*   Updated: 2024/05/03 14:45:08 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		ft_up(mlx);
	if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		ft_down(mlx);
	if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		ft_left(mlx);
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		ft_right(mlx);
	if (keysym == XK_Escape)
		ft_exit(mlx);
	return (0);
}

void	ft_up(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->p_x;
	y = mlx->map->p_y;
	if (mlx->map->tab[y - 1][x] == '1')
		return ;
	else if (mlx->map->tab[y - 1][x] == 'E')
		ft_p_exit(mlx, 1);
	else
	{
		if (mlx->map->tab[y - 1][x] == 'C')
		{
			mlx->map->c--;
			mlx->map->tab[y - 1][x] = '0';
		}
		ft_print_move(mlx, 1, mlx->all_img->img_pu);
	}
	mlx->map->p_y = y - 1;
}

void	ft_down(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->p_x;
	y = mlx->map->p_y;
	if (mlx->map->tab[y + 1][x] == '1')
		return ;
	else if (mlx->map->tab[y + 1][x] == 'E')
		ft_p_exit(mlx, 2);
	else
	{
		if (mlx->map->tab[y + 1][x] == 'C')
		{
			mlx->map->c--;
			mlx->map->tab[y + 1][x] = '0';
		}
		ft_print_move(mlx, 2, mlx->all_img->img_pd);
	}
	mlx->map->p_y = y + 1;
}

void	ft_left(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->p_x;
	y = mlx->map->p_y;
	if (mlx->map->tab[y][x - 1] == '1')
		return ;
	else if (mlx->map->tab[y][x - 1] == 'E')
		ft_p_exit(mlx, 3);
	else
	{
		if (mlx->map->tab[y][x - 1] == 'C')
		{
			mlx->map->c--;
			mlx->map->tab[y][x - 1] = '0';
		}
		ft_print_move(mlx, 3, mlx->all_img->img_pl);
	}
	mlx->map->p_x = x - 1;
}

void	ft_right(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->p_x;
	y = mlx->map->p_y;
	if (mlx->map->tab[y][x + 1] == '1')
		return ;
	else if (mlx->map->tab[y][x + 1] == 'E')
		ft_p_exit(mlx, 4);
	else
	{
		if (mlx->map->tab[y][x + 1] == 'C')
		{
			mlx->map->c--;
			mlx->map->tab[y][x + 1] = '0';
		}
		ft_print_move(mlx, 4, mlx->all_img->img_pr);
	}
	mlx->map->p_x = x + 1;
}
