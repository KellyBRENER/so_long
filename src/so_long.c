/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:55:14 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/17 15:34:26 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_error(char *message)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(message, 1);
	exit(1);
}
void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	main(int argc, char **argv)
{
	t_map_data	*map;
	t_mlx_data	*mlx;

	mlx = NULL;
	map = NULL;
	if (argc != 2)
		ft_error("wrong number of arguments");
	map = ft_check_map(argv[1]);
	ft_free_tab(map->tab);
	map->tab = ft_init_map_tab(argv[1], map);
	mlx = ft_init_mlx();
	if (!mlx)
	{
		ft_free_tab(map->tab);
		ft_error("mlx opening failed");
	}
//	t_data	win_temp;
//	win_temp.img = mlx_new_image(mlx_ptr, 1920, 1080);
//	win_temp.addr = mlx_get_data_addr(win_temp.img, &win_temp.bits_per_pixel, &win_temp.line_length, &win_temp.endian);
//	my_mlx_pixel_put(&img, x, y, 0xFF000000);
	mlx_loop(mlx_ptr);
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_loop(mlx_ptr);//keep the process alive
//	avant de cloturer le programme:
	mlx_destroy_display(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
	if (map->tab)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
	ft_free_tab(map->tab);
	free(map);
	return (0);
}
