/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:34:36 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/26 13:57:12 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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
	//if (mlx)
	//	ft_printf("%d", keysym);
	return (0);
}

void	ft_up(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->P_x;
	y = mlx->map->P_y;
	if (mlx->map->tab[y - 1][x] == '1')
		return;
	if (mlx->map->tab[y - 1][x] == 'C')
	{
		mlx->map->C--;
		mlx->map->tab[y - 1][x] = '0';
	}
	ft_print_move(mlx, 1);
	if (mlx->map->tab[y - 1][x] == 'E' && mlx->map->C == 0)
		ft_exit(mlx);
	mlx->map->P_y = y - 1;
}

void	ft_down(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->P_x;
	y = mlx->map->P_y;
	if (mlx->map->tab[y + 1][x] == '1')
		return;
	if (mlx->map->tab[y + 1][x] == 'C')
	{
		mlx->map->C--;
		mlx->map->tab[y + 1][x] = '0';
	}
	ft_print_move(mlx, 2);
	if (mlx->map->tab[y + 1][x] == 'E' && mlx->map->C == 0)
		ft_exit(mlx);
	mlx->map->P_y = y + 1;
}

void	ft_left(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->P_x;
	y = mlx->map->P_y;
	if (mlx->map->tab[y][x - 1] == '1')
		return;
	if (mlx->map->tab[y][x - 1] == 'C')
	{
		mlx->map->C--;
		mlx->map->tab[y][x - 1] = '0';
	}
	ft_print_move(mlx, 3);
	if (mlx->map->tab[y][x - 1] == 'E' && mlx->map->C == 0)
		ft_exit(mlx);
	mlx->map->P_x = x - 1;
}

void	ft_right(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = mlx->map->P_x;
	y = mlx->map->P_y;
	if (mlx->map->tab[y][x + 1] == '1')
		return;
	if (mlx->map->tab[y][x + 1] == 'C')
	{
		mlx->map->C--;
		mlx->map->tab[y][x + 1] = '0';
	}
	ft_print_move(mlx, 4);
	if (mlx->map->tab[y][x + 1] == 'E' && mlx->map->C == 0)
		ft_exit(mlx);
	mlx->map->P_x = x + 1;
}
void	ft_print_move(t_mlx_data *mlx, int dir)
{
	int	x;
	int	y;

	x = mlx->map->P_x;
	y = mlx->map->P_y;
	if (mlx->map->tab[y][x] == 'E')
		ft_img_to_window(mlx, mlx->all_img->img_E, x, y);
	else
		ft_img_to_window(mlx, mlx->all_img->img_F, x, y);
	if (dir == 1)//up
		ft_img_to_window(mlx, mlx->all_img->img_PR, x, y - 1);
	else if (dir == 2)//down
		ft_img_to_window(mlx, mlx->all_img->img_PR, x, y + 1);
	else if (dir == 3)//left
		ft_img_to_window(mlx, mlx->all_img->img_PL, x - 1, y);
	else//right
		ft_img_to_window(mlx, mlx->all_img->img_PR, x + 1, y);
	mlx->move++;
	ft_printf("%d\n", mlx->move);
}
