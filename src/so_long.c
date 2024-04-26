/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:55:14 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/26 13:55:15 by kbrener-         ###   ########.fr       */
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
	mlx_key_hook(mlx->win_ptr, &ft_move, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, ft_exit, (void *)mlx);//gere croix fenetre
	mlx_loop(mlx->mlx_ptr);
	ft_exit(mlx);
}
