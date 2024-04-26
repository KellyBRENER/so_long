/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:55:14 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/26 15:06:10 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*clean et sort du programme proprement en cas d'erreur*/
void	ft_error(t_mlx_data *mlx, char *message)
{
	ft_clean_all(mlx);
	write(1, "Error\n", 6);
	ft_putstr_fd(message, 1);
	exit(1);
}

/*clean et sort du programme proprement si esc ou close*/
int	ft_exit(void *mlx)
{
	ft_clean_all((t_mlx_data *)mlx);
	exit(0);
}

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
	mlx_hook(mlx->win_ptr, 17, 0, ft_exit, (void *)mlx);
	mlx_loop(mlx->mlx_ptr);
	ft_exit(mlx);
}
