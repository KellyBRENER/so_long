/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:31:51 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/26 11:26:23 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_error(t_mlx_data *mlx, char *message)
{
	ft_clean_all(mlx);
	write(1, "Error\n", 6);
	ft_putstr_fd(message, 1);
	exit(1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
}

void	ft_free_map(t_mlx_data *mlx)
{
	int	i;

	i = 0;
	if (mlx->map->tab)
	{
		ft_free_tab(mlx->map->tab);
	}
	free(mlx->map);
	mlx->map = NULL;
}

void	ft_free_image(t_mlx_data *mlx)
{
	if (mlx->all_img)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_PR);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_PL);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_W);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_F);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_E);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_C);
		//besoin de free image?
		free(mlx->all_img);
		mlx->all_img = NULL;
	}
}

/*clean tout ce qui a potentiellement ete malloc*/
void	ft_clean_all(t_mlx_data *mlx)
{
	if (mlx)
	{
		if (mlx->map)
			ft_free_map(mlx);
		if (mlx->all_img)
			ft_free_image(mlx);
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->mlx_ptr)
			mlx_destroy_display(mlx->mlx_ptr);
	}
	free(mlx->mlx_ptr);
	free(mlx);
}

/*clean et sort du programme proprement si esc ou close*/
int	ft_exit(void *mlx)
{
	ft_clean_all((t_mlx_data *)mlx);
	exit(0);
}
