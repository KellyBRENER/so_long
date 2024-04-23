/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:55:14 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/23 13:38:23 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/
int	main(int argc, char **argv)
{
	t_mlx_data	*mlx;

	mlx = NULL;
	if (argc != 2)
		ft_error(mlx, "wrong number of arguments");
	mlx = malloc(sizeof(t_mlx_data));
	if (!mlx)
		ft_error(NULL, "t_mlx_data malloc failed");
	ft_check_map(mlx, argv[1]);
	ft_free_tab(mlx->map->tab);
	mlx->map->tab = ft_init_map_tab(argv[1], mlx->map);
	ft_init_mlx(mlx);
	ft_print_map(mlx);
	mlx_key_hook(mlx->win_ptr, ft_move(), mlx);
	mlx_hook(mlx->win_ptr, 17, 0, (void *)exit, 0);
//	t_data	win_temp;
//	win_temp.img = mlx_new_image(mlx_ptr, 1920, 1080);
//	win_temp.addr = mlx_get_data_addr(win_temp.img, &win_temp.bits_per_pixel, &win_temp.line_length, &win_temp.endian);
//	my_mlx_pixel_put(&img, x, y, 0xFF000000);
	mlx_loop(mlx->mlx_ptr);
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_loop(mlx_ptr);//keep the process alive
//	avant de cloturer le programme:
	ft_clean_all(mlx);
	exit (0);
}
