/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:55:14 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/09 16:31:35 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdlib.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	void	*mlx_ptr;//identifiant de connection au serveur graphique
	void	*win_ptr;//identifiant de la nouvelle fenêtre
	t_data	img;
	mlx_ptr = mlx_init();//connection avec le serveur graphique
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world!");
	if (!win_ptr)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_loop(mlx_ptr);//keep the process alive
//	avant de cloturer le programme:
	mlx_destroy_display(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
}
