/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:31:51 by kbrener-          #+#    #+#             */
/*   Updated: 2024/05/03 13:48:40 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_pr);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_peno);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_peok);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_pd);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_pu);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_pl);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_w);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_f);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_e);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_c);
		mlx_destroy_image(mlx->mlx_ptr, mlx->all_img->img_black);
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
